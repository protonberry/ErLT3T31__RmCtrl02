// ErLT3T31__RMCTRL02
//Save as main using EEPROM that does not work befor new branch to use Preferences
#define DEBUG true
#if DEBUG
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

#include "Arduino.h"
#include "img_logo.h"
#include "basicChkplus.h"
#include "ChkLogo240x135.h"
#include "pin_config.h"
#include "Board_Config.h"

#define FORMAT_SPIFFS_IF_FAILED true
#include "FS.h"
#include "SPIFFS.h"
#include <esp_now.h>
#include <WiFi.h>              // Built-in
#include <ESPmDNS.h>           // Built-in
#include <AsyncTCP.h>          // https://github.com/me-no-dev/AsyncTCP
#include <ESPAsyncWebServer.h> // https://github.com/me-no-dev/ESPAsyncWebServer
#include "esp_system.h"        // Built-in
#include "esp_spi_flash.h"     // Built-in
#include "esp_wifi_types.h"    // Built-in
#include "esp_bt.h"            // Built-in
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <EEPROM.h>
#include <Wire.h>
#include "OneButton.h"
#include "TFT_eSPI.h" /* Please use the TFT library provided in the library. */
#define LCD_MODULE_CMD_1
#include "DataStruc01.h"
#include "GlobalVar.h"
/* The product now has two screens, and the initialization code needs a small change in the new version. The LCD_MODULE_CMD_1 is used to define the
 * switch macro. */

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprSu = TFT_eSprite(&tft);  // Declare Sprite object "spr" with pointer to "tft" object
TFT_eSprite sprData = TFT_eSprite(&tft);  // Declare Sprite object "spr" with pointer to "tft" object
TFT_eSprite sprTor = TFT_eSprite(&tft);  // Declare Sprite object "spr" with pointer to "tft" object
TFT_eSprite sprMsg = TFT_eSprite(&tft);  // Declare Sprite object "spr" with pointer to "tft" object
TFT_eSprite sprDataOK = TFT_eSprite(&tft);  // Declare Sprite object "spr" with pointer to "tft" object

#include "Screens.h"

 
// Peer info
esp_now_peer_info_t peerInfo;
//*******************************************
OneButton buttonGreen(BUTTON_Green_PIN, true);
OneButton buttonRed(BUTTON_Red_PIN, true);
//################  VERSION for web site ###########################################
String Version = "1.0"; // Programme version, see change log at end


//################ VARIABLES ###########################################

AsyncWebServer server(80);

typedef struct
{
  String filename;
  String ftype;
  String fsize;
} fileinfo;

String webpage, MessageLine;
fileinfo Filenames[205]; // Enough for most purposes!
bool StartupErrors = false;
int start, downloadtime = 1, uploadtime = 1, downloadsize, uploadsize, downloadrate, uploadrate, numfiles;

//*****Versions*******
char Vnum[] = "04"; // MV31 working, save here as fall back
//char Vnum[] = "03"; // New Instr to MV, stop,set cal, reset fact settings
//char Vnum[] = "02"; // add espnow to send and received MV data
//char Vnum[] = "01"; // start with LT3 master and added E_LTMU11NA_NOW4



#include "FileDefinitions.h"

bool CheckforG_G()
{
  Bcode = 0;
  bool Q15 = false;
  buttonGreen.tick();
  if(Bcode == 15){ Q15 = true ;}
  return Q15 ; 
}
void SendInstrutionstoMV(){
esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &RM_Instruction, sizeof(RM_Instruction));
    debug("R=");debug(RM_Instruction.RM_InstructionType); debug(",");
    debug(RM_Instruction.RM_DegtoRotate); debug(",");
    debug(RM_Instruction.RM_RotationSpeed); debug(",");
    debug(RM_Instruction.RM_Reading_SpeedSPS); debug(",");
  
  if (result == ESP_OK) {
   Serial.println("Sending confirmed");
    debugln("RMsendOK");
}
  else {
    debugln("Sending error");
  }
}

 void SaveEEPROM()
{
  EEPROM.put(eeAddress100 + 14, Msel);
//  EEPROM.put(eeAddress100 + 25, Load_Calibration_Factor);
  EEPROM.put(eeAddress100 + 40, Test_ID);
  EEPROM.put(eeAddress100 + 44, ProjectID);
  EEPROM.put(eeAddress100 + 48, SampleID);
  EEPROM.put(eeAddress100 + 52, Blade);
  EEPROM.put(eeAddress100 + 56, Recordflag);
  EEPROM.put(eeAddress100 + 15, Locked);
  debugln(EEPROM.commit());
}
 #include "MVstartStop.h"
 #include "CallBacks.h"

//********************Button actions functions
//*****************************************************************

