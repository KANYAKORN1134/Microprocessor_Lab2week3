#define DATA_PIN 11
#define CLOCK_PIN 13
#define LATCH_PIN 10

int i=0;
int data;
void setup()
{
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}
void loop()
{
  data=0b10000000;
  for(i=0;i<16;i++){

    digitalWrite(DATA_PIN, (data>>(7-i))&0x01);
    digitalWrite(CLOCK_PIN, HIGH);
    delay(150);
    digitalWrite(CLOCK_PIN, LOW);
    delay(150);
    digitalWrite(LATCH_PIN, HIGH);
    delay(20);
    digitalWrite(LATCH_PIN, LOW);
    delay(20);
  }
}
