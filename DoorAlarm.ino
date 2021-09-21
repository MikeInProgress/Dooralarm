#define LED_R 10
#define LED_G 11
#define LED_B 12
#define Buzzer A5
#define Alarm 0

bool open = false;
void setup() {
  
  pinMode(LED_R, OUTPUT); 
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Alarm, INPUT_PULLUP); 
  
  digitalWrite(LED_R, LOW); 
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
}
 
void loop() {
    
  if (digitalRead(Alarm) == LOW) { 
    digitalWrite(LED_R, LOW); 
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
    open = false;
  }else {
    open = true;
    tone(Buzzer, 4300);
    noTone(Buzzer);
    while(open)
    {
      
    digitalWrite(LED_R, HIGH); 
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
    
    delay(280);
    digitalWrite(LED_R, LOW); 
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
    }
  
  }
}
