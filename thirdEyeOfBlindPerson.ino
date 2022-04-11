#define trigger 8
#define echo 9
#define buzzPin 7
int distance=0;
int travell;



void setup() {
  // put your setup code here, to run once:                    
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzPin,OUTPUT);
  Serial.begin(9600);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  travell=pulseIn(echo,HIGH);
  distance=travell*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance <=100){
    digitalWrite(buzzPin,HIGH);
    Serial.println("Obstacle detected ahead");

    delay(500);
  }
   else{
    digitalWrite(buzzPin,LOW);
   }
  
  delay(1000);
 


}
