EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "ESP32-PoE TF Zero HAT Adapter"
Date "2021-09-06"
Rev "1"
Comp "net.Media SR"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L #netMedia:Olimex-ESP32-PoE-ESP32 U1
U 1 1 61366C4C
P 2300 1600
F 0 "U1" H 2275 2265 50  0000 C CNN
F 1 "Olimex-ESP32-PoE-ESP32" H 2275 2174 50  0000 C CNN
F 2 "#netMedia:Olimex-ESP32-PoE" H 2300 950 50  0001 C CNN
F 3 "~" H 2300 950 50  0001 C CNN
	1    2300 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 6136901D
P 950 1450
F 0 "#PWR01" H 950 1200 50  0001 C CNN
F 1 "GND" H 955 1277 50  0000 C CNN
F 2 "" H 950 1450 50  0001 C CNN
F 3 "" H 950 1450 50  0001 C CNN
	1    950  1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 1400 950  1400
$Comp
L #tinkerforge:Raspberry_Pi_2_3 J1
U 1 1 6136C324
P 6900 2850
F 0 "J1" H 6900 4331 50  0000 C CNN
F 1 "Raspberry_Pi_2_3" H 6900 4240 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x20_P2.54mm_Vertical" H 7900 4100 50  0001 C CNN
F 3 "https://www.raspberrypi.org/documentation/hardware/raspberrypi/schematics/RPI-3B-V1_2-SCHEMATIC-REDUCED.pdf" H 6950 2700 50  0001 C CNN
	1    6900 2850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR05
U 1 1 6136F6AB
P 6700 1100
F 0 "#PWR05" H 6700 950 50  0001 C CNN
F 1 "+5V" H 6715 1273 50  0000 C CNN
F 2 "" H 6700 1100 50  0001 C CNN
F 3 "" H 6700 1100 50  0001 C CNN
	1    6700 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 61370221
P 6850 4400
F 0 "#PWR06" H 6850 4150 50  0001 C CNN
F 1 "GND" H 6855 4227 50  0000 C CNN
F 2 "" H 6850 4400 50  0001 C CNN
F 3 "" H 6850 4400 50  0001 C CNN
	1    6850 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 4150 6500 4300
Wire Wire Line
	6500 4300 6600 4300
Wire Wire Line
	6850 4300 6850 4400
Wire Wire Line
	6600 4150 6600 4300
Connection ~ 6600 4300
Wire Wire Line
	6600 4300 6700 4300
Wire Wire Line
	6700 4150 6700 4300
Connection ~ 6700 4300
Wire Wire Line
	6700 4300 6800 4300
Wire Wire Line
	6800 4150 6800 4300
Connection ~ 6800 4300
Wire Wire Line
	6800 4300 6850 4300
Wire Wire Line
	7200 4150 7200 4300
Wire Wire Line
	7200 4300 7100 4300
Connection ~ 6850 4300
Wire Wire Line
	7100 4150 7100 4300
Connection ~ 7100 4300
Wire Wire Line
	7100 4300 7000 4300
Wire Wire Line
	7000 4150 7000 4300
Connection ~ 7000 4300
Wire Wire Line
	7000 4300 6900 4300
Wire Wire Line
	6900 4150 6900 4300
Connection ~ 6900 4300
Wire Wire Line
	6900 4300 6850 4300
Wire Wire Line
	6700 1100 6700 1350
Wire Wire Line
	6800 1550 6800 1350
Wire Wire Line
	6800 1350 6700 1350
Connection ~ 6700 1350
Wire Wire Line
	6700 1350 6700 1550
NoConn ~ 7000 1550
NoConn ~ 7100 1550
Wire Wire Line
	950  1400 950  1450
Text GLabel 3250 1400 2    50   Input ~ 0
MISO
Text GLabel 8050 2850 2    50   Input ~ 0
MISO
Text GLabel 1350 1900 0    50   Output ~ 0
MOSI
Text GLabel 8050 2950 2    50   Output ~ 0
MOSI
Wire Wire Line
	1650 1900 1350 1900
Wire Wire Line
	2900 1400 3250 1400
Text GLabel 1350 1600 0    50   Output ~ 0
CLK
Wire Wire Line
	1650 1600 1350 1600
