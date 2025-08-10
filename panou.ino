#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS     10
#define TFT_DC      9
#define TFT_RST     8

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

Servo myServo;
Servo myServo180;

int sensor_1 = A0;
int sensor_2 = A1;
int sensor_3 = A2;
int sensor_4 = A3;
int servo_360 = 3;
int servo_180 = 5;
int angle_180 = 90;
Servo myservo;

bool eZi = true; 

void setup() {
  myServo.attach(servo_360);
  myServo180.attach(servo_180);
  myServo180.write(90);

  pinMode(sensor_1, INPUT);
  pinMode(sensor_2, INPUT);
  pinMode(sensor_3, INPUT);
  pinMode(sensor_4, INPUT);

  Serial.begin(9600);

  tft.init(240, 240);
  tft.setRotation(0);
  tft.fillScreen(ST77XX_BLACK);
}


void deseneazaSoare() {
  tft.fillScreen(ST77XX_CYAN);
  tft.fillCircle(120, 120, 30, ST77XX_YELLOW);
  for (int i = 0; i < 360; i += 45) {
    int x1 = 120 + cos(radians(i)) * 40;
    int y1 = 120 + sin(radians(i)) * 40;
    int x2 = 120 + cos(radians(i)) * 60;
    int y2 = 120 + sin(radians(i)) * 60;
    tft.drawLine(x1, y1, x2, y2, ST77XX_YELLOW);
  }
}

void deseneazaLuna() {
  tft.fillScreen(ST77XX_BLUE);
  tft.fillCircle(120, 120, 30, ST77XX_WHITE);
  tft.fillCircle(110, 120, 30, ST77XX_BLUE); 
}


int move_360(Servo myservo, int s1, int s2, int s3, int s4) {
  int speed_trig = 97;
  int speed_inv_trig = 85;

  int val1 = analogRead(s1);
  int val2 = analogRead(s2);
  int val3 = analogRead(s3);
  int val4 = analogRead(s4) - 50;

  int treshold = 200;
  int val_right = max(val1, val3);
  int val_left = max(val2, val4);

  if (abs(val_right - val_left) > treshold) {
    if (val_right > val_left)
      myServo.write(speed_trig);
    else
      myServo.write(speed_inv_trig);
  } else {
    myServo.write(90);
  }
  delay(50);
}

int move_180(Servo myServo180, int s1, int s2, int s3, int s4) {
  int val1 = analogRead(s1);
  int val2 = analogRead(s2);
  int val3 = analogRead(s3);
  int val4 = analogRead(s4) - 50;

  int val_right = val1 + val3;
  int val_left = val2 + val4;
  int treshold = 350;

  if (abs(val_right - val_left) > treshold) {
    if (val_right > val_left && angle_180 < 135)
      angle_180 += 2;
    else if (val_right < val_left && angle_180 > 18)
      angle_180 -= 2;
    myServo180.write(angle_180);
  }
  delay(50);
}

void loop() {
  move_360(myservo, sensor_1, sensor_2, sensor_3, sensor_4);
  move_180(myServo180, sensor_1, sensor_2, sensor_3, sensor_4);

  int val1 = analogRead(sensor_1);
  int val2 = analogRead(sensor_2);
  int val3 = analogRead(sensor_3);
  int val4 = analogRead(sensor_4);

  tft.fillRect(0, 0, 240, 60, ST77XX_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_GREEN);
  tft.setCursor(10, 10); tft.print("S1: "); tft.print(val1);
  tft.setCursor(10, 30); tft.print("S2: "); tft.print(val2);
  tft.setCursor(130, 10); tft.print("S3: "); tft.print(val3);
  tft.setCursor(130, 30); tft.print("S4: "); tft.print(val4);

  int luminaTotala = val1 + val2 + val3 + val4;
  if (luminaTotala > 2500 && !eZi) {
    deseneazaSoare();
    eZi = true;
  }
  if (luminaTotala <= 2500 && eZi) {
    deseneazaLuna();
    eZi = false;
  }

  delay(100);
}