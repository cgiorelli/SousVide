# Crock-Pot Sous-Vide

Developed on the Aruindo IDE, this code turns your Crock-Pot into a Sous-Vide cooker.

##Table of Contents

&nbsp; [Introduction](https://github.com/lallo188/SousVide/blob/master/README.md#intro) <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [What is Sous-Vide?](https://github.com/lallo188/SousVide/blob/master/README.md#what-is-sous-vide) <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [Project Description](https://github.com/lallo188/SousVide/blob/master/README.md#project-description) <br />
&nbsp; [Code](https://github.com/lallo188/SousVide/blob/master/README.md#code) <br />
&nbsp;&nbsp; [NodeMCU Notes](https://github.com/lallo188/SousVide/blob/master/README.md#nodemcu-notes) <br />
&nbsp; [Wiring Diagrams](https://github.com/lallo188/SousVide/blob/master/README.md#wiring-diagrams) <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [Arunio Uno](https://github.com/lallo188/SousVide/blob/master/README.md#ardunio-uno)  <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [NodeMCU](https://github.com/lallo188/SousVide/blob/master/README.md#nodemcu)  <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [General Relay](https://github.com/lallo188/SousVide/blob/master/README.md#general-relay)  <br />

##Introduction

####What is Sous-Vide?

> Sous-vide (French for "under vacuum") is a method of cooking in which food is sealed in airtight plastic bags then placed in a water bath or in a temperature-controlled steam environment for longer than normal cooking times (usually 1 to 6 hours, up to 48 or more in some select cases) at an accurately regulated temperature much lower than normally used for cooking, typically around 55 to 60 °C (131 to 140 °F) for meat and higher for vegetables. The intent is to cook the item evenly, ensuring that the inside is properly cooked without overcooking the outside, and retain moisture.
[- Wikipedia](https://en.wikipedia.org/wiki/Sous-vide)

####Project Description

The Ardunio version of the project was created as extra-credit for my Digital Control with Embedded Systems class. After having used it, I wanted to make it's footprint on my counter smaller and so that's were the ESP8266 based NodeMCU comes in. Being able to control it wirelessly, and view the progress from anywhere were no brainers; so the NodeMCU version of the project is currently being created.

##Code

All code has been deveploped on the Arduino IDE, and can be found in the respective folders above.

####NodeMCU Notes

While the schematic can be found below, the code is still a work in progress and will be uploaded when completed.

##Wiring Diagrams

####Ardunio Uno
![Ardunio Wiring Diagram](https://raw.githubusercontent.com/lallo188/SousVide/master/Images/Arduino_Sous-Vide-Wiring-Diagram.png)

####NodeMCU

![NodeMCU Wiring Diagram](https://raw.githubusercontent.com/lallo188/SousVide/master/Images/NodeMCU_v3-Sous-Vide-Wire_Diagram.png)

An LED may be used to as status indicator, in order to do so just hook it up to an emtpy digital pin.

####General Relay

![Relay Wiring Diagram](https://raw.githubusercontent.com/lallo188/SousVide/master/Images/Relay_Wall_Wiring_Diagram.png)


**This part needs to be done carefully and at one's own risk as main voltage is used. Make sure to unplug all cords from the voltage source when working on them.**
