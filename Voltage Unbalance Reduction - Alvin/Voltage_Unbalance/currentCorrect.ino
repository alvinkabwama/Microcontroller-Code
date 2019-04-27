void currentCorrect()
{
  if(Irms1 < minim)
  {
    bluecurrent = 0;
   
  }
  else
  {
    bluecurrent = Irms1;
  
  }

   if(Irms2 < minim)
  {
    redcurrent = 0;
 
  }
   else
  {
    redcurrent = Irms2+0.15;
   
  }

   if(Irms3 < minim)
  {
    
    yellowcurrent = 0;
    
  }
   else
  {
    yellowcurrent = Irms3;
 
  }


  
  
}

