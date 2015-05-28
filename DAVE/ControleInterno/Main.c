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
 *Byte 3 : PWM 3 (Arma)
 ***************************************************/

//TODO Separar partes do codigo em arquivos diferentes
/***************************************************/
/*************DECLARACAO DAS DEFINICOES*************/
/***************************************************/

#define NULL 0
//Defines referentes aos limites
#define PWM_LIM 60

//Defines referentes ao protocolo
#define BYTES_TO_SEND 5
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

/***************************************************/
/**********DECLARACAO DE VARIAVEIS GLOBAIS**********/
/***************************************************/

char configuration[15];
char data_R[BYTES_TO_SEND];
char data_E[BYTES_TO_SEND];

/***************************************************/
/***********************MAIN************************/
/***************************************************/

int main(void)
{
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
	DAVE_Init();			// Initialization of DAVE Apps
	/*Etapa de inicializacao*/
	configure_R(); //Configura transceptor como receptor
	//IO004_SetPin(LED1); //Leds para debug
	//IO004_SetPin(LED2);

	/*Loop do codigo*/
	while(1)
	{
		if (IO004_ReadPin(DR1))
		{
			read_R();
		}
	}
	return 0;
}

/***************************************************/
/***************FUNCOES DO TRANSCEPTOR**************/
/***************************************************/

void read_R()
{
	int i, j;
	IO004_ResetPin(CE);
	delay(50000);
	uint8_t temp = 0;
	for (j = 0; j < BYTES_TO_SEND; j++)
	{
		for (i = 7; i > -1; i --)
		{
			if (IO004_ReadPin(DATA)) temp |= (1<<i);
			pulse_R();
		}
		data_R[j] = temp;
	}
	IO004_SetPin(CE);
	delay(50000);
}

void pulse_R()
{
	delay(300);
	IO004_SetPin(CLK1);
	delay(300);
	IO004_ResetPin(CLK1);
}

void configure_R()
{
	/*Atribuicao de valores ao vetor de configuracao do transceptor*/
	configuration[0] = 0xC5;//RF_CH# e OP_MODE 0b11000101
	configuration[1] = 0x4F;//RX2_EN, CM, RFDR_SB13, X0_F, RF_PWR 0b01101111
	configuration[2] = 0xA3;//addr_w
	configuration[3] = 0xEE;//Comeco enderco CH1 00000001
	configuration[4] = 0xDD;//0b00000000
	configuration[5] = 0xCC;//0b11010100
	configuration[6] = 0xBB;//0b11011111
	configuration[7] = 0xAA;//Fim enderco CH1 0b11101010
	configuration[8] = 0b00000000;//Comeco enderco CH2
	configuration[9] = 0b00000000;
	configuration[10] = 0b00000000;
	configuration[11] = 0b00000000;
	configuration[12] = 0b00000000;//Fim enderco CH2
	configuration[13] = 0x28;//num bits enviados (1 byte nesse ex) TODO arrumar
	configuration[14] = 0b00000000;

	IO004_ResetPin(CE);
	IO004_SetPin(CS);
	int i, j;
	for (i = 14; i > -1; i--)
	{
		for (j = 7; j > -1; j--)
		{
			if ((configuration[i]&(1<<j))>0) IO004_SetPin(DATA);
			else IO004_ResetPin(DATA);;
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

void delay(long unsigned int i)
{
	while(i--)
	{
		__NOP();
	}
}
