/* =========================================================================== *
 * Copyright (c) 2014, Infineon Technologies AG                                *
 * All rights reserved.                                                        *
 *                                                                             *
 * Redistribution and use in source and binary forms, with or without          *
 * modification, are permitted provided that the following conditions are met: *
 * Redistributions of source code must retain the above copyright notice, this *
 * list of conditions and the following disclaimer. Redistributions in binary  *
 * form must reproduce the above copyright notice, this list of conditions and *
 * the following disclaimer in the documentation and/or other materials        *
 * provided with the distribution. Neither the name of the copyright holders   *
 * nor the names of its contributors may be used to endorse or promote         *
 * products derived from this software without specific prior written          *
 * permission.                                                                 *
 *                                                                                                                                                                                                                                                                                                                   *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       *
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      *
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR           *
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       *
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         *
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; *
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    *
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     *
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF      *
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                  *
 * To improve the quality of the software, users are encouraged to share       *
 * modifications, enhancements or bug fixes with                               *
 * Infineon Technologies AG (dave@infineon.com).                               *
 *                                                                             *
 * ==========================================================================
 * ** PLATFORM : Infineon XMC4500 Series (Relax Kit)                          **
 **                                                                            **
 ** AUTHOR : Application Engineering Team                                      **
 **                                                                            **
 ** Project version update to  v 1.0.0  Initial Version  	                  **
 **                            v 1.0.2  Updated with latest apps,linker and    **
 **                                     startup files        	              **
 **                                                                            **
 ** MODIFICATION DATE : May, 27, 2014                                          **
 **                                                                            **
 *******************************************************************************/

/** @file Main.c
 *  @brief Main source file for this PWMSP001 demo. This file contains the main
 *  tasks of the demo and is responsible for the initial application hardware
 *  configuration
 */

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)
void Tick_Handler(void);
void delayms(uint32_t delay_ms);
void delayus(uint32_t delay_us);
void Software_Timers_Init(void);
void verifyChange(void);

uint32_t ticks = 0UL;
uint32_t lastTick = 0UL;
float value = 1.0;
float period = 17.0;
int status = 1;

/**
 * @brief main function
 * @param[in] None
 * @return None
 */
int main(void) {
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)

	DAVE_Init(); // Initialization of DAVE Apps

	ticks = 0;
	//lastTick = value * 1000 / SYSTM002_SYSTICK_INTERVAL;
	//Software_Timers_Init();

	while (1) {

		//TODO: Change Handle
		if (IO004_ReadPin(IO004_Handle0) == 0) {
			//delayms(100);
			while (IO004_ReadPin(IO004_Handle0) == 0)
				;
			/*value += 0.1;
			 if (value > 2.0)
			 value = 2.0;*/

			value += 1;
			if (value > 20)
				value = 20;

			PWMSP001_SetDutyCycle(PWMSP001_Handle0, value);
		}

		if (IO004_ReadPin(IO004_Handle1) == 0) {
			//delayms(100);
			while (IO004_ReadPin(IO004_Handle1) == 0)
				;
			/*value -= 0.1;
			 if (value < 1.0)
			 value = 1.0;*/
			value -= 1;
			if (value < 10)
				value = 10;

			PWMSP001_SetDutyCycle(PWMSP001_Handle0, value);
		}

		//verifyChange();

	}
	return 0;
}

/**
 * @brief PWM_Period_Interrupt handler: executes every period match of PWMSP001/0.
 * @param[in] None
 * @return None
 */

//void PWM_Period_Interrupt(void)
//{
//	static uint32_t state;
//	status_t status;
//	status = DAVEApp_SUCCESS;
//	/* state machine to change the different duty cycle */
//	switch(state)
//	{
//		/* Updating of duty cycle to 10% */
//		case 0: status =  PWMSP001_SetCompare(&PWMSP001_Handle0, 0x8C9F); break;
//		case 16000: status =  PWMSP001_SetCompare(&PWMSP001_Handle0, 0x7CFF); break;
//
//		case 32000: status =  PWMSP001_SetCompare(&PWMSP001_Handle0, 0x1F3F); break;
//		case 34000: status =  PWMSP001_SetCompare(&PWMSP001_Handle0, 0x2EDF); break;
//		case 36000: status =  PWMSP001_SetCompare(&PWMSP001_Handle0, 0x3E7F); break;
//		case 38000: status =  PWMSP001_SetCompare(&PWMSP001_Handle0, 0x4E1F); break;
//		case 40000: status =  PWMSP001_SetCompare(&PWMSP001_Handle0, 0x5DBF); break;
//		case 42000: status =  PWMSP001_SetCompare(&PWMSP001_Handle0, 0x6D5F); break;
//
//
//		/* Updating of duty cycle to 90% */
//		case 8000: status =  PWMSP001_SetCompare(&PWMSP001_Handle0, 0x0F9F); break;
//
//		default:	break;
//	}
//	if(status != DAVEApp_SUCCESS)
//	{
//	  PWMSP001_Stop((PWMSP001_HandleType*)&PWMSP001_Handle0);
//	}
//
//	// Updating of the state machine
//	state++;
//	if(state>=44000)	state= 0;
//}
void verifyChange() {

	if (status == 0 && ticks >= period * 1000 / SYSTM002_SYSTICK_INTERVAL) {
		IO004_SetPin(IO004_Handle2);
		status = 1;
		ticks = 0;
	} else if (status == 1 && ticks >= value * 1000 / SYSTM002_SYSTICK_INTERVAL) {
		IO004_ResetPin(IO004_Handle2);
		status = 0;
	}

}

void Software_Timers_Init() {
	handle_t TaskTimerId;

	TaskTimerId = SYSTM002_CreateTimer(SYSTM002_SYSTICK_INTERVAL,
			SYSTM002_PERIODIC, &Tick_Handler, NULL);
	if (TaskTimerId != 0) {
//Timer created successfully so start it
		SYSTM002_StartTimer(TaskTimerId);
	}
}

void delayus(uint32_t delay_us) {
	uint32_t currenttick = ticks;
	while (ticks - currenttick < (delay_us / SYSTM002_SYSTICK_INTERVAL))
		;
	ticks = 0;
}

void delayms(uint32_t delay_ms) {
	delayus(1000 * delay_ms);
}

//1 tick por 100 us
void Tick_Handler(void) {
	ticks++;
}
