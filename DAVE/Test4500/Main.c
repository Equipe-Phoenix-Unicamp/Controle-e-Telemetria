/*
 * Main.c
 *
 *  Created on: 20/11/2014
 *      Author: Carlos
 */





#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)


/* DADO3:
BIT 0: BLAH2
BIT 1: BUZINA
BIT 2: ENABLE
BIT 3: ALBH2
BIT 4: BLAH1
BIT 5: ALBH1
*/
#define PWM_LIM 60

#define	BLAH2		0
#define	BUZINA		1
#define	ENABLE		2
#define	ALBH2		3
#define	BLAH1		4
#define	ALBH1		5

#define CS	 	IO004_Handle1
#define CLK1 	IO004_Handle2
#define DATA 	IO004_Handle4
#define DR1		IO004_Handle5
#define CE 		IO004_Handle6

#define ATT 		IO004_Handle11 //Amarelo
#define CMD			IO004_Handle12 //Laranja
#define CONT_DADO 	IO004_Handle9 //Marrom
#define CONT_CLK 	IO004_Handle10 //Azul

#define tempoInicio     300
#define tempoClk        300
#define tempoEntreByte  100

#define LED1 IO004_Handle7
#define LED2 IO004_Handle8

int psxDado[6];
char configuration[15];
char data_R = '0';
char data_E[4];

void psxLeControle();
void psxGravaByte(int byteDado);
int psxLeByte();

