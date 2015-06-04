/*
 * Main.c
 *
 *  Created on: 20/11/2014
 *      Author: Carlos
 */

/* DADO3:
 BIT 0: BLAH2
 BIT 1: BUZINA
 BIT 2: ENABLE
 BIT 3: ALBH2
 BIT 4: BLAH1
 BIT 5: ALBH1
 */

/*
 * Potenciometro(costas)
 * |	|
 * Gnd	Sig
 *
 *
 *
 *
 *
 * |
 * Vcc
 * */

/***************************************************
 * Codigo organizado para uso no XI WINTER CHALLENGE
 *Byte 0 : LEDS (? definido no spartacus, retirar quando trocar prgrama do feather)
 *Byte 1 : PWM 1
 *Byte 2 : PWM 2
 *Byte 3 : SENTIDOS
 *Byte 4 : PWM 3 (Arma)
 ***************************************************/


#include <DAVE3.h>

//TODO Separar partes do codigo em arquivos diferentes
/***************************************************/
/*************DECLARACAO DAS DEFINICOES*************/
/***************************************************/

#define NULL 0
#define _TRUE 1
#define _FALSE 0
//Defines referentes aos limites
#define PWM_LIM 60

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

//Defines referentes ao transceptor
#define CS	 	IO004_Handle1
#define CLK1 	IO004_Handle2
#define DATA 	IO004_Handle4
#define DR1		IO004_Handle5
#define CE 		IO004_Handle6

// Defines referentes aos sinais PWM para os ESCs
#define PWM_MOTOR_RIGHT &PWMSP001_Handle0
#define FREQ_MOTOR_LOCOMOTION 60 //Hz
#define PER_MOTOR_LOCOMOTION (1.0f/FREQ_MOTOR_LOCOMOTION) //s
#define MAX_PER_MOTOR_LOCOMOTION 0.002f //s
#define MIN_PER_MOTOR_LOCOMOTION 0.001f //s
#define ZERO_PER_MOTOR_LOCOMOTION 0.0015f //s
#define FREQ_MOTOR_WEAPON 60 //Hz
#define PER_MOTOR_WEAPON (1.0f/FREQ_MOTOR_WEAPON) //s
#define MAX_PER_MOTOR_WEAPON 0.002f //s
#define MIN_PER_MOTOR_WEAPON 0.001f //s
#define ZERO_PER_MOTOR_WEAPON 0.001f //s
#define PWM_MOTOR_LEFT &PWMSP001_Handle1
#define PWM_MOTOR_WEAPON &PWMSP001_Handle2
#define PWM_MOTOR_CUT_OFF 20

//Defines referentes ao fail safe
#define RUNNING 1
#define FAIL 0
#define TICK_FAIL_SAFE 5000 //0.5s
//defines referentes ao controle de direcao locomocao
#define DIR_NULL 2
#define DIR_FRONT 1
#define DIR_BACK 0
#define TICK_BREAK_PWM 50000 //150ms
#define TICK_ZERO_PWM 50000 //500ms
#define STATUS_BREAK 0
#define STATUS_ZERO 1
#define STATUS_NORMAL 2
//==============================

/***************************************************/
/**************DECLARACAO DAS FUNCOES***************/
/***************************************************/

void delay(long unsigned int i);
void pulse_R();
void configure_R();
void read_R();
void delay(long unsigned int i);
void updateButtonStates();
void start_PWM_signals(void);
void start_PWM_signals_test(void);
void update_PWM_signals(void);
void update_PWM_signals_test(float per_teste);
void Tick_Handler(void);
void delayms(uint32_t delay_ms);
void delayus(uint32_t delay_us);
void Software_Timers_Init();

/***************************************************/
/**********DECLARACAO DE VARIAVEIS GLOBAIS**********/
/***************************************************/

