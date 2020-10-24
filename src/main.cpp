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
 * @include WiFiUdp.h
 * @include NTPClient.h
*********************************************************************************************************************/
#include <Arduino.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
/**
 * setting up WiFi credentials
 * replace with your credentials
*/

const char auth[] = ""; // replace with AUTH token
const char ssid[] = "";                    // replace with SSID
const char password[] = "";                   // replace with PASSWORD
const int threshold = 200;                              // normal concentration not to be exceeded
const int nSampling = 500;                              // sampling rate
/**
 * @brief create instance of Blynk Timer
*/
BlynkTimer timer;
/**
 * @brief create instance of WiFiUDP client
 * @brief create ntp client to get current time 
 * Set Time Offset
 * 19800  --> India 
 * -18000 --> New York
 * 0      --> London
 * 
*/
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000); // change time zone with 19800
/**
 * @brief reads the LPG concentration with MQ 2 sensor and send email if it exceeds threshold
*/
void ICACHE_RAM_ATTR sendSensorData()
{
  // read sensor and take average of reading
  long total = 0;
  for (int i = 1; i <= nSampling; i++)
  {
    total += system_adc_read();
    delay(5);
  }
  total /= nSampling;
  // write sensor data to Virtual Pin 0
  Blynk.virtualWrite(V0, total);
  if (total >= threshold)
  {
    // send email & notification
    Blynk.notify("LPG Leakage Detected on " + timeClient.getFormattedTime());
    Blynk.email("LPG Leakage warning!", "LPG Leakage was detected at " + timeClient.getFormattedTime());
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
  timeClient.begin();
}

void loop()
{
  // run Blynk server and timer
  Blynk.run();
  timer.run();
  timeClient.update();
}
