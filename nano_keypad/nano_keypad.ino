#include <Keypad.h>

char tus;
char tus_takimi[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte satir_pinleri[4] = {9, 8, 7, 6};
byte sutun_pinleri[4] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(tus_takimi), satir_pinleri, sutun_pinleri, 4, 4);

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  char key = keypad.getKey();
  if(key){
    Serial.write(key);
  }
  delay(50);
}
