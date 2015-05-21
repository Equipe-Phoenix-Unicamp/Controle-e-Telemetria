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
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** AUTHOR : Application Engineering Team                                      **
**                                                                            **
** version 1.0.6 (Updated with latest apps)	                                  **
**                                                                            **
** MODIFICATION DATE : May 27, 2014                                           **
**                                                                            **
*******************************************************************************/
/* Change History:
 *    Date       version       Details
 * 23-Nov-2012   1.0.0    Initial version
 * 01-Aug-2013   1.0.2    Update to latest DAVE Apps version e.g. ADC001 App v1.0.8
 * 16-Sep-2013   1.0.4    Updated with latest apps - ADC001[1.0.12], ADCGLOB001[1.0.16],
 *                        ADCGROUP001[1.0.18], DAVESUPPORT[1.0.36], LIBS[1.0.18],
 *                        MOTORLIBS[1.0.18]
 * 27-May-2013   1.0.6    (Migrated to new App versions) (Update-site Version 1.0.64)
 */

#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)

/* To store the conversion result */
ADC001_ResultHandleType Result;

int main(void)
{
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)


	DAVE_Init();			// Initialization of DAVE Apps

	/* Generate Load Event*/
	ADC001_GenerateLoadEvent(&ADC001_Handle0);

	while(1)
	{

	}
	return 0;
}
/* Global Result Register ISR*/
void GlobalResultEvent(void)
{
    /* Read the Result Register*/
    ADC001_GetResult(&ADC001_Handle0,&Result);
}
