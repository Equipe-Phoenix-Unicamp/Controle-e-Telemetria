/*
 * Main.c
 *
 *  Created on: May 9, 2015
 *      Author: JM
 */

#include <DAVE3.h> //Declarations from DAVE3 Code Generation (includes SFR declaration)
/* DADO3:
 BIT 0: BLAH2
 BIT 1: BUZINA
 BIT 2: ENABLE
 BIT 3: ALBH2
 BIT 4: BLAH1
 BIT 5: ALBH1
 */

/***************************************************
 * Codigo organizado para uso no XI WINTER CHALLENGE
 *Byte 0 : LEDS (? definido no spartacus, retirar quando trocar prgrama do feather)
 *Byte 1 : PWM 1
 *Byte 2 : PWM 2
 *Byte 3 : SENTIDOS
 *Byte 4 : PWM 3 (Arma)
 ***************************************************/

//TODO Separar partes do codigo em arquivos diferentes
/***************************************************/
/*************DECLARACAO DAS DEFINICOES*************/
/***************************************************/

#define NULL 0

//Defines referentes ao protocolo
#define BYTES_TO_RECEIVE 5
//Defines referentes ao byte DADO 3
#define	BLAH2		0		//LEFT-BACK
#define	BUZINA		1		//USELESS
#define	ENABLE		2		//USELESS
#define	ALBH2		3		//LEFT-FRONT
#define	BLAH1		4		//RIGHT-BACK
#define	ALBH1		5		//RIGHT-FRONT
#define	LEFT_BACK	BLAH2
#define	LEFT_FRONT	ALBH2
#define	RIGHT_BACK	BLAH1
#define	RIGHT_FRONT	ALBH1
#define DATA_TEST0 BUZINA
#define DATA_TEST1 ENABLE

//Defines referentes ao transceptor
#define CS	 	IO004_Handle10
#define CLK1 	IO004_Handle11
#define DATA 	IO004_Handle12
#define DR1		IO004_Handle13
#define CE 		IO004_Handle14

//Defines referentes ao driver da ponte H
#define ERR_INTRPT_LEFT		IO002_Handle1
#define DIR_LEFT			IO004_Handle6
#define Enable_LEFT			IO004_Handle7
#define DvrDis_LEFT			IO004_Handle8
#define ERR_Input_LEFT		IO004_Handle15
#define PWM_LEFT			&PWMSP001_Handle1
#define ERR_INTRPT_RIGHT	IO002_Handle0
#define DIR_RIGHT			IO004_Handle0
#define Enable_RIGHT		IO004_Handle1
#define DvrDis_RIGHT		IO004_Handle2
#define ERR_Input_RIGHT		IO004_Handle3
#define PWM_RIGHT			&PWMSP001_Handle0

//Define Faiscador
#define FAISCADOR			IO004_Handle9
#define GND					IO004_Handle4

//Define referentes a ponte H
#define PWM_LIMITATION 70
#define PWM_DUTY_LIM_MAX 100
#define PWM_DUTY_LIM_MIN 8
#define PWM_DUTY_LIM_ZERO 0
#define DIR_FRONT_LEFT 0
#define DIR_REV_LEFT 1
#define DIR_FRONT_RIGHT 0
#define DIR_REV_RIGHT 1
#define PWM_MOTOR_CUT_OFF 50
#define PWM_MOTOR_RIGHT &PWMSP001_Handle0
#define PWM_MOTOR_LEFT &PWMSP001_Handle1
#define FREQ_MOTOR_LOCOMOTION 30000 //Hz
//Defines referentes ao fail safe
#define RUNNING 1
#define FAIL 0

//Defines referentes a testes de locomocao
#define LINEAR 	2
#define DEGRAU 	0
#define EXP	1

//==============================

/***************************************************/
/**************DECLARACAO DAS FUNCOES***************/
/***************************************************/

void Tick_Handler(void);
void Testando_Handler(void);
void interrupt_left(void);
void interrupt_right(void);
void delayms(uint32_t delay_ms);
void delayus(uint32_t delay_us);
void Software_Timers_Init(void);
void WakeUp(void);
void pulse_R(void);
void configure_R(void);
void read_R(void);
void update_driver_signals(void);
void delay(long unsigned int i);
void start_driver_signals(void);
float calculateDutyCicle(char mode, unsigned char data);
int floor(float value);
void error(void);

/***************************************************/
/**********DECLARACAO DE VARIAVEIS GLOBAIS**********/
/***************************************************/

char configuration[15];
unsigned char data_R[BYTES_TO_RECEIVE];
uint32_t ticks = 0UL;
uint32_t status_ticks = 0UL;
uint32_t sudden_run_ticks = 0UL;
uint32_t error_ticks = 0UL;
bool value = 0UL;
float last_duty_right = 0;
float last_duty_left = 0;
char error_left = 0;
char error_right = 0;

