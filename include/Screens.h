// Menu Screens ***********************************************

void SoilSaber0()
{
 // tft.fillScreen(TFT_BLACK);
  tft.fillRectVGradient(0,0,ScreenW -1,ScreenH-1,TFT_SKYBLUE,TFT_BROWN);
  tft.drawRect(0,0,ScreenW -1,ScreenH-1,TFT_WHITE);
tft.drawRect(0,0,ScreenW,ScreenH,TFT_BLUE);
//tft.drawRect(0,0,tft.width(),tft.height(),TFT_RED);

  tft.LFont;
  tft.setTextDatum(C_BASELINE);
  tft.setTextColor(TFT_RED);
  int lineStart = LFontPixH + LFontPixH/4;
  tft.drawString("SoilSaber MV", ScreenW/2,lineStart);

  lineStart= lineStart + int(1.4*MFontPixH) ;
  tft.setTextColor(TFT_DARKCYAN);
  tft.MFont;
  tft.drawString("Check Plus", ScreenW/2,lineStart);
  
  lineStart= lineStart + int(1.3*MFontPixH) ;
  tft.drawString("Innovation, LLC", ScreenW/2,lineStart);

    if (XSFontPixH == 7) { lineStart= lineStart + int(1.3*XSFontPixH) - XSFontPixH ; } // Font 1
    else {lineStart= lineStart + int(1.6*XSFontPixH) ;}
  tft.XSFont;
  tft.setTextColor(TFT_BLUE);
  tft.drawString("Click    to continue", ScreenW/2, lineStart);

if(XSFontPixH == 7) {   tft.fillCircle((ScreenW/2)-tft.textWidth("Click    to continue")*.16, lineStart + XSFontPixH/2, XSFontPixH/2, TFT_GREEN);
lineStart= lineStart + int(1.3*SFontPixH) +XSFontPixH ; } // if previous is font 1

 else {tft.fillCircle((ScreenW/2)-tft.textWidth("Click    to continue")*.16, lineStart - XSFontPixH/2, XSFontPixH/2, TFT_GREEN);
lineStart= lineStart + int(1.6*SFontPixH) ;}
  tft.setTextColor(TFT_YELLOW);
tft.SFont;
  tft.drawString( sSerial_No, ScreenW/2, lineStart);
}

void ButtonClick1()
{
//tft.fillScreen(TFT_BLACK);
//  tft.fillRectVGradient(0,0,ScreenW -1,ScreenH-1,TFT_SKYBLUE,TFT_BROWN);
  tft.drawRect(0,0,ScreenW -1,ScreenH-1,TFT_WHITE);
  tft.MFont;
  tft.setTextDatum(C_BASELINE);
  tft.setTextColor(TFT_GREEN);
  int lineStart = MFontPixH + MFontPixH/8;
  tft.drawString("BUTTON CLICKS", ScreenW/2,lineStart);

tft.SFont;
tft.setTextColor(TFT_CYAN);
tft.setTextDatum(L_BASELINE);
lineStart= lineStart + int(1.6*SFontPixH) ;
tft.drawString("Next Field", ScreenW*.33,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);
tft.fillCircle(2.5*SFontPixH, lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);

lineStart= lineStart + int(1.3*SFontPixH) ;
tft.drawString("Lock/Unlock", ScreenW*.33,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);
tft.fillCircle(SFontPixH+2.5*SFontPixH, lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);
tft.fillCircle(SFontPixH+1.6*SFontPixH ,lineStart - SFontPixH/2, SFontPixH/9, TFT_RED);
tft.fillCircle(SFontPixH+.9*SFontPixH, lineStart - SFontPixH/2, SFontPixH/9, TFT_RED);

lineStart= lineStart + int(2.*SFontPixH) ;
tft.drawString("Up/Inc", ScreenW*.33,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_GREEN);

lineStart= lineStart + int(1.3*SFontPixH) ;
tft.drawString("Down/Dec", ScreenW*.33,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_GREEN);
tft.fillCircle(2.5*SFontPixH, lineStart - SFontPixH/2, SFontPixH/2, TFT_GREEN);

lineStart= lineStart + int(1.3*SFontPixH) ;
tft.drawString("Fast Inc", ScreenW*.33,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_GREEN);
tft.fillCircle(SFontPixH+0.9*SFontPixH, lineStart - SFontPixH/2, SFontPixH/9, TFT_GREEN);
tft.fillCircle(SFontPixH+1.4*SFontPixH ,lineStart - SFontPixH/2, SFontPixH/9, TFT_GREEN);
tft.fillCircle(SFontPixH+1.9*SFontPixH, lineStart - SFontPixH/2, SFontPixH/9, TFT_GREEN);
tft.fillCircle(SFontPixH+2.4*SFontPixH, lineStart - SFontPixH/2, SFontPixH/9, TFT_GREEN);
}

