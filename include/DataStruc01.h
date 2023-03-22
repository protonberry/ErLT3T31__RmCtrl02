// Define a data structure receive
typedef struct MVremote_instructions
{
  int8_t RM_InstructionType = 0; //  0 = Status, 1 = start test, 3 = Stop, 
                                 //5 = Save to EEPROM, 6 = reset to factory
  float RM_DegtoRotate = 0.;
  float RM_RotationSpeed = 0.;
  float RM_Reading_SpeedSPS = 0.;
  float RM_NewCalFactor = 0. ;
} MVremote_instructions;

// Create a structured object
MVremote_instructions RM_Instruction;

// Define a data structure Send
typedef struct MVstatus_results
{
  int8_t MVstatus = 0;
  // 0= Ready to test, 1 = testing results, 2 = stopped Max Torque,
  // 3 = Test stopped by user, 4 = Test completed
  int MVrotation = 0;
  int MVtorque = 0;
  bool MVsendOK = false ;
  char MVserial_No[15] = "              " ;
  float MVcalFact  = 0. ;
} MVstatus_results;

// Create a structured object
MVstatus_results MV_Data;

#if defined(LCD_MODULE_CMD_1)
typedef struct {
  uint8_t cmd;
  uint8_t data[14];
  uint8_t len;
} lcd_cmd_t;
lcd_cmd_t lcd_st7789v[] = {
    {0x11, {0}, 0 | 0x80},
    {0x3A, {0X05}, 1},
    {0xB2, {0X0B, 0X0B, 0X00, 0X33, 0X33}, 5},
    {0xB7, {0X75}, 1},
    {0xBB, {0X28}, 1},
    {0xC0, {0X2C}, 1},
    {0xC2, {0X01}, 1},
    {0xC3, {0X1F}, 1},
    {0xC6, {0X13}, 1},
    {0xD0, {0XA7}, 1},
    {0xD0, {0XA4, 0XA1}, 2},
    {0xD6, {0XA1}, 1},
    {0xE0, {0XF0, 0X05, 0X0A, 0X06, 0X06, 0X03, 0X2B, 0X32, 0X43, 0X36, 0X11, 0X10, 0X2B, 0X32}, 14},
    {0xE1, {0XF0, 0X08, 0X0C, 0X0B, 0X09, 0X24, 0X2B, 0X22, 0X43, 0X38, 0X15, 0X16, 0X2F, 0X37}, 14},
};
#endif
