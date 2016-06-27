#include <OneWire.h>
#include <LiquidCrystal.h>

//  ___  ___  _   __   _   ___          _ 
// | __|| __|/ | /  \ / | | __|__  __ _| |_  ___  __ _
// | _| | _| | || () || | | _| \ \/ /|_   _||  _|/ _` |
// |___||___||_| \__/ |_| |___|/_/\_\  |_|  |_|  \__,_|
//
// Crock-Pot Sous-Vide Cooker
// Carlo Giorelli

float SetTemp = 150; // This is the temperature that the water needs to be
bool debug = true; // Only functions if debug is on. I believe this is due to the serial write being required.

#define D7 2
#define D6 3
#define D5 4
#define D4 5
#define Enable 6
#define RS 7
#define Relay_NO 10 //Normally Open pin for the relay.
#define DA18B20 11 //The Signal Wire of the 1wire Temp sensor
#define Board_led 13

OneWire ds(DA18B20);
LiquidCrystal lcd(RS,Enable,D4,D5,D6,D7);
char outPins[] = {Relay_NO,Board_led}; //An array of pins that get set to OUTPUT mode

void heat(){analogWrite(Relay_NO, 255);}
void cool(){analogWrite(Relay_NO, 0);}

float read_temp(){
  ds.reset();
  byte data[12];
  byte addr[2];
  float celsius, fahrenheit;
  
  if ( !ds.search(addr)) {
    ds.reset_search();
    delay(250);
    //return;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1); 
  delay(1000);
  ds.reset();
  ds.select(addr);    
  ds.write(0xBE);     
  for (byte i = 0; i < 9; i++) {
    data[i] = ds.read();
  }
  int16_t raw = (data[1] << 8) | data[0];
  celsius = (float)raw / 16.0;
  fahrenheit = celsius * 1.8 + 32.0;
  return fahrenheit;
}

void setup() {
  for(int i = 0;i < sizeof(outPins);i++){pinMode(outPins[i],OUTPUT);}
  if(debug){Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Set:");
  lcd.setCursor(9,0);
  lcd.print(SetTemp);
  lcd.setCursor(0,1);
  lcd.print("Current:");
  digitalWrite(Board_led, LOW);
  } 
}
float current_temp;

void loop() {
  current_temp = read_temp();
  lcd.setCursor(9,1);
  lcd.print(current_temp);
  if ( current_temp < (SetTemp+2)){
    heat();
    if (debug){
      Serial.print("  Heating \n");
      Serial.print("Current Temp: ");
      Serial.print(current_temp);
      Serial.print(" F  Set to: ");
      Serial.print(SetTemp);
      Serial.print(" F \n\n");
      }
    
   }
  else if ( current_temp > (SetTemp+2)){
    cool();
    if (debug){
      Serial.print("  Cooling \n");
      Serial.print("Current Temp: ");
      Serial.print(current_temp);
      Serial.print(" F  Set to: ");
      Serial.print(SetTemp);
      Serial.print(" F \n\n");
      }
    }
}
