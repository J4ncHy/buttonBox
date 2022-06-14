
//BUTTON BOX 
//Tested in WIN10 + Assetto Corsa
//AMSTUDIO
//20.8.17
#include <Joystick.h>
#include <Keypad.h>


#define ENABLE_PULLUPS
#define NUMBUTTONS 16
#define NUMROWS 4
#define NUMCOLS 4
#define NUMROTARIES 4


byte buttons[NUMROWS][NUMCOLS] = {
  {0,1,2,3},
  {4,5,6,7},
  {8,9,10,11},
  {12,13,14,15},
};

struct rotariesdef {
  byte pin1;
  byte pin2;
  int ccwchar;
  int cwchar;
  volatile unsigned char state;
};


rotariesdef rotaries[NUMROTARIES] {
  
  {0,1,16,17,0},
  {2,3,18,19,0},
  {5,6,20,21,0},
  {A0,A1,22,23,0},
};

#define DIR_CCW 0x10
#define DIR_CW 0x20
#define R_START 0x0

#ifdef HALF_STEP
#define R_CCW_BEGIN 0x1
#define R_CW_BEGIN 0x2
#define R_START_M 0x3
#define R_CW_BEGIN_M 0x4
#define R_CCW_BEGIN_M 0x5
const unsigned char ttable[6][4] = {
  // R_START (00)
  {R_START_M,            R_CW_BEGIN,     R_CCW_BEGIN,  R_START},
  // R_CCW_BEGIN
  {R_START_M | DIR_CCW, R_START,        R_CCW_BEGIN,  R_START},
  // R_CW_BEGIN
  {R_START_M | DIR_CW,  R_CW_BEGIN,     R_START,      R_START},
  // R_START_M (11)
  {R_START_M,            R_CCW_BEGIN_M,  R_CW_BEGIN_M, R_START},
  // R_CW_BEGIN_M
  {R_START_M,            R_START_M,      R_CW_BEGIN_M, R_START | DIR_CW},
  // R_CCW_BEGIN_M
  {R_START_M,            R_CCW_BEGIN_M,  R_START_M,    R_START | DIR_CCW},
};
#else,
#define R_CW_FINAL 0x1
#define R_CW_BEGIN 0x2
#define R_CW_NEXT 0x3
#define R_CCW_BEGIN 0x4
#define R_CCW_FINAL 0x5
#define R_CCW_NEXT 0x6

const unsigned char ttable[7][4] = {
  // R_START
  {R_START,    R_CW_BEGIN,  R_CCW_BEGIN, R_START},
  // R_CW_FINAL
  {R_CW_NEXT,  R_START,     R_CW_FINAL,  R_START | DIR_CW},
  // R_CW_BEGIN
  {R_CW_NEXT,  R_CW_BEGIN,  R_START,     R_START},
  // R_CW_NEXT
  {R_CW_NEXT,  R_CW_BEGIN,  R_CW_FINAL,  R_START},
  // R_CCW_BEGIN
  {R_CCW_NEXT, R_START,     R_CCW_BEGIN, R_START},
  // R_CCW_FINAL
  {R_CCW_NEXT, R_CCW_FINAL, R_START,     R_START | DIR_CCW},
  // R_CCW_NEXT
  {R_CCW_NEXT, R_CCW_FINAL, R_CCW_BEGIN, R_START},
};
#endif

byte colPins[NUMCOLS] = {4,7,8,9}; 
byte rowPins[NUMROWS] = {14,10,16,15}; 

Keypad buttbx = Keypad( makeKeymap(buttons), rowPins, colPins, NUMROWS, NUMCOLS); 

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_JOYSTICK, 39, 0,
  false, false, false, false, false, false,
  false, false, false, false, false);

void setup() {
  Joystick.begin();
  rotary_init();
}

void loop() { 

  CheckAllEncoders();

  CheckAllButtons();
}

int potentiometerButtons(int val){

  int x = 1024 / 15;
  
  if (val < 1*x){
      return 1;
  }else if(val > 1*x && val <= 2*x){
      return 2;
  }else if(val > 2*x && val <= 3*x){
      return 3;
  }else if(val > 3*x && val <= 4*x){
      return 4;
  }else if(val > 4*x && val <= 5*x){
      return 5;
  }else if(val > 5*x && val <= 6*x){
      return 6;
  }else if(val > 6*x && val <= 7*x){
      return 7;
  }else if(val > 7*x && val <= 8*x){
      return 8;
  }else if(val > 8*x && val <= 9*x){
      return 9;
  }else if(val > 9*x && val <= 10*x){
      return 10;
  }else if(val > 10*x && val <= 11*x){
      return 11;
  }else if(val > 11*x && val <= 12*x){
      return 12;
  }else if(val > 12*x && val <= 13*x){
      return 13;
  }else if(val > 13*x && val <= 14*x){
      return 14;
  }else if(val > 14*x){
      return 15;
  }
  return 0;
}

void CheckAllButtons(void) {
      if (buttbx.getKeys())
    {
       for (int i=0; i<LIST_MAX; i++)   
        {
           if ( buttbx.key[i].stateChanged )   
            {
            switch (buttbx.key[i].kstate) {  
                    case PRESSED:
                    case HOLD:
                              Joystick.setButton(buttbx.key[i].kchar, 1);
                              break;
                    case RELEASED:
                    case IDLE:
                              Joystick.setButton(buttbx.key[i].kchar, 0);
                              break;
            }
           }   
         }
     }
     
     /*int val = analogRead(A2);
     int prevButton = 0;
     int button = potentiometerButtons(val);
     Serial.println(button);
     
     for(int i = 0; i < 15; i++){
        Joystick.setButton(23+i,0);
     }
     if(button != 0 && prevButton != button){
      Serial.println("diff");
      Joystick.setButton(23+button,1);
      prevButton = button;
     }*/
  }

  void rotary_init() {
  for (int i=0;i<NUMROTARIES;i++) {
    pinMode(rotaries[i].pin1, INPUT);
    pinMode(rotaries[i].pin2, INPUT);
    #ifdef ENABLE_PULLUPS
      digitalWrite(rotaries[i].pin1, HIGH);
      digitalWrite(rotaries[i].pin2, HIGH);
    #endif
  }
}


unsigned char rotary_process(int _i) {
   unsigned char pinstate = (digitalRead(rotaries[_i].pin2) << 1) | digitalRead(rotaries[_i].pin1);
  rotaries[_i].state = ttable[rotaries[_i].state & 0xf][pinstate];
  return (rotaries[_i].state & 0x30);
}

void CheckAllEncoders(void) {
  for (int i=0;i<NUMROTARIES;i++) {
    unsigned char result = rotary_process(i);
    if (result == DIR_CCW) {
      Joystick.setButton(rotaries[i].ccwchar, 1); delay(50); Joystick.setButton(rotaries[i].ccwchar, 0);
    };
    if (result == DIR_CW) {
      Joystick.setButton(rotaries[i].cwchar, 1); delay(50); Joystick.setButton(rotaries[i].cwchar, 0);
    };
  }
}
