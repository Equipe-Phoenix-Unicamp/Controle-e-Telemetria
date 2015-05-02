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

/***************************************************
 * Codigo organizado para uso no XI WINTER CHALLENGE
 * ----Protocolo de comunicacao: todo
 *
 *
 ***************************************************/


/***************************************************/
/*************DECLARACAO DAS DEFINICOES*************/
/***************************************************/

#define NULL 0
//Defines referentes aos limites
#define PWM_LIM 60

//Defines referentes ao protocolo
#define BYTES_TO_SEND 4
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
//Defines referentes ao controle
#define ATT 		IO004_Handle11 //Amarelo
#define CMD			IO004_Handle12 //Laranja
#define CONT_DADO 	IO004_Handle9 //Marrom
#define CONT_CLK 	IO004_Handle10 //Azul
//Defines referentes aos delays do controle
#define tempoInicio     300
#define tempoClk        300
#define tempoEntreByte  100
//Defines referentes aos LEDS da Relax kit (debug only)
#define LED1 IO004_Handle7
#define LED2 IO004_Handle8

/***************************************************/
/**************DECLARACAO DAS FUNCOES***************/
/***************************************************/

void psxLeControle();
int psxTrocaByte(int byteDado);
int psxLeByte();
void delay(long unsigned int i);
void pulse_R();
void configure_R();
void configure_E();
void write_E();
void read_R();
void delay(long unsigned int i);
void printByteToInt(char a);
void psxConfiguraControle();
void psxEnterConfigMode();
void psxExitConfigMode();
void psxSetAnalogMode();
void psxHandShake();

/***************************************************/
/*********CALLBACK PARA BOTOES DO CONTROLE**********/
/***************************************************/

void * l1 = NULL;
void * l2 = NULL;
void * r1 = NULL;
void * r2 = NULL;
void * cross = NULL;
void * sqr = NULL;
void * triangle = NULL;
void * circle = NULL;
void * left = NULL;
void * right = NULL;
void * up = NULL;
void * down = NULL;
void * start = NULL;
void * select = NULL;

/***************************************************/
/*********************INCLUDES**********************/
/***************************************************/

#include <DAVE3.h>		//Declarations from DAVE3 Code Generation (includes SFR declaration)

/***************************************************/
/**********DECLARACAO DE VARIAVEIS GLOBAIS**********/
/***************************************************/

int psxDado[6];
char configuration[15];
char data_R = '0';
char data_E[BYTES_TO_SEND];
uint8_t psx_status;

/***************************************************/
/***********************MAIN************************/
/***************************************************/

int main(void)
{
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
	DAVE_Init();			// Initialization of DAVE Apps
	/*Etapa de inicializacao*/
	configure_E(); //Configura transceptor como emissor
	IO004_SetPin(LED1); //Leds para debug
	IO004_SetPin(LED2);
	//VER COMOFAS pra ligar analog do controle aqui ja
	psxHandShake();
	psxConfiguraControle();
	/*Booleanos de controle para estados do robo*/
	BOOLType flipped = 0;
	BOOLType isPressed = 0;
	BOOLType lastIsPressed = 0;
	/*Loop do controle*/
	while(1)
	{
		/*Inicializa o que sera mandado*/
		BOOLType blah2 = 1;
		BOOLType buzina = 1;
		BOOLType enable = 0;
		BOOLType albh2 = 1;
		BOOLType blah1 = 1;
		BOOLType albh1 = 1;
		int16_t pow1, pow2;
		/*Le controle*/
		psxLeControle();
		/*Com dados do controle atribui valores e chama callbacks*/
		if (psxDado[1]&1<<3) isPressed = 1;
		else isPressed = 0;
		if (lastIsPressed == 0 && isPressed == 1) flipped = !flipped;
		data_E[0] = 173;
		if (psxDado[5] == 0 && psxDado[3] == 0) continue; //Enquanto for zero nao faz nada -> tirar quando ligar o analogico
		pow1 = (psxDado[5]-127);//<<1; //Analog esq //Subtrai 127 para saber o sentido
		pow2 = (psxDado[3]-127);//<<1;
		data_E[3] = 0;
		int16_t temp; //Variavel para armazenamento temporario dos calculos
		if (!flipped) //Robo virado, variavel atribuida pelo clique de um botao
		{
			if (pow1 < -30) albh2 = 0; //ok
			else if (pow1 > 30) blah2 = 0; //ok
			if (pow2 < -30) albh1 = 0;
			else if (pow2 > 30) blah1 = 0;
			temp = pow1>0?pow1*2:(-pow1)*2;
			data_E[1] = temp*PWM_LIM/100;
			temp = pow2>0?pow2*2:(-pow2)*2;
			data_E[2] = temp*PWM_LIM/100;
		}
		else
		{
			if (pow2 > 30) albh2 = 0; //ok
			else if (pow2 < -30) blah2 = 0; //ok
			if (pow1 > 30) albh1 = 0;
			else if (pow1 < -30) blah1 = 0;
			temp = pow1>0?pow1*2:(-pow1)*2;
			data_E[2] = temp*PWM_LIM/100;
			temp = pow2>0?pow2*2:(-pow2)*2;
			data_E[1] = temp*PWM_LIM/100;
		}
		//if (data_E[1] > 20 || data_E[2] > 20) enable = 1;
		data_E[3] = data_E[3] | (blah1 << BLAH1) | (blah2 << BLAH2) | (albh1 << ALBH1) | (albh2 << ALBH2) | (enable << ENABLE) | (buzina << BUZINA);
		write_E();
		lastIsPressed = isPressed;
	}
	return 0;
}

