/*******************************************************************************
 Copyright (c) 2014, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without**
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4500 AB Step Series                                 **
**                                                                            **
** AUTHOR : Application Engineering Team                                      **
**                                                                            **
** version 1.0.0 (Initial version)			                                  **
** version 1.0.2 (Updated to Public release                                   **
**                1.0.50 DAVE APPs Library)			                          **
** version 1.0.4 (Updated to Public release                                   **
**                1.0.64 DAVE APPs Library)			                          **
** MODIFICATION DATE : May 23, 2014                                           **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
**           App Developer                                                    **
*******************************************************************************/





#include <DAVE3.h>			//Declarations from DAVE3 Code Generation it includes also XMC4500.h

void delayfunction();


int main(void)
{
	// ... Initializes Apps configurations ...
	DAVE_Init();

	// ... infinite loop ...
	while(1)
	{
		//
	   IO004_ResetPin(IO004_Handle0);	// Clear P1.6
	   delayfunction();

	   IO004_SetPin(IO004_Handle1);		// Turns off LED (P3.9)
	   delayfunction();

	   IO004_SetPin(IO004_Handle0);		// Set P1.6 (external interrupt is triggered on rising edge)
	   delayfunction();
	}

}

/**
 * @brief This function is a delay function for 76ms
 * @param[in/out] None
 *
 */
void delayfunction(void)
{
	uint32_t tmp1, tmp2;

	for(tmp1=0;tmp1<10000;tmp1++)
	{
		for(tmp2=0;tmp2<100;tmp2++)
		{

		}
	}
}

/**
 * @brief ERU Event Handler (Handler for external Interrupt): Turns on P3.9 on ERU event
 * @param[in/out] None
 *
 */
void ERU_Event_Handler(void)
{
	uint32_t status;

	//Reads Status Flag
	status = RD_REG(ERU001_Handle0.ERURegs->EXICON[ERU001_Handle0.InputChannel],ERU_EXICON_FL_Msk , ERU_EXICON_FL_Pos);

	if(status)
    {
    	IO004_ResetPin(IO004_Handle1);		// ERU event received, turn on LED
    	ERU001_ClearFlag(ERU001_Handle0);	// Clears the Status Flag
    }

}
