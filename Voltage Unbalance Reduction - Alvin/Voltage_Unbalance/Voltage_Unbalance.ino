// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"                   // Include Emon Library
#include <LiquidCrystal.h>
EnergyMonitor bluephase;   
EnergyMonitor redphase;   
EnergyMonitor yellowphase;   


LiquidCrystal lcd(8, 7, 6, 5, 4, 3);

int u1b = 43;  //this unit has four lights
int u1r = 45;
int u1y = 47;

int u2b = 37; //this unit has three lights
int u2r = 39;
int u2y = 41;


int u3b = 31;  //this unit has two lights
int u3r = 33;
int u3y = 35;

int bcb = 10;
int rcb = 11;
int ycb = 12;// Create an instance


int bluewarningled = 15;
int redwarningled = 16;
int yellowwarningled = 17;

double Irms1 = 0;
double Irms2 = 0;
double Irms3 = 0;

double maxcurrent = 0;
double mincurrent = 0;
double threshold = 0; 

int bluerem = 0;
int redrem = 0;
int yellowrem = 0;

double bluecurrent = 0;
double redcurrent = 0;
double yellowcurrent = 0;
double minim = 0.22;
double maxallowedcurrent = 4;
int delaytym = 1000;
int smcheck = 0;
int smpin = A7;
int smled = 14;
double avcurrent  = 0;
double voltageunbperc = 0;
double currentdiff = 0;
int dt = 1000;


int n = 0;
int maxcurrentpos = 0;
int mincurrentpos = 0;

int contrastpin = 9;
double currentarray[3] = {0, 0, 0};

void setup()
{  
  Serial.begin(9600);


 pinMode(bluewarningled, OUTPUT);
pinMode(redwarningled, OUTPUT); 
pinMode(yellowwarningled,OUTPUT);

  pinMode(bcb,  OUTPUT);
  pinMode(rcb,  OUTPUT);
  pinMode(ycb, OUTPUT);
  pinMode(smled, OUTPUT);
  
  bluephase.current(0, 111.1);
  redphase.current(1, 111.1);
  yellowphase.current(2, 111.1);
  
  
   for(int k = 31;k < 54;k++)
{
  pinMode(k, OUTPUT);
}

  digitalWrite(u1b, HIGH);
  digitalWrite(u1r, LOW);
  digitalWrite(u1y, LOW);
  
 
  digitalWrite(u2b, LOW);
  digitalWrite(u2r, HIGH);
  digitalWrite(u2y, LOW);

  digitalWrite(u3b, LOW);
  digitalWrite(u3r, LOW);
  digitalWrite(u3y, HIGH);


  digitalWrite(bcb, LOW);
  digitalWrite(rcb, LOW);
  digitalWrite(ycb, LOW);

  

}

void loop()
{

 
   Irms1 = (bluephase.calcIrms(1480))/3;  // Calculate Irms only
   Irms2 = (redphase.calcIrms(1480))/3;  // Calculate Irms only
   Irms3 = (yellowphase.calcIrms(1480))/3;  // Calculate Irms only
  
  currentCorrect();

  currentarray[0] = bluecurrent;
  currentarray[1] = redcurrent;
  currentarray[2] = yellowcurrent;
  maxcurrent = 0;
  for(n=0;n<3;n++)
  {
    if(currentarray[n] > maxcurrent)
    {
      maxcurrent = currentarray[n];
      maxcurrentpos = n+1;
      //Looking for  phase with the most current 
    }
   
  }
  mincurrent = 100;
   for(n=0;n<3;n++)
  {
    if(currentarray[n] < mincurrent )
    {
      mincurrent = currentarray[n];
      mincurrentpos = n+1;
      //Looking for  phase with the least current 
      
    }
   
  }

  voltageUnbalanceCalc();

  

  
  Serial.print("BC");
  Serial.print(bluecurrent);
  Serial.print("      ");
  Serial.print("RC");
  Serial.print(redcurrent); 
  
  Serial.print("      ");
   Serial.print("YC");
  Serial.print(yellowcurrent); 
  Serial.print("      ");
  Serial.println();

  /*Serial.print("MAX CURRENT is ");
  Serial.println(maxcurrent);
   Serial.print("MIN CURRENT is ");
  Serial.println(mincurrent);*/

  if(maxcurrent > maxallowedcurrent)
  {

  if(maxcurrentpos == 1)
  {
    digitalWrite(bluewarningled, HIGH);
    delay(dt);
    if(mincurrentpos == 2)
    {  
       digitalWrite(u1b, LOW);
       digitalWrite(u1y, LOW);
       delay(delaytym);
       digitalWrite(u1r, HIGH);
       ;
    }
    else if(mincurrentpos == 3)
    {
       digitalWrite(u1b, LOW);
       digitalWrite(u1r, LOW);
       delay(delaytym);
       digitalWrite(u1y, HIGH);
    }
    else 
    {
      
    }
    digitalWrite(bluewarningled, LOW);
  }


  else if(maxcurrentpos == 2)
  {
    digitalWrite(redwarningled, HIGH);
    delay(dt);
    if(mincurrentpos == 1)
    {  
       
       digitalWrite(u2r, LOW);
       digitalWrite(u2y, LOW);
       delay(delaytym);
       digitalWrite(u2b, HIGH);
       
    }
    else if(mincurrentpos == 3)
    {
       digitalWrite(u2r, LOW);
       digitalWrite(u2b, LOW);
       delay(delaytym);
       digitalWrite(u2y, HIGH);
    }
    else 
    {
      
    }
    digitalWrite(redwarningled, LOW);
    
  }
  
  else if(maxcurrentpos == 3)
  {
    digitalWrite(yellowwarningled, HIGH);
    delay(dt);
    if(mincurrentpos == 1)
    {  
 
      digitalWrite(u3y, LOW);
      digitalWrite(u3r, LOW);
      delay(delaytym);
      digitalWrite(u3b, HIGH);
      
          
    }
    else if(mincurrentpos == 2)
    {
      digitalWrite(u3b, LOW);
      digitalWrite(u3y, LOW);
      delay(delaytym);
      digitalWrite(u3r, HIGH);
    }
    else 
    {
      
    }
    digitalWrite(yellowwarningled, LOW);
  }
  else
  {
    
  }
  }
  slowDown();
   if(smcheck == 0)
  {
    delaytym = 0;
  }
  else
  {
    delaytym = 1000;  
  }
  /*Serial.print("SM is ");
  Serial.println(smcheck);

  Serial.print("DT is ");
  Serial.println(delaytym);


   Serial.print("Voltage unbalance is ");
  Serial.println(100- voltageunbperc);*/
}
