#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
int lock =A0;

char keys[ROWS][COLS] = {
  {'#','0','*'},
  {'9','8','7'},
  {'6','5','4'},
  {'3','2','1'}
};

char key_code[3];
char password[3]={'3','2','1'};

unsigned int k=0;
unsigned int i=0;

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  pinMode(lock, OUTPUT);
  digitalWrite(lock,HIGH);
}

void loop(){
  char key = keypad.getKey();
   
    if(key != NO_KEY){
    Serial.println(key);
    Serial.println("pressed:");    
    Serial.print(i);    
    key_code[i++]=key;
     k=i;
    delay(200);
    digitalWrite(lock, HIGH);
      }
     
 if(k==3){
   //if(key_code[0]=='3'&&key_code[1]=='2'&&key_code[2]=='1')
   if(!(strncmp(password, key_code,3)))
   {
    Serial.println("in conditon");
    //delay(1000);
    digitalWrite(lock, LOW);
    Serial.println("lock high");
    delay(1000);
    digitalWrite(lock, HIGH); 
    Serial.println("lock low");
    delay(1000);
    i=k=0;
   }
  }
}

  
