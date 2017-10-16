#include <LiquidCrystal.h>
#include <TimerOne.h>
#include <Wire.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

const int btn = 8;
const int rst = 9;
const int bs = 3;
const int nModes= 3; //Numero de Modos
int h = 0;
int m = 0;
volatile int s = 0;
volatile int mode = 0;
volatile bool update = false;
volatile bool pause = false;
char clockText[10];
String modeText = "p";

void setup(){
    Wire.begin();
    lcd.begin(16, 2);
    pinMode(btn, INPUT);
    pinMode(rst, INPUT);
    pinMode(bs, OUTPUT);
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(secs);
}
void secs(){
    if(pause == false){
      s++;
      update = true;
    }
}
void updateClock(){
    m += s / 60;
    s = s % 60;
    h += m / 60;
    m = m % 60;
    h = h % 24;
    
    if(s == 0){
        playSound();
    }
    if(s<0){
        s = 0;
    }
}

void playSound(){//reproducir sonido en buzzer(bs) pin#3
    tone(bs, 900, 300);
}

void change(){
    mode++;
    mode = mode % nModes;
    update=true;
    switch(mode){ //Mostrar texto opcional sobre el modo
        case 0: modeText= "p"; //p Pausa
        break;
        case 1: modeText = "r";//r Reset
        break;
        case 2: modeText = "N";//N None
        break;
    }
    lcd.clear();
    sendPrint();
}
void setMode(){
    lcd.clear();
    switch(mode){
    case 0 ://Si modo == 0 pausa
        pause = !pause;
        if(pause==true){
            lcd.print("    Pausado");
        }else{
            lcd.clear();
            sendPrint();
        }
    break;
    case 1://Si modo == 1 reset
        s=0;m=0;h=0;
        sendPrint();
    break;
    case 2: break;// Si modo == 2 do something
     }
    
}

void sendPrint(){ //Imprimir variables en lcd (Cambiar funcion para imprimir en otro lado o solo guardar los datos
    lcd.setCursor(4,0);
      sprintf(clockText, "%02d:%02d:%02d", h,m,s);
        lcd.print(clockText);
        lcd.setCursor(15, 0);
        lcd.print(modeText);
}

void loop(){
    if(digitalRead(btn)==HIGH){//Boton para cambiar de modos
        delay(20);
        digitalWrite(btn, HIGH);
       change();
    while(digitalRead(btn)==HIGH);
    }
    if(digitalRead(rst)==HIGH){//Boton para seleccionar modo
        delay(20);
        digitalWrite(rst, HIGH);
        setMode();
        while(digitalRead(rst)==HIGH);
    }
    
   if(update==true){
      lcd.clear();
      updateClock();
      sendPrint();
      update=false;
   }
}
