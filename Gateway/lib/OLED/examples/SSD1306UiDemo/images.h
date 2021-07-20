#define LoRa_Logo_width 59
#define LoRa_Logo_height 39

#define WiFi_Logo_width 60
#define WiFi_Logo_height 36

#define HelTec_LOGO_width 128
#define HelTec_LOGO_height 53

#define BT_width 8
#define BT_height 10

#define BAT_width 20
#define BAT_height 9

#define WIFI_width 14
#define WIFI_height 8

const unsigned char LoRa_Logo_bits[] PROGMEM = {
  0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0x1F, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xFE, 0x01, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0xFF, 0xF1, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xF0, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x1E, 
  0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0xFF, 0xC1, 0xFF, 0x07, 0x00, 0x00, 
  0x1F, 0xC0, 0xFF, 0xE7, 0xFF, 0x0F, 0x00, 0x00, 0x1F, 0xC0, 0x83, 0xE7, 
  0xFF, 0x1F, 0x00, 0x00, 0x1F, 0x00, 0x00, 0xE0, 0xFF, 0x1F, 0x70, 0x00, 
  0x1F, 0x00, 0xFE, 0xE0, 0x03, 0x1F, 0xFE, 0x01, 0x1F, 0x00, 0xFF, 0xE1, 
  0x03, 0x1F, 0xFF, 0x03, 0x1F, 0x80, 0xFF, 0xE3, 0x03, 0x9F, 0xFF, 0x07, 
  0x1F, 0xC0, 0xFF, 0xE7, 0x03, 0x9F, 0xFF, 0x07, 0x1F, 0xC0, 0xC7, 0xE7, 
  0xFF, 0x9F, 0x8F, 0x07, 0x1F, 0xC0, 0x83, 0xE7, 0xFF, 0x0F, 0xF0, 0x07, 
  0x1F, 0xC0, 0x83, 0xE7, 0xFF, 0x07, 0xFF, 0x07, 0x1F, 0xC0, 0x83, 0xE7, 
  0xFF, 0x83, 0xFF, 0x07, 0x1F, 0xC0, 0x83, 0xE7, 0xE3, 0x87, 0x9F, 0x07, 
  0x1F, 0xC0, 0x83, 0xE7, 0xE3, 0xC7, 0x87, 0x07, 0xFF, 0xCF, 0xC7, 0xE7, 
  0xC3, 0xCF, 0xC7, 0x07, 0xFF, 0xCF, 0xFF, 0xE7, 0xC3, 0xDF, 0xFF, 0x07, 
  0xFF, 0x8F, 0xFF, 0xE3, 0x83, 0x9F, 0xFF, 0x07, 0xFF, 0x0F, 0xFF, 0xE1, 
  0x03, 0x1F, 0xFF, 0x07, 0xFF, 0x0F, 0xFE, 0xE0, 0x03, 0x1F, 0xBE, 0x07, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x83, 0x07, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x1E, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xE0, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0xFF, 0xF1, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0x1F, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char WiFi_Logo_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x07, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xE0, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF,
  0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
  0xFF, 0x03, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
  0x00, 0xFF, 0xFF, 0xFF, 0x07, 0xC0, 0x83, 0x01, 0x80, 0xFF, 0xFF, 0xFF,
  0x01, 0x00, 0x07, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x0C, 0x00,
  0xC0, 0xFF, 0xFF, 0x7C, 0x00, 0x60, 0x0C, 0x00, 0xC0, 0x31, 0x46, 0x7C,
  0xFC, 0x77, 0x08, 0x00, 0xE0, 0x23, 0xC6, 0x3C, 0xFC, 0x67, 0x18, 0x00,
  0xE0, 0x23, 0xE4, 0x3F, 0x1C, 0x00, 0x18, 0x00, 0xE0, 0x23, 0x60, 0x3C,
  0x1C, 0x70, 0x18, 0x00, 0xE0, 0x03, 0x60, 0x3C, 0x1C, 0x70, 0x18, 0x00,
  0xE0, 0x07, 0x60, 0x3C, 0xFC, 0x73, 0x18, 0x00, 0xE0, 0x87, 0x70, 0x3C,
  0xFC, 0x73, 0x18, 0x00, 0xE0, 0x87, 0x70, 0x3C, 0x1C, 0x70, 0x18, 0x00,
  0xE0, 0x87, 0x70, 0x3C, 0x1C, 0x70, 0x18, 0x00, 0xE0, 0x8F, 0x71, 0x3C,
  0x1C, 0x70, 0x18, 0x00, 0xC0, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x08, 0x00,
  0xC0, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x0C, 0x00, 0x80, 0xFF, 0xFF, 0x1F,
  0x00, 0x00, 0x06, 0x00, 0x80, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x07, 0x00,
  0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0xF8, 0xFF, 0xFF,
  0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x01, 0x00, 0x00,
  0x00, 0x00, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF,
  0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x1F, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x80, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  };

