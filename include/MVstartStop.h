 void MVstart()
{
  sprMsg.fillSprite(TFT_BLACK);
  sprMsg.pushSprite(ScreenW-(ScreenW*.25),S3YPosSS -SFontPixH);

  TestinProgress = true;
  MaxSx = 0. ;
  rotAtMax = 0. ;
  TorMaxflag = false;
/*
  if (((TestStage == 1) && (Recordflag > 0)) || ((TestStage == 2) && (Recordflag == 2)) || ((TestStage == 3) && (Recordflag > 1)) )
    {  Test_ID = Test_ID + 1;
      if (Test_ID>200){Test_ID = 1 ;}
      }
  SaveEEPROM();
    EEPROM.get(eeAddress100 + 40, Test_ID);
  debug("test_id= ");debugln(Test_ID);
*/
  char filechar[31];
  char datachar[31];
  String fileString;
  String dataString;

  if (((TestStage == 1) && (Recordflag > 0)) || ((TestStage == 2) && (Recordflag == 2)) || ((TestStage == 3) && (Recordflag > 1)) )
//  if (Recordflag != 0)
  {
      Test_ID = Test_ID + 1;
      if (Test_ID>200){Test_ID = 1 ;}
  SaveEEPROM();
    EEPROM.get(eeAddress100 + 40, Test_ID);
  debug("test_id= ");debugln(Test_ID);

    fileString = '/' + String(ProjectID) + String(SampleID) + String(Test_ID) += ".csv";
    fileString.toCharArray(filechar, 14);

    dataString = String(Test_ID) + ",Seq No" + ",Sn:" + sSerial_No + '\n';
    dataString.toCharArray(datachar, 30);
    writeFile(SPIFFS, filechar, datachar);

    dataString = String(ProjectID) + ",Project ID" + '\n';
    dataString.toCharArray(datachar, 30);
    appendFile(SPIFFS, filechar, datachar);
      
    switch (TestStage)
  {

  case 1:
      dataString = String(SampleID) + ",Sample ID, Undisturbed" + '\n';
      break;
  case 2:
      dataString = String(SampleID) + ",Sample ID, Remolding" + '\n';
      break;
  case 3:
      dataString = String(SampleID) + ",Sample ID, Residual" + '\n';
      break;
  } 
    
    dataString.toCharArray(datachar, 30);
    appendFile(SPIFFS, filechar, datachar);

    dataString = String(VaneBladeCon[Blade], 2) + ",Blade Const for " + VaneBladeDes[Blade]  ;
    dataString.toCharArray(datachar, 30);
    appendFile(SPIFFS, filechar, datachar);
    
    dataString = ", Cal Factor =" + String(Load_Calibration_Factor) +'\n';
    dataString.toCharArray(datachar, 30);
    appendFile(SPIFFS, filechar, datachar);

    dataString = String("Deg*10,Torque in-lb*1000") + '\n';
    dataString.toCharArray(datachar, 30);
    appendFile(SPIFFS, filechar, datachar);

 //   fileString = "fn: " + String(ProjectID) + String(SampleID) + String(Test_ID);
    fileString = String(ProjectID) + String(SampleID) + String(Test_ID);
}
  else
  {
    fileString = "NO REC";
  }

  fileString.toCharArray(filechar, 14);
  
  sprData.SFont;
  sprData.fillSprite(TFT_BLACK);
  sprData.setTextColor(TFT_CYAN);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawString("fn: ", 0,SFontPixH);

  sprData.setTextColor(TFT_YELLOW);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawString(fileString, sprData.textWidth("fn:  "),SFontPixH);
  sprData.pushSprite((ScreenW/2)+1,S3YPosfn-SFontPixH);

  sprData.fillSprite(TFT_BLACK);
  sprData.setTextColor(TFT_CYAN);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawString("Bld: ", 0,SFontPixH);

  sprData.setTextColor(TFT_YELLOW);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawString(VaneBladeDes[Blade], sprData.textWidth("Bld:  "),SFontPixH);
  sprData.pushSprite(2,S3YPosfn-SFontPixH);

  SendInstrutionstoMV();
  debugln(TestStage);
  debugln(Recordflag);
  debugln(fileString);
  debugln(filechar);
  debugln(S3YPosfn);
  debugln("File header written");
}

 
 void MVend()
{
  sprMsg.XSFont; 
  sprMsg.fillSprite(TFT_BLACK);
  sprMsg.setTextColor(TFT_RED);
  sprMsg.setTextDatum(R_BASELINE);
switch (MV_Data.MVstatus)
{
case 0:
  break;
case 1:
debug("*****Should not be here");
//   RM_Instruction.RM_InstructionType = 0;
//   SendInstrutionstoMV();
  break;
case 2:
  sprMsg.drawString("by Max T", (ScreenW*.25)-1,SFontPixH);
  break;
case 3:
  sprMsg.drawString("by User", (ScreenW*.25)-1,SFontPixH);
  break;
case 4:
  sprMsg.drawString("Complete", (ScreenW*.25)-1,SFontPixH);
  break;

default:
  break;
}
  sprMsg.pushSprite(ScreenW-(ScreenW*.25),S3YPosSS -SFontPixH);

  sprData.SFont;
  sprData.fillSprite(TFT_BLACK);
  sprData.setTextColor(TFT_CYAN);
  sprData.setTextDatum(R_BASELINE);
  sprData.drawString("deg", (ScreenW/2)-1,SFontPixH);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawString("Frot:", 0,SFontPixH);

  sprData.setTextColor(TFT_YELLOW);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawFloat(rotAtMax,1, sprData.textWidth("Frot: "),SFontPixH);
  sprData.pushSprite((ScreenW/2)+1,S3YPosRot -SFontPixH);
  
  TestinProgress = false ;

}