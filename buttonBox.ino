#inlude <Keypad.h>

int buttonToggle = 0;
int prevValue = 0;

const byte ROWS = 3;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5', '6','7'},
  {'8','9','A','B'},
};

byte colPins[COLS] = {A0, A1, A2, A3}; //connect to the row pinouts of the keypad
byte rowPins[ROWS]= {10,11,12}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


void setup(){
  Serial.begin(9600);
  pinMode(A5, INPUT);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
}
c
