#include <Arduino.h>

#include <Wire.h>

#include <LiquidCrystal_I2C.h>

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial playerMP3Serial(10, 11);

DFRobotDFPlayerMini playerMP3;

#define b1 3

#define b2 2

#define b3 4

#define b4 5

#define b5 6

#define b6 8

#define b7 9

#define b8 12

#define b9 13

#define b10 7

#define buttonPin A0



int leitura1 = 0;

int leitura2 = 0;

int leitura3 = 0;

int leitura4 = 0;

int leitura5 = 0;

int leitura6 = 0;

int leitura7 = 0;

int leitura8 = 0;

int leitura9 = 0;

int leitura10 = 0;



int leiturainter;

int ope = 0;

int som = 0;
int som1 = 0;


int estadoBotao = 0;
int contadorBotao = 1;
int lastcontagembotao = 0;
const int btn = A0;


void setup() {

  playerMP3Serial.begin(9600);
  Serial.println();
  Serial.println(F("Iniciando DFPlayer ... (Espere 3~5 segundos)"));
  if (!playerMP3.begin(playerMP3Serial)) {
    Serial.println(F("Falha:"));
    Serial.println(F("1.conexões!"));
    Serial.println(F("2.cheque o cartão SD!"));
    while (true) {
      delay(0);
    }
  }
  Serial.println(F("DFPlayer iniciado!"));
  playerMP3.volume(29);

#ifdef DEBUG
  Serial.println("o Setup acabou");
#endif


  lcd.init();

  lcd.backlight();




  pinMode(b1, INPUT);

  pinMode(b2, INPUT);

  pinMode(b3, INPUT);

  pinMode(b4, INPUT);

  pinMode(b5, INPUT);

  pinMode(b6, INPUT);

  pinMode(b7, INPUT);

  pinMode(b8, INPUT);

  pinMode(b9, INPUT);

  pinMode(b10, INPUT);

  pinMode(btn, INPUT_PULLUP);





  Serial.begin(9600);
}
void loop() {

  leitura1 = digitalRead(b1);

  leitura2 = digitalRead(b2);

  leitura3 = digitalRead(b3);

  leitura4 = digitalRead(b4);

  leitura5 = digitalRead(b5);

  leitura6 = digitalRead(b6);

  leitura7 = digitalRead(b7);

  leitura8 = digitalRead(b8);

  leitura9 = digitalRead(b9);

  leitura10 = digitalRead(b10);

  Serial.println(leitura2);

  estadoBotao = digitalRead(btn);
  if (estadoBotao == HIGH) {

    if (contadorBotao <= 1) {
      contadorBotao = 2;
    } else {
      contadorBotao = 1;
    }


    delay(1000);
  }

  if (contadorBotao == 1) {
    som = 0;
    numeros();
    
  } else if (contadorBotao == 2) {
    contas();
  }
}

void numeros() {

  desaitvaBtns();

  if (som1 == 0) {
    playerMP3.playFolder(1, 23);
    lcd.setCursor(0, 0);
    lcd.print("Conhecendos os ");
    lcd.setCursor(0, 1);
    lcd.print("numeros");
    delay(3000);
    lcd.clear();
    lcd.print("escolha um ");
    lcd.setCursor(0, 1);
    lcd.print("numero");
    som1 = 1;
  }

  if (leitura1 == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("1");
    playerMP3.playFolder(1, 1);
    delay(1000);
  } else if (leitura2 == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2");
    playerMP3.playFolder(1, 2);
    delay(1000);
  } else if (leitura3 == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("3");
    playerMP3.playFolder(1, 3);
    delay(1000);
  } else if (leitura4 == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("4");
    playerMP3.playFolder(1, 4);
    delay(1000);
  } else if (leitura5 == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5");
    playerMP3.playFolder(1, 5);
    delay(1000);
  } else if (leitura6 == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("6");
    playerMP3.playFolder(1, 6);
    delay(1000);
  } else if (leitura7 == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("7");
    playerMP3.playFolder(1, 7);
    delay(1000);
  } else if (leitura8 == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("8");
    playerMP3.playFolder(1, 8);
    delay(1000);
  } else if (leitura9 == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("9");
    playerMP3.playFolder(1, 9);
    delay(1000);
  } else if (leitura10 == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("10");
    playerMP3.playFolder(1, 10);
    delay(1000);
  }
}

