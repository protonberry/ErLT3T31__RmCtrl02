void DispTorque()
{
  if(TestinProgress) {

  sprTor.XLFont;
  sprTor.fillSprite(TFT_BLACK);
  sprTor.setTextColor(TFT_YELLOW);
  sprTor.setTextDatum(C_BASELINE);
  sprTor.drawNumber(MV_Data.MVtorque, LFontPixH*4/2,XLFontPixH);
  sprTor.pushSprite((ScreenW-LFontPixH*4)/2,ScreenH-XLFontPixH/2 - XLFontPixH);
   debug(TestinProgress);
   debug(":");
 debugln(MV_Data.MVstatus);
  }
}
void Torque50()
{
if(TestinProgress){
  RM_Instruction.RM_InstructionType = 0;
   SendInstrutionstoMV();
    TestinProgress = false ;


}  else 
{ RM_Instruction.RM_DegtoRotate = 10. ;
  RM_Instruction.RM_Reading_SpeedSPS = 3. ;
  RM_Instruction.RM_RotationSpeed = 0. ;
  RM_Instruction.RM_InstructionType = 1;
   SendInstrutionstoMV();
    TestinProgress = true ;
}
}
