int clk_pin = 13; //SHCP
int latch_pin =10; //STCP
int data_pin =11; //DS
int d;
void setup()
{
pinMode(clk_pin, OUTPUT);
pinMode(latch_pin, OUTPUT);
pinMode(data_pin, OUTPUT);
pinMode(A0, INPUT);
Serial.begin(9600);
}

void loop()
{
for (int i = 0; i &lt; 16 || i &gt; 0; i = i)
{
digitalWrite(latch_pin, LOW);
for (int c = 0; c &lt; 16; c++)
{
d=analogRead(A3);
if (c == i)
{
digitalWrite(data_pin, HIGH);
}
else
{
digitalWrite(data_pin, LOW);
}
digitalWrite(clk_pin, HIGH);
digitalWrite(clk_pin, LOW);
}
if (analogRead(A0) == 0)
{
i--;
if (i &lt; 0) i = 15;
digitalWrite(latch_pin, HIGH);
delay(10);
}
if (analogRead(A1) == 0)
{
i++;
if (i &gt; 15) i = 0;
digitalWrite(latch_pin, HIGH);
delay(10);
}
delay(d*2);
digitalWrite(latch_pin, HIGH);
Serial.print(d);
}
}
