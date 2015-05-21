DESCRIPTION:
ERU Example: In the program, a pulse is constantly generated on P1.6 and LED is turned off. 
This can be connected to P3.6(ERU0.A1) to create a trigger event. This triggers an external 
event interrupt (ERU0.SR3) that clears up the status flag and lights up an LED (P3.9). 

REQUIRMENTS:
XMC4500 AB CPU board

SETUP: Connect XMC4500 AB CPU Board


HOW TO CREATE THE PROJECT:
1) Select the NVIC002App, IO004(two instance IO004/0(p1.6) and IO004/1(p3.9)), IO002(p3.6), ERU001 and ERU002.
2) NVIC002, In Interrupt Node Configuration  UI select Enable interrupt at initialisation and set ERU_Event_Handler
   as User defined interrupt handler.
   IO004/0, In Configure Pin UI select Output Enable. 
   IO004/1, In Configure Pin UI select Output Enable.
   ERU002, In Configuration UI select 'ON_TRIGGER' as Service request generation mode.
   ERU001, In Configuration UI select 'A' as Event request select and rising and falling edge.
3) Signal connections: 
'pad Signal' of IO002(Instance 0)  is connected to the 'signal A Input' of ERU001.  
'Trigger Pulse Output' of ERU001 is connected to 'Trigger Input' of ERU002.
'Gated Trigger Output' of ERU002 is connected to 'Interrupt Node' Signal of NVIC002/0 (Instance 0).   
4  Connect P1.6 to P3.6 on xmc4500 board  
5) Generate the code and build the project.
6) Download and run the project.


OBSERVATIONS:
1. When P1.6 to P3.6 is connected, LED P3.9 is blinking on and off, as an 
   external event is constantly occurring.
2. When P1.6 to P3.6 is not connected, LED P3.9 is off as no external 
   event has occurred. 
