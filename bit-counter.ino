
void setup()
{

  for (int i = 4; i <= 11; i++)
  {
    pinMode(i, OUTPUT);
  }
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
}
