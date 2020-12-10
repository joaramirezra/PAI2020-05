EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "PCB sensorica respirador"
Date "2020-05-04"
Rev "V1.0"
Comp "powered by Datalica"
Comment1 ""
Comment2 ""
Comment3 "licences : creative commons v4.0"
Comment4 "Autor : Johan Ramirez"
$EndDescr
$Comp
L Connector:Conn_01x05_Male Conector_mancho
U 1 1 5EB0C22E
P 2250 1450
F 0 "Conector_mancho" H 2700 1100 50  0000 C CNN
F 1 "Conector_PCB" H 2300 1800 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x05_P1.27mm_Vertical" H 2250 1450 50  0001 C CNN
F 3 "~" H 2250 1450 50  0001 C CNN
	1    2250 1450
	1    0    0    -1  
$EndComp
Text GLabel 2450 1250 2    50   Input ~ 0
5V
Text GLabel 2450 1350 2    50   Input ~ 0
3.3V
Text GLabel 2450 1450 2    50   Input ~ 0
GND
Text GLabel 2450 1550 2    50   Input ~ 0
Rx
Text GLabel 2450 1650 2    50   Input ~ 0
Tx
Text GLabel 7750 1650 1    50   Input ~ 0
5V
Text GLabel 7750 4750 3    50   Input ~ 0
GND
$Comp
L ABP_Sensor:ABPDANT015PGAA5 S3
U 1 1 5EB1E6EE
P 2350 7250
F 0 "S3" H 2200 7400 50  0000 C CNN
F 1 "ABPDANT015PGAA5" H 2350 7000 50  0000 C CNN
F 2 "" H 1900 7300 50  0001 C CNN
F 3 "" H 1900 7300 50  0001 C CNN
	1    2350 7250
	1    0    0    -1  
$EndComp
$Comp
L ABP_Sensor:ABPDANT015PGAA5 S21
U 1 1 5EB23E0B
P 1500 5500
F 0 "S21" H 1350 5650 50  0000 C CNN
F 1 "ABPDANT060MGAA5" H 1500 5250 50  0000 C CNN
F 2 "" H 1050 5550 50  0001 C CNN
F 3 "" H 1050 5550 50  0001 C CNN
	1    1500 5500
	1    0    0    -1  
$EndComp
$Comp
L ABP_Sensor:ABPDANT015PGAA5 S22
U 1 1 5EB243D5
P 3400 5500
F 0 "S22" H 3250 5650 50  0000 C CNN
F 1 "ABPDANT060MGAA5" H 3400 5250 50  0000 C CNN
F 2 "" H 2950 5550 50  0001 C CNN
F 3 "" H 2950 5550 50  0001 C CNN
	1    3400 5500
	1    0    0    -1  
$EndComp
Text GLabel 1900 7200 0    50   Input ~ 0
GND
Text GLabel 1100 5450 0    50   Input ~ 0
GND
Text GLabel 3000 5450 0    50   Input ~ 0
GND
Text GLabel 2750 7200 2    50   Input ~ 0
5V
Text GLabel 1900 5450 2    50   Input ~ 0
5V
Text GLabel 3800 5450 2    50   Input ~ 0
5V
Text GLabel 2050 7400 0    50   Input ~ 0
Vout_s3
Text GLabel 1200 5650 0    50   Input ~ 0
Vout_s21
Text GLabel 3100 5650 0    50   Input ~ 0
Vout_s22
$Comp
L ABP_Sensor:Gage_P_sensor ABPDJJT001PDSA3
U 1 1 5EB1C1B5
P 2500 3450
F 0 "ABPDJJT001PDSA3" H 2500 3250 50  0000 C CNN
F 1 "S1" H 2350 3650 50  0000 C CNN
F 2 "" H 2500 3450 50  0001 C CNN
F 3 "" H 2500 3450 50  0001 C CNN
	1    2500 3450
	1    0    0    -1  
$EndComp
Text GLabel 1750 3200 0    50   Input ~ 0
GND
Text GLabel 1750 3500 0    50   Input ~ 0
3.3V
$Comp
L Device:C c3
U 1 1 5EB48D02
P 2350 6900
F 0 "c3" V 2200 6850 50  0000 C CNN
F 1 "0.1uF" V 2500 7000 50  0000 C CNN
F 2 "" H 2388 6750 50  0001 C CNN
F 3 "~" H 2350 6900 50  0001 C CNN
	1    2350 6900
	0    1    1    0   
$EndComp
$Comp
L Device:C c21
U 1 1 5EB4B8C8
P 1500 5150
F 0 "c21" V 1350 5100 50  0000 C CNN
F 1 "0.1uF" V 1650 5250 50  0000 C CNN
F 2 "" H 1538 5000 50  0001 C CNN
F 3 "~" H 1500 5150 50  0001 C CNN
	1    1500 5150
	0    1    1    0   
