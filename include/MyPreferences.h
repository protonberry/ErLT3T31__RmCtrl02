  EEPROM.put(eeAddress100 + 14, Msel);
//  EEPROM.put(eeAddress100 + 25, Load_Calibration_Factor);
  EEPROM.put(eeAddress100 + 40, Test_ID);
  EEPROM.put(eeAddress100 + 44, ProjectID);
  EEPROM.put(eeAddress100 + 48, SampleID);
  EEPROM.put(eeAddress100 + 52, Blade);
  EEPROM.put(eeAddress100 + 56, Recordflag);
  EEPROM.put(eeAddress100 + 15, Locked);


static volatile int Test_ID = 0;
int SampleID = 8;
int ProjectID = 3;
int Blade = 2;
int Recordflag = 2;
bool Locked = false;
static volatile bool MenuChgFlag = true;
uint8_t Msel = 0;





void InitEEvalues(){
   unsigned int Msel = EElike.getUInt("counter", 0); 
}