void contas() {


  if (som1 == 1) {

    playerMP3.playFolder(2, 24);
    lcd.setCursor(0, 0);
    lcd.print("Conhecendos as ");
    lcd.setCursor(0, 1);
    lcd.print("operacoes");
    delay(3500);
    lcd.clear();

    som1 = 0;
  }


  if (ope == 0) {
    op0();
  } else if (ope == 1) {
    op1();
  } else if (ope == 2) {
    op2();
  } else if (ope == 3) {
    op3();
  } else if (ope == 4) {
    op4();
  } else if (ope == 5) {
    op5();
  } else if (ope == 6) {
    op6();
  } else if (ope == 7) {
    op7();
  } else if (ope == 8) {
    op8();
  } else if (ope == 9) {
    op9();
  }
}
void desaitvaBtns() {

  digitalWrite(leitura10, LOW);
  digitalWrite(leitura9, LOW);
  digitalWrite(leitura8, LOW);
  digitalWrite(leitura7, LOW);
  digitalWrite(leitura6, LOW);
  digitalWrite(leitura5, LOW);
  digitalWrite(leitura4, LOW);
  digitalWrite(leitura3, LOW);
  digitalWrite(leitura2, LOW);
  digitalWrite(leitura1, LOW);
}
void verificaAcertou(String msg) {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print(msg);
  delay(2000);
};
void op0() {
  desaitvaBtns();

  if (som == 0) {
    lcd.setCursor(2, 0);
    lcd.print("2 - 1 ");
    playerMP3.playFolder(2, 16);
    delay(3000);
    som = 1;
  }
  if (leitura1 == HIGH) {

    playerMP3.playFolder(2, 22);
    verificaAcertou("ACERTOU");
    lcd.setCursor(2, 1);
    delay(200);
    lcd.clear();
    som = 0;
    ope = 1;

  } else if (leitura9 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 - 1 ");
    playerMP3.playFolder(2, 16);
    delay(3000);
    ope = 0;
  } else if (leitura8 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 - 1 ");
    playerMP3.playFolder(2, 16);
    delay(3000);
    ope = 0;
  } else if (leitura7 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 - 1 ");
    playerMP3.playFolder(2, 16);
    delay(3000);
    ope = 0;
  } else if (leitura6 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 - 1 ");
    playerMP3.playFolder(2, 16);
    delay(3000);
    ope = 0;
  } else if (leitura5 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 - 1 ");
    playerMP3.playFolder(2, 16);
    delay(3000);
    ope = 0;
  } else if (leitura4 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 - 1 ");
    playerMP3.playFolder(2, 16);
    delay(3000);
    ope = 0;
  } else if (leitura3 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 - 1 ");
    playerMP3.playFolder(2, 16);
    delay(3000);
    ope = 0;
  } else if (leitura2 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 - 1 ");
    playerMP3.playFolder(2, 16);
    delay(3000);
    ope = 0;
  } else if (leitura10 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 - 1 ");
    playerMP3.playFolder(2, 16);
    delay(3000);
    ope = 0;
  }
}
void op1() {
  desaitvaBtns();
  //emitir som
  if (som == 0) {
    lcd.setCursor(2, 0);
    lcd.print("2 + 2 ");
    playerMP3.playFolder(2, 11);
    delay(3000);
    som = 1;
  }
  if (leitura4 == HIGH) {
    playerMP3.playFolder(2, 22);
    verificaAcertou("ACERTOU");
    delay(200);
    lcd.clear();
    ope = 2;
    som = 0;
  } else if (leitura10 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 + 2 ");
    playerMP3.playFolder(2, 11);
    delay(3000);
    ope = 1;
  } else if (leitura9 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 + 2 ");
    playerMP3.playFolder(2, 11);
    delay(3000);
    ope = 1;
  } else if (leitura8 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 + 2 ");
    playerMP3.playFolder(2, 11);
    delay(3000);
    ope = 1;
  } else if (leitura7 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 + 2 ");
    playerMP3.playFolder(2, 11);
    delay(3000);
    ope = 1;
  } else if (leitura6 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 + 2 ");
    playerMP3.playFolder(2, 11);
    delay(3000);
    ope = 1;
  } else if (leitura5 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 + 2 ");
    playerMP3.playFolder(2, 11);
    delay(3000);
    ope = 1;
  } else if (leitura3 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 + 2 ");
    playerMP3.playFolder(2, 11);
    delay(3000);
    ope = 1;
  } else if (leitura2 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 + 2 ");
    playerMP3.playFolder(2, 11);
    delay(3000);
    ope = 1;
  } else if (leitura1 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("2 + 2 ");
    playerMP3.playFolder(2, 11);
    delay(3000);
    ope = 1;
  }
}
void op2() {
  desaitvaBtns();
  if (som == 0) {
    lcd.setCursor(2, 0);
    lcd.print("5 - 3 ");
    playerMP3.playFolder(2, 17);
    delay(3000);
    som = 1;
  }
  if (leitura2 == HIGH) {
    playerMP3.playFolder(2, 22);
    verificaAcertou("ACERTOU");
    delay(200);
    lcd.clear();
    ope = 3;
    som = 0;
  } else if (leitura10 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 - 3 ");
     playerMP3.playFolder(2, 17);
    delay(3000);
    ope = 2;
  } else if (leitura9 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 - 3 ");
     playerMP3.playFolder(2, 17);
    delay(3000);
    ope = 2;
  } else if (leitura8 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 - 3 ");
     playerMP3.playFolder(2, 17);
    delay(3000);
    ope = 2;
  } else if (leitura7 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 - 3 ");
     playerMP3.playFolder(2, 17);
    delay(3000);
    ope = 2;
  } else if (leitura6 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 - 3 ");
     playerMP3.playFolder(2, 17);
    delay(3000);
    ope = 2;
  } else if (leitura5 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 - 3 ");
    playerMP3.playFolder(2, 17);
    delay(3000);
    ope = 2;
  } else if (leitura4 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 - 3 ");
    playerMP3.playFolder(2, 17);
    delay(3000);
    ope = 2;
  } else if (leitura3 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 - 3 ");
    playerMP3.playFolder(2, 17);
    delay(3000);
    ope = 2;
  } else if (leitura1 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 - 3 ");
    playerMP3.playFolder(2, 17);
    delay(3000);
    ope = 2;
  }
};
void op3() {
  desaitvaBtns();
  if (som == 0) {
    lcd.setCursor(2, 0);
    lcd.print("4 + 2 ");
    playerMP3.playFolder(2, 12);
    delay(3000);
    som = 1;
  }
  if (leitura6 == HIGH) {
    playerMP3.playFolder(2, 22);
    verificaAcertou("ACERTOU");
    delay(200);
    lcd.clear();
    ope = 4;
    som = 0;
  } else if (leitura10 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("4 + 2 ");
    playerMP3.playFolder(2, 12);
    delay(3000);
    ope = 3;
  } else if (leitura9 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("4 + 2 ");
    playerMP3.playFolder(2, 12);
    delay(3000);
    ope = 3;
  } else if (leitura8 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
     lcd.setCursor(2, 0);
    lcd.print("4 + 2 ");
    playerMP3.playFolder(2, 12);
    delay(3000);
    ope = 3;
  } else if (leitura7 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("4 + 2 ");
    playerMP3.playFolder(2, 12);
    delay(3000);
    ope = 3;
  } else if (leitura5 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("4 + 2 ");
    playerMP3.playFolder(2, 12);
    delay(3000);
    ope = 3;
  } else if (leitura4 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("4 + 2 ");
    playerMP3.playFolder(2, 12);
    delay(3000);
    ope = 3;
  } else if (leitura3 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("4 + 2 ");
    playerMP3.playFolder(2, 12);
    delay(3000);
    ope = 3;
  } else if (leitura2 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("4 + 2 ");
    playerMP3.playFolder(2, 12);
    delay(3000);
    ope = 3;
  } else if (leitura1 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("4 + 2 ");
    playerMP3.playFolder(2, 12);
    delay(3000);
    ope = 3;
  }
};
void op4() {
  desaitvaBtns();
  if (som == 0) {
    lcd.setCursor(2, 0);
    lcd.print("9 - 6 ");
    playerMP3.playFolder(2, 18);
    delay(3000);
    som = 1;
  }
  if (leitura3 == HIGH) {
    playerMP3.playFolder(2, 22);
    verificaAcertou("ACERTOU");
    delay(200);
    lcd.clear();
    ope = 5;
    som = 0;
  } else if (leitura10 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("9 - 6 ");
    playerMP3.playFolder(2, 18);
    delay(3000);
    ope = 4;
  } else if (leitura9 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("9 - 6 ");
    playerMP3.playFolder(2, 18);
    delay(3000);
    ope = 4;
  } else if (leitura8 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("9 - 6 ");
    playerMP3.playFolder(2, 18);
    delay(3000);
    ope = 4;
  } else if (leitura7 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("9 - 6 ");
    playerMP3.playFolder(2, 18);
    delay(3000);
    ope = 4;
  } else if (leitura6 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("9 - 6 ");
    playerMP3.playFolder(2, 18);
    delay(3000);
    ope = 4;
  } else if (leitura5 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("9 - 6 ");
    playerMP3.playFolder(2, 18);
    delay(3000);
    ope = 4;
  } else if (leitura4 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("9 - 6 ");
    playerMP3.playFolder(2, 18);
    delay(3000);
    ope = 4;
  } else if (leitura2 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("9 - 6 ");
    playerMP3.playFolder(2, 18);
    delay(3000);
    ope = 4;
  } else if (leitura1 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("9 - 6 ");
    playerMP3.playFolder(2, 18);
    delay(3000);
    ope = 4;
  }
}
void op5() {
  desaitvaBtns();
  if (som == 0) {
    lcd.setCursor(2, 0);
    lcd.print("5 + 3 ");
    playerMP3.playFolder(2, 13);
    delay(3000);
    som = 1;
  }
  if (leitura8 == HIGH) {
    playerMP3.playFolder(2, 22);
    verificaAcertou("ACERTOU");
    delay(200);
    lcd.clear();
    ope = 6;
    som = 0;
  } else if (leitura10 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 + 3 ");
    playerMP3.playFolder(2, 13);
    delay(3000);
    ope = 5;
  } else if (leitura9 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 + 3 ");
    playerMP3.playFolder(2, 13);
    delay(3000);
    ope = 5;
  } else if (leitura7 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 + 3 ");
    playerMP3.playFolder(2, 13);
    delay(3000);
    ope = 5;
  } else if (leitura6 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 + 3 ");
    playerMP3.playFolder(2, 13);
    delay(3000);
    ope = 5;
  } else if (leitura5 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 + 3 ");
    playerMP3.playFolder(2, 13);
    delay(3000);
    ope = 5;
  } else if (leitura4 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 + 3 ");
    playerMP3.playFolder(2, 13);
    delay(3000);
    ope = 5;
  } else if (leitura3 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 + 3 ");
    playerMP3.playFolder(2, 13);
    delay(3000);
    ope = 5;
  } else if (leitura2 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 + 3 ");
    playerMP3.playFolder(2, 13);
    delay(3000);
    ope = 5;
  } else if (leitura1 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("5 + 3 ");
    playerMP3.playFolder(2, 13);
    delay(3000);
    ope = 5;
  }
}
void op6() {
  if (som == 0) {
    lcd.setCursor(2, 0);
    lcd.print("10 - 3 ");
    playerMP3.playFolder(2, 19);
    delay(3000);
    som = 1;
  }
  if (leitura7 == HIGH) {
    playerMP3.playFolder(2, 22);
    verificaAcertou("ACERTOU");
    delay(200);
    lcd.clear();
    ope = 7;
    som = 0;
  } else if (leitura10 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("10 - 3 ");
    playerMP3.playFolder(2, 19);
    delay(3000);
    ope = 6;
  } else if (leitura9 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("10 - 3 ");
    playerMP3.playFolder(2, 19);
    delay(3000);
    ope = 6;
  } else if (leitura8 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("10 - 3 ");
    playerMP3.playFolder(2, 19);
    delay(3000);
    ope = 6;
  } else if (leitura6 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("10 - 3 ");
    playerMP3.playFolder(2, 19);
    delay(3000);
    ope = 6;
  } else if (leitura5 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("10 - 3 ");
    playerMP3.playFolder(2, 19);
    delay(3000);
    ope = 6;
  } else if (leitura4 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("10 - 3 ");
    playerMP3.playFolder(2, 19);
    delay(3000);
    ope = 6;
  } else if (leitura3 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("10 - 3 ");
    playerMP3.playFolder(2, 19);
    delay(3000);
    ope = 6;
  } else if (leitura2 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("10 - 3 ");
    playerMP3.playFolder(2, 19);
    delay(3000);
    ope = 6;
  } else if (leitura1 == HIGH) {

    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("10 - 3 ");
    playerMP3.playFolder(2, 19);
    delay(3000);
    ope = 6;
  }
}
void op7() {
  if (som == 0) {
    lcd.setCursor(2, 0);
    lcd.print("1 + 1 ");
    playerMP3.playFolder(2, 14);
    delay(3000);
    som = 1;
  }
  if (leitura2 == HIGH) {
    playerMP3.playFolder(2, 22);
    verificaAcertou("ACERTOU");
    delay(200);
    lcd.clear();
    ope = 8;
    som = 0;
  } else if (leitura10 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("1 + 1 ");
    playerMP3.playFolder(2, 14);
    delay(3000);
    ope = 7;
  } else if (leitura9 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("1 + 1 ");
    playerMP3.playFolder(2, 14);
    delay(3000);
    ope = 7;
  } else if (leitura8 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("1 + 1 ");
    playerMP3.playFolder(2, 14);
    delay(3000);
    ope = 7;
  } else if (leitura7 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("1 + 1 ");
    playerMP3.playFolder(2, 14);
    delay(3000);
    ope = 7;
  } else if (leitura6 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("1 + 1 ");
    playerMP3.playFolder(2, 14);
    delay(3000);
    ope = 7;
  } else if (leitura5 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("1 + 1 ");
    playerMP3.playFolder(2, 14);
    delay(3000);
    ope = 7;
  } else if (leitura4 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("1 + 1 ");
    playerMP3.playFolder(2, 14);
    delay(3000);
    ope = 7;
  } else if (leitura3 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("1 + 1 ");
    playerMP3.playFolder(2, 14);
    delay(3000);
    ope = 7;
  } else if (leitura1 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("1 + 1 ");
    playerMP3.playFolder(2, 14);
    delay(3000);
    ope = 7;
  }
};
void op8() {
  desaitvaBtns();
  if (som == 0) {
    lcd.setCursor(2, 0);
    lcd.print("8 - 4 ");
    playerMP3.playFolder(2, 20);
    delay(3000);
    som = 1;
  }
  if (leitura4 == HIGH) {
    playerMP3.playFolder(2, 22);
    verificaAcertou("ACERTOU");
    delay(200);
    lcd.clear();
    ope = 9;
    som = 0;
  } else if (leitura10 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("8 - 4 ");
    playerMP3.playFolder(2, 20);
    delay(3000);
    ope = 8;
  } else if (leitura9 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("8 - 4 ");
    playerMP3.playFolder(2, 20);
    delay(3000);
    ope = 8;
  } else if (leitura8 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("8 - 4 ");
    playerMP3.playFolder(2, 20);
    delay(3000);
    ope = 8;
  } else if (leitura7 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("8 - 4 ");
    playerMP3.playFolder(2, 20);
    delay(3000);
    ope = 8;
  } else if (leitura6 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("8 - 4 ");
    playerMP3.playFolder(2, 20);
    delay(3000);
    ope = 8;
  } else if (leitura5 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("8 - 4 ");
    playerMP3.playFolder(2, 20);
    delay(3000);
    ope = 8;
  } else if (leitura3 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("8 - 4 ");
    playerMP3.playFolder(2, 20);
    delay(3000);
    ope = 8;
  } else if (leitura2 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("8 - 4 ");
    playerMP3.playFolder(2, 20);
    delay(3000);
    ope = 8;
  } else if (leitura1 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("8 - 4 ");
    playerMP3.playFolder(2, 20);
    delay(3000);
    ope = 8;
  }
};
void op9() {
  desaitvaBtns();
  if (som == 0) {
    lcd.setCursor(2, 0);
    lcd.print("7 + 2 ");
    playerMP3.playFolder(2, 15);
    delay(3000);
    som = 1;
  }
  if (leitura9 == HIGH) {
    playerMP3.playFolder(2, 22);
    verificaAcertou("ACERTOU");
    delay(200);
    lcd.clear();
    ope = 0;
    som = 0;
  } else if (leitura10 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("7 + 2 ");
    playerMP3.playFolder(2, 15);
    delay(3000);
    ope = 9;
  } else if (leitura4 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("7 + 2 ");
    playerMP3.playFolder(2, 15);
    delay(3000);
    ope = 9;
  } else if (leitura8 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("7 + 2 ");
    playerMP3.playFolder(2, 15);
    delay(3000);
    ope = 9;
  } else if (leitura7 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("7 + 2 ");
    playerMP3.playFolder(2, 15);
    delay(3000);
    ope = 9;
  } else if (leitura6 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("7 + 2 ");
    playerMP3.playFolder(2, 15);
    delay(3000);
    ope = 9;
  } else if (leitura5 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("7 + 2 ");
    playerMP3.playFolder(2, 15);
    delay(3000);
    ope = 9;
  } else if (leitura3 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("7 + 2 ");
    playerMP3.playFolder(2, 15);
    delay(3000);
    ope = 9;
  } else if (leitura2 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("7 + 2 ");
    playerMP3.playFolder(2, 15);
    delay(3000);
    ope = 9;
  } else if (leitura1 == HIGH) {
    playerMP3.playFolder(2, 21);
    verificaAcertou("ERROU");
    delay(200);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("7 + 2 ");
    playerMP3.playFolder(2, 15);
    delay(3000);
    ope = 9;
  }
}
