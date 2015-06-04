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
#define PWM_LIM 70

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
//Defines dos botoes para realizar as callbacks
#define L_UM (psxDado[1] & (1<<2))
#define L_DOIS (psxDado[1] & (1<<0))
#define L_TRES (psxDado[0] & (1<<2))
#define R_UM (psxDado[1] & (1<<3))
#define R_DOIS (psxDado[1] & (1<<1))
#define R_TRES (psxDado[0] & (1<<1))
#define CROSS (psxDado[1] & (1<<6))
#define SQR (psxDado[1] & (1<<7))
#define TRIANGLE (psxDado[1] & (1<<4))
#define CIRCLE (psxDado[1] & (1<<5))
#define LEFT (psxDado[0] & (1<<7))
#define RIGHT (psxDado[0] & (1<<5))
#define UP (psxDado[0] & (1<<4))
#define DOWN (psxDado[0] & (1<<6))
#define START (psxDado[0] & (1<<3))
#define SELECT (psxDado[0] & (1<<0))



//Defines referentes a testes de locomocao
#define LINEAR 	2
#define DEGRAU 	0
#define EXP	1

/***************************************************/
/*********************INCLUDES**********************/
/***************************************************/

#include <DAVE3.h>		//Declarations from DAVE3 Code Generation (includes SFR declaration)
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
void updateButtonStates();
void flip(void);
void turbo(void);
void changeMode(char a_mode);

/***************************************************/
/*********CALLBACK PARA BOTOES DO CONTROLE**********/
/***************************************************/

void (*l_um)(void) = turbo;
void (*l_dois)(void) = NULL;
void (*l_tres)(void) = NULL;
void (*r_um)(void) = turbo;
void (*r_dois)(void) = NULL;
void (*r_tres)(void) = NULL;
void (*cross)(void) = flip;
void (*sqr)(char m) = changeMode;
void (*triangle)(char m) = changeMode;
void (*circle)(char m) = changeMode;
void (*left)(void) = NULL;
void (*right)(void) = NULL;
void (*up)(void) = NULL;
void (*down)(void) = NULL;
void (*start)(void) = NULL;
void (*select)(void) = NULL;

//Variaveis de controle do joystick
BOOLType l_um_state = 0;
BOOLType l_dois_state = 0;
BOOLType l_tres_state = 0;
BOOLType r_um_state = 0;
BOOLType r_dois_state = 0;
BOOLType r_tres_state = 0;
BOOLType cross_state = 0;
BOOLType sqr_state = 0;
BOOLType triangle_state = 0;
BOOLType circle_state = 0;
BOOLType left_state = 0;
BOOLType right_state = 0;
BOOLType up_state = 0;
BOOLType down_state = 0;
BOOLType start_state = 0;
BOOLType select_state = 0;

BOOLType l_um_state_before = 0;
BOOLType l_dois_state_before = 0;
BOOLType l_tres_state_before = 0;
BOOLType r_um_state_before = 0;
BOOLType r_dois_state_before = 0;
BOOLType r_tres_state_before = 0;
BOOLType cross_state_before = 0;
BOOLType sqr_state_before = 0;
BOOLType triangle_state_before = 0;
BOOLType circle_state_before = 0;
BOOLType left_state_before = 0;
BOOLType right_state_before = 0;
BOOLType up_state_before = 0;
BOOLType down_state_before = 0;
BOOLType start_state_before = 0;
BOOLType select_state_before = 0;

/***************************************************/
/**********DECLARACAO DE VARIAVEIS GLOBAIS**********/
/***************************************************/

int psxDado[6];
char configuration[15];
char data_R = '0';
char data_E[BYTES_TO_SEND];
uint8_t psx_status;
/*Booleanos de controle para estados do robo*/
BOOLType flipped = 0;
ADC001_ResultHandleType result;
uint8_t pwm_max;
char mode = LINEAR;

/***************************************************/
/***********************MAIN************************/
/***************************************************/

