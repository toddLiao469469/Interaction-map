
//六個燈在shift register的狀態
const char LED[7]={0x01,0x02,0x04,0x08,0x10,0x20,0x00};
//74HC595的三個腳位
const int dataPin = 4; 
const int clockPin = 2;
const int latchPin  = 3;
//六個按鈕
const char Button[6]={3,4,5,6,7,8};


void setup(){
    for(i=0;i<sizeof(Button);i++){
        pinMode(Button[i],INPUT);
    }
    pinMode(dataPin,OUTPUT);
    pinMode(clockPin,OUTPUT);
    pinMode(latchPin,OUTPUT);


}



void loop()
{
    for(i=0;i<sizeof(Button);i++){
        if(digitalRead(Button[i])==HIGH){
            shiftOut(dataPin, clockPin, LSBFIRST,LED[i]);   //從左邊讀取LED[i]的資料 
            
        }
    }   
    
}

void PlayMusic(int fileOrder){
    
}