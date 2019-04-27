int SET1RIGHT = 22;
int SET1RED = 24;
int SET1YELLOW = 26;
int SET1DOWN =28;
int SET1LEFT = 30;
int SET1GREEN = 32;

int SET2RIGHT = 46;
int SET2RED = 48;
int SET2YELLOW = 42;

int SET2DOWN =40;
int SET2LEFT = 38;
int SET2GREEN = 36;

int SET1PEDRED = 33;
int SET1PEDGREEN = 31;
int SET2PEDRED = 35;
int SET2PEDGREEN = 37;



int OVERRIDELED = 23;

int MODE0RANGESWITCH = 14;
int MODE1SWITCH = 15;
int MODE2SWITCH = 17;
int MODE3SWITCH = 19;
int MODE4SWITCH = 16;
int MODE5SWITCH = 18;
int OVSWITCH = 20;




int remember_state=0;

int timedelay = 10;
int loopcounter = 1000;
int loopcounter_main = 1500;



void setup()
{
  Serial.begin(9600);
  for(int n=22; n<49; n++)
  {
   pinMode(n, OUTPUT); 
  }
  
  for(int k=14; k<21; k++)
  {
   pinMode(k, INPUT); 
  }
  
   
}

 void MODE1(void)
 {
  digitalWrite(SET1RIGHT,LOW);
  digitalWrite(SET1RED,LOW);
  digitalWrite(SET1YELLOW,LOW);
  digitalWrite(SET1DOWN,HIGH);
  digitalWrite(SET1LEFT,LOW);
  digitalWrite(SET1GREEN,HIGH);
  
  digitalWrite(SET1PEDRED, HIGH);
  digitalWrite(SET1PEDGREEN, LOW);
  digitalWrite(SET2PEDRED, LOW);
  digitalWrite(SET2PEDGREEN,HIGH);
   
  digitalWrite(SET2RIGHT,LOW);
  digitalWrite(SET2RED,HIGH);
  digitalWrite(SET2YELLOW,LOW);
  digitalWrite(SET2DOWN,LOW);
  digitalWrite(SET2LEFT,LOW);
  digitalWrite(SET2GREEN,LOW);
 }
 
 
 void MODE2(void)
 {
  digitalWrite(SET1RIGHT,HIGH);
  digitalWrite(SET1RED,HIGH);
  digitalWrite(SET1YELLOW,LOW);
  digitalWrite(SET1DOWN,LOW);
  digitalWrite(SET1LEFT,LOW);
  digitalWrite(SET1GREEN,LOW);
  
  digitalWrite(SET1PEDRED, HIGH);
  digitalWrite(SET1PEDGREEN, LOW);
  digitalWrite(SET2PEDRED, HIGH);
  digitalWrite(SET2PEDGREEN,LOW);
  
  digitalWrite(SET2RIGHT,LOW);
  digitalWrite(SET2RED,HIGH);
  digitalWrite(SET2YELLOW,LOW);
  digitalWrite(SET2DOWN,LOW);
  digitalWrite(SET2LEFT,LOW);
  digitalWrite(SET2GREEN,LOW);
 }
 
 
 
 void MODE3(void)
 {
  digitalWrite(SET2RIGHT,LOW);
  digitalWrite(SET2RED,LOW);
  digitalWrite(SET2YELLOW,LOW);
  digitalWrite(SET2DOWN,HIGH);
  digitalWrite(SET2LEFT,LOW);
  digitalWrite(SET2GREEN,HIGH);
  
  digitalWrite(SET1PEDRED, LOW);
  digitalWrite(SET1PEDGREEN, HIGH);
  digitalWrite(SET2PEDRED, HIGH);
  digitalWrite(SET2PEDGREEN,LOW);
  
  
  digitalWrite(SET1RIGHT,LOW);
  digitalWrite(SET1RED,HIGH);
  digitalWrite(SET1YELLOW,LOW);
  digitalWrite(SET1DOWN,LOW);
  digitalWrite(SET1LEFT,LOW);
  digitalWrite(SET1GREEN,LOW);
 }
 
 void MODE4(void)
 {
  digitalWrite(SET2RIGHT,HIGH);
  digitalWrite(SET2RED,HIGH);
  digitalWrite(SET2YELLOW,LOW);
  digitalWrite(SET2DOWN,LOW);
  digitalWrite(SET2LEFT,LOW);
  digitalWrite(SET2GREEN,LOW);
  
  digitalWrite(SET1PEDRED, HIGH);
  digitalWrite(SET1PEDGREEN, LOW);
  digitalWrite(SET2PEDRED, HIGH);
  digitalWrite(SET2PEDGREEN,LOW);
  
  digitalWrite(SET1RIGHT,LOW);
  digitalWrite(SET1RED,HIGH);
  digitalWrite(SET1YELLOW,LOW);
  digitalWrite(SET1DOWN,LOW);
  digitalWrite(SET1LEFT,LOW);
  digitalWrite(SET1GREEN,LOW);
 }
 
 void MODE5(void)
 {
  digitalWrite(SET2RIGHT,LOW);
  digitalWrite(SET2RED, HIGH);
  digitalWrite(SET2YELLOW,LOW);
  digitalWrite(SET2DOWN,LOW);
  digitalWrite(SET2LEFT,HIGH);
  digitalWrite(SET2GREEN,LOW);
  
  digitalWrite(SET1PEDRED, HIGH);
  digitalWrite(SET1PEDGREEN, LOW);
  digitalWrite(SET2PEDRED, HIGH);
  digitalWrite(SET2PEDGREEN,LOW);
  
  
  digitalWrite(SET1RIGHT,LOW);
  digitalWrite(SET1RED,HIGH);
  digitalWrite(SET1YELLOW,LOW);
  digitalWrite(SET1DOWN,LOW);
  digitalWrite(SET1LEFT,HIGH);
  digitalWrite(SET1GREEN,LOW);
 }
 
 void SET1ORANGE(void)
 {
  digitalWrite(SET1RIGHT,LOW);
  digitalWrite(SET1RED,LOW);
  digitalWrite(SET1YELLOW,HIGH);
  digitalWrite(SET1DOWN,LOW);
  digitalWrite(SET1LEFT,LOW);
  digitalWrite(SET1GREEN,LOW);
  
  
  digitalWrite(SET2RIGHT,LOW);
  digitalWrite(SET2RED,HIGH);
  digitalWrite(SET2YELLOW,LOW);
  digitalWrite(SET2DOWN,LOW);
  digitalWrite(SET2LEFT,LOW);
  digitalWrite(SET2GREEN,LOW);
 }
 
 void SET2ORANGE(void)
 {
  digitalWrite(SET1RIGHT,LOW);
  digitalWrite(SET1RED,HIGH);
  digitalWrite(SET1YELLOW,LOW);
  digitalWrite(SET1DOWN,LOW);
  digitalWrite(SET1LEFT,LOW);
  digitalWrite(SET1GREEN,LOW);
  
  
  digitalWrite(SET2RIGHT,LOW);
  digitalWrite(SET2RED,LOW);
  digitalWrite(SET2YELLOW,HIGH);
  digitalWrite(SET2DOWN,LOW);
  digitalWrite(SET2LEFT,LOW);
  digitalWrite(SET2GREEN,LOW);
 }
 
 void MODEORANGE(void)
 {
   digitalWrite(SET1RIGHT,LOW);
  digitalWrite(SET1RED,LOW);
  digitalWrite(SET1YELLOW,HIGH);
  digitalWrite(SET1DOWN,LOW);
  digitalWrite(SET1LEFT,LOW);
  digitalWrite(SET1GREEN,LOW);
  
  digitalWrite(SET1PEDRED, HIGH);
  digitalWrite(SET1PEDGREEN, LOW);
  digitalWrite(SET2PEDRED, HIGH);
  digitalWrite(SET2PEDGREEN,LOW);
  
  
  
  digitalWrite(SET2RIGHT,LOW);
  digitalWrite(SET2RED,LOW);
  digitalWrite(SET2YELLOW,HIGH);
  digitalWrite(SET2DOWN,LOW);
  digitalWrite(SET2LEFT,LOW);
  digitalWrite(SET2GREEN,LOW);
 }
 
  
