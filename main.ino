#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

//六個燈在shift register的狀態
const char LED[7]={0x01,0x02,0x04,0x08,0x10,0x20,0x00};
//74HC595的三個腳位
const int dataPin = 4; 
const int clockPin = 2;
const int latchPin  = 3;
//六個按鈕
const char Button[6]={5,6,7,8,9,10};

const char rxpin = 12;
const char txpin = 11;
SoftwareSerial mySerial(rxpin, txpin); // RX, TX

void setup(){
    pinMode(rxpin, INPUT);
    pinMode(txpin, OUTPUT);
    mySerial.begin (9600);
    mp3_set_serial (mySerial);  //set softwareSerial for DFPlayer-mini mp3 module 
    Serial.begin(115200);
    
    for(int i=0;i<sizeof(Button);i++){
        pinMode(Button[i],INPUT);
    }
    pinMode(dataPin,OUTPUT);
    pinMode(clockPin,OUTPUT);
    pinMode(latchPin,OUTPUT);

    mp3_set_volume (30);
}

void loop(){
    for(int Order=0;Order<6;Order++){
        int mp3Order = Order + 1 ;
        if(digitalRead(Button[Order] == HIGH)){
            
            
            LEDPlay(Order)
            MP3Play(mp3Order);
            LEDClose();
            
            delay(100);
        }
    }   
}

void LEDPlay(int Order){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, LED[Order]);
    digitalWrite(latchPin, HIGH); 
}

void LEDClose(void){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, LED[]);
    digitalWrite(latchPin, HIGH); 
}

void MP3Play(int Order){
    switch(Order){
        mp3_play(Order);
            case 1:
                delay(10000);
                break;
            case 2:
                delay(10000);
                break;
            case 3:
                delay(10000);
                break;
            case 4:
                delay(10000);
                break;
             case 5:
                delay(10000);
                break;
            case 6:
                delay(10000);
                break;
    }
}