// Button task definition*************************************************
void ButtonDecode(int BB)
{
  switch (BB)
  {
  case 0: break;
  case 11:
  //  if (TestinProgress) {break;}
  //  if (Locked && EditFieldsFlag) 
  //  {     
  //    FieldVal[Vsel] = FieldVal[Vsel] + 1;
  //   if (FieldVal[Vsel] > VmaxVal[Vsel])
  //    FieldVal[Vsel] = VminVal[Vsel];
//    PrintReverse();
  //  break;
   // }
  //  if (Locked) {break;}
   
    Msel = Msel + 1;
    if (Msel > Mmax)
      Msel = 0;
    MenuChgFlag = true;
    MenuScreen(Msel);
    //   if(Msel == 5 )  DispTorque() ;
    break;
  case 12:
  //  if (TestinProgress) {break;}
  //  if (Locked && EditFieldsFlag) 
  //  {     
  // FieldVal[Vsel] = FieldVal[Vsel] - 1;
  //  if (FieldVal[Vsel] < VminVal[Vsel])
  //    FieldVal[Vsel] = VmaxVal[Vsel];
  //  PrintReverse();
  //  break;
   // }
   // if (Locked) {break;}
     Msel = Msel - 1;
    if (Msel < 1)
      Msel = Mmax;
    MenuChgFlag = true;
    MenuScreen(Msel);
    break;
  case 13:
    if (TestinProgress) {break;}
    if (Locked && EditFieldsFlag) {PressCnt = 0;}
    break;
  case 14:
    if (TestinProgress) {break;}
    if (Locked && EditFieldsFlag) {

   if (PressCnt < 20)
    {
      FieldVal[Vsel] = FieldVal[Vsel] + 1;
      vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    else if (PressCnt < 30)
    {
      FieldVal[Vsel] = FieldVal[Vsel] + 10;
      vTaskDelay(300 / portTICK_PERIOD_MS);
    }
    else
    {
      FieldVal[Vsel] = FieldVal[Vsel] + 50;
      vTaskDelay(500 / portTICK_PERIOD_MS);
    }

    if (FieldVal[Vsel] > VmaxVal[Vsel])
    {
      FieldVal[Vsel] = VminVal[Vsel];
      PressCnt = 0;
    }
    //PrintReverse();
    if (PressCnt == 0)
      vTaskDelay(700 / portTICK_PERIOD_MS);
    PressCnt = PressCnt + 1;
    debug(PressCnt);
    debug("ccc");
    break;
      
    }
    break;
  case 15:
  if(TestinProgress){
    RM_Instruction.RM_InstructionType = 3 ;
    SendInstrutionstoMV(); 
  }
   else{  
    if (Msel == 3)
        MV31();
      if (Msel == 4)
        MV43();
      if (Msel == 5)
        Torque50();
   }
    break;
  /*
    if (Locked && EditFieldsFlag) {PressCnt = 0;}
 debug("TestinProgress "); debugln(TestinProgress);
 if (TestinProgress)
    {     
  //    NumSteps = StepCounter   ;
 //debug("StepCounter "); debugln(StepCounter);debug("NumSteps "); debugln(NumSteps);
     if (TorMaxflag)
      {
//        u8g2.updateDisplayArea(0, 6, 16, 2);
      }
      TestinProgress = !TestinProgress ;
    }
    else
    {
      if (Msel == 3)
        MV31();
      if (Msel == 4)
        MV43();
      if (Msel == 5)
        DispTorque();
    }
    break;
*/
    case 31:
//    if (Msel == 5)
//      LoadCellTare();

    break;
  case 32:
    if (Locked && EditFieldsFlag) 
    {
//    if (Msel == 2 || Msel == 6)
//    {
//      PrintRegular();
      Vsel = Vsel + 1;
      if (Vsel == (FieldStart + NumFields))
        Vsel = FieldStart;
 //     PrintReverse();
//    }
    }
    break;
  case 33:
    break;
  case 34:
    break;
  case 35:
  RM_Instruction.RM_DegtoRotate = 0. ;
  RM_Instruction.RM_Reading_SpeedSPS = BB ;
  RM_Instruction.RM_RotationSpeed = 0. ;
  RM_Instruction.RM_InstructionType = 0;
   SendInstrutionstoMV();
/*
   Locked = !Locked;
    SaveEEPROM();

    MenuScreen(Msel);
    if (Msel == 2 || Msel == 6)
    {
      if (Locked)  { EditFieldsFlag = 1;} else {  EditFieldsFlag = 0;  }
    }
*/
    break;
  }
}
int chk_buttons()
{
  Bcode = 0;
  buttonGreen.tick();
  buttonRed.tick();
  if (Bcode)
  {
    ButtonDecode(Bcode);
  }
  //  if(Bcode){debug(Msel); debug(Bcode); ButtonDecode(Bcode);}
  return Bcode;
}