const unsigned char HelTec_LOGO_bits[] PROGMEM = {
  0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0xF0, 0x03, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x07, 0xF0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0xF0, 0x0F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x1F, 0xF0, 0x1F, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xE0, 0x1F, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xE0, 0x3F, 0xF8, 0x3F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0xF8, 0x3F, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xE0, 0x1F, 0xF8, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0xF8, 0x1F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0xFC, 0x1F, 
  0x80, 0xFF, 0x8F, 0x7F, 0xC0, 0xFF, 0x7F, 0xC0, 0xFF, 0x03, 0xC0, 0x3F, 
  0xF0, 0x1F, 0xFC, 0x1F, 0xE0, 0xFF, 0x87, 0x3F, 0xC0, 0xFF, 0x7F, 0xF0, 
  0xFF, 0x01, 0xF8, 0xFF, 0xF0, 0x0F, 0xFC, 0x1F, 0xE0, 0xFF, 0x87, 0x3F, 
  0xE0, 0xFF, 0x7F, 0xF8, 0xFF, 0x01, 0xFE, 0xFF, 0xF8, 0x0F, 0xFE, 0x0F, 
  0xF0, 0xFF, 0x87, 0x3F, 0xE0, 0xFF, 0x7F, 0xFC, 0xFF, 0x01, 0xFF, 0xFF, 
  0xF8, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF, 0xC7, 0x3F, 0xE0, 0xFF, 0x3F, 0xFC, 
  0xFF, 0x81, 0xFF, 0xFF, 0xF8, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF, 0xC3, 0x1F, 
  0xE0, 0xFF, 0x3F, 0xFC, 0xFF, 0xC0, 0xFF, 0x7F, 0xFC, 0xFF, 0xFF, 0x0F, 
  0xF8, 0xFF, 0xC3, 0x1F, 0xE0, 0xFF, 0x3F, 0xFC, 0xFF, 0xE0, 0xFF, 0x7F, 
  0xFC, 0xFF, 0xFF, 0x07, 0xF8, 0x03, 0xC0, 0x1F, 0x00, 0xFE, 0x01, 0xFE, 
  0x00, 0xF0, 0x3F, 0x70, 0xFC, 0xFF, 0xFF, 0x07, 0xF8, 0x03, 0xE0, 0x0F, 
  0x00, 0xFE, 0x00, 0xFE, 0x00, 0xF0, 0x1F, 0x60, 0xFC, 0xFF, 0xFF, 0x07, 
  0xF8, 0x03, 0xE0, 0x0F, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xF0, 0x07, 0x20, 
  0xFE, 0xFF, 0xFF, 0x07, 0xFC, 0xFF, 0xE1, 0x0F, 0x00, 0xFF, 0x00, 0xFF, 
  0x7F, 0xF8, 0x07, 0x00, 0xFE, 0x83, 0xFF, 0x03, 0xFC, 0xFF, 0xF1, 0x0F, 
  0x00, 0x7F, 0x00, 0xFF, 0x7F, 0xF8, 0x03, 0x00, 0xFE, 0x83, 0xFF, 0x03, 
  0xFC, 0xFF, 0xF0, 0x07, 0x00, 0x7F, 0x00, 0xFF, 0x7F, 0xFC, 0x03, 0x00, 
  0xFE, 0x81, 0xFF, 0x03, 0xFC, 0xFF, 0xF0, 0x07, 0x00, 0x7F, 0x00, 0xFF, 
  0x3F, 0xFC, 0x03, 0x00, 0xFF, 0xC1, 0xFF, 0x01, 0xFE, 0xFF, 0xF0, 0x07, 
  0x80, 0x3F, 0x80, 0xFF, 0x3F, 0xFC, 0x03, 0x00, 0xFF, 0xC1, 0xFF, 0x01, 
  0xFE, 0xFF, 0xF8, 0x07, 0x80, 0x3F, 0x80, 0xFF, 0x3F, 0xFC, 0x03, 0x10, 
  0xFF, 0xC1, 0xFF, 0x01, 0xFE, 0x00, 0xF8, 0x03, 0x80, 0x3F, 0x80, 0x3F, 
  0x00, 0xFC, 0x03, 0x0C, 0xFF, 0xC0, 0xFF, 0x01, 0xFF, 0x00, 0xF8, 0x03, 
  0xC0, 0x3F, 0x80, 0x3F, 0x00, 0xFC, 0x07, 0x0E, 0xFF, 0xE0, 0xFF, 0x00, 
  0x7F, 0x00, 0xF8, 0x03, 0xC0, 0x1F, 0xC0, 0x3F, 0x00, 0xFC, 0xFF, 0x0F, 
  0xFF, 0xE0, 0xFF, 0x00, 0xFF, 0x7F, 0xFC, 0xFF, 0xC1, 0x1F, 0xC0, 0xFF, 
  0x1F, 0xFC, 0xFF, 0x0F, 0x7F, 0xE0, 0xFF, 0x00, 0xFF, 0x3F, 0xFC, 0xFF, 
  0xC1, 0x1F, 0xC0, 0xFF, 0x0F, 0xF8, 0xFF, 0x07, 0x7E, 0xE0, 0xFF, 0x80, 
  0xFF, 0x3F, 0xFC, 0xFF, 0xE0, 0x1F, 0xC0, 0xFF, 0x0F, 0xF8, 0xFF, 0x07, 
  0x7C, 0xF0, 0x7F, 0x80, 0xFF, 0x3F, 0xFE, 0xFF, 0xE0, 0x0F, 0xE0, 0xFF, 
  0x0F, 0xF0, 0xFF, 0x07, 0xF8, 0xF0, 0x7F, 0x80, 0xFF, 0x1F, 0xFE, 0xFF, 
  0xE0, 0x0F, 0xE0, 0xFF, 0x0F, 0xE0, 0xFF, 0x07, 0xE0, 0xF0, 0x7F, 0x80, 
  0xFF, 0x1F, 0xFE, 0xFF, 0xE0, 0x0F, 0xE0, 0xFF, 0x07, 0x80, 0xFF, 0x03, 
  0x00, 0xF0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x3C, 0x00, 0x00, 0xF8, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x3F, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xF8, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x1F, 0x00, 0x8F, 0xF7, 0xFF, 0x7C, 
  0xBC, 0xC7, 0xF3, 0xFF, 0xFC, 0xBC, 0x07, 0x00, 0x00, 0xFC, 0x1F, 0x00, 
  0x8F, 0x73, 0xFF, 0xFE, 0xBE, 0xC7, 0xFB, 0xFF, 0xFE, 0xBD, 0x03, 0x00, 
  0x00, 0xFC, 0x1F, 0x80, 0x8F, 0x73, 0xFF, 0xEF, 0xFE, 0xE7, 0xFB, 0x77, 
  0xEF, 0xFD, 0x03, 0x00, 0x00, 0xFC, 0x1F, 0x80, 0xDF, 0x7B, 0x9C, 0xE7, 
  0xFE, 0xF7, 0xE3, 0x71, 0xE7, 0xFD, 0x03, 0x00, 0x00, 0xFC, 0x0F, 0xC0, 
  0xDF, 0x79, 0x9E, 0xE3, 0xFE, 0xF3, 0xE3, 0x78, 0xE7, 0xFF, 0x03, 0x00, 
  0x00, 0xFC, 0x0F, 0xE0, 0xDF, 0x39, 0x8E, 0xF3, 0xFF, 0xFB, 0xE7, 0xF8, 
  0xE7, 0xFE, 0x01, 0x00, 0x00, 0xFC, 0x0F, 0xE0, 0xDF, 0x3F, 0x8E, 0x7F, 
  0xFF, 0xFF, 0xE7, 0x38, 0x7F, 0xEE, 0x01, 0x00, 0x00, 0xF8, 0x0F, 0x70, 
  0xDC, 0x1F, 0x0E, 0x3F, 0xFF, 0x9D, 0xF7, 0x38, 0x3F, 0xEF, 0x01, 0x00, 
  0x00, 0xF8, 0x0F, 0x00, 0x00, 0x03, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 
  0x08, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x0F, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  };

