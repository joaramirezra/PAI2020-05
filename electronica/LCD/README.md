## Instructions
Tutorial in :

https://blog.nikunjchauhan.com/how-to-use-i2c-lcd-with-arduino-uno-or-mega/

1.  select I2C library.zip form above downloaded file.
2.  Open the Ardino Software in your computer and from the menu bar of softer select the “sketch > Include library > add Zip library.”
3.  Now Select the file we downloaded before so the library will add automatically.
4.  Now its time to connect the I2C LCD with Arduino Boards. Connect SDA pin of LCD to SDA, SCL pin to SCL pin , VCC pin to 5V and GND to Ground  of Arduino uno or Mega. ( Pin Name of SDA and SCL will be found on  backside of board.)
5.  After connecting wired connect the arduino board to computer and open the scanner file from  above downloaded zip.
6.  Upload the scanner program to arduino baord.
7.  After uploading program open the serial monitor.
8.  In the serial monitor you will find the I2C LCD Address like “0 ×3F” etc. Note Down the address.
9.  Now open the Example Program attached and Replace the Address with own address.
10. Upload the Program and its Done.
