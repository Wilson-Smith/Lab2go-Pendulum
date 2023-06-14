float voltage;
int counter = 0;
bool contact = false;
float limit_voltage = 3.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltage = analogRead(A1)*5./1024;
 // Serial.println(V);

  delay(1);

  if (voltage > limit_voltage && !contact){
      Serial.println(counter);
      counter = 0;
      contact = true;
  }
  
  else if (voltage < limit_voltage){
    contact = false;
  }

  counter = counter + 1; 
}