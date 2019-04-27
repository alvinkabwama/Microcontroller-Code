

int phase1 = 5;
int phase2 = 6;
int phase3 = 7;

int tym = 0;
 

void setup() 
{  
 pinMode(phase1, OUTPUT);
 pinMode(phase2, OUTPUT);
 pinMode(phase3, OUTPUT);
}

void loop() 
{
 digitalWrite(phase2,LOW);
 digitalWrite(phase3,LOW);
 delay(tym);
 digitalWrite(phase1,HIGH);
 delay(5000);

 
 digitalWrite(phase1,LOW);
 digitalWrite(phase3,LOW);
 delay(tym);
 digitalWrite(phase2,HIGH);
 delay(5000);

 
 digitalWrite(phase1,LOW);
 digitalWrite(phase2,LOW);
 delay(tym);
 digitalWrite(phase3,HIGH);
 delay(5000);
}