char configuration[15];
unsigned char data_R[BYTES_TO_RECEIVE];
int status_ticks;
uint32_t ticks = 0UL;
int block_pwm_update_tick_left;
int block_pwm_update_tick_right;
unsigned char last_direction_right = DIR_NULL;
unsigned char last_direction_left = DIR_NULL;
unsigned char block_left = 0;
unsigned char block_right = 0;
unsigned char status_block_left = STATUS_NORMAL;
unsigned char status_block_right = STATUS_NORMAL;

/***************************************************/
/***********************MAIN************************/
/***************************************************/

int main(void) {
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
	DAVE_Init(); // Initialization of DAVE Apps
	/*Etapa de inicializacao*/
	configure_R(); //Configura transceptor como receptor
	//IO004_SetPin(LED1); //Leds para debug
	//IO004_SetPin(LED2);

	start_PWM_signals();
//	start_PWM_signals_test();

	float per_teste = MIN_PER_MOTOR_LOCOMOTION;
	char status = RUNNING;
	status_ticks = 0;
	ticks = 0;
	block_pwm_update_tick_left = 0;
	block_pwm_update_tick_right = 0;
	Software_Timers_Init();

	/*Loop do codigo*/
	while (1) {
		if (IO004_ReadPin(DR1)) {
			status_ticks = 0;
			read_R();
			update_PWM_signals();
		} else {
			if (status_ticks > TICK_FAIL_SAFE) { //0.5s
				status = FAIL;
				start_PWM_signals();
			}
		}

//		PWMSP001_SetDutyCycle(PWM_MOTOR_RIGHT,
//				100.0f * 0.0016f / PER_MOTOR_LOCOMOTION);
//
//		PWMSP001_SetDutyCycle(PWM_MOTOR_LEFT,
//				100.0f * 0.0016f / PER_MOTOR_LOCOMOTION);
//
//		int teste = 30000;
//		while (teste--)
//			delay(1000000);
//
//		PWMSP001_SetDutyCycle(PWM_MOTOR_RIGHT,
//				100.0f * 0.0014f / PER_MOTOR_LOCOMOTION);
//
//		PWMSP001_SetDutyCycle(PWM_MOTOR_LEFT,
//				100.0f * 0.0014f / PER_MOTOR_LOCOMOTION);
//
//		teste = 30000;
//		while (teste--)
//			delay(1000000);

//		if (IO004_ReadPin(IO004_Handle7) == 0) {
//					while (IO004_ReadPin(IO004_Handle7) == 0)
//						;
//
//					if(per_teste >= MAX_PER_MOTOR_LOCOMOTION)
//						status = 1;
//
//					if(per_teste <= MIN_PER_MOTOR_LOCOMOTION)
//						status = 0;
//
//					if(status)
//						per_teste -= 0.00005;
//					else
//						per_teste += 0.00005;
//
//					update_PWM_signals_test( per_teste);
//		}
	}
	return 0;
}

//void start_PWM_signals_test(void) {
//
//	PWMSP001_Start(PWM_MOTOR_RIGHT);
//	PWMSP001_SetPwmFreq(PWM_MOTOR_RIGHT, FREQ_MOTOR_LOCOMOTION);
//	PWMSP001_SetDutyCycle(PWM_MOTOR_RIGHT,
//			100.0f * ZERO_PER_MOTOR_LOCOMOTION / PER_MOTOR_LOCOMOTION);
//
//	PWMSP001_Start(PWM_MOTOR_LEFT);
//	PWMSP001_SetPwmFreq(PWM_MOTOR_LEFT, FREQ_MOTOR_LOCOMOTION);
//	PWMSP001_SetDutyCycle(PWM_MOTOR_LEFT,
//			100.0f * ZERO_PER_MOTOR_LOCOMOTION / PER_MOTOR_LOCOMOTION);
//
//}
//void update_PWM_signals_test(float per_teste) {
//
//	PWMSP001_SetDutyCycle(PWM_MOTOR_RIGHT,
//			100.0f * per_teste / PER_MOTOR_LOCOMOTION);
//
//	PWMSP001_SetDutyCycle(PWM_MOTOR_LEFT,
//			100.0f * per_teste / PER_MOTOR_LOCOMOTION);
//}

