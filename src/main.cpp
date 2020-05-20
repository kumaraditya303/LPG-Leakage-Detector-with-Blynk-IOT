/*********************************************************************************************************************
 * @file main.cpp
 * @author Kumar Aditya
 * @version 2.0
 * @date 20-05-2020
 * @rahuladitya303
 * @brief Reads the LPG concentration with MQ 2 sensor and send email & notification in case of leakage
*********************************************************************************************************************/

#define BLYNK_PRINT Serial
/*********************************************************************************************************************
 * @include Arduino.h
 * @include BlynkSimpleEsp8266.h
*********************************************************************************************************************/
#include <Arduino.h>
#include <BlynkSimpleEsp8266.h>

/**
 * setting up WiFi credentials
 * replace with your credentials
*/

const char auth[] = "Cd1kKPUH-vaaU0XBbN2bN1egE1vLFM6r"; // replace with AUTH token
const char ssid[] = "AndroidAPB9CF";                    // replace with SSID
const char password[] = "rahul12345";                   // replace with PASSWORD
const int threshold = 200;                              // normal concentration not to be exceeded
const int nSampling = 500;                              // sampling rate
/**
 * @brief create instance of Blynk Timer
*/
BlynkTimer timer;
/**
 * @brief reads the LPG concentration with MQ 2 sensor and send email if it exceeds threshold
*/
void ICACHE_RAM_ATTR sendSensorData()
{
  // read sensor and take average of reading
  long total = 0;
  for (int i = 1; i <= nSampling; i++)
  {

    int x = system_adc_read();
    total += x;
    delay(10);
  }
  total /= nSampling;
  // write sensor data to Virtual Pin 0
  Blynk.virtualWrite(V0, total);
  if (total >= threshold)
  {
    // send email & notification
    Blynk.notify("LPG Leakage Detected!");
    Blynk.email("LPG Leakage warning!", "Warning");
    delay(10000);
  }
}
void setup()
{
  // start serial communication
  Serial.begin(115200);
  // start Blynk server
  Blynk.begin(auth, ssid, password);
  timer.setInterval(100L, sendSensorData);
}

void loop()
{
  // run Blynk server and timer
  Blynk.run();
  timer.run();
}