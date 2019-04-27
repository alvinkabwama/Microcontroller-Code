void currentCorrect()
{
  if(Irms1 < 0.2)
  {
    Irms1 = 0;
  }

   if(Irms2 < 0.2)
  {
    Irms2 = 0;
  }

   if(Irms3 < 0.2)
  {
    Irms3 = 0;
  }


  Irms1 = Irms1/3;
  Irms2 = Irms2/3;
  Irms3 = Irms3/3;
  
}

