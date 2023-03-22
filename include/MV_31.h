void MVtest31()
{
  float DispSu = 0.;
//  float MaxSu = 0.;
  bool Maxflag = false;
//  int Numdig = 1;
//  int NumdigDeg = 1;
//  MaxWtgm = 0.;

 // int Ptorque = 0;
 // int Pdegrees = 0;

  char filechar[31];
  char datachar[31];
  String fileString;
  String dataString;
  if (((TestStage == 1) && (Recordflag > 0)) || ((TestStage == 2) && (Recordflag == 2)) || ((TestStage == 3) && (Recordflag > 1)) )
  {
    fileString = '/' + String(ProjectID) + String(SampleID) + String(Test_ID) += ".csv";
    fileString.toCharArray(filechar, 14);
  }
    if (((TestStage == 1) && (Recordflag > 0)) || ((TestStage == 2) && (Recordflag == 2)) || ((TestStage == 3) && (Recordflag > 1)) )
    {
   
      dataString = String(String(MV_Data.MVrotation) + ',' + String(MV_Data.MVtorque)) + '\n';
      dataString.toCharArray(datachar, 31);
      appendFile(SPIFFS, filechar, datachar);
    }
    if (MV_Data.MVtorque > 0.)
      DispSu = MV_Data.MVtorque * VaneBladeCon[Blade]/1000.;
    else
      DispSu = 0.;
    if (DispSu > MaxSx)
    {
      MaxSx = DispSu;
      rotAtMax = float(MV_Data.MVrotation)/10. ;
      Maxflag = true;
    }

    
    
  sprSu.LFont;
  sprSu.fillSprite(TFT_BLACK);
  sprSu.setTextColor(TFT_YELLOW);
  sprSu.setTextDatum(C_BASELINE);
  sprSu.drawNumber(MaxSx, LFontPixH*4/2,LFontPixH);
  sprSu.pushSprite((ScreenW-LFontPixH*4)/2,ScreenH- LFontPixH-LFontPixH/3);
  
  sprData.SFont;
  sprData.fillSprite(TFT_BLACK);
  sprData.setTextColor(TFT_CYAN);
  sprData.setTextDatum(R_BASELINE);
  sprData.drawString("deg", (ScreenW/2)-1,SFontPixH);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawString("Rot:", 0,SFontPixH);

  sprData.setTextColor(TFT_YELLOW);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawFloat((float(MV_Data.MVrotation)/10.),1, sprData.textWidth("Rot: "),SFontPixH);
  sprData.pushSprite((ScreenW/2)+1,S3YPosRot -SFontPixH);

  sprData.SFont;
  sprData.fillSprite(TFT_BLACK);
  sprData.setTextColor(TFT_CYAN);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawString("Su= ", 0,SFontPixH);

  sprData.setTextColor(TFT_YELLOW);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawNumber(DispSu, sprData.textWidth("Su=  "), SFontPixH);
  sprData.pushSprite(2,S3YPosSu-SFontPixH);
  /*
  sprData.fillSprite(TFT_BLACK);
  sprData.setTextColor(TFT_CYAN);
  sprData.setTextDatum(R_BASELINE);
  sprData.drawString("deg", (ScreenW/2)-1,SFontPixH);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawString("Rot:", 0,SFontPixH);

  sprData.setTextColor(TFT_YELLOW);
  sprData.setTextDatum(L_BASELINE);
  sprData.drawFloat((float(MV_Data.MVrotation)/10.),1, sprData.textWidth("Rot: "),SFontPixH);
  sprData.pushSprite((ScreenW/2)+1,S3YPosRot -SFontPixH);
  */
  }


void MV31()
{
//  MenuScreen(Msel) ;
 if(!TestinProgress){
  TestStage = 1;
  //BladeDegPerMin = UDBladeDegPerMin;
  //TestDurationDeg = UDTestDurationDeg;
  RM_Instruction.RM_DegtoRotate = UDTestDurationDeg ;
  RM_Instruction.RM_Reading_SpeedSPS = SamplingRate ;
  RM_Instruction.RM_RotationSpeed =   BladeDegPerMin = UDBladeDegPerMin ;
  RM_Instruction.RM_InstructionType = 1;
 //    TestinProgress = true ;
 
  debugln("MVStart1");
  MVstart();
//  SendInstrutionstoMV();

  debugln("MVtest1");
  //MVtest31();
  debugln("MVend1");
  //MVend();
  debugln("MVend1xx");
 } else {
  RM_Instruction.RM_InstructionType = 0;
 SendInstrutionstoMV(); 
// delay(1000);
//MVend();
 }
}
