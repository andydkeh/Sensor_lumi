const int ld = A5;
const int piezo = 3;
const int led = 2;
const int pot = A0;

void setup()
{
    pinMode(ld, INPUT);
    pinMode(piezo, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(pot, INPUT);
    Serial.begin(9600);
}

void loop()
{
    Serial.println(analogRead(ld));
  	int sensor = analogRead(ld);
    if (sensor >= 54 && sensor <= 600){
        tone(piezo, 1000);
        delay(400);
        noTone(piezo);
        delay(400);
    }
  
    //aqui fica o potênciometro 
    int valoPot = analogRead(pot);
    int luminosidade = map(valoPot, 0, 1023, 0, 255);  
    Serial.print(valoPot);   
    
    Serial.println(luminosidade);  
    analogWrite(led, luminosidade); 
}