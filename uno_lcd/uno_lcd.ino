#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char key;
int fonk=1;

String tanim = "";

float tanim_kumesi;
float goruntu_kumesi;

void baslangic(){
  while(true){
    lcd.home();
    lcd.print("Fonksiyon");
    lcd.setCursor(0,1);
    lcd.print("Makinesi");
    
    if(Serial.available()){
      key = Serial.read();
      if(key=='A'){
        lcd.clear();
        break;
      }
    }
  }
}

void fonksec(){
  while(true){
    lcd.home();
    lcd.print("Fonksiyon sec");
    lcd.setCursor(0,1);
    lcd.print(fonk);
    lcd.print(". ");
    if(fonk==1) lcd.print("f(x)=x+x^2");
    if(fonk==2) lcd.print("f(x)=(x-6x)/2");
    if(fonk==3) lcd.print("f(x)=2x*3x");
    if(fonk==4) lcd.print("f(x)=(3x-5)/x");
    
    if(Serial.available()){
      key=Serial.read();
      if(key=='B'){
       delay(50);
       if(fonk==1) fonk=4;
       else fonk=fonk-1;
       lcd.clear();
       delay(50);
    }
      if(key=='C'){
       delay(50);
       if(fonk==4) fonk=1;
       else fonk=fonk+1;
       lcd.clear();
       delay(50);
    }
      if(key=='A'){
        lcd.clear();
        tanim="";
        break;
      }
    }    
  }  
}

float f(float x){
  return x+(x*x);
}

float g(float x){
  return (x-6*x)/2;
}

float h(float x){
  return (2*x)*(3*x);
}

float t(float x){
  return (3*x)/x;
}

void degergir(){
  while(true){
   lcd.home();
   lcd.print("Deger gir");
   
   if(Serial.available()){
    key=Serial.read();
    if(key=='A') islem();
    else if(key=='B');
    else if(key=='C');
    else if(key=='D') fonksec();
    else if(key=='*'){tanim = "";}
    else if(key=='#'){tanim = tanim + ".";}
    else{tanim = tanim + key;}
    
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(tanim);
  }
  delay(50);
  }
}

void islem(){
  lcd.clear();
  while(true){
    tanim_kumesi = tanim.toFloat();
    if(fonk==1) goruntu_kumesi=f(tanim_kumesi);
    if(fonk==2) goruntu_kumesi=g(tanim_kumesi);
    if(fonk==3) goruntu_kumesi=h(tanim_kumesi);
    if(fonk==4) goruntu_kumesi=t(tanim_kumesi);
  
    lcd.setCursor(0,0);
    lcd.print("Tanim");
    lcd.print(tanim_kumesi);
    lcd.setCursor(0,1);
    lcd.print("Goruntu ");
    lcd.print(goruntu_kumesi);
    delay(50);
    if(Serial.available()){
      key=Serial.read();
      if(key=='D'){
        tanim = "";
        break;
      }
    }
  }
}

void setup() {
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
  
  baslangic();
  delay(50);
  fonksec();

}

void loop() {
  degergir();
  delay(50);
}
