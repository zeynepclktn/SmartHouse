#include <SoftwareSerial.h>
#include <Servo.h>



Servo myservo; 



String state;
String state2;

int pos = 0; 

int led1=2;
int led2=3;
int led3=4;
int led4=5;
int led5=12;
int sayi1=11;
int sayi2=10;
int klima=6;

int inputPin = 7; // hareket sensör sinyal pin
int pirState = LOW; // hareket durumu
int val = 0; // hareket sensöründen okunan değer
int pinSpeaker = 10; //buzzer pin




void setup() {

  
  Serial.begin(9600);
  pinMode(led1,OUTPUT);  
  pinMode(led2,OUTPUT);  
  pinMode(led3,OUTPUT);  
  pinMode(led4,OUTPUT);  
  pinMode(led5,OUTPUT);
  pinMode(klima,OUTPUT);  
  pinMode(inputPin, INPUT); // hareket sensör pini giriş tanımlama
  pinMode(pinSpeaker, OUTPUT);
  myservo.attach(9);
}
void loop() 
{ 

    val = digitalRead(inputPin); // hareket sensöründen değer okuma

                   
                    if (val == HIGH) { // okunan değer hıgh ise
                    playTone(300, 160); // alarm çal
                    delay(150);
                      
                    if (pirState == LOW) { // hareket sensör durumu low ise
                    Serial.println("Hareket algılandı!");
                    pirState = HIGH; // Hareket sensör durumunu hıgh yap
                    }
                    } else {
                    playTone(0, 0);
                    delay(300);
                    if (pirState == HIGH){ // Hareket sensör durumunu hıgh yap
                    Serial.println("Hareket yok!");
                    pirState = LOW;
                    }
                    }
                    
                    
                    
          
                     
                    


  
  
   while (Serial.available())
   {
   
     
     delay(10);
     char c=Serial.read();
     state+=c; 
     state2+=c;
   }

      
      
     if(state.length()>0)
     {
      Serial.println(state);
     
 
     if(state=="Oda1LedYak")
     {//oda11 i açma
       digitalWrite(led1,1);
       state="";
     }
     if(state=="Oda1LedSondur")//oda1i kapama
     {
       digitalWrite(led1,0);
       state="";
     }
     if(state=="Oda2LedYak")//oda2 i açma
     {
       digitalWrite(led2,1);
       state="";
     }
     if(state=="Oda2LedSondur")//oda2 i kapama
     {
       digitalWrite(led2,0);
       state="";
     }
     if(state=="Oda3LedYak")//oda3 i açma
     {
      digitalWrite(led3,1);
      state="";
     }
      if(state=="Oda3LedSondur")//oda3 i kapama
     {
      digitalWrite(led3,0);
      state="";
     }
      if(state=="GarajLedYak")//oda4 i açma
     {
      digitalWrite(led4,1);
      state="";
     }
      if(state=="GarajLedSondur")//oda4 i kapama
     {
      digitalWrite(led4,0);
      state="";
     } 
     if(state=="KlimaCalistir")//klima açma
     {
      digitalWrite(klima,1);
      state="";
     }
      if(state=="KlimaDurdur")//klima kapama
     {
      digitalWrite(klima,0);//buraya kod eklenecek
      state="";
     }
      if(state=="ArkaKapiAc")
     {
        for (pos = 0; pos <= 180; pos += 1)
        { 
           myservo.write(pos);                    
        }
         state="";
     }
      if(state=="ArkaKapiKapat")//burayada
     {
       for (pos = 180; pos >= 0; pos -= 1)
       { 
         myservo.write(pos);          
       }
       state="";
     }
  
   
     

  }

  }

  void playTone(long duration, int freq) {
duration *= 2000;
int period = (1.0 / freq) * 1000000;
long elapsed_time = 0;
while (elapsed_time < duration) {
digitalWrite(pinSpeaker,HIGH);
digitalWrite(led5,HIGH);
delayMicroseconds(period / 2);
digitalWrite(pinSpeaker, LOW);
digitalWrite(led5,LOW);
delayMicroseconds(period / 2);
elapsed_time += (period);
}
}
