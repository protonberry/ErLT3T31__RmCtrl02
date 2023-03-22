//tft.setFreeFont()
#define Board 1
#if Board == 1
// Lilygo T-Display-S3 320x170 LT3
#define ScreenW  320 
#define ScreenH  170
#define XLFont setTextFont(6)
#define LFont setFreeFont( &FreeSans24pt7b)
#define MFont setFreeFont( &FreeSans18pt7b)
#define SFont setFreeFont( &FreeSans12pt7b)
#define XSFont setFreeFont( &FreeSans9pt7b)
#define XLFontPixH 36
#define LFontPixH 34
#define MFontPixH 26
#define SFontPixH 18
#define XSFontPixH 13
#endif
#if Board == 2
// Lilygo T-Display LTD
#define ScreenW  240
#define ScreenH  135
#define XLFont setTextFont(6)
#define LFont setFreeFont( &FreeSans18pt7b)
#define MFont setFreeFont( &FreeSans12pt7b)
#define SFont setFreeFont( &FreeSans9pt7b)
#define XSFont setFreeFont( &FreeSans9pt7b)
//#define XSFont tft.setTextFont(2)
#define XLFontPixH 36
#define LFontPixH 26
#define MFontPixH 18
#define SFontPixH 13
#define XSFontPixH 13
#endif
#if Board == 3
// Lilygo T-QT-S3 LQP
#define ScreenW  128
#define ScreenH  128
#define XLFont setFreeFont( &FreeSans18pt7b)
#define LFont setFreeFont( &FreeSans9pt7b)
#define MFont setFreeFont( &FreeSans9pt7b)
#define SFont setTextFont(2)
#define XSFont setTextFont(1)
#define XLFontPixH 26
#define LFontPixH 13
#define MFontPixH 13
#define SFontPixH 10
#define XSFontPixH 7
#endif
#if Board == 4
// Lilygo T-Doggle
#define ScreenW  160 
#define ScreenH  80
#define XLFont setFreeFont( &FreeSans18pt7b)
#define LFont setTextFont(4)
#define MFont setFreeFont( &FreeSans9pt7b)
#define SFont setTextFont(2)
#define XSFont setTextFont(1)
#define XLFontPixH 26
#define LFontPixH 18
#define MFontPixH 13
#define SFontPixH 10
#define XSFontPixH 7
#endif

/*
#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
#define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
//#define LOAD_FONT8N // Font 8. Alternative to Font 8 above, slightly narrower, so 3 digits fit a 160 pixel TFT
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts
tft.setFreeFont( &TomThumb); // 5v
tft.setFreeFont( &FreeSans9pt7b); // 11v
tft.setFreeFont( &FreeSans12pt7b); // 17v
tft.setFreeFont( &FreeSans18pt7b); // 25v
tft.setFreeFont( &FreeSans24pt7b); // 32v
tft.setTextFont(1); // 7v
tft.setTextFont(2); // 11v
tft.setTextFont(4); // 19v
tft.setTextFont(6); // 36v
#if Board == 1
// Lilygo T-Display-S3 320x170 LT3
#define ScreenW  320 
#define ScreenH  170
#define XXLargeFont &Font64rle
#define XLargeFont &FreeSans24pt7b
#define LargeFont &FreeSans18pt7b
#define MedFont &FreeSans12pt7b
#define SmallFont &FreeSans9pt7b
#define XSmallFont &glcdfont
#define XXSmallFont &TomThumb
#endif
#if Board == 2
// Lilygo T-Display LTD
#define ScreenW  240
#define ScreenH  135
#define XXLargeFont &Font64rle
#define XLargeFont &FreeSans18pt7b
#define LargeFont &FreeSans12pt7b
#define MedFont &FreeSans9pt7b
#define SmallFont &FreeSans9pt7b
#define XSmallFont &glcdfont
#define XXSmallFont &TomThumb
#endif
#if Board == 3
// Lilygo T-QT-S3 LQP
#define ScreenW  128
#define ScreenH  128
#define XXLargeFont &Font64rle
#define XLargeFont &FreeSans24pt7b
#define LargeFont &FreeSans18pt7b
#define MedFont &FreeSans18pt7b
#define SmallFont &FreeSans24pt7b
#define XSmallFont &glcdfont
#define XXSmallFont &TomThumb
#endif
#if Board == 4
// Lilygo T-Doggle
#define ScreenW  160 
#define ScreenH  80
#define XXLargeFont &Font64rle
#define XLargeFont &FreeSans24pt7b
#define LargeFont &FreeSans12pt7b
#define MedFont &FreeSans12pt7b
#define SmallFont &FreeSans9pt7b
#define XSmallFont &glcdfont
#define XXSmallFont &TomThumb
#endif
*/