void delay(long unsigned int i);
void delay_R();
void configure_R();
void configure_E();
void write_E();
void read_R()
{
  int i;
  IO004_ResetPin(CE);
  delay(50000);
  uint8_t temp = 0;

  for (i = 7; i > -1; i --)
  {
    if (IO004_ReadPin(DATA)) temp |= (1<<i); //(digitalRead(DATA_R) == HIGH) temp |= (1<<i);
    delay_R();
  }
  data_R = temp;
  IO004_SetPin(CE); //digitalWrite(CE_R, HIGH);
  delay(50000);
}
void delay(long unsigned int i)
{
	while(i--)
	{
		__NOP();
	}
}
void printByteToInt(char a);
int main(void)
{
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
	configuration[0] = 0xC5;//RF_CH# e OP_MODE 0b11011110
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

	DAVE_Init();			// Initialization of DAVE Apps

	configure_E();
	IO004_SetPin(LED1);
	IO004_SetPin(LED2);
	psxLeControle();
	BOOLType flipped = 0;
	BOOLType isPressed = 0;
	BOOLType lastIsPressed = 0;
	//uint16_t pow_max = 255*PWM_LIM/100;
	while(1)
	{
		BOOLType blah2 = 1;
		BOOLType buzina = 1;
		BOOLType enable = 0;
		BOOLType albh2 = 1;
		BOOLType blah1 = 1;
		BOOLType albh1 = 1;
		int16_t pow1, pow2;
		//127
		psxLeControle();
		if (psxDado[1]&1<<3) isPressed = 1;
		else isPressed = 0;
		if (lastIsPressed == 0 && isPressed == 1) flipped = !flipped;
		data_E[0] = 173;
		if (psxDado[5] == 0 && psxDado[3] == 0) continue;
		pow1 = (psxDado[5]-127);//<<1; //Analog esq //Subtrai 127 para saber o sentido
		pow2 = (psxDado[3]-127);//<<1;
		data_E[3] = 0;
		if (!flipped)
		{
			if (pow1 < -30) albh2 = 0; //ok
			else if (pow1 > 30) blah2 = 0; //ok
			if (pow2 < -30) albh1 = 0;
			else if (pow2 > 30) blah1 = 0;
		}
		else
		{
			if (pow2 > 30) albh2 = 0; //ok
			else if (pow2 < -30) blah2 = 0; //ok
			if (pow1 > 30) albh1 = 0;
			else if (pow1 < -30) blah1 = 0;
		}
		int16_t temp;
		/*temp = pow1>0?pow1*2:(-pow1)*2;
		data_E[1] = (temp)>pow?220:temp;
		temp = pow2>0?pow2*2:(-pow2)*2;
		data_E[2] = (temp)>220?220:temp;*/
		if (!flipped)
		{
			temp = pow1>0?pow1*2:(-pow1)*2;
			data_E[1] = temp*PWM_LIM/100;
			temp = pow2>0?pow2*2:(-pow2)*2;
			data_E[2] = temp*PWM_LIM/100;
		}
		else
		{
			temp = pow1>0?pow1*2:(-pow1)*2;
			data_E[2] = temp*PWM_LIM/100;
			temp = pow2>0?pow2*2:(-pow2)*2;
			data_E[1] = temp*PWM_LIM/100;
		}
		//if (data_E[1] > 20 || data_E[2] > 20) enable = 1;
		data_E[3] = data_E[3] | (blah1 << BLAH1) | (blah2 << BLAH2) | (albh1 << ALBH1) | (albh2 << ALBH2) | (enable << ENABLE) | (buzina << BUZINA);
		write_E();
		lastIsPressed = isPressed;
		//IO004_TogglePin(LED1);
//		printByteToInt(psxDado[0]);
		//UART001_WriteData(UART001_Handle0, 'o');
		//UART001_WriteData(UART001_Handle0, 'i');
//		printByteToInt(psxDado[1]);
//		UART001_WriteData(UART001_Handle0, ' ');
//		printByteToInt(psxDado[2]);
//		UART001_WriteData(UART001_Handle0, ' ');
//		printByteToInt(psxDado[3]);
//		UART001_WriteData(UART001_Handle0, ' ');
//		printByteToInt(psxDado[4]);
//		UART001_WriteData(UART001_Handle0, ' ');
//		printByteToInt(psxDado[5]);
//		UART001_WriteData(UART001_Handle0, '\r');
//		UART001_WriteData(UART001_Handle0, '\n');
	}
	return 0;
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

void delay_R()
{
	delay(300);
	IO004_SetPin(CLK1);  //digitalWrite(CLK_R, HIGH);
	delay(300);
	IO004_ResetPin(CLK1); //digitalWrite(CLK_R, LOW);
}

void configure_E()
{
  configuration[0] &= ~1;
  IO004_ResetPin(CE);
  IO004_SetPin(CS);
  int i, j;
  for (i = 14; i > -1; i--)
  {
    for (j = 7; j > -1; j--)
    {
      if ((configuration[i]&(1<<j))>0) IO004_SetPin(DATA);
      else IO004_ResetPin(DATA);;
      delay_R();
    }
  }
  IO004_ResetPin(CS);
  delay(50000);
}
void configure_R()
{
	configuration[0] |= 1;
	IO004_ResetPin(CE);
	IO004_SetPin(CS);
	int i, j;
	for (i = 14; i > -1; i--)
	{
		for (j = 7; j > -1; j--)
			{
				if ((configuration[i]&(1<<j))>0) IO004_SetPin(DATA); //digitalWrite(DATA_R, HIGH);
				else IO004_ResetPin(DATA); //digitalWrite(DATA_R, LOW);
				delay_R();
			}
	}
	IO004_ResetPin(CS); // digitalWrite(CS_R, LOW);
	IO004_SetPin(CE); // digitalWrite(CE_R, HIGH); //Deixa pronto para ler
	delay(50000);
	IO004_DisableOutputDriver(&DATA, IO004_CONT_POLLING);
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
      //Serial.print((configuration[i]&(1<<j))>0?1:0);
      if ((configuration[i]&(1<<j))>0) IO004_SetPin(DATA);//digitalWrite(DATA_E, HIGH);
      else IO004_ResetPin(DATA);//digitalWrite(DATA_E, LOW);
      delay_R();
    }
    //Serial.println();
  }//Endereco destino enviado
  for (j = 7; j > -1; j --)
  {
    //Serial.print((data & (1<<j))>0?1:0);
    if ((data_E[0] & (1<<j))>0) IO004_SetPin(DATA);//digitalWrite(DATA_E, HIGH);
    else IO004_ResetPin(DATA);//digitalWrite(DATA_E, LOW);
    delay_R();
  }
  for (j = 7; j > -1; j --)
    {
      //Serial.print((data & (1<<j))>0?1:0);
      if ((data_E[1] & (1<<j))>0) IO004_SetPin(DATA);//digitalWrite(DATA_E, HIGH);
      else IO004_ResetPin(DATA);//digitalWrite(DATA_E, LOW);
      delay_R();
    }
  for (j = 7; j > -1; j --)
    {
      //Serial.print((data & (1<<j))>0?1:0);
      if ((data_E[2] & (1<<j))>0) IO004_SetPin(DATA);//digitalWrite(DATA_E, HIGH);
      else IO004_ResetPin(DATA);//digitalWrite(DATA_E, LOW);
      delay_R();
    }//termina de enviar dados
  for (j = 7; j > -1; j --)
    {
      //Serial.print((data & (1<<j))>0?1:0);
      if ((data_E[3] & (1<<j))>0) IO004_SetPin(DATA);//digitalWrite(DATA_E, HIGH);
      else IO004_ResetPin(DATA);//digitalWrite(DATA_E, LOW);
      delay_R();
    }
  //Serial.println();
  //digitalWrite(CE_E, LOW);
  IO004_ResetPin(CE);
  delay(5000);//delayMicroseconds(250);
}
void psxLeControle()
{
	int psxByte = 0;
	int psxCont;

	IO004_SetPin(CMD);
	IO004_SetPin(CONT_CLK);
	IO004_ResetPin(ATT);
	//digitalWrite(cmd,HIGH);
	//digitalWrite(clk,HIGH);
	//digitalWrite(att,LOW);
	delay(tempoInicio);
	//delayMicroseconds(tempoInicio);

	psxByte = 1;
	psxGravaByte(psxByte);

	psxByte = 66;
	psxGravaByte(psxByte);

	psxByte = 0;
	psxGravaByte(psxByte);

	for (psxCont = 0; psxCont<6; psxCont++)
		psxDado[psxCont] = psxLeByte();

	IO004_SetPin(ATT);
	//digitalWrite(att,HIGH);
}