$EndComp
$Comp
L Device:C c22
U 1 1 5EB4BB91
P 3400 5150
F 0 "c22" V 3250 5100 50  0000 C CNN
F 1 "0.1uF" V 3550 5250 50  0000 C CNN
F 2 "" H 3438 5000 50  0001 C CNN
F 3 "~" H 3400 5150 50  0001 C CNN
	1    3400 5150
	0    1    1    0   
$EndComp
$Comp
L Device:C c1
U 1 1 5EB513FD
P 1850 3350
F 0 "c1" H 1965 3396 50  0000 L CNN
F 1 "0.1uF" H 1965 3305 50  0000 L CNN
F 2 "" H 1888 3200 50  0001 C CNN
F 3 "~" H 1850 3350 50  0001 C CNN
	1    1850 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3350 2200 3200
Wire Wire Line
	2200 3200 1850 3200
Wire Wire Line
	2200 3450 2050 3450
Wire Wire Line
	2050 3450 2050 3500
Wire Wire Line
	2050 3500 1850 3500
Wire Wire Line
	2500 6900 2650 6900
Wire Wire Line
	2650 6900 2650 7200
Wire Wire Line
	2750 7200 2650 7200
Connection ~ 2650 7200
Wire Wire Line
	2200 6900 2050 6900
Wire Wire Line
	2050 6900 2050 7200
Wire Wire Line
	1900 7200 2050 7200
Connection ~ 2050 7200
Wire Wire Line
	3550 5150 3700 5150
Wire Wire Line
	3700 5150 3700 5450
Wire Wire Line
	3250 5150 3100 5150
Wire Wire Line
	3100 5150 3100 5450
Wire Wire Line
	3000 5450 3100 5450
Connection ~ 3100 5450
Wire Wire Line
	3800 5450 3700 5450
Connection ~ 3700 5450
Wire Wire Line
	1350 5150 1200 5150
Wire Wire Line
	1200 5150 1200 5450
Wire Wire Line
	1100 5450 1200 5450
Connection ~ 1200 5450
Wire Wire Line
	1650 5150 1800 5150
Wire Wire Line
	1800 5150 1800 5450
Wire Wire Line
	1900 5450 1800 5450
Connection ~ 1800 5450
Wire Wire Line
	1750 3200 1850 3200
Connection ~ 1850 3200
Wire Wire Line
	1750 3500 1850 3500
Connection ~ 1850 3500
Text GLabel 2000 3650 0    50   Input ~ 0
ss
Wire Wire Line
	2200 3550 2050 3550
Wire Wire Line
	2050 3550 2050 3650
Wire Wire Line
	2000 3650 2050 3650
Text GLabel 2800 3350 2    50   Input ~ 0
SCLK
Text GLabel 2800 3450 2    50   Input ~ 0
MISO
Wire Notes Line
	4350 2350 500  2350
Wire Notes Line
	500  500  4350 500 
Wire Notes Line
	4350 4300 500  4300
Wire Notes Line
	4350 7800 500  7800
Wire Notes Line
	500  500  500  7800
Wire Notes Line
	500  6300 4350 6300
Wire Notes Line
	4350 700  2200 700 
Wire Notes Line
	2200 700  2200 500 
Wire Notes Line
	4350 500  4350 7800
Text Notes 2500 650  0    79   Italic 0
conexión y alimentación
Wire Notes Line
	4350 2550 2200 2550
Wire Notes Line
	2200 2550 2200 2350
Text Notes 2900 2500 0    79   Italic 0
Sensor flujo\n
Wire Notes Line
	4350 4500 2200 4500
Wire Notes Line
	2200 4500 2200 4300
Text Notes 2300 4450 0    79   Italic 0
Presion expiratoria e inspiratoria\n
Wire Notes Line
	4350 6500 2200 6500
Wire Notes Line
	2200 6500 2200 6300
Text Notes 2750 6450 0    79   Italic 0
Presión oxigeno\n
Wire Wire Line
	7750 1650 7750 1750
Wire Wire Line
	7850 1750 7750 1750
$Comp
L MCU_Microchip_ATmega:ATmega328-PU U?
U 1 1 5EBD03CD
P 7750 3250
F 0 "U?" H 7106 3296 50  0000 R CNN
F 1 "ATmega328-PU" H 7106 3205 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 7750 3250 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 7750 3250 50  0001 C CNN
	1    7750 3250
	1    0    0    -1  
$EndComp
Connection ~ 7750 1750
$Comp
L Device:Crystal Y?
U 1 1 5EBD3DA2
P 8650 2700
F 0 "Y?" V 8696 2569 50  0000 R CNN
F 1 "Crystal" V 8605 2569 50  0000 R CNN
F 2 "" H 8650 2700 50  0001 C CNN
F 3 "~" H 8650 2700 50  0001 C CNN
	1    8650 2700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8650 2550 8450 2550
Wire Wire Line
	8450 2550 8450 2650
Wire Wire Line
	8450 2650 8350 2650
Wire Wire Line
	8650 2850 8450 2850
Wire Wire Line
	8450 2850 8450 2750
Wire Wire Line
	8450 2750 8350 2750
$EndSCHEMATC
