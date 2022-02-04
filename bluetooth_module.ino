#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(2, 3); // RX | TX 
char state; 
int LED = 13; 
int BULB = 8;
void setup() 
{   
   Serial.begin(9600); 
   MyBlue.begin(9600); 
   pinMode(LED, OUTPUT); 
   pinMode(BULB, OUTPUT); 
   digitalWrite(BULB, HIGH);
   Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
   if (MyBlue.available()) 
      state = MyBlue.read();
     
   if (state == 'G') 
   { 
      Serial.println(state);
      digitalWrite(LED, HIGH); 
      Serial.println("LED On"); 
   } 
   else if (state == 'R') 
   {
      Serial.println(state);
      digitalWrite(LED, LOW); 
      Serial.println("LED Off"); 
   }

   if (state == 'O') 
   { 
      Serial.println(state);
      digitalWrite(BULB, LOW); 
      Serial.println("BULB On"); 
   } 
   else if (state == 'F') 
   {
      Serial.println(state);
      digitalWrite(BULB, HIGH); 
      Serial.println("BULB Off"); 
   }
}  