const unsigned char BT_bits[] PROGMEM = {
  0x18, 0x28, 0x4A, 0x2C, 0x18, 0x2C, 0x4A, 0x28, 0x18, 0x00,
  };

const unsigned char BAT_bits[] PROGMEM = {
  0xFC, 0xFF, 0x0F, 0x04, 0x00, 0x08, 0xF7, 0xDE, 0x0B, 0xF1, 0xDE, 0x0B, 
  0xF1, 0xDE, 0x0B, 0xF1, 0xDE, 0x0B, 0xF7, 0xDE, 0x0B, 0x04, 0x00, 0x08, 
  0xFC, 0xFF, 0x0F,
  };

const unsigned char WIFI_bits[] PROGMEM = {
  0xF0, 0x03, 0x04, 0x08, 0xF2, 0x13, 0x09, 0x24, 0xE4, 0x09, 0x10, 0x02, 
  0xC0, 0x00, 0xC0, 0x00,
  };


//屏幕下方的小圆点
const unsigned char activeSymbol[] PROGMEM = {
    B00000000,
    B00000000,
    B00011000,
    B00100100,
    B01000010,
    B01000010,
    B00100100,
    B00011000
};

const unsigned char inactiveSymbol[] PROGMEM = {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00000000,
    B00000000
};
