SparkFun Qwiic Pressure with LPS25HB
========================================

![Qwiic Pressure Sensor - LPS25HB](https://cdn.sparkfun.com/assets/parts/1/3/0/1/3/14767-Qwiic_Pressure_Sensor_-_LPS25HB-05.jpg)

[*Qwiic Pressure Sensor - LPS25HB (SPX-14767)*](https://www.sparkfun.com/products/14767)

The LPS25HB is an absolute pressure sensor which means that it has an internal vacuum as a reference. (As opposed to *differential* and *gage* sensors, see [this](https://cdn.sparkfun.com/assets/e/1/2/4/1/HoneywellTechnicalNote_Absolute_v_Gage_pressure.pdf) description by Honeywell for more info) Absolute pressure sensors are often used as altimeters however they can be seen in other applications like the [Robotic Finger Sensor v2](https://www.sparkfun.com/products/14687). 

You can use this absolute pressure sensor to inform a drone autopilot of altitude, make a personal weather station, or maybe even help test someone's lung function! As part of the Qwiic system adding more capabilities like data logging with the [Qwiic OpenLog](https://www.sparkfun.com/products/14641) is a cinch!

The LPS25HB is the newest version of the LPS25H by STMicroelectronics featuring the widest range of sensing pressures (26 kPa to 126 kPa) and very high precision (as low as 1 Pa RMS, which equates to approximately 8 centimeters of air at sea level). Other features such as the 25 Hz update rate and durability to withstand nearly 2.5 MPa over-pressure make this a great choice for absolute pressure sensor. Additionally the LPS25HB comes in a stylish plastic IC package, as opposed to the standard metal casing seen on most other pressure sensors.

In addition to the Qwiic connectors this sensor breakout exposes the I2C and SPI lines as plated through hole (PTH) connections on either side. SPI access will allow for even faster communication with the sensor (up to 10 MHz!) 

This board is one of our many [Qwiic](https://www.sparkfun.com/qwiic) compatible boards! Simply plug and go. No soldering, no figuring out which is SDA or SCL, and no voltage regulation or translation required!

SparkFun labored with love to create this code. Feel like supporting open source hardware? 
Buy a [breakout board](https://www.sparkfun.com/products/14688) from SparkFun!

Repository Contents
-------------------

* **/Documents** - Datasheets
* **/Hardware** - Eagle design files (.brd, .sch)

Library
--------------
* **[Arduino Library](https://github.com/sparkfun/SparkFun_LPS25HB_Arduino_Library)** - Library for reading pressure and changing sensor settings

License Information
-------------------

This product is _**open source**_! 

If you have any questions or concerns on licensing, please contact techsupport@sparkfun.com.

Please use, reuse, and modify these files as you see fit. Please maintain attribution to SparkFun Electronics and release any derivative under the same license.

Distributed as-is; no warranty is given.

- Your friends at SparkFun.