DESCRIPTION:
ADC_Example: This example demonstrates the VADC Background request source 
functionality using ADC001 App: 1 Channel is configured to run continuously 
in background mode


REQUIRMENTS:
XMC4500 CPU_45A_V2 (AB Step) board

SETUP:Connect XMC4500 CPU_45A_V2 (AB Step) Board

HOW TO CREATE THE PROJECT:
1) Select the ADC001 App and  NVIC002 App.
2) In ADC001, enter number of channel in GROUP-A(Default Value) as one and 
   select the channel(Channel-AA) in Channel Select tab and enable result 
   event in the Interrupts tab.For continuous conversion select the 
   "Autoscan Mode" in Background configuration tab.
3) In NVIC002_0 App, Select "Enable Interrupt At Initialization".
    Enter the "User defined Interrupt Handler" and define it in the code.
4) Make the following signal connection:
   - Connect the "Result Event" signal of ADC001 app to the "NVIC Interrupt" 
     signal of NVIC002_0 App.
5) Manual Pin assignment: This is to define the board specific I/O constraints
	In this case IO001/0 (Potentiometer) is assigned to port 14.1 because on the 
	Hexagon XMC4500 CPU_45A_V2 (AB Step) board the potentiometer is connected to this pin.      
5) Call ADC001_GenerateLoadEvent after Dave_Init().
6) Generate the code and build the project.
7) Download and run the project. 


OBSERVATIONS:
1. Conversion should be happened in  the configured Channel.
2. Read the converted values from Result variable in Debug mode.
   Content of Result variable depends on the position of the potentiometer