void SampleData2()
{
//  tft.fillScreen(TFT_BLACK);
//  tft.fillRectVGradient(0,0,ScreenW -1,ScreenH-1,TFT_SKYBLUE,TFT_BROWN);
  tft.drawRect(0,0,ScreenW -1,ScreenH-1,TFT_WHITE);
  tft.MFont;
  tft.setTextDatum(C_BASELINE);
  tft.setTextColor(TFT_GREEN);
  int lineStart = MFontPixH + MFontPixH/8;
  tft.drawString("SAMPLE DATA", ScreenW/2,lineStart);

  tft.SFont;
tft.setTextColor(TFT_CYAN);
tft.setTextDatum(L_BASELINE);
lineStart= lineStart + int(1.6*SFontPixH) ;
tft.drawString("Lock-chg / unL-save", ScreenW*.25,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);
tft.fillCircle(SFontPixH+2.5*SFontPixH, lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);
tft.fillCircle(SFontPixH+1.6*SFontPixH ,lineStart - SFontPixH/2, SFontPixH/9, TFT_RED);
tft.fillCircle(SFontPixH+.9*SFontPixH, lineStart - SFontPixH/2, SFontPixH/9, TFT_RED);

tft.setTextDatum(L_BASELINE);
lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("Next Field", ScreenW*.25,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);
tft.fillCircle(2.5*SFontPixH, lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);

tft.setTextDatum(R_BASELINE);

S2YPosSampleID = lineStart= lineStart + int(1.3*SFontPixH) ;
tft.drawString("Sample ID:", ScreenW/2,lineStart);

S2YPosProjectID = lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("Proj ID:", ScreenW/2,lineStart);

S2YPosLastSeq = lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("Lst Seq Ct:", ScreenW/2,lineStart);
  
S2YPosBld = lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("Blade:", ScreenW/2,lineStart);
}

void TestMV3()
  {
  bool Locked = false;
//  tft.fillScreen(TFT_BLACK);
//  tft.fillRectVGradient(0,0,ScreenW -1,ScreenH-1,TFT_SKYBLUE,TFT_BROWN);
//  tft.drawRect(0,0,ScreenW -1,ScreenH-1,TFT_WHITE);
//tft.drawRect(0,0,ScreenW,ScreenH,TFT_BLUE);
//tft.drawRect(0,0,tft.width(),tft.height(),TFT_RED);
  tft.MFont;
  tft.setTextDatum(C_BASELINE);
  if (Locked) tft.setTextColor(TFT_RED); else tft.setTextColor(TFT_GREEN);
  int lineStart = MFontPixH + MFontPixH/8;
  tft.drawString("TEST MV", ScreenW/2,lineStart);
 
 tft.SFont;
tft.setTextColor(TFT_CYAN);
tft.setTextDatum(L_BASELINE);

S3YPosSS = lineStart= lineStart + int(1.3*SFontPixH) ;
tft.drawString("Start/Stop", ScreenW*.25,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_GREEN);
tft.fillCircle(SFontPixH+2.5*SFontPixH, lineStart - SFontPixH/2, SFontPixH/2, TFT_GREEN);
tft.fillCircle(SFontPixH+1.6*SFontPixH ,lineStart - SFontPixH/2, SFontPixH/9, TFT_GREEN);
tft.fillCircle(SFontPixH+.9*SFontPixH, lineStart - SFontPixH/2, SFontPixH/9, TFT_GREEN);

 S3YPosBld = S3YPosfn = lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("Bld:", 2,lineStart);
tft.drawString("fn:", ScreenW/2,lineStart);

 S3YPosSu = S3YPosRot = lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("Su=", 2,lineStart);
tft.drawString("Rot=", ScreenW/2,lineStart);
tft.setTextDatum(R_BASELINE);
tft.drawString("deg", ScreenW-2,lineStart);

 lineStart= lineStart + int(SFontPixH/4) ;
tft.drawFastHLine(0,lineStart,ScreenW, TFT_WHITE);

 tft.setTextDatum(C_BASELINE);
 lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("MAX Su, psf", ScreenW/2,lineStart);
/*
tft.MFont;
 tft.setTextColor(TFT_YELLOW);
tft.setTextDatum(C_BASELINE);
 lineStart= lineStart + int(1.2*MFontPixH) ;
tft.drawString("1234", ScreenW/2,ScreenH-MFontPixH/2);
*/
tft.LFont;
 tft.setTextColor(TFT_YELLOW);
tft.setTextDatum(C_BASELINE);
 S3YPosMaxSu = lineStart= lineStart + int(1.2*LFontPixH) ;
tft.drawString("0000", ScreenW/2,ScreenH-LFontPixH/3);

 
  }