/***************************************************/
/**********INICIALIZA OS SINAIS DE PWM COM *********/
/****PERIODOS CORRETOS E CICLOS PARA MOTOR PARADO***/
/***************************************************/

void start_PWM_signals(void) {

//	TODO: Pinos dos motores

	PWMSP001_Start(PWM_MOTOR_RIGHT);
	PWMSP001_SetPwmFreq(PWM_MOTOR_RIGHT, FREQ_MOTOR_LOCOMOTION);
	PWMSP001_SetDutyCycle(PWM_MOTOR_RIGHT,
			100.0f * ZERO_PER_MOTOR_LOCOMOTION / PER_MOTOR_LOCOMOTION);

	PWMSP001_Start(PWM_MOTOR_LEFT);
	PWMSP001_SetPwmFreq(PWM_MOTOR_LEFT, FREQ_MOTOR_LOCOMOTION);
	PWMSP001_SetDutyCycle(PWM_MOTOR_LEFT,
			100.0f * ZERO_PER_MOTOR_LOCOMOTION / PER_MOTOR_LOCOMOTION);

	PWMSP001_Start(PWM_MOTOR_WEAPON);
	PWMSP001_SetPwmFreq(PWM_MOTOR_WEAPON, FREQ_MOTOR_WEAPON);
	PWMSP001_SetDutyCycle(PWM_MOTOR_WEAPON,
			100.0f * ZERO_PER_MOTOR_WEAPON / PER_MOTOR_WEAPON);

}

