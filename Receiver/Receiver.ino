//Include needed Libraries at beginning
#include "nRF24L01.h"                  // NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"                      // built in library for RF radio
#include "SPI.h"                       // Serial Peripheral Interface (SPI)used for communication between microcontroller
   
int LED = 8;                           // global variable of type int have been declared and initailzed to pin 8 on Uno
                                       // this variable will be used for the LED output that would be turned on after switch is pressed
int message[1] = {000};                // 8bit worth of array of type integer, which was
                                       // used to store value before being sent through the NRF24L01 (radio)
  
RF24 radio(9,10);                      // object of  NRF24L01 that depends RF24, which comes with the class that has
                                       // MISO, MOSI, SCK pins as well as spi inside of it
                                       // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO physically.

const uint64_t addr = 0xA1A1A1A1A1A1;  // Address that needs to be the same for both NRF24L01 of the 
                                       // and of the Arduino Uno and the Arduino Nano

// ********************* initialization function ***************************//
// In this function, we will set up everything for the receiver
void setup(void){
  radio.begin();                       // Start the NRF24L01
                                       // activating the serial communication through radio 
                                       // begin() --> RF24 radio object's the data rate in bits per second (baud) for serial data transmission. 
  
  radio.openReadingPipe(1,addr);       // Get NRF24L01 ready to receive
                                       // reading MOSI/MISO using the addr shared between arduinos. 1 being the first communication
                                       // if there are more than one address, 2 and 3 and so on can be used.
                                       // openReadingPipe(value) --> SPI reading function using the address provided through parameter
  
  radio.startListening();              // Listen to see if information received
                                       // actual transmission of data being done with the reading function used.
                                       // startListening() -> once SPI connection is established, data transmission can be read through SPI,
                                       
  pinMode(LED, OUTPUT);                // Set LED in UNO pin to an OUTPUT
                                       // pinMode() -> Configures the specified pin to behave either as an input or an output. 
}


// ********************* iteration function  ***************************//
// this function handles actual function of the receiver
void loop(void){
  
  while (radio.available())            // while there is radio connection
  {                                    // available() -> checks for SPI connection between the radio
    radio.read(message, 1);            // Read information from the NRF24L01
                                       // read() --> reads the data in the SPI. data is in the message variable, located in the 1 in SPI.
    
    if (message[0] == 111)             // Indicates switch is pressed
    {
      digitalWrite(LED,HIGH);          // LED ON
                                       // digitalWrite() --> Write a HIGH or a LOW value to a digital pin.
    }
    else                               // if the switch is not pressed
    {
      digitalWrite(LED,LOW);           // LED OFF
    }
  }
}