void TestMVur4()
  {
  bool Locked = false;
 // tft.fillScreen(TFT_BLACK);
//  tft.fillRectVGradient(0,0,ScreenW -1,ScreenH-1,TFT_SKYBLUE,TFT_BROWN);
  tft.drawRect(0,0,ScreenW -1,ScreenH-1,TFT_WHITE);
  tft.MFont;
  tft.setTextDatum(C_BASELINE);
  if (Locked) tft.setTextColor(TFT_RED); else tft.setTextColor(TFT_GREEN);
  int lineStart = MFontPixH + MFontPixH/8;
  tft.drawString("TEST MV U+R", ScreenW/2,lineStart);
 
 tft.SFont;
tft.setTextColor(TFT_CYAN);
tft.setTextDatum(L_BASELINE);

 lineStart= lineStart + int(1.3*SFontPixH) ;
tft.drawString("Start/Stop", ScreenW*.25,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_GREEN);
tft.fillCircle(SFontPixH+2.5*SFontPixH, lineStart - SFontPixH/2, SFontPixH/2, TFT_GREEN);
tft.fillCircle(SFontPixH+1.6*SFontPixH ,lineStart - SFontPixH/2, SFontPixH/9, TFT_GREEN);
tft.fillCircle(SFontPixH+.9*SFontPixH, lineStart - SFontPixH/2, SFontPixH/9, TFT_GREEN);

 S4YPosBld = S4YPosfn = lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("Bld:", 2,lineStart);
tft.drawString("fn:", ScreenW/2,lineStart);

 S4YPosS = S4YPosRot = lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("S=", 2,lineStart);
tft.drawString("Rot=", ScreenW/2,lineStart);
tft.setTextDatum(R_BASELINE);
tft.drawString("deg", ScreenW-2,lineStart);

 lineStart= lineStart + int(SFontPixH/4) ;
tft.drawFastHLine(0,lineStart,ScreenW, TFT_WHITE);

 tft.setTextDatum(C_BASELINE);
 lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("MAX, psf", ScreenW/2,lineStart);
tft.drawString("Su", ScreenW*.2,lineStart);
tft.drawString("Sr", ScreenW*.8,lineStart);
/*
tft.MFont;
 tft.setTextColor(TFT_YELLOW);
tft.setTextDatum(C_BASELINE);
 lineStart= lineStart + int(1.2*MFontPixH) ;
tft.drawString("1234", ScreenW/2,ScreenH-MFontPixH/2);
*/
tft.LFont;
 tft.setTextColor(TFT_YELLOW);
tft.setTextDatum(C_BASELINE);
 S4YPosMaxSu = S4YPosMaxSr = lineStart= lineStart + int(1.2*LFontPixH) ;
tft.drawString("0000", ScreenW*.2,ScreenH-LFontPixH/3);
tft.drawString("0000", ScreenW*.8,ScreenH-LFontPixH/3);
  }
 
 void Torque5()
{
   bool Locked = false;
//  tft.fillScreen(TFT_BLACK);
//  tft.fillRectVGradient(0,0,ScreenW -1,ScreenH-1,TFT_SKYBLUE,TFT_BROWN);
  tft.drawRect(0,0,ScreenW -1,ScreenH-1,TFT_WHITE);
  tft.MFont;
  tft.setTextDatum(C_BASELINE);
  if (Locked) tft.setTextColor(TFT_RED); else tft.setTextColor(TFT_GREEN);
  int lineStart = MFontPixH + MFontPixH/8;
  tft.drawString("TORQUE", ScreenW/2,lineStart);
 
 tft.SFont;
tft.setTextColor(TFT_CYAN);
tft.setTextDatum(L_BASELINE);

 lineStart= lineStart + int(1.8*SFontPixH) ;
tft.drawString("Start/Stop", ScreenW*.25,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_GREEN);
tft.fillCircle(SFontPixH+2.5*SFontPixH, lineStart - SFontPixH/2, SFontPixH/2, TFT_GREEN);
tft.fillCircle(SFontPixH+1.6*SFontPixH ,lineStart - SFontPixH/2, SFontPixH/9, TFT_GREEN);
tft.fillCircle(SFontPixH+.9*SFontPixH, lineStart - SFontPixH/2, SFontPixH/9, TFT_GREEN);

  lineStart= lineStart + int(SFontPixH/2) ;
tft.drawFastHLine(0,lineStart,ScreenW, TFT_WHITE);

  tft.setTextDatum(C_BASELINE);
 lineStart= lineStart + int(1.5*SFontPixH) ;
tft.drawString("Torque, in-Lbs", ScreenW/2,lineStart);

 tft.XLFont;
 tft.setTextColor(TFT_YELLOW);
tft.setTextDatum(C_BASELINE);
 S5YPosMaxTorque = lineStart= lineStart + int(1.2*XLFontPixH) ;
tft.drawString("0000", ScreenW*.5,ScreenH-XLFontPixH/2);
}
 
 void Calibration6()
{
//  tft.fillScreen(TFT_BLACK);
//  tft.fillRectVGradient(0,0,ScreenW -1,ScreenH-1,TFT_SKYBLUE,TFT_BROWN);
  tft.drawRect(0,0,ScreenW -1,ScreenH-1,TFT_WHITE);
  tft.MFont;
  tft.setTextDatum(C_BASELINE);
  tft.setTextColor(TFT_GREEN);
  int lineStart = MFontPixH + MFontPixH/8;
  tft.drawString("CALIBRATION", ScreenW/2,lineStart);

  tft.SFont;
tft.setTextColor(TFT_CYAN);
tft.setTextDatum(L_BASELINE);
lineStart= lineStart + int(1.6*SFontPixH) ;
tft.drawString("Lock-chg / unL-save", ScreenW*.25,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);
tft.fillCircle(SFontPixH+2.5*SFontPixH, lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);
tft.fillCircle(SFontPixH+1.6*SFontPixH ,lineStart - SFontPixH/2, SFontPixH/9, TFT_RED);
tft.fillCircle(SFontPixH+.9*SFontPixH, lineStart - SFontPixH/2, SFontPixH/9, TFT_RED);

tft.setTextDatum(L_BASELINE);
lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("Next Field", ScreenW*.25,lineStart);
tft.fillCircle(SFontPixH ,lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);
tft.fillCircle(2.5*SFontPixH, lineStart - SFontPixH/2, SFontPixH/2, TFT_RED);

tft.setTextDatum(R_BASELINE);

S6YPosRecData = lineStart= lineStart + int(2.3*SFontPixH) ;
tft.drawString("RecData?:", ScreenW/2,lineStart);

S6YPosCalFactor = lineStart= lineStart + int(2.*SFontPixH) ;
tft.drawString("CalFactor:", ScreenW/2,lineStart);
/*
lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("Lst Seq Ct:", ScreenW/2,lineStart);
  
lineStart= lineStart + int(1.2*SFontPixH) ;
tft.drawString("Blade:", ScreenW/2,lineStart);
*/
}

void ScreenSizes() {
  tft.drawRect(0,0,319,169,TFT_WHITE);
  tft.drawRect(0,0,239,134,TFT_WHITE);
  tft.drawRect(0,0,127,127,TFT_WHITE);
  tft.drawRect(0,0,159,79,TFT_WHITE);
  tft.drawRect(0,0,127,63,TFT_WHITE);
 }
void MenuScreen(int CurrentDisplay)
{
  tft.fillScreen(TFT_BLACK);
  tft.setTextDatum(TL_DATUM);
  tft.MFont;
  tft.setTextColor(TFT_WHITE);
  tft.drawNumber(CurrentDisplay,0,0);
  
  switch (CurrentDisplay)
  {

  case 0:
    SoilSaber0();
    break;
  case 1:
    ButtonClick1();
    break;
  case 2:
    SampleData2();
    break;
  case 3:
    TestMV3();
    break;
  case 4:
    TestMVur4();
    break;
  case 5:
    Torque5();
    break;
  case 6:
    Calibration6();
    break;
  }
}