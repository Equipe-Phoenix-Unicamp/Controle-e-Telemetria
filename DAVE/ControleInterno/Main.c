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

//TODO Separar partes do codigo em arquivos diferentes
/***************************************************/
/*************DECLARACAO DAS DEFINICOES*************/
/***************************************************/

#define NULL 0
//Defines referentes aos limites
#define PWM_LIM 60

//Defines referentes ao protocolo
#define BYTES_TO_RECEIVE 5
//Defines referentes ao byte DADO 3
#define	BLAH2		0
#define	BUZINA		1
#define	ENABLE		2
#define	ALBH2		3
#define	BLAH1		4
#define	ALBH1		5
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
#define ZERO_PER_MOTOR_LOCOMOTION 0.0016f //s
#define FREQ_MOTOR_WEAPON 60 //Hz
#define PER_MOTOR_WEAPON (1.0f/FREQ_MOTOR_WEAPON) //s
#define MAX_PER_MOTOR_WEAPON 0.002f //s
#define MIN_PER_MOTOR_WEAPON 0.001f //s
#define ZERO_PER_MOTOR_WEAPON 0.001f //s
#define PWM_MOTOR_LEFT &PWMSP001_Handle1
#define PWM_MOTOR_WEAPON &PWMSP001_Handle2
//==============================

#include <DAVE3.h>		//Declarations from DAVE3 Code Generation (includes SFR declaration)
//#include

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
void update_PWM_signals(void);

/***************************************************/
/**********DECLARACAO DE VARIAVEIS GLOBAIS**********/
/***************************************************/

char configuration[15];
char data_R[BYTES_TO_RECEIVE];

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

	/*Loop do codigo*/
	while (1) {
		if (IO004_ReadPin(DR1)) {
			read_R();
			update_PWM_signals();
		}
	}
	return 0;
}

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

	float per_motor_right = (data_R[1])*(MAX_PER_MOTOR_LOCOMOTION - MIN_PER_MOTOR_LOCOMOTION)/255  + MIN_PER_MOTOR_LOCOMOTION;
	PWMSP001_SetDutyCycle(PWM_MOTOR_RIGHT,
			100.0f * per_motor_right / PER_MOTOR_LOCOMOTION);
	float per_motor_left = (data_R[2])*(MAX_PER_MOTOR_LOCOMOTION - MIN_PER_MOTOR_LOCOMOTION)/255  + MIN_PER_MOTOR_LOCOMOTION;
	PWMSP001_SetDutyCycle(PWM_MOTOR_LEFT,
			100.0f * per_motor_left / PER_MOTOR_LOCOMOTION);
	float per_weapon = (data_R[4])*(MAX_PER_MOTOR_WEAPON - MIN_PER_MOTOR_WEAPON)/255  + MIN_PER_MOTOR_WEAPON;
	PWMSP001_SetDutyCycle(PWM_MOTOR_WEAPON, 100.0f * per_weapon / PER_MOTOR_WEAPON);

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
/*****************FUNCOES GERAIS********************/
/***************************************************/

void delay(long unsigned int i) {
	while (i--) {
		__NOP();
	}
}
