int Echo = A5;  
int Trig =A4; 

int Distance = 0;

void setup()
{
  Serial.begin(9600);     //Initialize the serial ports
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
}


void Distance_test()  
{
  digitalWrite(Trig, LOW);   //Give the trigger pin 2μs low level 
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  //Give the trigger pin 10μs high level,at least 10μs
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    
  float Fdistance = pulseIn(Echo, HIGH);  //(unit：us)
  Fdistance= Fdistance/58;       
  // X second=（ 2 * Y meter）/344 ==》X second = 0.0058 * Y meter ==》cm = us / 58
  Distance = Fdistance;
}  

void loop()
{
  Distance_test();
  if((2<Distance)&(Distance<400))
  {
    Serial.print("Distance:");     
    Serial.print(Distance);        
    Serial.println("cm");       
  }
  else
  {
    Serial.println("!!! Out of range");      
  }
  delay(250);
}


