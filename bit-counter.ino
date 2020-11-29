int Number = 0;
bool valueBtnInc;
bool prevValueBtnInc = true;
bool checkIncBtn;
bool valueBtnDec;
bool prevValueBtnDec = true;
bool checkDecBtn;
int count = 0;
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

  valueBtnDec = digitalRead(2);
  checkDecBtn = checkDecBtnState(valueBtnDec, prevValueBtnDec);
  if (checkDecBtn)
  {

    count++;
    if (count % 2 == 0)
    {

      if (Number > 0)
      {
        Number = Number - 1;
        calculate(Number);
      }

      count = 0;
    }
  }

  valueBtnInc = digitalRead(3);
  checkIncBtn = checkIncBtnState(valueBtnInc, prevValueBtnInc);
  if (checkIncBtn)
  {

    count++;
    if (count % 2 == 0)
    {

      if (Number < 255)
      {
        Number = Number + 1;
        calculate(Number);
      }

      count = 0;
    }
  }

  prevValueBtnDec = valueBtnDec;
  prevValueBtnInc = valueBtnInc;
}

bool checkIncBtnState(bool now, bool before)
{

  if (now != before)
  {

    return true;
  }
  else
  {
    return false;
  }
}

bool checkDecBtnState(bool now, bool before)
{

  if (now != before)
  {

    return true;
  }
  else
  {
    return false;
  }
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