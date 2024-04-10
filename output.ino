#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"
int ir1=2;
int ir2=3;
int ir3=5;
int ir4=6;


TMRpcm tmrpcm;

void setup(){
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  pinMode(ir4,INPUT);
tmrpcm.speakerPin = 9;
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}   tmrpcm.setVolume(5);
    /*tmrpcm.play("A.wav");
    delay(1000);tmrpcm.play("B.wav");
    delay(1000);tmrpcm.play("C.wav");
    delay(1000);tmrpcm.play("D.wav");
    delay(1000);tmrpcm.play("E.wav");
    delay(1000);tmrpcm.play("F.wav");
    delay(1000);tmrpcm.play("G.wav");*/
    
}

void loop(){  tmrpcm.stopPlayback();
     
     if ((digitalRead(ir1)==1)&&(digitalRead(ir3)==0)&&(digitalRead(ir4)==0))
          {  delay(100);
              if (digitalRead(ir2)==1)  
                   {  tmrpcm.play("G.wav"); delay(500); } 
              else  if (digitalRead(ir2)==0)
                   {  tmrpcm.play("C.wav"); delay(500); } }
      if ((digitalRead(ir2)==1)&&(digitalRead(ir4)==0))
          {  delay(100);
                if ((digitalRead(ir1)==1)&&(digitalRead(ir3)==0))
                   {  tmrpcm.play("G.wav"); delay(500); } 
                else if ((digitalRead(ir1)==0)&&(digitalRead(ir3)==1))
                   {  tmrpcm.play("A.wav"); delay(500); }
                else if ((digitalRead(ir1)==0)&&(digitalRead(ir3)==0))
                   {  tmrpcm.play("D.wav"); delay(500); } }
      if ((digitalRead(ir3)==1)&&(digitalRead(ir1)==0))
          {  delay(100);
                if ((digitalRead(ir2)==1)&&(digitalRead(ir4)==0))
                   {  tmrpcm.play("A.wav"); delay(500); } 
                else if ((digitalRead(ir2)==0)&&(digitalRead(ir4)==1))
                   {  tmrpcm.play("B.wav"); delay(500); }
                else if ((digitalRead(ir2)==0)&&(digitalRead(ir4)==0))
                   {  tmrpcm.play("E.wav"); delay(500); } }
       if ((digitalRead(ir4)==1)&&(digitalRead(ir2)==0)&&(digitalRead(ir1)==0))
          {  delay(100);
              if (digitalRead(ir3)==1)  
                   {  tmrpcm.play("B.wav"); delay(500); } 
              else  if (digitalRead(ir2)==0)
                   {  tmrpcm.play("F.wav"); delay(500); } }
        
 /* else if ((digitalRead(ir1)==0)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==0)&&(digitalRead(ir4)==0))
  { 
    tmrpcm.play("D.wav"); delay(500); }
  else if ((digitalRead(ir1)==0)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==0))
  {  
    tmrpcm.play("E.wav"); delay(500);}
  else if ((digitalRead(ir1)==0)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==0)&&(digitalRead(ir4)==1))
  {  
    tmrpcm.play("F.wav"); delay(500);}
  else if ((digitalRead(ir1)==1)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==0)&&(digitalRead(ir4)==0))
  {  
    tmrpcm.play("G.wav"); delay(500);}
  else if ((digitalRead(ir1)==0)&&(digitalRead(ir2)==1)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==0))
  {  
    tmrpcm.play("A.wav"); delay(500);}
  else if ((digitalRead(ir1)==0)&&(digitalRead(ir2)==0)&&(digitalRead(ir3)==1)&&(digitalRead(ir4)==1))
  { 
    tmrpcm.play("B.wav"); delay(500);} */
    }
