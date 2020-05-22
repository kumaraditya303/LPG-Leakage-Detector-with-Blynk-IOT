---
title: LPG Leakage Detector with Blynk IOT
description: This is Blynk IOT project which monitors the LPG sensor data 500 times, takes the average of sampling to reduce noise, notifies the user of the leakage and sends email
author: Kumar Aditya
ms.date: 22/05/2020
---

# LPG Leakage Detector with Blynk IOT
> [!NOTE]
> This is version v2.0 of the LPG Leakage Detector project . In the earlier project a custom library was used to send email whereas in this project Blynk IOT service is used for sending email and also supports notification!

**This is Blynk IOT project which monitors the LPG sensor data 500 times, takes the average of sampling to reduce noise, notifies the user of the leakage and sends email.
You need to download [Blynk app](https://play.google.com/store/apps/details?id=cc.blynk) from playstore and create an account and add my app to your account by scanning the QR Code.
<br>
Project [repository](https://github.com/rahuladitya303/LPG-Leakage-Detector-with-Blynk-IOT.git)<br>
Project [website](https://rahuladitya303.github.io/LPG-Leakage-Detector-with-Blynk-IOT/)<br>
Project [v1.0](https://github.com/rahuladitya303/ESP8266_LPG_Leakage_Email_Sender.git)**

# Getting Started with Arduino IDE
* Download the latest release from [GitHub](https://github.com/rahuladitya303/LPG-Leakage-Detector-with-Blynk-IOT.git)
* Change the credentials in the main file
```cpp
const char auth[] = "********"; // replace with AUTH token
const char ssid[] = "********"; // replace with SSID
const char password[] = "********"; // replace with PASSWORD
```
* Change your time zone 
```cpp
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000); // change time zone with 19800
```  

| Time zone  | Offset |
| :-----------: | :--------: |
| India | 19800|
| New York  | -18000 |
| London | 0 |