/***************************************************/
/***************FUNCOES DO TRANSCEPTOR**************/
/***************************************************/

void read_R()
{
	int i;
	IO004_ResetPin(CE);
	delay(50000);
	uint8_t temp = 0;

	for (i = 7; i > -1; i --)
	{
		if (IO004_ReadPin(DATA)) temp |= (1<<i);
		pulse_R();
	}
	data_R = temp;
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

void configure_E()
{
	/*Atribuicao de valores ao vetor de configuracao do transceptor*/
	configuration[0] = 0xC4;//RF_CH# e OP_MODE 0b11011110
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
	configuration[13] = 0x20;//num bits enviados (1 byte nesse ex)
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
	IO004_ResetPin(CS);
	delay(50000);
}
void write_E()
{
	int i, j;
	IO004_SetPin(CE);
	delay(1000);
	for (i = 7; i > 2 ; i --)
	{
		for (j = 7; j > -1; j --)
		{
			if ((configuration[i]&(1<<j))>0) IO004_SetPin(DATA);
			else IO004_ResetPin(DATA);
			pulse_R();
		}
	}
	for (i = 0; i < BYTES_TO_SEND; i++)
	{
		for (j = 7; j > -1; j --)
		{
			if ((data_E[i] & (1<<j))>0) IO004_SetPin(DATA);
			else IO004_ResetPin(DATA);
			pulse_R();
		}
	}//termina de enviar dados
	IO004_ResetPin(CE);
	delay(5000);
}
/***************************************************/
/****************FUNCOES DO CONTROLE****************/
/***************************************************/
void psxConfiguraControle()
{
	psxEnterConfigMode();
	psxSetAnalogMode();
	psxExitConfigMode();
}

void psxEnterConfigMode()
{
	int psxByte = 0;
	IO004_SetPin(CMD);
	IO004_SetPin(CONT_CLK);
	IO004_ResetPin(ATT);
	delay(tempoInicio);

	psxByte = 1;
	psxTrocaByte(psxByte);

	psxByte = 0x43;
	psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	psxByte = 0x1;
	psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	IO004_SetPin(ATT);
}

void psxSetAnalogMode()
{
	int psxByte = 0;
	IO004_SetPin(CMD);
	IO004_SetPin(CONT_CLK);
	IO004_ResetPin(ATT);
	delay(tempoInicio);

	psxByte = 1;
	psxTrocaByte(psxByte);

	psxByte = 0x44;
	psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	psxByte = 0x1;
	psxTrocaByte(psxByte);

	psxByte = 0x3;
	psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	IO004_SetPin(ATT);
}

void psxExitConfigMode()
{
	int psxByte = 0;
	IO004_SetPin(CMD);
	IO004_SetPin(CONT_CLK);
	IO004_ResetPin(ATT);
	delay(tempoInicio);

	psxByte = 1;
	psxTrocaByte(psxByte);

	psxByte = 0x43;
	psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	psxByte = 0x5A;
	psxTrocaByte(psxByte);

	psxByte = 0x5A;
	psxTrocaByte(psxByte);

	psxByte = 0x5A;
	psxTrocaByte(psxByte);

	psxByte = 0x5A;
	psxTrocaByte(psxByte);

	psxByte = 0x5A;
	psxTrocaByte(psxByte);

	IO004_SetPin(ATT);
}

void psxLeControle()
{
	int psxByte = 0;
	int psxCont;

	IO004_SetPin(CMD);
	IO004_SetPin(CONT_CLK);
	IO004_ResetPin(ATT);
	delay(tempoInicio);

	psxByte = 1;
	psxTrocaByte(psxByte);

	psxByte = 0x42;
	psx_status = psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	for (psxCont = 0; psxCont<6; psxCont++)
		psxDado[psxCont] = psxTrocaByte(0);

	IO004_SetPin(ATT);
}

void psxHandShake()
{
	int psxByte = 0;
	int psxCont;

	IO004_SetPin(CMD);
	IO004_SetPin(CONT_CLK);
	IO004_ResetPin(ATT);
	delay(tempoInicio);

	psxByte = 1;
	psxTrocaByte(psxByte);

	psxByte = 0x42;
	psx_status = psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	psxByte = 0;
	psxTrocaByte(psxByte);

	IO004_SetPin(ATT);
}

int psxTrocaByte(int byteDado)
{
	int c;
	int aux = 0;
	for (c=0;c<=7;c++)
	{
		if(byteDado & (0x01<<c))
			IO004_SetPin(CMD);
		else
			IO004_ResetPin(CMD);
		IO004_ResetPin(CONT_CLK);
		delay(tempoClk);
		if (!IO004_ReadPin(CONT_DADO))
			aux = aux | (1 << c);
		IO004_SetPin(CONT_CLK);
		delay(tempoClk);
	}
	IO004_SetPin(CMD);
	delay(tempoEntreByte);
	return aux;
}
//void psxLeControle()
//{
//	int psxByte = 0;
//	int psxCont;
//
//	IO004_SetPin(CMD);
//	IO004_SetPin(CONT_CLK);
//	IO004_ResetPin(ATT);
//	delay(tempoInicio);
//
//	psxByte = 1;
//	psxGravaByte(psxByte);
//
//	psxByte = 66;
//	psxGravaByte(psxByte);
//
//	psxByte = 0;
//	psxGravaByte(psxByte);
//
//	for (psxCont = 0; psxCont<6; psxCont++)
//		psxDado[psxCont] = psxLeByte();
//
//	IO004_SetPin(ATT);
//}
//void psxGravaByte(int byteDado, int byteLido)
//{
//	int c;
//	for (c=0;c<=7;c++)
//	{
//		if(byteDado & (0x01<<c))
//			IO004_SetPin(CMD);
//		else
//			IO004_ResetPin(CMD);
//		IO004_ResetPin(CONT_CLK);
//		delay(tempoClk);
//		IO004_SetPin(CONT_CLK);
//		delay(tempoClk);
//	}
//	IO004_SetPin(CMD);
//	delay(tempoEntreByte);
//}
//int psxLeByte()
//{
//	int aux = 0;
//	int c;
//
//	for (c=0;c<=7;c++)
//	{
//		IO004_ResetPin(CONT_CLK);
//		delay(tempoClk);
//		if (!IO004_ReadPin(CONT_DADO))
//	  		  aux = aux | (1 << c);
//	  	IO004_SetPin(CONT_CLK);
//	  	delay(tempoClk);
//	}
//	delay(tempoEntreByte);
//	return (aux);
//}

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
void printByteToInt(char a)
{
	char c = a%10 + '0';
	a /=10;
	char d = a%10 + '0';
	a /=10;
	char e = a%10 + '0';
	UART001_WriteData(UART001_Handle0, e);
	UART001_WriteData(UART001_Handle0, d);
	UART001_WriteData(UART001_Handle0, c);

}

