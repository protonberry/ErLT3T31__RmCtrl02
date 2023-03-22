void MV43()
{
  MenuScreen(Msel) ;
  TestStage = 1;

  
  BladeDegPerMin = UDBladeDegPerMin;
  TestDurationDeg = UDTestDurationDeg;
  debugln("MVStart1");
  MVstart();
  debugln("MVtest1");
  //MVtest43();
  debugln("MVend1");
  MVend();
  debugln("MVend1xx");

  if (TorMaxflag)
    return;

  delay(1000);
  TestStage = 2;
  //u8g2.drawStr(120,30,"F");
  BladeDegPerMin = FastBladeDegPerMin;
  TestDurationDeg = FastTestDurationDeg;
  debugln("MVStart2");
  MVstart();
  debugln("MVtest2");
  //MVtest43();
  debugln("MVend2");
  MVend();

//  ReleaseTorque();
  delay(5000);
  TestStage = 3;
  BladeDegPerMin = ResBladeDegPerMin;
  TestDurationDeg = ResTestDurationDeg;
  
  debugln("MVStart3");
  MVstart();
  debugln("MVtest3");
  //MVtest43();
  debugln("MVend3");
  MVend();
  debugln("MVend3xx");
}
