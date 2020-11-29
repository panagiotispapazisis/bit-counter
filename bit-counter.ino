void setup()
{
  for (int i = 4; i <= 11; i++)
  {
    pinMode(i, OUTPUT);
  }

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{

  for (int i = 4; i <= 11; i++)
  {
    digitalWrite(i, HIGH);
    delay(100);
  }

  for (int i = 11; i >= 4; i--)
  {

    digitalWrite(i, LOW);
    delay(100);
  }
  Serial.println(digitalRead(2));
  Serial.println(digitalRead(3));
}
