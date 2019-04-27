int green = 13;
int left = 12;
int yellow = 11;
int straight = 10; 
int red = 9;
int right = 8;
int override_LED = 7;
int override_switch = 6;
int mode1switch = 5;
int mode2switch = 4;
int mode3switch = 3;
int mode4switch = 2;

int mode = 1;
int rememberstate = 0;

int timedelay = 10;
int loopcounter = 1000;
void setup() {
  
  for(int n=7; n<14; n++)
  {
    pinMode(n, OUTPUT);
  }
    
   for(int k=2;k<7;k++)
  {
    pinMode(k, INPUT);
  }
    
   Serial.begin(9600);  
}

//Function for checking mode switch 

void modeswitchcheck(void)
{
  if(digitalRead(override_switch) == 1)
  {
    if(rememberstate == 0)
    {
     rememberstate = 1;
    delay(500);
    }
    else
    {
    rememberstate = 0;
    delay(500);
    }
  }
}


//Function definition for switching on the different LEDs
 void lights(int n)
 {
   if(n==1)
   {
     digitalWrite(green, HIGH);
     digitalWrite(left, HIGH);
     digitalWrite(straight, HIGH);
     digitalWrite(yellow, LOW);
     digitalWrite(red, LOW);
     digitalWrite(right, LOW); 
   }
   else if(n==2)
   {
     digitalWrite(green, LOW);
     digitalWrite(left, LOW);
     digitalWrite(straight, LOW);
     digitalWrite(yellow, HIGH);
     digitalWrite(red, LOW);
     digitalWrite(right, LOW); 
   }
   
   else if(n==3)
   {
     digitalWrite(green, LOW);
     digitalWrite(left, LOW);
     digitalWrite(straight, LOW);
     digitalWrite(yellow, LOW);
     digitalWrite(red, HIGH);
     digitalWrite(right, LOW); 
   }
   
   else if(n==4)
   {
     digitalWrite(green, LOW);
     digitalWrite(left, LOW);
     digitalWrite(straight, LOW);
     digitalWrite(yellow, LOW);
     digitalWrite(red, HIGH);
     digitalWrite(right, HIGH); 
   }
   
   else
   {
     ;
   }
 }
   


void loop() {
  
  while(rememberstate==1)
  {
    digitalWrite(override_LED, HIGH);
    
  if(digitalRead(mode1switch) == 1)
  {
    lights(1);
  }
  
  if(digitalRead(mode2switch) == 1)
  {
    lights(2);
  }
  
  if(digitalRead(mode3switch) == 1)
  {
    lights(3);
  }
  
  if(digitalRead(mode4switch) == 1)
  {
    lights(4);
  }
  modeswitchcheck();
  
  }
  digitalWrite(override_LED, LOW);
  modeswitchcheck();
  
  
  
  
 while(rememberstate==0)
{
 
  if(rememberstate==0)
  {
    //Switch on mode 1 of lights
    for(int n = 1; n< loopcounter;n++)
    {
      lights(1);
      delay(timedelay);
      modeswitchcheck();
      if(rememberstate == 1)
      {
       n=loopcounter;
      }
    }
  }
  
  if(rememberstate==0)
  {
    //Switch on mode 2 of lights
    for(int n = 1; n<100;n++)
    {
      lights(2);
      delay(timedelay);
      modeswitchcheck();
      if(rememberstate == 1)
      {
       n=100;
      }
    }
  }
  
  if(rememberstate==0)
  {
    //Switch on mode 3 of lights
    for(int n = 1; n< 100;n++)
    {
      lights(3);
      delay(timedelay);
      modeswitchcheck();
      if(rememberstate == 1)
      {
       n=100;
      }
    }
  }
  
  if(rememberstate==0)
  {
    //Switch on mode 4 of lights
    for(int n = 1; n<loopcounter;n++)
    {
      lights(4);
      delay(timedelay);
      modeswitchcheck();
      if(rememberstate == 1)
      {
       n=loopcounter;
      }
    }
  }
  
}
  
   
}
  
 
   
      


