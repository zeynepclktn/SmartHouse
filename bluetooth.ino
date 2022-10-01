#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo;
Servo myservo1;
 int ldrPin=A2;  //LDR Bahçe Işıkları
int ldrDeger=0; //LDR Bahçe Işıkları
int esikDeger=50; //LDR Bahçe Işıkları
int led=2; //Bluetooth 
int pos = 9;  //Bluetooth 
int pos2 = 10;  
String data; //Bluetooth 
int PIRpini = 8; // PIR Bağalacak pin   // hareket sensörü
int OkunanDeger; //hareket sensçrü

void setup() {
   pinMode(12, OUTPUT); //LDR Bahçe Işıkları
  Serial.begin(9600);
   myservo.attach(9); //Bluetooth
   myservo1.attach(10); 
  pinMode(13, OUTPUT); //LED için Pin 13 modunu çıkış olarak belirler //hareket sensörü
Serial.begin(9600);
}
void loop() { 
  ldrDeger=analogRead(ldrPin);  //LDR Bahçe Işıkları
  if(ldrDeger<esikDeger){ //LDR Bahçe Işıkları
    digitalWrite(12, LOW);
     Serial.println("Karanlık");
     //LDR Bahçe Işıkları
  } //LDR Bahçe Işıkları
  else{ //LDR Bahçe Işıkları
    
    digitalWrite(12, HIGH);//LDR Bahçe Işıkları
     Serial.println("Aydınlık");
  }

  OkunanDeger = digitalRead(PIRpini); //PIR durumunu oku // Hareket Sensörü
  
  if (OkunanDeger == LOW) { //Hareket Sensörü
  //  Serial.println("Hareket yok"); //Değer düşük ise hareket yok yaz //Hareket Sensörü
  }
  else {
   // Serial.println("Hirsiz Var!"); //Değer yüksek ise hareket var. //Hareket Sensörü
//  Ses / Cızırtı
//  tone (pin no, Hz olarak ses frekansı, ms olarak süre) 
  tone(5, 100, 50); //Hareket Sensörü
  delay (100); //Hareket Sensörü
  tone(5, 200, 100); //Hareket Sensörü
  delay (100); //Hareket Sensörü
  tone(5, 100, 50);  //Hareket Sensörü
  }

 if (Serial.available()){ //Bluetooth 
    
     delay(10); //Bluetooth 
     char c=Serial.read(); //Bluetooth 
     data+=c;  //Bluetooth 

   
   if(data=="Led1Ac"){ //Bluetooth 
     digitalWrite(led,1); //Bluetooth 
      data="";  //Bluetooth 
   }
      if(data=="Led1Kapat"){ //Bluetooth 
     digitalWrite(led,0); //Bluetooth 
      data="";  //Bluetooth 
   }
       if(data=="Motor1Ac") //Bluetooth 
     { 
        for (pos = 0; pos <= 180; pos += 1) //Bluetooth 
        { 
           myservo.write(pos);              //Bluetooth        
        }
      data="";  //Bluetooth 
     }
      if(data=="Motor1Kapat")//burayada //Bluetooth 
     {
       for (pos = 180; pos >= 0; pos -= 1) //Bluetooth 
       { 
         myservo.write(pos);          //Bluetooth 
       }
        data=""; //Bluetooth 
     }
     if(data=="Motor2Ac") //Bluetooth 
     { 
        for (pos2 = 0; pos2 <= 180; pos2 += 1) //Bluetooth 
        { 
           myservo1.write(pos2);              //Bluetooth        
        }
      data="";  //Bluetooth 
     }
      if(data=="Motor2Kapat") //Bluetooth 
     {
       for (pos2 = 180; pos2 >= 0; pos2 -= 1) //Bluetooth 
       { 
         myservo1.write(pos2);          //Bluetooth 
      
       }
        data=""; //Bluetooth 
         myservo1.write(0); 
     }
     delay(100); //Bluetooth  
  }
}






  