int main(void) {
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
	PORT0 ->HWSEL &= ~0x0000c000UL; //Faz pin 0.7 funcionar
	PORT0 ->HWSEL |= 0 << 14;
	DAVE_Init(); // Initialization of DAVE Apps
	//PORT0->HWSEL &= ~0x0000c000UL; //Faz pin 0.7 funcionar
	//PORT0->HWSEL |= 0 << 14;
	/*Etapa de inicializacao*/
	configure_E(); //Configura transceptor como emissor
	//IO004_SetPin(LED1); //Leds para debug
	//IO004_SetPin(LED2);
	//VER COMOFAS pra ligar analog do controle aqui ja

	psxHandShake();
	psxConfiguraControle();
	ADC001_GenerateLoadEvent(&ADC001_Handle0);
	ADC001_GetResult(&ADC001_Handle0, &result);
	/*Loop do controle*/
	while (1) {
		ADC001_GetResult(&ADC001_Handle0, &result);
		pwm_max = PWM_LIM;
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
		if (psx_status != 140) //Nao ta analogico
				{
			psxHandShake();
			psxConfiguraControle();
			continue;
		}
		/*Com dados do controle atribui valores e chama callbacks*/
		if (START && start) {
			start_state = 1;
			start();
		}
		if (SELECT && select) {
			select_state = 1;
			select();
		}
		if (L_DOIS && l_dois) {
			l_dois_state = 1;
			l_dois();
		}
		if (L_UM && l_um) {
			l_um_state = 1;
			l_um();
		}
		if (L_TRES && l_tres) {
			l_tres_state = 1;
			l_tres();
		}
		if (R_UM && r_um) {
			r_um_state = 1;
			r_um();
		}
		if (R_DOIS && r_dois) {
			r_dois_state = 1;
			r_dois();
		}
		if (R_TRES && r_tres) {
			r_tres_state = 1;
			r_tres();
		}
		if (SQR && sqr) {
			sqr_state = 1;
			sqr(DEGRAU);
//			changeMode(DEGRAU);
		}
		if (TRIANGLE && triangle) {
			triangle_state = 1;
			triangle(LINEAR);
//			changeMode(LINEAR);
		}
		if (CIRCLE && circle) {
			circle_state = 1;
			circle(EXP);
//			changeMode(EXP);
		}
		if (CROSS && cross) {
			cross_state = 1;
			cross();
		}
		if (LEFT && left) {
			left_state = 1;
			left();
		}
		if (RIGHT && right) {
			right_state = 1;
			right();
		}
		if (UP && up) {
			up_state = 1;
			up();
		}
		if (DOWN && down) {
			down_state = 1;
			down();
		}

		//

		data_E[0] = pwm_max;
		//if (psxDado[5] == 0 && psxDado[3] == 0) continue; //Enquanto for zero nao faz nada -> tirar quando ligar o analogico
		pow1 = (psxDado[5] - 127); //<<1; //Analog esq //Subtrai 127 para saber o sentido
		pow2 = (psxDado[3] - 127); //<<1;
		data_E[3] = 0;
		int16_t temp; //Variavel para armazenamento temporario dos calculos
		if (!flipped) //Robo virado, variavel atribuida pelo clique de um botao
		{
			if (pow1 < -30)
				albh2 = 0; //ok
			else if (pow1 > 30)
				blah2 = 0; //ok
			else {
				albh2 = 1;
				blah2 = 0;
			}
			if (pow2 < -30)
				albh1 = 0;
			else if (pow2 > 30)
				blah1 = 0;
			else {
				albh1 = 1;
				blah1 = 0;
			}
			temp = pow1 > 0 ? pow1 * 2 : (-pow1) * 2;
			if (temp > 255)
				temp = 255;
			data_E[1] = temp * pwm_max / 100;
			temp = pow2 > 0 ? pow2 * 2 : (-pow2) * 2;
			if (temp > 255)
				temp = 255;
			data_E[2] = temp * pwm_max / 100;
		} else {
			if (pow2 > 30)
				albh2 = 0; //ok
			else if (pow2 < -30)
				blah2 = 0; //ok
			else {
				albh2 = 1;
				blah2 = 0;
			}
			if (pow1 > 30)
				albh1 = 0;
			else if (pow1 < -30)
				blah1 = 0;
			else {
				albh1 = 1;
				blah1 = 0;
			}
			temp = pow1 > 0 ? pow1 * 2 : (-pow1) * 2;
			if (temp > 255)
				temp = 255;
			data_E[2] = temp * pwm_max / 100;
			temp = pow2 > 0 ? pow2 * 2 : (-pow2) * 2;
			if (temp > 255)
				temp = 255;
			data_E[1] = temp * pwm_max / 100;
		}
		//if (data_E[1] > 20 || data_E[2] > 20) enable = 1;

		char data_0 = (mode & 1);
		char data_1 = ((mode >> 1) & 1);

//		data_E[3] = data_E[3] | (blah1 << BLAH1) | (blah2 << BLAH2)
//				| (albh1 << ALBH1) | (albh2 << ALBH2) | (enable << ENABLE)
//				| (buzina << BUZINA);
		data_E[3] = data_E[3] | (blah1 << BLAH1) | (blah2 << BLAH2)
						| (albh1 << ALBH1) | (albh2 << ALBH2) | (data_1 << ENABLE)
						| (data_0 << BUZINA);
		data_E[4] = result.Result >> 4; //Resultado tem precisao de 12bits, divide por 16 para obter 8 bits = 1 byte

		write_E();
		updateButtonStates();
	}
	return 0;
}

