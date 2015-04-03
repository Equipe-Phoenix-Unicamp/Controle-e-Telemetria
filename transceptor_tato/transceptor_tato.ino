/*********************************************************************************
Codigo para arduino criado para testes envolvendo o transceptor da Tato.
Referencia: http://www.tato.ind.br/produto/Transceptor-2.4GHz.html

IMPORTANTE: alimentação 3.3v, e o codigo exemplo do site precisa de modificacoes
para funcionar no atmega328.
*********************************************************************************/

int CS_R = 8;
int CLK_R = 9;
int DATA_R = 10;
int DR_R = 11;
int CE_R = 12;

int CS_E = 7;
int CLK_E = 6;
int DATA_E = 5;
int CE_E = 4;

char configuration[15];

char data = 0;
char data_R[4];
void setup() {
  Serial.begin(9600);
  configuration[0] = 0xC5;//RF_CH# e OP_MODE
  configuration[1] = 0x4F;//RX2_EN, CM, RFDR_SB13, X0_F, RF_PWR
  configuration[2] = 0xA3;//addr_w
  configuration[3] = 0xEE;//Comeco enderco CH1
  configuration[4] = 0xDD;
  configuration[5] = 0xCC;
  configuration[6] = 0xBB;
  configuration[7] = 0xAA;//Fim enderco CH1
  configuration[8] = B00000000;//Comeco enderco CH2
  configuration[9] = B00000000;
  configuration[10] = B00000000;
  configuration[11] = B00000000;
  configuration[12] = B00000000;//Fim enderco CH2
  configuration[13] = 0x20;//num bits enviados (1 byte nesse ex)
  configuration[14] = B00000000;
  
  digitalWrite(CS_R, LOW);
  digitalWrite(DATA_R, LOW);
  digitalWrite(CLK_R, LOW);
  digitalWrite(CE_R, LOW);
  digitalWrite(DR_R, LOW);
  
  digitalWrite(CS_E, LOW);
  digitalWrite(DATA_E, LOW);
  digitalWrite(CLK_E, LOW);
  digitalWrite(CE_E, LOW);
  
  pinMode(CS_R, OUTPUT);
  pinMode(DATA_R, OUTPUT);
  pinMode(CLK_R, OUTPUT);
  pinMode(CE_R, OUTPUT);
  pinMode(DR_R, INPUT);
  
  pinMode(CS_E, OUTPUT);
  pinMode(DATA_E, OUTPUT);
  pinMode(CLK_E, OUTPUT);
  pinMode(CE_E, OUTPUT);
  
  //configure_E();
  data = '0';
  configure_R();
}
int i = 0;
void loop() {
  //data = '0';
  //if (Serial.available() > 0)
    //data = Serial.read();
  //Serial.println(data);
  //write_E();
  while (digitalRead(DR_R) == LOW);
  read_R();
  Serial.print((uint8_t)(data_R[0]));
  Serial.print("\t");
  Serial.print((uint8_t)(data_R[1]));
  Serial.print("\t");
  Serial.print((uint8_t)(data_R[2]));
  Serial.print("\t");
  for (i = 7; i > -1; i--)
  {
    Serial.print((data_R[3]&(1<<i))>0?1:0);
  }
  Serial.println();
  //data++;
  //delay(500);
    
}

void write_E()
{
  int i, j;
  digitalWrite(CE_E,HIGH);
  //Serial.println("\nEscrevendo");
  delayMicroseconds(5);
  for (i = 7; i > 2 ; i --)
  {
    for (j = 7; j > -1; j --)
    {
      //Serial.print((configuration[i]&(1<<j))>0?1:0);
      if ((configuration[i]&(1<<j))>0) digitalWrite(DATA_E, HIGH);
      else digitalWrite(DATA_E, LOW);
      delay_E();
    }
    //Serial.println();
  }//Endereco destino enviado
  for (j = 7; j > -1; j --)
  {
    //Serial.print((data & (1<<j))>0?1:0);
    if ((data & (1<<j))>0) digitalWrite(DATA_E, HIGH);
    else digitalWrite(DATA_E, LOW);
    delay_E();
  }//termina de enviar dados
  //Serial.println();
  digitalWrite(CE_E, LOW);
  delayMicroseconds(250);
}

void read_R()
{
  data_R[0] = 0;
  data_R[1] = 0;
  data_R[2] = 0;
  data_R[3] = 0;
  //Serial.print("\nRecebendo");
  int i;
  digitalWrite(CE_R, LOW);
  delayMicroseconds(2);
  char temp = 0;
  
  for (i = 7; i > -1; i --)
  {
    if (digitalRead(DATA_R) == HIGH) temp |= (1<<i);
    delay_R();
  }
  //Serial.println((int)temp);
  data_R[0] = temp;
  temp = 0;
  for (i = 7; i > -1; i --)
  {
    if (digitalRead(DATA_R) == HIGH) temp |= (1<<i);
    delay_R();
  }
  //Serial.println((int)temp);
  data_R[1] = temp;
  temp = 0;
  for (i = 7; i > -1; i --)
  {
    if (digitalRead(DATA_R) == HIGH) temp |= (1<<i);
    delay_R();
  }
  //Serial.println((int)temp);
  data_R[2] = temp;
  temp = 0;
  for (i = 7; i > -1; i --)
  {
    if (digitalRead(DATA_R) == HIGH) temp |= (1<<i);
    delay_R();
  }
  //Serial.println((int)temp);
  data_R[3] = temp;
  temp = 0;
  digitalWrite(CE_R, HIGH);
  delayMicroseconds(1);
}

void delay_R()
{
  delayMicroseconds(1);
  digitalWrite(CLK_R, HIGH);
  delayMicroseconds(1);
  digitalWrite(CLK_R, LOW);
}

void delay_E()
{
  delayMicroseconds(1);
  digitalWrite(CLK_E, HIGH);
  delayMicroseconds(1);
  digitalWrite(CLK_E, LOW);
}

void configure_E()
{
  configuration[0] &= ~1;
  digitalWrite(CE_E, LOW);
  digitalWrite(CS_E, HIGH);
  Serial.println("\nConfigurando E");
  int i, j;
  for (i = 14; i > -1; i--)
  {
    for (j = 7; j > -1; j--)
    {
      Serial.print((configuration[i]&(1<<j))>0?1:0);
      if ((configuration[i]&(1<<j))>0) digitalWrite(DATA_E, HIGH);
      else digitalWrite(DATA_E, LOW);
      delay_E();
    }
    Serial.println();
  }
  digitalWrite(CS_E, LOW);
  delayMicroseconds(250);
}

void configure_R()
{
  pinMode(DATA_R, OUTPUT);
  configuration[0] |= 1;
  digitalWrite(CE_R, LOW);
  digitalWrite(CS_R, HIGH);
  int i, j;
  Serial.println("\nConfigurando R");
  for (i = 14; i > -1; i--)
  {
    for (j = 7; j > -1; j--)
    {
      Serial.print((configuration[i]&(1<<j))>0?1:0);
      if ((configuration[i]&(1<<j))>0) digitalWrite(DATA_R, HIGH);
      else digitalWrite(DATA_R, LOW);
      delay_R();
    }
    Serial.println();
  }
  pinMode(DATA_R, INPUT);
  digitalWrite(CS_R, LOW);
  digitalWrite(CE_R, HIGH); //Deixa pronto para ler
  delayMicroseconds(250);
}