void clickGreen() { Bcode = 11; }
void doubleclickGreen() { Bcode = 12; }
void longPressStartGreen() { Bcode = 13; }
void longPressGreen() { Bcode = 14; }
void longPressStopGreen() { Bcode = 15; }
void clickRed() { Bcode = 31; }
void doubleclickRed() { Bcode = 32; }
void longPressStartRed() { Bcode = 33; }
void longPressRed() { Bcode = 34; }
void longPressStopRed() { Bcode = 35; }

#include "MV_31.h"
#include "MV_43.h"
#include "MV_50Torque.h"
#include "DecodeButtonPress.h"

void EditFields()
{
//  u8g2.setFont(u8g2_font_6x13_tr);
  FieldVal[1] = SampleID;
  FieldVal[2] = ProjectID;
  FieldVal[3] = Test_ID;
  FieldVal[4] = Blade;
  //    FieldVal[5] = Load_Calibration_Factor; FieldVal[6] = Blade;
  FieldVal[6] = Load_Calibration_Factor;
  FieldVal[5] = Recordflag;
  if (Msel == 2)
  {
    FieldStart = 1;
    NumFields = 4;
  }
  else
  {
    FieldStart = 5;
    NumFields = 2;
  }
  Vsel = FieldStart;
  //    debug("FieldStart ");debugln(FieldStart);
  // u8g2.clearBuffer();
  //PrintReverse();
  // u8g2.sendBuffer();
  // debugln("buff1 ");
  // delay(5000);
  while (Locked)
  {
    chk_buttons();
  }
  SampleID = FieldVal[1];
  ProjectID = FieldVal[2];
  Test_ID = FieldVal[3];
  Blade = FieldVal[4];
  Load_Calibration_Factor = FieldVal[6];
  Recordflag = FieldVal[5];
  //    Load_Calibration_Factor = FieldVal[5]; Blade = FieldVal[6];
  SaveEEPROM();
  MenuScreen(Msel);
}

void setup() {
  pinMode(PIN_POWER_ON, OUTPUT);
  digitalWrite(PIN_POWER_ON, HIGH);

  Serial.begin(115200);
  Serial.println("Hello T-Display-S3 w=");
  Serial.print(tft.width());
EEPROM.begin(EEPROM_SIZE);
  delay(100);
  debugln(Test_ID);
  debugln(ProjectID);
  debugln(SampleID);
  debugln(Blade);
  /*
  EEPROM.put(eeAddress100+14,Msel);
  EEPROM.put(eeAddress100+15,Locked);
  EEPROM.put(eeAddress100+25,Load_Calibration_Factor);
  EEPROM.put(eeAddress100+32,Torque_Calibration_Factor);
  EEPROM.put(eeAddress100+40,Test_ID);
  EEPROM.put(eeAddress100+44,ProjectID);
  EEPROM.put(eeAddress100+48,SampleID);
  EEPROM.put(eeAddress100+52,Blade);
  EEPROM.put(eeAddress100+56,Recordflag);
  EEPROM.commit();
  */
  delay(100);
  //EEPROM.get(eeAddress100 + 0, Serial_No);
  EEPROM.get(eeAddress100 + 14, Msel);
  EEPROM.get(eeAddress100 + 15, Locked);
  //EEPROM.get(eeAddress100 + 16, AllowableLoadgm);
  //EEPROM.get(eeAddress100 + 20, AllowableTorque);
  //EEPROM.get(eeAddress100 + 25, Load_Calibration_Factor);
  //EEPROM.get(eeAddress100 + 32, Torque_Calibration_Factor);
  EEPROM.get(eeAddress100 + 40, Test_ID);
  EEPROM.get(eeAddress100 + 44, ProjectID);
  EEPROM.get(eeAddress100 + 48, SampleID);
  EEPROM.get(eeAddress100 + 52, Blade);
  EEPROM.get(eeAddress100 + 56, Recordflag);
  /*
  debugln(Test_ID);
  debugln(ProjectID);
  debugln(SampleID);
  debugln(Blade);
  */
  
  tft.init();
  sprSu.createSprite(LFontPixH*4,LFontPixH*1.2);
  sprData.createSprite((ScreenW/2)-1,SFontPixH*1.2);
  sprTor.createSprite(XLFontPixH*4,1+XLFontPixH*1.2);
  sprMsg.createSprite(ScreenW*.25,1+SFontPixH*1.2);
  sprDataOK.createSprite(10,10);

#if defined(LCD_MODULE_CMD_1)
  for (uint8_t i = 0; i < (sizeof(lcd_st7789v) / sizeof(lcd_cmd_t)); i++) {
    tft.writecommand(lcd_st7789v[i].cmd);
    for (int j = 0; j < lcd_st7789v[i].len & 0x7f; j++) {
      tft.writedata(lcd_st7789v[i].data[j]);
    }

    if (lcd_st7789v[i].len & 0x80) {
      delay(120);
    }
  }
#endif

  tft.setRotation(3);
  tft.setSwapBytes(true);
/*
  tft.fillScreen(TFT_BLACK);
  tft.pushImage(0, 0, 320, 170, (uint16_t *)img_logo);
  delay(2000);
  tft.fillScreen(TFT_BLACK);
  tft.pushImage(96, 21, 127, 127, basicChkplus);
  delay(2000);
*/
  tft.fillScreen(TFT_BLACK);
  tft.pushImage((ScreenW-240)/2, (ScreenH-135)/2, 240, 135, ChkLogo240x135);
  delay(2000);

  ledcSetup(0, 2000, 8);
  ledcAttachPin(PIN_LCD_BL, 0);
  ledcWrite(0, 255);

// StupFile system********************************************************************
  WiFi.mode(WIFI_AP_STA); // *****
  
  // Initilize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
 
  // Register the send callback
  esp_now_register_send_cb(OnDataSent);
    // Register receive callback function
  esp_now_register_recv_cb(OnDataRecv);

  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

  WiFi.softAP(ssid, password);
  vTaskDelay(100 / portTICK_PERIOD_MS);
  IPAddress Ip(192, 168, 12, 25);
  IPAddress NMask(255, 255, 255, 0);
  WiFi.softAPConfig(Ip, Ip, NMask);
  IPAddress myIP = WiFi.softAPIP();
  debug("AP IP address: ");
  debugln(myIP);
  if (!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED))
  {
    debugln("SPIFFS Mount Failed");
    return;
  }
  // ##################### HOMEPAGE HANDLER ###########################
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    debugln("Home Page...");
#ifdef AccessControl
    //   if (!request->authenticate(http_username, http_password)) // Comment out to remove need for login username & password
    //     return request->requestAuthentication();                // Comment out to remove need for login username & password
