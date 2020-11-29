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

  while (Serial.available() == 0)
    ;
  int value = Serial.parseInt();
  calculate(value);
}
void calculate(int val)
{

  int dataArray[8] = {128, 64, 32, 16, 8, 4, 2, 1};
  int bitArray[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  for (int i = 0; i < 8; i++)
  {
    bitArray[i] = val / dataArray[i];
    val = val % dataArray[i];
  }

  int count = 4;
  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(count, bitArray[i]);
    count = count + 1;
  }
}