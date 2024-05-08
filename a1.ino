#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN_1   9     // 第一个 RC522 模块的复位引脚
#define SS_PIN_1    10    // 第一个 RC522 模块的 SPI Slave Select 引脚

#define RST_PIN_2   9     // 第二个 RC522 模块的复位引脚
#define SS_PIN_2    8     // 第二个 RC522 模块的 SPI Slave Select 引脚

MFRC522 mfrc522_1(SS_PIN_1, RST_PIN_1); // 创建第一个 MFRC522 实例
MFRC522 mfrc522_2(SS_PIN_2, RST_PIN_2); // 创建第二个 MFRC522 实例
void setup() {
  // 啟動串列通訊，波特率設置為9600
  Serial.begin(9600);
  // 初始化一個LED燈，在13號腳位
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // 當接收到電腦端的數據時，點亮LED燈
    digitalWrite(13, HIGH);
    delay(1000); // 等待一秒
    digitalWrite(13, LOW);

    // 清空串列緩衝區
    while(Serial.available() > 0) {
      char t = Serial.read();
    }
  }
}