#endif
    Home(); // Build webpage ready for display
    request->send(200, "text/html", webpage); });

  // ##################### DOWNLOAD HANDLER ##########################
  server.on("/download", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    debugln("Downloading file...");
    Select_File_For_Function("[DOWNLOAD]", "downloadhandler"); // Build webpage ready for display
    request->send(200, "text/html", webpage); });

  // ##################### DIR HANDLER ###############################
  server.on("/dir", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    debugln("File Directory...");
    Dir(request); // Build webpage ready for display
    request->send(200, "text/html", webpage); });

  // ##################### DELETE HANDLER ############################
  server.on("/delete", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    debugln("Deleting file...");
    Select_File_For_Function("[DELETE]", "deletehandler"); // Build webpage ready for display
    request->send(200, "text/html", webpage); });

  // ##################### NOT FOUND HANDLER #########################
  server.onNotFound(notFound);

  server.begin(); // Start the server
  if (!StartupErrors)
    debugln("System started successfully...");
  else
    debugln("There were problems starting all services...");
  Directory(); // Update the file list

//  link the button Green functions.
  buttonGreen.attachClick(clickGreen);
  buttonGreen.attachDoubleClick(doubleclickGreen);
  buttonGreen.attachLongPressStart(longPressStartGreen);
  buttonGreen.attachLongPressStop(longPressStopGreen);
  buttonGreen.attachDuringLongPress(longPressGreen);
  // link the button Red functions.
  buttonRed.attachClick(clickRed);
  buttonRed.attachDoubleClick(doubleclickRed);
  buttonRed.attachLongPressStart(longPressStartRed);
  buttonRed.attachLongPressStop(longPressStopRed);
  buttonRed.attachDuringLongPress(longPressRed);

  
Msel= 0 ;
RM_Instruction.RM_InstructionType = 0;
SendInstrutionstoMV(); 
vTaskDelay(500);
// sSerial_No = Serial_No;
  strcpy(sSerial_No, MV_Data.MVserial_No);
  strcat(sSerial_No, Vnum);






MenuScreen(Msel);

  debugln(Msel);
  debugln("Finished Setup");
 
}

double PrevMillis = 0;
void loop() {
//  if (EditFieldsFlag == 1) {EditFieldsFlag = EditFieldsFlag +1 ; EditFields();}
 if(NewMVdata && (MV_Data.MVstatus > 0)){
  sprDataOK.fillSprite(TFT_RED);
  if(MV_Data.MVsendOK) {sprDataOK.fillSprite(TFT_GREEN);}
 sprDataOK.pushSprite(ScreenW-10, ScreenH-10);

  if(Msel == 3) {MVtest31();}
//  if(Msel == 4) {MVtest43();}
  if(Msel == 5) {DispTorque();}
  if(MV_Data.MVstatus > 1){MVend();}
  NewMVdata = false;

   } 
  chk_buttons();
/*
if ( millis()-PrevMillis >10000 && MV_Data.MVstatus < 1){
  PrevMillis = millis() ;
  RM_Instruction.RM_InstructionType = 0 ;
 RM_Instruction.RM_DegtoRotate = 69. ;
 RM_Instruction.RM_Reading_SpeedSPS = 4. ;
 RM_Instruction.RM_RotationSpeed = 1818. ;
 delay(500);
  SendInstrutionstoMV();
}
  */
  }