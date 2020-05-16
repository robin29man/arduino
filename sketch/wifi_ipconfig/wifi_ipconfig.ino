
#include <WiFi.h>


void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.print("\n\n-----------------------\n");
  Serial.print("Program Start\n");
  
  WiFi.begin("IODATA-bf2a34-2G", "8625783654701"); // お使いのWiFiのSSID, パスワードに変更してください

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(WiFi.status());
    delay(500);
  }

  // 接続に成功したらIPアドレスを表示
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void loop() {
  // 3秒おきにシリアルモニタにHello Worldを表示
  Serial.print("Hello World!\n");
  delay(3000);
}
