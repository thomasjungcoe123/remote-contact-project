

//Include needed Libraries
#include "nRF24L01.h"                  //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"                      // built in library for RF radio
#include "SPI.h"                       // Serial Peripheral Interface (SPI)used for communication between microcontroller

// extra declaration
#define inputSwitch 8                  // input switch is connected to Pin 8 on NANO.
                                       // this is done using the variable name inputButtom
                                       // more inputables can be implemented using other pins and defining them.
                         
int message[1] = {000};                // 8bit worth of array of type integer, which was
                                       // used to store value before being sent through the NRF24L01 (radio)

RF24 radio(9,10);                      // object of  NRF24L01 that depends RF24, which comes with the class that has
                                       // MISO, MOSI, SCK pins as well as spi inside of it
                                       // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO physically.

const uint64_t addr = 0xA1A1A1A1A1A1;  // Address that needs to be the same for both NRF24L01 of the 
                                       // of the Arduino Uno and the Arduino Nano

// ********************* initialization function ***************************//
// In this function, we will set up everything for the transmitter
void setup(void){

  pinMode(inputSwitch, INPUT_PULLUP);  // Define the switch pin on NANO as an input using Internal Pullups
                                       // the pin was internall pulled-up for switch since it's logic low / active low
                                       // pinMode() -> Configures the specified pin to behave either as an input or an output. 
  
  digitalWrite(inputSwitch,HIGH);      // Set Pin to HIGH at beginning
                                       // by sending in high, we make sure that the receiver's output is not activated
                                       // digitalWrite() -> Write a HIGH or a LOW value to a digital pin.
  
  radio.begin();                       // Start the NRF24L01
                                       // activating the serial communication through radio 
                                       // begin() --> RF24 radio object's the data rate in bits per second (baud) for serial data transmission. 
                                       
  radio.openWritingPipe(addr);         // Get NRF24L01 ready to transmit
                                       // actual transmission of data being done with the writing function used.
                                       // openWritingPipe(value) --> SPI writing function with the address provided through parameter
}



// ********************* iteration function  ***************************//
// this function handles actual function of the transmitter
void loop(void){

  if (digitalRead(inputSwitch) == LOW){   // If Switch is Activated, new message is sent to the receiver
                                          // digitalRead() --> returns the value of the parameter
                                          // our switch is active-lOW, so if it's LOW, than it means it is ON.
                                          // Thus, the switch is pressed.
    
    message[0] = 111;                     // 8 bit message that had 000, would turn into 111.
    radio.write(message, 1);              // Send logic HIGH through NRF24L01
  }
  else {
    message[0] = 000;                     // if the switch's state is HIGH, keep sending 000 through SPI
    radio.write(message, 1);              // Send logic LOW through NRF24L01
  }
}
