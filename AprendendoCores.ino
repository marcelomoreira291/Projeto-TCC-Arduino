#define rele1 2
#define rele2 3
#define rele3 4
#define rele4 5
#define rele5 6
#define rele6 7
#define rele7 13

#define outPin 8
#define s0 9
#define s1 10
#define s2 11
#define s3 12

boolean DEBUG = true;

//  Variáveis
int red, grn, blu;
String cor ="";

void setup(){

  Serial.begin(9600);
  
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  pinMode(rele5, OUTPUT);
  pinMode(rele6, OUTPUT);
  pinMode(rele7, OUTPUT);

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT); // Saída do sensor para entrada do arduino

  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH); 
  digitalWrite(rele3, HIGH); 
  digitalWrite(rele4, HIGH); 
  digitalWrite(rele5, HIGH); 
  digitalWrite(rele6, HIGH); 
  digitalWrite(rele7, HIGH);

  // Configurando a escala de frequência para 100%
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
}

void loop(){
  lerCor();
  mostraRGB();
}

// Ler componentes do RBG
void lerRGB(){
  red = 0, grn = 0, blu = 0;
  
  int n = 10;
  for (int i = 0; i < n; ++i){
    //Ler o componente vermelho
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    red = red + pulseIn(outPin, LOW);
  
   //Ler o componente verde
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    grn = grn + pulseIn(outPin, LOW);
    
   //Ler o componente azul
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    blu = blu + pulseIn(outPin, LOW);
  }
  red = red/n;
  grn = grn/n;
  blu = blu/n;
}

/***************************************************
 Mostrando dados capturados no Monitor Serial
****************************************************/
void mostraRGB(void){
  Serial.print("vermelho= ");
  Serial.print(red);
  Serial.print("   verde= ");
  Serial.print(grn);
  Serial.print("   azul= ");
  Serial.print(blu);
  Serial.print (" - ");
  Serial.print (cor);
  Serial.println (" detectado!");
}

void lerCor(){  
  lerRGB();
     if(red>11  && red<21 && grn>39 && grn<49 && blu>23 && blu<33){
       digitalWrite(rele1, LOW);
       digitalWrite(rele2, HIGH); 
       digitalWrite(rele3, HIGH); 
       digitalWrite(rele4, HIGH); 
       digitalWrite(rele5, HIGH); 
       digitalWrite(rele6, HIGH); 
       digitalWrite(rele7, HIGH);
       cor = "VERMELHO";
       delay(1500);
       digitalWrite(rele1, HIGH);

      } else if(red>56 && red<66  && grn>26 && grn<36 && blu>18 && blu<28){
        digitalWrite(rele1, HIGH);
        digitalWrite(rele2, LOW); 
        digitalWrite(rele3, HIGH); 
        digitalWrite(rele4, HIGH); 
        digitalWrite(rele5, HIGH); 
        digitalWrite(rele6, HIGH); 
        digitalWrite(rele7, HIGH);
        cor = "VERDE";
        delay(1500);
        digitalWrite(rele2, HIGH); 
       
      } else if(red>56 && red<66  && grn>25 && grn<35 && blu>7  && blu<17){
        digitalWrite(rele1, HIGH);
        digitalWrite(rele2, HIGH); 
        digitalWrite(rele3, LOW); 
        digitalWrite(rele4, HIGH); 
        digitalWrite(rele5, HIGH); 
        digitalWrite(rele6, HIGH); 
        digitalWrite(rele7, HIGH);
        cor = "AZUL";
        delay(1500);
        digitalWrite(rele3, HIGH); 
      
      } else if(red>5  && red<15  && grn>8  && grn<18 && blu>15  && blu<25){
        digitalWrite(rele1, HIGH);
       digitalWrite(rele2, HIGH); 
       digitalWrite(rele3, HIGH); 
       digitalWrite(rele4, LOW); 
       digitalWrite(rele5, HIGH); 
       digitalWrite(rele6, HIGH); 
       digitalWrite(rele7, HIGH);
       cor = "AMARELO";
       delay(1500);
       digitalWrite(rele4, HIGH); 
      
      } else if(red>5  && red<11   && grn>5  && grn<11  && blu>3  && blu<9){
       digitalWrite(rele1, HIGH);
       digitalWrite(rele2, HIGH); 
       digitalWrite(rele3, HIGH); 
       digitalWrite(rele4, HIGH); 
       digitalWrite(rele5, LOW); 
       digitalWrite(rele6, HIGH); 
       digitalWrite(rele7, HIGH);
       cor = "BRANCO";
       delay(1500);
       digitalWrite(rele5, HIGH);  
      
      } else if(red>56 && red<66  && grn>52 && grn<62 && blu>29 && blu<39){
       digitalWrite(rele1, HIGH);
       digitalWrite(rele2, HIGH); 
       digitalWrite(rele3, HIGH); 
       digitalWrite(rele4, HIGH); 
       digitalWrite(rele5, HIGH); 
       digitalWrite(rele6, LOW); 
       digitalWrite(rele7, HIGH);
       cor = "ROXO";
       delay(1500);
       digitalWrite(rele6, HIGH);
      
      } else if(red>7 && red<17  && grn>23 && grn<33 && blu>17 && blu<27){
       digitalWrite(rele1, HIGH);
       digitalWrite(rele2, HIGH); 
       digitalWrite(rele3, HIGH); 
       digitalWrite(rele4, HIGH); 
       digitalWrite(rele5, HIGH); 
       digitalWrite(rele6, HIGH); 
       digitalWrite(rele7, LOW);
       cor = "LARANJA";
       delay(1500);
       digitalWrite(rele7, HIGH); 
      
      } else {
        cor = "SEM_COR";
      }
}
