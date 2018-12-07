int counter =0;
int value;
int ldr = A0;
int laser=3;
char data; 
bool on = false;
void setup() {
  pinMode (laser,OUTPUT);
  Serial.begin(9600);
  
  }

void loop(){
  value = analogRead(ldr);

  delay(250);
  
  if (on && value<800){
      counter++;
      Serial.println (counter);
      
      }
  
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

   delay(500);












   
   }
 
  
