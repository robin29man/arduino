#include <Wire.h>
#include <WiFi.h>
 
#define PWR 17
#define GND 16
#define I2Cadr 0x3A // 固定
byte  VLCD = 27;  // コントラスト(0～63)

char ipadd;

void setup() {
  /*
  pinMode(GND, OUTPUT);
  digitalWrite(GND, LOW);
  pinMode(PWR, OUTPUT);
  digitalWrite(PWR, HIGH);
  */

  Wire.begin();
  delay(100);
  lcd_cmd(0x34);
  delay(5);
  lcd_cmd(0x34);
  delay(5);
  lcd_cmd(0x34);
  delay(40);

  Wire.beginTransmission(I2Cadr);
  Wire.write(0x00); // CO = 0,RS = 0
  Wire.write(0x35);
  Wire.write(0x41);
  Wire.write(0x80 | VLCD);
  Wire.write(0xC0 | VLCD);
  Wire.write(0x34);
  Wire.endTransmission();

  lcd_cmd(0x01);
  delay(400);

  lcd_cmd(0x0C);
  lcd_cmd(0x06);

  delay(500);
}

void loop() {

  lcd_setCursor(0, 0);
  lcd_printStr("Stay Home ");
  lcd_setCursor(0, 1);
  lcd_printStr(" Stay Healthy");
  delay(500);
  lcd_setCursor(0, 0);
  lcd_printStr(" Stay Home");
  lcd_setCursor(0, 1);
  lcd_printStr("Stay Healthy ");
  delay(500);
}

void lcd_cmd(unsigned char x) {
  Wire.beginTransmission(I2Cadr);
  Wire.write(0b00000000); // CO = 0,RS = 0
  Wire.write(x);
  Wire.endTransmission();
}

void lcd_data(unsigned char x){
  Wire.beginTransmission(I2Cadr);
  Wire.write(0b01000000); // CO = 0, RS = 1
  Wire.write(x ^ 0x80);
  Wire.endTransmission();
}

// 文字の表示
void lcd_printStr(const char *s) {
  Wire.beginTransmission(I2Cadr);
  while (*s) {
    if (*(s + 1)) {
      Wire.write(0b11000000); // CO = 1, RS = 1
      Wire.write(*s ^ 0x80);
    } else {
      Wire.write(0b01000000); // CO = 0, RS = 1
      Wire.write(*s ^ 0x80);
    }
    s++;
  }
  Wire.endTransmission();
}
 
// 表示位置の指定
void lcd_setCursor(unsigned char x, unsigned char y) {
  lcd_cmd(0x80 | (y * 0x40 + x));
}
