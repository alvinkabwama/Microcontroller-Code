// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3


#include <LiquidCrystal.h>
#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor phase1;
EnergyMonitor phase2;
EnergyMonitor phase3;
// Create an instance


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

int bcb = 49;
int rcb = 51;
int ycb = 53;



  double Irms1 = 0;
  double Irms2 = 0;
  double Irms3 = 0;


double maxcurrent = 0;
double mincurrent = 0;
double threshold = 0; 

int bluerem = 0;
int redrem = 0;
int yellowrem = 0;

int n = 0;
int maxcurrentpos = 0;
int mincurrentpos = 0;

int contrastpin = 9;
double currentarray[3] = {0, 0, 0};



void setup()
{  

  pinMode(14, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
 /* digitalWrite(14, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);*/

  lcd.begin(16, 2);
   
  analogWrite(contrastpin, 127);  
  lcd.clear();
  
  Serial.begin(9600);
  
  phase1.current(0, 111.1);             // Current: input pin, calibration.
  phase2.current(1, 111.1);
  phase3.current(2, 111.1);

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
   Irms1 = (phase1.calcIrms(1480));  // Calculate Irms only(A0)
   Irms2 = (phase2.calcIrms(1480));  // Calculate Irms only(A1)
   Irms3 = (phase3.calcIrms(1480));  // Calculate Irms only(A2)

  Serial.print((Irms1/3)*230.0);         // Apparent power
  Serial.println(" Watts and ");

  currentCorrect();

  

  currentarray[0] = Irms1;
  currentarray[1] = Irms2;
  currentarray[2] = Irms3;
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

  if(maxcurrent > 4)
  {

  if(maxcurrentpos == 1)
  {
    if(mincurrentpos == 2)
    {  
       digitalWrite(u1b, LOW);
       digitalWrite(u1r, HIGH);
       digitalWrite(u1y, LOW);
    }
    else if(mincurrentpos == 3)
    {
       digitalWrite(u1b, LOW);
       digitalWrite(u1r, LOW);
       digitalWrite(u1y, HIGH);
    }
    else 
    {
      
    }
    
  }


  else if(maxcurrentpos == 2)
  {
    if(mincurrentpos == 1)
    {  
       
       digitalWrite(u2r, LOW);
       digitalWrite(u2y, LOW);
       digitalWrite(u2b, HIGH);
       
    }
    else if(mincurrentpos == 3)
    {
       digitalWrite(u2r, LOW);
       digitalWrite(u2b, LOW);
       digitalWrite(u2y, HIGH);
    }
    else 
    {
      
    }
    
  }
  
  else if(maxcurrentpos == 3)
  {
    if(mincurrentpos == 1)
    {  
      Serial.println("SWITCHING");
      digitalWrite(u3y, LOW);
      digitalWrite(u3r, LOW);
      digitalWrite(u3b, HIGH);
      
          
    }
    else if(mincurrentpos == 2)
    {
      digitalWrite(u3y, LOW);
      digitalWrite(u3r, HIGH);
      digitalWrite(u3b, LOW);
    }
    else 
    {
      
    }
    
  }
  else
  {
    
  }
  }
  

   /*Irms1 = analogRead(A0);  // Calculate Irms only
   Irms2 = analogRead(A1);  // Calculate Irms only
   Irms3 = analogRead(A2);  // Calculate Irms only

  Serial.print("POWER IS ");
  Serial.print((Irms1/3)*230.0);         // Apparent power
  Serial.print(" Watts and ");*/

  
 
 
 
  Serial.print(Irms1);
  Serial.print("          ");
  Serial.print(Irms2); 
  Serial.print("          ");
  Serial.println(Irms3);
  Serial.print("MAX CURRENT is ");
  Serial.println(maxcurrent);
   Serial.print("MIN CURRENT is ");
  Serial.println(mincurrent);


  /* Serial.print(Irms1);
  Serial.print("          ");
  Serial.print(Irms2); 
  Serial.print("          ");
  Serial.println(Irms3);*/

  /*lcd.print("P1 = ");
  lcd.print(Irms1);
  lcd.setCursor(7, 0);
  lcd.print("P2 = ");
  lcd.print(Irms2);
  lcd.setCursor(0, 1);
  lcd.print("P2 = ");
  lcd.print(Irms3);*/
  
  
}
