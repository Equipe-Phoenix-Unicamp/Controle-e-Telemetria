/*
 * Main.c
 *
 *  Created on: May 9, 2015
 *      Author: JM
 */

#include <DAVE3.h> //Declarations from DAVE3 Code Generation (includes SFR declaration)
void Tick_Handler(void);
void Testando_Handler(void);
void delayms(uint32_t delay_ms);
void delayus(uint32_t delay_us);
void Software_Timers_Init(void);
void WakeUp(void);

uint32_t ticks = 0UL;
bool value = 0UL;

int main(void) {
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)

	DAVE_Init(); // Initialization of DAVE Apps

	ticks = 0;
	Software_Timers_Init();

	/*PWMSP001_SetDutyCycle(&PWMSP001_Handle0,1);
	 PWMSP001_Start(&PWMSP001_Handle0);
	 delayms(100);
	 IO004_TogglePin(IO004_Handle5);
	 IO004_TogglePin(IO004_Handle0);
	 delayms(100);
	 */

	IO004_TogglePin(IO004_Handle0);

	WakeUp();

	while (1) {

		/*value = IO004_ReadPin(IO004_Handle7);

		 if (value == 0)
		 value = 0;*/

		//DIR
		/*if (IO004_ReadPin(IO004_Handle7) == 0) {
			delayms(100); //Anti debounce
			while (IO004_ReadPin(IO004_Handle7) == 0)
				; //Wait until button released
			IO004_TogglePin(IO004_Handle5);
			PWMSP001_SetDutyCycle(&PWMSP001_Handle0, 100.0);
			delayus(100);
			IO004_TogglePin(IO004_Handle0);
			delayus(100);
			PWMSP001_SetDutyCycle(&PWMSP001_Handle0, 50);

		}*/

		//DrvDis
		if (IO004_ReadPin(IO004_Handle7) == 0) {
			delayms(100); //Anti debounce
			while (IO004_ReadPin(IO004_Handle7) == 0);
			IO004_TogglePin(IO004_Handle5);
			IO004_TogglePin(IO004_Handle2);

		}

		//ENABLE
		if (IO004_ReadPin(IO004_Handle8) == 0) {
			delayms(100);
			while (IO004_ReadPin(IO004_Handle8) == 0)
				;
			IO004_TogglePin(IO004_Handle6);
			IO004_TogglePin(IO004_Handle1);
			/*delayms(10);
			 IO004_TogglePin(IO004_Handle6);
			 IO004_TogglePin(IO004_Handle1);*/
		}

		//delayus(100);
		//IO004_TogglePin(IO004_Handle0);

	}
	return 0;
}

void WakeUp(void) {

	//Enable
	IO004_TogglePin(IO004_Handle1);
	delayus(100);
	IO004_TogglePin(IO004_Handle1);

	//DrvDis
	/*IO004_SetPin(IO004_Handle2);
	delayms(1);
	IO004_TogglePin(IO004_Handle2);*/

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

void Tick_Handler(void) {
	ticks++;
}

void Testando_Handler(void) {

	uint32_t status;

	/*status = RD_REG(ERU001_Handle0.ERURegs->EXICON[ERU001_Handle0.InputChannel],ERU_EXICON_FL_Msk , ERU_EXICON_FL_Pos);

	 if(status)
	 {
	 IO004_ResetPin(IO004_Handle6);		// ERU event received, turn on LED
	 ERU001_ClearFlag(ERU001_Handle0);	// Clears the Status Flag
	 }*/
}
