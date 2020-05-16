/*
手持ちのLCDではうまくいかず。
インポートしたLiquidCrystal_I2C.h内のlcd関数を調べる必要がありそう。
ただ結局、当該LCDのSwitchScience HPで紹介されてたスケッチで動かせたので詳細は追わず。
*/

#include <LiquidCrystal_I2C.h>

#define lcdAddress 0x3A //上で確認したアドレスを書く。
#define lcdColumns 16 //使用するLCDの列数を書く
#define lcdRows 2  //使用するLCDの行数を書く

LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);

int column, row;
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

void setup() {
  lcd.init();//LCDを初期化する
  //lcd.backlight();//LCDのバックライトをオンにする
  lcd.createChar(0, heart);//上で宣言した文字を設定する
}

void loop() {
  column = 2;
  row = 0;
  lcd.setCursor(column, row); //カーソールを任意の場所に変更する
  lcd.print("Hello,world!");//任意の文字列を出力する
  
  column = 7;
  row = 1;
  lcd.setCursor(column, row); //カーソールを任意の場所に変更する
  lcd.write(0);//setupで設定した文字を出力する

}
