Remote Contact

$project
========

This project will transfer a data bit between microprocessors using arduino Uno and arduino Nano with radio connect to each.
This will be actuated using something similiar to that of a remote controller. The arduino Nano will have function as the 
transmitter using radio and a switch as input from user. The arduino Uno will have a function as the receiver using radio
and a LED.

Setup on Software
------------------
	- Two different hosts are required for this setup since its about remote controller
	- One script for the host that is in charge of the transmitting data.
	- One script for the host that is in charge of the receiving data.


How to use:
-----------
	- Install arduino IDE either through a host (window/mac/etc) or through online.
	- import library.
	- compile the code on Uno and Nano each.
	- upload the code on Uno and Nano each.
	- simply press the switch in Uno in order to light-up the LED in NANO.

Components
---------

	- arduino (UNO & NANO)
	- radio (NRF24L01 x 2)
	- a switch
	- a LED


Contribute
----------

NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24 for upgraded version of built in NRF42 librarry.