/***************************************************/
/***********************MAIN************************/
/***************************************************/

int main(void) {
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)

	DAVE_Init(); // Initialization of DAVE Apps

	Software_Timers_Init();
	WakeUp();
	configure_R();

	ticks = 0;
	status_ticks = 0;
	char status = RUNNING;
	start_driver_signals();

	IO004_SetPin(Enable_LEFT);

	while (1) {
		if (IO004_ReadPin(DR1)) {
			status_ticks = 0;
			read_R();
			update_driver_signals();
		} else {
			if (status_ticks > 5000) { //0.5s
				status = FAIL;
				start_driver_signals();
			}
		}
	}
	return 0;
}

void WakeUp(void) {

	//Enable
//	IO004_TogglePin(IO004_Handle1);
//	delayus(100);
//	IO004_TogglePin(IO004_Handle1);

	//DrvDis
	/*IO004_SetPin(IO004_Handle2);
	 delayms(1);
	 IO004_TogglePin(IO004_Handle2);*/

}

void start_driver_signals(void) {

	PWMSP001_Start(PWM_MOTOR_RIGHT);
	PWMSP001_SetPwmFreq(PWM_MOTOR_RIGHT, FREQ_MOTOR_LOCOMOTION);
	PWMSP001_SetDutyCycle(PWM_MOTOR_RIGHT, PWM_DUTY_LIM_ZERO);

	PWMSP001_Start(PWM_MOTOR_LEFT);
	PWMSP001_SetPwmFreq(PWM_MOTOR_LEFT, FREQ_MOTOR_LOCOMOTION);
	PWMSP001_SetDutyCycle(PWM_MOTOR_LEFT, PWM_DUTY_LIM_ZERO);

}

void update_driver_signals(void) {

	unsigned char direction = data_R[3];
	float duty_motor_left = PWM_DUTY_LIM_ZERO;
	float duty_motor_right = PWM_DUTY_LIM_ZERO;
	float direction_motor_left = 0;
	float direction_motor_right = 0;

	char mode = LINEAR;

	if (!(direction & (1 << DATA_TEST1))) {

		if (direction & (1 << DATA_TEST0))
			mode = EXP;
		else
			mode = DEGRAU;

	}

	if (direction & (1 << LEFT_FRONT)) {

		if (data_R[1] > PWM_MOTOR_CUT_OFF)
			duty_motor_left = calculateDutyCicle(mode, data_R[1]);
//			duty_motor_left = (((float) data_R[1]) / 255) * 100.0f;
		direction_motor_left = DIR_FRONT_LEFT;

	} else if (direction & (1 << LEFT_BACK)) {
		if (data_R[1] > PWM_MOTOR_CUT_OFF)
			duty_motor_left = calculateDutyCicle(mode, data_R[1]);
//			duty_motor_left = (((float) data_R[1]) / 255) * 100.0f;
		direction_motor_left = DIR_REV_LEFT;
	}

	if (direction & (1 << RIGHT_FRONT)) {

		if (data_R[2] > PWM_MOTOR_CUT_OFF)
			duty_motor_right = calculateDutyCicle(mode, data_R[2]);
//			duty_motor_right = (((float) data_R[2]) / 255) * 100.0f;
		direction_motor_right = DIR_FRONT_RIGHT;

	} else if (direction & (1 << RIGHT_BACK)) {
		if (data_R[2] > PWM_MOTOR_CUT_OFF)
			duty_motor_right = calculateDutyCicle(mode, data_R[2]);
//			duty_motor_right = (((float) data_R[2]) / 255) * 100.0f;
		direction_motor_right = DIR_REV_RIGHT;
	}

	if (direction_motor_left) {
		IO004_ResetPin(DIR_LEFT);
	} else {
		IO004_SetPin(DIR_LEFT);
	}

	if (direction_motor_right) {
		IO004_ResetPin(DIR_RIGHT);
	} else {
		IO004_SetPin(DIR_RIGHT);
	}

	PWMSP001_SetDutyCycle(PWM_MOTOR_RIGHT, duty_motor_right);

	PWMSP001_SetDutyCycle(PWM_MOTOR_LEFT, duty_motor_left);

}

