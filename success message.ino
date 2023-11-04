const int trigPin = 9;
const int echoPin = 10;

long duration;
double distance;
bool here;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  duration = pulseIn(echoPin, HIGH);
  distance = duration;
  if(duration > 5000.00){
    here = false;
    if(!here){
    Serial.println("Come Back Soon!");  
    }
  }
    else{

      Serial.println("Success is only achieved through hard work!");
    }
 // Serial.print("Distance: ");
//  Serial.println(distance);
  

  
}