Text GLabel 8050 3050 2    50   Output ~ 0
CLK
$Comp
L Jumper:SolderJumper_3_Open JP3
U 1 1 6138613C
P 4300 4100
F 0 "JP3" H 4300 4305 50  0000 C CNN
F 1 "CS C" H 4300 4214 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm" H 4300 4100 50  0001 C CNN
F 3 "~" H 4300 4100 50  0001 C CNN
	1    4300 4100
	-1   0    0    1   
$EndComp
$Comp
L Jumper:SolderJumper_3_Open JP4
U 1 1 61386BEF
P 3300 4100
F 0 "JP4" H 3300 4305 50  0000 C CNN
F 1 "CS D" H 3300 4214 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm" H 3300 4100 50  0001 C CNN
F 3 "~" H 3300 4100 50  0001 C CNN
	1    3300 4100
	-1   0    0    1   
$EndComp
$Comp
L Jumper:SolderJumper_3_Open JP5
U 1 1 6139118B
P 5250 4100
F 0 "JP5" H 5250 4305 50  0000 C CNN
F 1 "CS E" H 5250 4214 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm" H 5250 4100 50  0001 C CNN
F 3 "~" H 5250 4100 50  0001 C CNN
	1    5250 4100
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR04
U 1 1 613945E6
P 3500 3900
F 0 "#PWR04" H 3500 3750 50  0001 C CNN
F 1 "+3.3V" H 3515 4073 50  0000 C CNN
F 2 "" H 3500 3900 50  0001 C CNN
F 3 "" H 3500 3900 50  0001 C CNN
	1    3500 3900
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 61395C99
P 1450 1050
F 0 "#PWR03" H 1450 900 50  0001 C CNN
F 1 "+5V" H 1465 1223 50  0000 C CNN
F 2 "" H 1450 1050 50  0001 C CNN
F 3 "" H 1450 1050 50  0001 C CNN
	1    1450 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR02
U 1 1 6139620D
P 1150 1050
F 0 "#PWR02" H 1150 900 50  0001 C CNN
F 1 "+3.3V" H 1165 1223 50  0000 C CNN
F 2 "" H 1150 1050 50  0001 C CNN
F 3 "" H 1150 1050 50  0001 C CNN
	1    1150 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1050 1450 1200
Wire Wire Line
	1450 1200 1650 1200
Wire Wire Line
	1150 1050 1150 1300
Wire Wire Line
	1150 1300 1650 1300
Wire Wire Line
	3500 4100 3500 3900
Text GLabel 5750 3250 0    50   Output ~ 0
CS_A
Text GLabel 3900 4100 0    50   Output ~ 0
CS_C
Text GLabel 2900 4100 0    50   Output ~ 0
CS_D
Text GLabel 4850 4100 0    50   Output ~ 0
CS_E
Wire Wire Line
	3900 4100 4100 4100
Wire Wire Line
	2900 4100 3100 4100
Wire Wire Line
	4850 4100 5050 4100
Text GLabel 3200 2100 2    50   Output ~ 0
CS_C
Text GLabel 3200 1800 2    50   Output ~ 0
CS_D
Text GLabel 1350 2100 0    50   Output ~ 0
CS_E
Wire Wire Line
	2900 1800 3200 1800
Wire Wire Line
	2900 2100 3200 2100
Wire Wire Line
	1650 2100 1350 2100
Text GLabel 5750 2850 0    50   Output ~ 0
CS_B
Text GLabel 3200 1700 2    50   Output ~ 0
CS_A
Text GLabel 3200 1600 2    50   Output ~ 0
CS_B
Wire Wire Line
	2900 1700 3200 1700
Wire Wire Line
	2900 1600 3200 1600
Wire Wire Line
	5750 2850 6000 2850
Wire Wire Line
	5750 3250 6000 3250
Wire Wire Line
	8050 2850 7800 2850
Wire Wire Line
	8050 2950 7800 2950
Wire Wire Line
	8050 3050 7800 3050
Wire Wire Line
	6000 3050 5250 3050
Wire Wire Line
	5250 3050 5250 3950
Wire Wire Line
	6000 2950 4300 2950
Wire Wire Line
	4300 2950 4300 3950
Wire Wire Line
	6000 2750 3300 2750
Wire Wire Line
	3300 2750 3300 3950
Wire Wire Line
	3500 4100 3500 4400
Wire Wire Line
	3500 4400 4500 4400
Wire Wire Line
	4500 4400 4500 4100
Wire Wire Line
	4500 4400 5450 4400
Wire Wire Line
	5450 4400 5450 4100
Connection ~ 4500 4400
Connection ~ 3500 4100
$EndSCHEMATC