void update_PWM_signals(void) {

//	TODO: Verificar valor de data_R co direita e esquerda

	//Esquerda data[1]
	//Direita data[2]

	float per_motor_right = ZERO_PER_MOTOR_LOCOMOTION;
	float per_motor_left = ZERO_PER_MOTOR_LOCOMOTION;
	unsigned char direction = data_R[3];
	float per_weapon = (data_R[4])
			* (MAX_PER_MOTOR_WEAPON - MIN_PER_MOTOR_WEAPON)
			/ 255+ MIN_PER_MOTOR_WEAPON;

	if (((direction & (1 << LEFT_FRONT)) && last_direction_left == DIR_BACK)
			|| ((direction & (1 << LEFT_BACK))
					&& last_direction_left == DIR_FRONT)) {
		if (!block_left) {
			block_left = _TRUE;
			block_pwm_update_tick_left = TICK_BREAK_PWM;
			per_motor_left = MIN_PER_MOTOR_LOCOMOTION;
			status_block_left = STATUS_BREAK;
		} else {
			block_left = _FALSE;
			status_block_left = STATUS_NORMAL;
		}

	}

	if (((direction & (1 << RIGHT_FRONT)) && last_direction_right == DIR_BACK)
			|| ((direction & (1 << RIGHT_BACK))
					&& last_direction_right == DIR_FRONT)) {
		if (!block_right) {
			block_right = _TRUE;
			block_pwm_update_tick_right = TICK_BREAK_PWM;
			status_block_right = STATUS_BREAK;
			per_motor_right = MIN_PER_MOTOR_LOCOMOTION;
		} else {
			block_right = _FALSE;
			status_block_right = STATUS_NORMAL;
		}
	}

	if (!block_left) {
		//caso normal
		if (direction & (1 << LEFT_FRONT)) {

			if (data_R[1] > PWM_MOTOR_CUT_OFF)
				per_motor_left =
						(((float) data_R[1]) / 255)
								* (MAX_PER_MOTOR_LOCOMOTION
										- ZERO_PER_MOTOR_LOCOMOTION)+ ZERO_PER_MOTOR_LOCOMOTION;

			last_direction_left = DIR_FRONT;
		} else if (direction & (1 << LEFT_BACK)) {
			if (data_R[1] > PWM_MOTOR_CUT_OFF)
				per_motor_left =
						(((float) data_R[1]) / 255)
								* (ZERO_PER_MOTOR_LOCOMOTION
										- MIN_PER_MOTOR_LOCOMOTION)+ MIN_PER_MOTOR_LOCOMOTION;
			last_direction_left = DIR_BACK;
		}
	} else {

		if (direction & (1 << LEFT_FRONT)) {
			last_direction_left = DIR_FRONT;
		}else{
			last_direction_left = DIR_BACK;
		}

		if (block_pwm_update_tick_left <= 0 && status_block_left == STATUS_BREAK) {
			block_pwm_update_tick_left = TICK_ZERO_PWM;
			status_block_left = STATUS_ZERO;
		} else if (block_pwm_update_tick_left
				<= 0&& status_block_left == STATUS_ZERO) {
			status_block_left = STATUS_NORMAL;
			block_left = _FALSE;
		}
	}

	if (!block_right) {
		//caso normal
		if (direction & (1 << RIGHT_FRONT)) {

			if (data_R[2] > PWM_MOTOR_CUT_OFF)
				per_motor_right =
						(((float) data_R[2]) / 255)
								* (MAX_PER_MOTOR_LOCOMOTION
										- ZERO_PER_MOTOR_LOCOMOTION)+ ZERO_PER_MOTOR_LOCOMOTION;

			last_direction_right = DIR_FRONT;
		} else if (direction & (1 << RIGHT_BACK)) {
			if (data_R[2] > PWM_MOTOR_CUT_OFF)
				per_motor_right =
						(((float) data_R[2]) / 255)
								* (ZERO_PER_MOTOR_LOCOMOTION
										- MIN_PER_MOTOR_LOCOMOTION)+ MIN_PER_MOTOR_LOCOMOTION;
			last_direction_right = DIR_BACK;
		}
	} else {

		if (block_pwm_update_tick_right
				<= 0&& status_block_right == STATUS_BREAK) {
			block_pwm_update_tick_right = TICK_ZERO_PWM;
			status_block_right = STATUS_ZERO;
		} else if (block_pwm_update_tick_right
				<= 0&& status_block_right == STATUS_ZERO) {
			status_block_right = STATUS_NORMAL;
			block_right = _FALSE;
		}
	}

	PWMSP001_SetDutyCycle(PWM_MOTOR_RIGHT,
			100.0f *(0.003f - per_motor_right) / PER_MOTOR_LOCOMOTION);

	PWMSP001_SetDutyCycle(PWM_MOTOR_LEFT,
			100.0f * per_motor_left / PER_MOTOR_LOCOMOTION);

	PWMSP001_SetDutyCycle(PWM_MOTOR_WEAPON,
			100.0f * per_weapon / PER_MOTOR_WEAPON);

//	float per_teste = (data_R[4])
//				* (MAX_PER_MOTOR_LOCOMOTION - MIN_PER_MOTOR_LOCOMOTION)
//				/ 255+ MIN_PER_MOTOR_LOCOMOTION;
//
//	PWMSP001_Start(PWM_MOTOR_RIGHT);
//		PWMSP001_SetPwmFreq(PWM_MOTOR_RIGHT, FREQ_MOTOR_LOCOMOTION);
//		PWMSP001_SetDutyCycle(PWM_MOTOR_RIGHT,
//				100.0f * per_teste / PER_MOTOR_LOCOMOTION);
//
//		PWMSP001_Start(PWM_MOTOR_LEFT);
//			PWMSP001_SetPwmFreq(PWM_MOTOR_LEFT, FREQ_MOTOR_LOCOMOTION);
//			PWMSP001_SetDutyCycle(PWM_MOTOR_LEFT,
//					100.0f * per_teste / PER_MOTOR_LOCOMOTION);

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
	ticks++;
	status_ticks++;
	block_pwm_update_tick_left--;
	block_pwm_update_tick_right--;
}

void delay(long unsigned int i) {
	while (i--) {

		__NOP();
	}
}
