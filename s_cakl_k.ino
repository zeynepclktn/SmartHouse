#include <LiquidCrystal.h> //sıcaklıksensoru
int lm35Pin = A0; //sıcaklıksensoru
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //sıcaklıksensoru
const int prob = A1;  // sensörümüzden gelen veri ucuna A0 pini atandı 

int olcum_sonucu;     // toprağa giren probdan gelen verilerin kayıt edildiği
     
int klima=7;                // değişkenimiz

void setup() 
{
 
  lcd.begin(16, 2); //sıcaklıksensoru
  analogReference(INTERNAL); //sıcaklıksensoru
  lcd.print("Sicaklik:"); //sıcaklıksensoru

  pinMode(klima,OUTPUT);  

}
 
void loop()
{
  
  //digitalWrite(klima,1);
  int sicaklikVolt = analogRead(lm35Pin); //sıcaklıksensoru 
  float sicaklikC = sicaklikC = sicaklikVolt / 9.31;  //sıcaklıksensoru
  lcd.setCursor(9, 0); //sıcaklıksensoru
  lcd.print(sicaklikC); //sıcaklıksensoru
  lcd.setCursor(14,0); //sıcaklıksensoru
 // lcd.print("/337C"); //sıcaklıksensoru
  delay(100); //sıcaklıksensoru
  olcum_sonucu = analogRead(prob); // prob pininden okunan veriyi ölçüm sonucuna kayıt ediyoruz //Nemsensoru
  lcd.setCursor(-1, 1); ////Nemsensoru
  lcd.print("Nem= "); //Nemsensoru
   lcd.setCursor(4,1); ////Nemsensoru
 lcd.print(olcum_sonucu); // Ölçülen değeri seri monitöre yazdırıyoruz //Nemsensoru
 delay(500); // seri monitördeki verileri rahat görebilmek veri için akışı yavaşlatıyoruz //Nemsensoru
 if (sicaklikC > 25){ 
digitalWrite(klima,1); // Klimayı çalıştır
}


}


