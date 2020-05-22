# LPG Leakage Detector with Blynk IOT
> This is version v2.0 of the LPG Leakage Detector project . In the earlier project a custom library was used to send email whereas in this project Blynk IOT service is used for sending email and also supports notification!

**This is Blynk IOT project which monitors the LPG sensor data 500 times, takes the average of sampling to reduce noise, notifies the user of the leakage and sends email.
You need to download [Blynk app](https://play.google.com/store/apps/details?id=cc.blynk) from playstore and create an account and add my app to your account by scanning the QR Code.<br><br>
Project [v1.0](https://github.com/rahuladitya303/ESP8266_LPG_Leakage_Email_Sender.git)
<br>
Project [repository](https://github.com/rahuladitya303/LPG-Leakage-Detector-with-Blynk-IOT.git)<br>
Project [website](https://rahuladitya303.github.io/LPG-Leakage-Detector-with-Blynk-IOT/)<br>**

___

# Project Working
* Sensor Data Logging<br>
![IMAGE](https://hackster.imgix.net/uploads/attachments/1126073/screenshot_20200522-162634_blynk_Rqx406p0IK.jpg?auto=compress%2Cformat&w=680&h=510&fit=max)<br>
* LPG Leakage Notification<br>
![IMAGE](https://hackster.imgix.net/uploads/attachments/1126072/screenshot_20200522-162653_blynk_B0kt1D3sqq.jpg?auto=compress%2Cformat&w=680&h=510&fit=max)<br>
* LPG Leakage Email
![IMAGE](https://hackster.imgix.net/uploads/attachments/1126075/annotation_2020-05-22_163006_ADuiSFfOCA.jpg?auto=compress%2Cformat&w=680&h=510&fit=max)


___

# Getting Started 
## Prerequisites
* ESP8266 dev board or NodeMCU
* Android phone or iOS phone
* Arduino IDE or PlatformIO 
## Create account on Blynk
* Download Blynk on your mobile phone <br>
![IMAGE](https://hackster.imgix.net/uploads/attachments/1126055/screenshot_20200522-154941_google_play_store_rhPcQGN3p7.jpg?auto=compress%2Cformat&w=680&h=510&fit=max)
* Create a account <br>
![IMAGE](https://hackster.imgix.net/uploads/attachments/1126052/screenshot_20200522-155030_blynk_G527rKXeS6.jpg?auto=compress%2Cformat&w=680&h=510&fit=max)
* Scan the QR code with Blynk and you will get my project  <br>
![IMAGE](https://hackster.imgix.net/uploads/attachments/1126058/screenshot_20200522-155132_blynk_RvbXTOzrgU.jpg?auto=compress%2Cformat&w=680&h=510&fit=max)
* You will get my project and click on settings and click on email token to receive token on email <br>
![IMAGE](https://hackster.imgix.net/uploads/attachments/1126054/screenshot_20200522-155248_blynk_jSLVD3ZgtH.jpg?auto=compress%2Cformat&w=680&h=510&fit=max)
* Token would be used later in main file<br>
![IMAGE](https://hackster.imgix.net/uploads/attachments/1126050/annotation_2020-05-22_155848_qX6LCMdOwj.jpg?auto=compress%2Cformat&w=680&h=510&fit=max)<br>
* QR Code
![IMAGE](https://hackster.imgix.net/uploads/attachments/1126081/screenshot_20200522-160132_blynk_Lbhk68qcuR.jpg?auto=compress%2Cformat&w=680&h=510&fit=max)


## Build and upload project 
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

* Install the dependencies<br>
[Blynk](https://github.com/blynkkk/blynk-library.git)<br>
[NTPClient](https://github.com/arduino-libraries/NTPClient.git)<br>

* Upload the project to ESP8266 board.

___

# Project made and maintained by Kumar Aditya