/***************************************************/
/***************FUNCOES DO TRANSCEPTOR**************/
/***************************************************/

void read_R() {
	int i;
	IO004_ResetPin(CE);
	delay(50000);
	uint8_t temp = 0;

	for (i = 7; i > -1; i--) {
		if (IO004_ReadPin(DATA))
			temp |= (1 << i);
		pulse_R();
	}
	data_R = temp;
	IO004_SetPin(CE);
	delay(50000);
}

void pulse_R() {
	delay(300);
	IO004_SetPin(CLK1);
	delay(300);
	IO004_ResetPin(CLK1);
}

void configure_E() {
	/*Atribuicao de valores ao vetor de configuracao do transceptor*/
	configuration[0] = 0xC4; //RF_CH# e OP_MODE 0b11011110
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
	IO004_ResetPin(CS);
	delay(50000);
}
void write_E() {
	int i, j;
	IO004_SetPin(CE);
	delay(1000);
	for (i = 7; i > 2; i--) {
		for (j = 7; j > -1; j--) {
			if ((configuration[i] & (1 << j)) > 0)
				IO004_SetPin(DATA);
			else
				IO004_ResetPin(DATA);
			pulse_R();
		}
	}
	for (i = 0; i < BYTES_TO_SEND; i++) {
		for (j = 7; j > -1; j--) {
			if ((data_E[i] & (1 << j)) > 0)
				IO004_SetPin(DATA);
			else
				IO004_ResetPin(DATA);
			pulse_R();
		}
	} //termina de enviar dados
	IO004_ResetPin(CE);
	delay(5000);
}
/***************************************************/
/****************FUNCOES DO CONTROLE****************/
/***************************************************/
void psxConfiguraControle() {
	psxEnterConfigMode();
	psxSetAnalogMode();
	psxExitConfigMode();
}

void psxEnterConfigMode() {
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

void psxSetAnalogMode() {
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

void psxExitConfigMode() {
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

void psxLeControle() {
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

	for (psxCont = 0; psxCont < 6; psxCont++)
		psxDado[psxCont] = psxTrocaByte(0);

	IO004_SetPin(ATT);
}

void psxHandShake() {
	int psxByte = 0;

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

int psxTrocaByte(int byteDado) {
	int c;
	int aux = 0;
	for (c = 0; c <= 7; c++) {

		if (byteDado & (0x01 << c))
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

void delay(long unsigned int i) {
	while (i--) {
		__NOP();
	}
}
void printByteToInt(char a) {
	char c = a % 10 + '0';
	a /= 10;
	char d = a % 10 + '0';
	a /= 10;
	char e = a % 10 + '0';
	UART001_WriteData(UART001_Handle0, e);
	UART001_WriteData(UART001_Handle0, d);
	UART001_WriteData(UART001_Handle0, c);

}

void adc_event(void) {
	ADC001_GetResult(&ADC001_Handle0, &result);
}

/***************************************************/
/*****************FUNCOES BOTOES********************/
/***************************************************/

void updateButtonStates() {
	l_um_state_before = l_um_state;
	l_dois_state_before = l_dois_state;
	l_tres_state_before = l_tres_state;
	r_um_state_before = r_um_state;
	r_dois_state_before = r_dois_state;
	r_tres_state_before = r_tres_state;
	cross_state_before = cross_state;
	sqr_state_before = sqr_state;
	triangle_state_before = triangle_state;
	circle_state_before = circle_state;
	left_state_before = left_state;
	right_state_before = right_state;
	up_state_before = up_state;
	down_state_before = down_state;
	start_state_before = start_state;
	select_state_before = select_state;

	l_um_state = 0;
	l_dois_state = 0;
	l_tres_state = 0;
	r_um_state = 0;
	r_dois_state = 0;
	r_tres_state = 0;
	cross_state = 0;
	sqr_state = 0;
	triangle_state = 0;
	circle_state = 0;
	left_state = 0;
	right_state = 0;
	up_state = 0;
	down_state = 0;
	start_state = 0;
	select_state = 0;
}

void turbo(void) {
	pwm_max = 100;
}

void shunt(void) {
	pwm_max = 40;
}

void flip(void) {
	flipped = !flipped;
}

void changeMode(char a_mode){

	mode = a_mode;
}
