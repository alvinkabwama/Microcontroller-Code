#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
//#define SD_ChipSelectPin 10  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...

TMRpcm tmrpcm;   // create an object for use in this sketch
char mychar;

void setup(){

  tmrpcm.speakerPin = 11; //11 on Mega, 9 on Uno, Nano, etc

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  tmrpcm.play("6.wav"); //the sound file "music" will play each time the arduino powers up, or is reset
}

void loop(){  

  if(Serial.available()){   
    mychar = Serial.read();

    if(mychar == 'o'){ //send the letter p over the serial monitor to start playback
      tmrpcm.play("1.wav");
      Serial.println("ONE PLAYED");
    } else if(mychar == 'r'){ //send the letter p over the serial monitor to start playback
      tmrpcm.play("2.wav");
    } else if(mychar == 'q'){ //send the letter p over the serial monitor to start playback
      tmrpcm.play("3.wav");
    } else if(mychar == 'p'){
      tmrpcm.play("4.wav");
    }
    else if(mychar == 'w'){ //send the letter p over the serial monitor to start playback
      tmrpcm.play("5.wav");
    }
    else if(mychar == 't'){ //send the letter p over the serial monitor to start playback
      tmrpcm.play("6.wav");
    }
    else if(mychar == 'y'){ //send the letter p over the serial monitor to start playback
      tmrpcm.play("1.wav");
    }
    else if(mychar == 'u'){ //send the letter p over the serial monitor to start playback
      tmrpcm.play("2.wav");
    }
    else if(mychar == 'i'){ //send the letter p over the serial monitor to start playback
      tmrpcm.play("3.wav");
    }
  }

}
