#pragma once
// Set your server access username and password here (OPTIONAL:)
const char* http_username = "admin";
const char* http_password = "admin";

// Set a server logical name, this gets translated to the physical IP address e.g. http://192.168.0.22
// NOTE: ONLY works if your browser supports this function
const char* ServerName    = "MVSaber";

// Set your Wi-Fi Credentials here
const char* ssid          = "ChkplusMV38";
const char* password      = "123456789";

//uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
//uint8_t broadcastAddress[] = {0x68, 0xB6, 0xB3, 0x23, 0x40, 0xD8};
//uint8_t broadcastAddress[] = {0x24, 0x6F, 0x28, 0x7A, 0x4A, 0x28};
uint8_t broadcastAddress[] = {0x4C, 0x75, 0x25, 0xA7, 0x87, 0xEC}; // MV UNIT38


/*ESP32S3*/
#define PIN_LCD_BL                   38

#define PIN_LCD_D0                   39
#define PIN_LCD_D1                   40
#define PIN_LCD_D2                   41
#define PIN_LCD_D3                   42
#define PIN_LCD_D4                   45
#define PIN_LCD_D5                   46
#define PIN_LCD_D6                   47
#define PIN_LCD_D7                   48

#define PIN_POWER_ON                 15

#define PIN_LCD_RES                  5
#define PIN_LCD_CS                   6
#define PIN_LCD_DC                   7
#define PIN_LCD_WR                   8
#define PIN_LCD_RD                   9

#define BUTTON_Red_PIN               0  //red/boot
#define BUTTON_Green_PIN             14 //green
#define PIN_BAT_VOLT                 4

#define I2C_SCL                      17
#define I2C_SDA                      18

#define PIN_TOUCH_INT                16
#define PIN_TOUCH_RES                21

//#define BTN1 36 //red/boot
//#define BTN2 34 //ENTER
//#define BTN3 14 //green
