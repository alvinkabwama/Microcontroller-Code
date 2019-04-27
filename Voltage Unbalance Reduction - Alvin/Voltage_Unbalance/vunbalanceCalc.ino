 void voltageUnbalanceCalc()
{
  avcurrent = (bluecurrent+yellowcurrent+redcurrent)/3;
  currentdiff = maxcurrent-avcurrent;

  voltageunbperc = (avcurrent/maxcurrent)*100;
}

