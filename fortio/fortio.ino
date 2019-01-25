int counter =0;
int value;
int ldr = A0;
int laser=13;
char data; 
bool on = false;
bool perase_fortio = false;


void setup() {
  pinMode (laser,OUTPUT);
  Serial.begin(9600);
  
  }

void loop(){
  value = analogRead(ldr);
//Serial.println (value);
  delay(250);
  
 
  
  if(Serial.available()>0){
    data=Serial.read();
  }
   if(data=='o'){
    digitalWrite(laser,HIGH);
    on = true;

   }
   else if (data=='c'){
    digitalWrite(laser,LOW);

    on = false;
   }

     value = analogRead(ldr);
    
   
 
    if(on && value<500)
    {
         
      perase_fortio = true;
    }

    if(on && value>500 && perase_fortio)
    {
      counter++;     
      perase_fortio = false;
    }

    Serial.println (counter);

    

   

   delay(500);
}