void modeswitchcheck(void)
{
  if(digitalRead(OVSWITCH) == 1)
  {
    if(remember_state == 0)
    {
     remember_state = 1;
    delay(500);
    }
    else
    {
    remember_state = 0;
    delay(500);
    }
  }
}

void loop()
{
  
   while(remember_state==1)
  {Serial.println("MANUAL");
    
    digitalWrite(OVERRIDELED, HIGH);
    
    
  if(digitalRead(MODE1SWITCH) == 1)
  {
    MODE1();
  }
  
  if(digitalRead(MODE2SWITCH) == 1)
  {
    MODE2();
  }
  
  if(digitalRead(MODE3SWITCH) == 1)
  {
    MODE3();
  }
  
  if(digitalRead(MODE4SWITCH) == 1)
  {
    MODE4();
  }
  if(digitalRead(MODE5SWITCH) == 1)
  {
    MODE5();
  }
  if(digitalRead(MODE0RANGESWITCH) == 1)
  {
    MODEORANGE();
  }
  modeswitchcheck();
  
  }
  
  
  
   while(remember_state==0)
{
  Serial.println("AUTOMATIC");
  digitalWrite(OVERRIDELED, LOW);
 
  if(remember_state==0)
  {
    //Switch on mode 1 of lights
    for(int n = 1; n<loopcounter_main;n++)
    {
      MODE1();
      delay(timedelay);
      modeswitchcheck();
      if(remember_state == 1)
      {
       n=loopcounter_main;
      }
    }
  }
  
  
  if(remember_state==0)
  {
    //Switch on mode 1 of lights
    for(int n = 1; n<200;n++)
    {
      SET1ORANGE();
      delay(timedelay);
      modeswitchcheck();
      if(remember_state == 1)
      {
       n=200;
      }
    }
  }
 
  
  if(remember_state==0)
  {
    //Switch on mode 2 of lights
    for(int n = 1; n<loopcounter;n++)
    {
      MODE2();
      delay(timedelay);
      modeswitchcheck();
      if(remember_state == 1)
      {
       n=loopcounter;
      }
    }
  }
  
  if(remember_state==0)
  {
    //Switch on mode 1 ORANGE of lights
    for(int n = 1; n<200;n++)
    {
      SET1ORANGE();
      delay(timedelay);
      modeswitchcheck();
      if(remember_state == 1)
      {
       n=200;
      }
    }
  }
  
  if(remember_state==0)
  {
    //Switch on mode 3 of lights
    for(int n = 1; n<loopcounter_main;n++)
    {
      MODE3();
      delay(timedelay);
      modeswitchcheck();
      if(remember_state == 1)
      {
       n=loopcounter_main;
      }
    }
  }
  
  
  if(remember_state==0)
  {
    //Switch on mode 2 ORANGE of lights
    for(int n = 1; n<200;n++)
    {
      SET2ORANGE();
      delay(timedelay);
      modeswitchcheck();
      if(remember_state == 1)
      {
       n=200;
      }
    }
  }
  
  if(remember_state==0)
  {
    //Switch on mode 4 of lights
    for(int n = 1; n<loopcounter;n++)
    {
      MODE4();
      delay(timedelay);
      modeswitchcheck();
      if(remember_state == 1)
      {
       n=loopcounter;
      }
    }
  }
  
  if(remember_state==0)
  {
    //Switch on mode 2 ORANGE of lights
    for(int n = 1; n<200;n++)
    {
      SET2ORANGE();
      delay(timedelay);
      modeswitchcheck();
      if(remember_state == 1)
      {
       n=200;
      }
    }
  }
  
  if(remember_state==0)
  {
    //Switch on mode 5 of lights
    for(int n = 1; n<loopcounter;n++)
    {
      MODE5();
      delay(timedelay);
      modeswitchcheck();
      if(remember_state ==  1)
      {
       n=loopcounter;
      }
    }
  }
  
  
  if(remember_state==0)
  {
    //Switch on mode 2 ORANGE of lights
    for(int n = 1; n<200;n++)
    {
      MODEORANGE();
      delay(timedelay);
      modeswitchcheck();
      if(remember_state == 1)
      {
       n=200;
      }
    }
  }
    
} 
  
}
