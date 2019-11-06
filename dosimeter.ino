#define CONV_FACTOR 0.00812
int interruptPin = 13;
long count = 0;
long CPM = 0;
long timePrevious = 0;
long timePreviousMeasure = 0;
long countPrevious = 0;
float radiationDose = 0.0;

void setup(){
  pinMode(interruptPin, INPUT);
  digitalWrite(interruptPin,HIGH);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(interruptPin),countPulse,FALLING);
  
}

void loop(){
  if (millis()-timePreviousMeasure > 10000){
    CountToCPM();
    float radiationDose = CPM * CONV_FACTOR;
    timePreviousMeasure = millis();
////    Serial.print("CPM: "); 
////    Serial.println(CPM);
//    Serial.print(" * ");
//    Serial.print(CONV_FACTOR);
//    Serial.print(" = ");
//    Serial.println(radiationDose);      
//    Serial.print("CPM=");
//    Serial.println(CPM);
    Serial.print(radiationDose);
    Serial.println(" uSv/h");
    count = 0;
  }
}

void countPulse(){
  detachInterrupt(0);
  count++;
  Serial.print("CPM increased: ");
  CountToCPM();
  Serial.println(CPM);
  while(digitalRead(2)==0){
  } 
}
int CountToCPM(){
      CPM = 6*count;
    }
