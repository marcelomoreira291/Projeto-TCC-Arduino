#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(10,11);
DFRobotDFPlayerMini myDFPlayer;


#define botaoA 2
#define botaoE 3
#define botaoI 4
#define botaoO 5
#define botaoU 6

#define releA 7
#define releE 8
#define releI 9
#define releO 12
#define releU 13

int leitorA = 0;
int leitorE = 0;
int leitorI = 0;
int leitorO = 0;
int leitorU = 0;
int msc;

void setup() {
  
  mySoftwareSerial.begin(9600);

  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini"));
  Serial.println(F("Inicializando modulo DFPlayer... (3~5 segundos)"));
  if (!myDFPlayer.begin(mySoftwareSerial))
  {
    Serial.println(F("Nao inicializado:"));
    Serial.println(F("1.Cheque as conexoes do DFPlayer Mini"));
    Serial.println(F("2.Insira um cartao SD"));
    while (true);
  }
  Serial.println();
  Serial.println(F("Modulo DFPlayer Mini inicializado!"));

  //Definicoes iniciais
  myDFPlayer.setTimeOut(500); //Timeout serial 500ms
  myDFPlayer.volume(30); //Volume 5
  myDFPlayer.EQ(0); //Equalizacao normal

  //Mostra o menu de comandos
  Serial.println();
  Serial.print("Numero de arquivos no cartao SD: ");
  Serial.println(myDFPlayer.readFileCounts(DFPLAYER_DEVICE_SD));

   
   pinMode(botaoA, INPUT);
   pinMode(botaoE, INPUT);
   pinMode(botaoI, INPUT);
   pinMode(botaoO, INPUT);
   pinMode(botaoU, INPUT);
   
   pinMode(releA, OUTPUT);
   pinMode(releE, OUTPUT);
   pinMode(releI, OUTPUT);
   pinMode(releO, OUTPUT);
   pinMode(releU, OUTPUT);

}

void loop() {
   leitorA = digitalRead(botaoA);
   leitorE = digitalRead(botaoE);
   leitorI = digitalRead(botaoI);
   leitorO = digitalRead(botaoO);
   leitorU = digitalRead(botaoU);


   if(leitorA == 1){

       msc = 1;
       
       digitalWrite(releA, HIGH);

       myDFPlayer.play(msc);

       delay(3750);

               
   }if(leitorE == 1){

       msc = 2;
       
       digitalWrite(releE, HIGH);

       myDFPlayer.play(msc);

       delay(3750);

               
   }if(leitorI == 1){

       msc = 3;
       
       digitalWrite(releI, HIGH);

       myDFPlayer.play(msc);

       delay(3750);

               
   }if(leitorO == 1){

       msc = 4;
       
       digitalWrite(releO, HIGH);

       myDFPlayer.play(msc);

       delay(3750);

               
   }if(leitorU == 1){

       msc = 5;
       
       digitalWrite(releU, HIGH);

       myDFPlayer.play(msc);

       delay(3750);
           
   }
   
   digitalWrite(releA, LOW);
   digitalWrite(releE, LOW);
   digitalWrite(releI, LOW);
   digitalWrite(releO, LOW);
   digitalWrite(releU, LOW);
   
   delay(200);
}