void psxGravaByte(int byteDado)
{
	int c;
	for (c=0;c<=7;c++)
	{
		if(byteDado & (0x01<<c))
			IO004_SetPin(CMD);
		  //digitalWrite(cmd,HIGH);
		else
			IO004_ResetPin(CMD);
		  //digitalWrite(cmd,LOW);
		IO004_ResetPin(CONT_CLK);
		//digitalWrite(clk,LOW);
		delay(tempoClk);
		//delayMicroseconds(tempoClk);
		IO004_SetPin(CONT_CLK);
		//digitalWrite(clk,HIGH);
		delay(tempoClk);
		//delayMicroseconds(tempoClk);
	}
	IO004_SetPin(CMD);
  //digitalWrite(cmd,HIGH);
	delay(tempoEntreByte);
  //delayMicroseconds(tempoEntreByte);
}

int psxLeByte()
{
	int aux = 0;
	int c;

	for (c=0;c<=7;c++)
	{
		IO004_ResetPin(CONT_CLK);
    //digitalWrite(clk,LOW);
		delay(tempoClk);
    //delayMicroseconds(tempoClk);
    //Serial.println(analogRead(dado));
		if (IO004_ReadPin(CONT_DADO))
	  	//if(analogRead(dado) > 400)
	  		  ;//aux = aux&(!c);
      //bitClear(aux,c);
	  	else
	  		  aux = aux | (1 << c);
	  //bitSet(aux,c);
	  	IO004_SetPin(CONT_CLK);
    //digitalWrite(clk,HIGH);
	  	delay(tempoClk);
    //delayMicroseconds(tempoClk);
	}
	delay(tempoEntreByte);
  //delayMicroseconds(tempoEntreByte);
	return (aux);
}