float calculateDutyCicle(char mode, unsigned char data) {

	unsigned char range = 255 - PWM_MOTOR_CUT_OFF;

	unsigned char pwm_duty_limit = data_R[0];

	if (mode == LINEAR) {
		return PWM_DUTY_LIM_MIN
				+ ((100 - PWM_DUTY_LIM_MIN)
						* (((float) data) - PWM_MOTOR_CUT_OFF)) / range;

	} else if (mode == EXP) {

		//MODO GAMBS ON

//		int correctedData = ((255*pwm_duty_limit - PWM_MOTOR_CUT_OFF)*data)/(255*pwm_duty_limit) + PWM_MOTOR_CUT_OFF;
		int duty_cicle;

		float value = 100.0f * data / ((pwm_duty_limit / 100.0f) * 255.0f);

		if (value < 10) {
			duty_cicle = 0;
		} else if (value < 75) {
			duty_cicle = (value - 10) * (33 - PWM_DUTY_LIM_MIN)
					* (pwm_duty_limit / 100.0f) / (65.0f);
			if (duty_cicle < PWM_DUTY_LIM_MIN)
				duty_cicle = 0;
		} else if (value < 90) {
			duty_cicle = (value - 75) * 33 * (pwm_duty_limit / 100.0f) / (25.0f)
					+ 33 * (pwm_duty_limit / 100.0f);
		} else {
			duty_cicle = (value - 90) * 33 * (pwm_duty_limit / 100.0f) / (10.0f)
					+ 66 * (pwm_duty_limit / 100.0f);
		}

		return duty_cicle;
		//MODO GAMBS OFF

	} else { // DEGRAU

		int nDegrau = 4;
		float larguraDegrau = range / nDegrau;
		float alturaDegrau = PWM_DUTY_LIM_MAX * pwm_duty_limit
				/ (100.0f * (nDegrau - 1));

		int sinalDegrau = floor((data / larguraDegrau)) * alturaDegrau;

		return sinalDegrau;

	}

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

void interrupt_left(void) {

}

void interrupt_right(void) {

}

/***************************************************/
/***************FUNCOES DO TRANSCEPTOR**************/
/***************************************************/

void read_R() {
	int i, j;
	IO004_ResetPin(CE);
	delay(50000);
	uint8_t temp = 0;
	for (j = 0; j < BYTES_TO_RECEIVE; j++) {
		for (i = 7; i > -1; i--) {
			if (IO004_ReadPin(DATA))
				temp |= (1 << i);
			pulse_R();
		}
		data_R[j] = temp;
		temp = 0;
	}
	IO004_SetPin(CE);
	delay(50000);
}

void pulse_R() {
	delay(300);
	IO004_SetPin(CLK1);
	delay(300);
	IO004_ResetPin(CLK1);
}

void configure_R() {
	/*Atribuicao de valores ao vetor de configuracao do transceptor*/
	configuration[0] = 0xC5; //RF_CH# e OP_MODE 0b11000101
	configuration[1] = 0x4F; //RX2_EN, CM, RFDR_SB13, X0_F, RF_PWR 0b01101111
	configuration[2] = 0xA3; //addr_w
	configuration[3] = 0xEE; //Comeco enderco CH1 00000001
	configuration[4] = 0xDD; //0b00000000
	configuration[5] = 0xCC; //0b11010100
	configuration[6] = 0xBB; //0b11011111
	configuration[7] = 0xAA; //Fim enderco CH1 0b11101010
	configuration[8] = 0b00000000; //Comeco enderco CH2
	configuration[9] = 0b00000000;
	configuration[10] = 0b00000000;
	configuration[11] = 0b00000000;
	configuration[12] = 0b00000000; //Fim enderco CH2
	configuration[13] = 0x28; //num bits enviados (1 byte nesse ex) TODO arrumar
	configuration[14] = 0b00000000;

	IO004_ResetPin(CE);
	IO004_SetPin(CS);
	int i, j;
	for (i = 14; i > -1; i--) {
		for (j = 7; j > -1; j--) {
			if ((configuration[i] & (1 << j)) > 0)
				IO004_SetPin(DATA);
			else
				IO004_ResetPin(DATA);
			;
			pulse_R();
		}
	}
	IO004_DisableOutputDriver(&DATA, IO004_CONT_POLLING);
	IO004_ResetPin(CS);
	IO004_SetPin(CE);
	delay(50000);
}

/***************************************************/
/****************FUNCOES TEMPORAIS******************/
/***************************************************/

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
	//ticks++;
	status_ticks++;
	error_ticks++;
	if(error_ticks == 1)
		trata_erro();
	if (error_ticks >= 100) {
		error_ticks = 0;
		error();
	}
}

void trata_erro(void){

	if(error_left){
		error_left = 0;
		IO004_SetPin(Enable_LEFT);
	}else{
		error_right = 0;
		IO004_SetPin(Enable_RIGHT);
	}
}

void delay(long unsigned int i) {
	while (i--) {

		__NOP();
	}
}

int floor(float value) {
	int a = value;
	return a;
}

void error(void) {

	if (!IO004_ReadPin(ERR_Input_LEFT)) {
		IO004_ResetPin(Enable_LEFT);
		error_left = 1;
	}

	if (!IO004_ReadPin(ERR_Input_RIGHT)) {
		IO004_ResetPin(Enable_RIGHT);
		error_right = 1;
	}

}
