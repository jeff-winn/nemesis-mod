EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "Nemesis Mod"
Date "2019-05-22"
Rev "v1.1"
Comp "https://github.com/jeff-winn/Nemesis-Mod"
Comment1 "For more information please visit the project website:"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
NoConn ~ 1500 1050
NoConn ~ 1500 2550
NoConn ~ 1500 2700
NoConn ~ 1500 2850
NoConn ~ 1500 3000
NoConn ~ 1500 3150
NoConn ~ 1500 3300
Text GLabel 1500 1200 0    50   Output ~ 0
3V
NoConn ~ 1500 1350
Text GLabel 2900 1950 2    50   Input ~ 0
5V
$Comp
L Nemesis-Mod:Adafruit_nRF52_Feather MCU
U 1 1 5DBD8417
P 2200 2200
F 0 "MCU" H 2200 3615 50  0000 C CNN
F 1 "Adafruit nRF52832 Feather" H 2200 3524 50  0000 C CNN
F 2 "" H 2850 900 50  0001 C CNN
F 3 "" H 2850 900 50  0001 C CNN
	1    2200 2200
	1    0    0    -1  
$EndComp
NoConn ~ 2900 1650
NoConn ~ 2900 1800
NoConn ~ 1800 4050
NoConn ~ 1800 4200
NoConn ~ 1800 4350
Text GLabel 1800 4500 2    50   Input ~ 0
SDA
Text GLabel 2900 3300 2    50   Output ~ 0
SDA
Text GLabel 1800 4650 2    50   Input ~ 0
SCL
Text GLabel 1800 5100 2    50   Input ~ 0
3V
NoConn ~ 1800 4800
Text GLabel 2900 3150 2    50   Output ~ 0
SCL
Text GLabel 2950 4550 3    50   Input ~ 0
3V
NoConn ~ 2550 4050
NoConn ~ 2550 4250
$Comp
L Nemesis-Mod:Adafruit_I2C_FRAM_Breakout FRAM1
U 1 1 5F5EE0C5
P 1300 4450
F 0 "FRAM1" V 1965 4317 50  0000 C CNN
F 1 "Adafruit I2C FRAM Breakout" V 1874 4317 50  0000 C CNN
F 2 "" H 1150 4900 50  0001 C CNN
F 3 "" H 1150 4900 50  0001 C CNN
	1    1300 4450
	0    -1   -1   0   
$EndComp
Text Label 1300 2250 2    50   ~ 0
RESET_DOWN
Wire Wire Line
	1500 2250 1300 2250
$Comp
L Nemesis-Mod:Nerf_Hopper_Lock LOCK1
U 1 1 5F60175A
P 2950 4150
F 0 "LOCK1" H 2950 4565 50  0000 C CNN
F 1 "Nerf Hopper Lock" H 2950 4474 50  0000 C CNN
F 2 "" H 2950 4450 50  0001 C CNN
F 3 "" H 2950 4450 50  0001 C CNN
	1    2950 4150
	1    0    0    -1  
$EndComp
Text Label 3500 4250 0    50   ~ 0
SOFT_LOCK1
Wire Wire Line
	3350 4250 3500 4250
Text Label 1300 2400 2    50   ~ 0
SOFT_LOCK1
Wire Wire Line
	1300 2400 1500 2400
Text Label 1300 1650 2    50   ~ 0
M1CS
Wire Wire Line
	1300 1800 1500 1800
Text Label 1300 1800 2    50   ~ 0
M2CS
Text Label 1300 1950 2    50   ~ 0
M3CS
Wire Wire Line
	1300 1950 1500 1950
Text Label 3100 2400 0    50   ~ 0
M3PWM
Text Label 3100 2850 0    50   ~ 0
M2PWM
Text Label 3100 3000 0    50   ~ 0
M1PWM
Text Label 3100 2700 0    50   ~ 0
M1SLP
Text Label 3100 2550 0    50   ~ 0
M2SLP
Wire Wire Line
	1500 1650 1300 1650
Wire Wire Line
	2900 2400 3100 2400
Wire Wire Line
	2900 2550 3100 2550
Wire Wire Line
	2900 2700 3100 2700
Wire Wire Line
	2900 2850 3100 2850
Wire Wire Line
	2900 3000 3100 3000
Text Label 1300 2100 2    50   ~ 0
M3SLP
Wire Wire Line
	1500 2100 1300 2100
Text Label 3100 2250 0    50   ~ 0
FIRE_DOWN
Text Label 3100 2100 0    50   ~ 0
REV_DOWN
Wire Wire Line
	2900 2100 3100 2100
Wire Wire Line
	2900 2250 3100 2250
Text Notes 9500 3650 2    50   ~ 0
12awg
Text Notes 7500 3450 2    50   ~ 0
20awg
Text Notes 7500 3100 2    50   ~ 0
20awg
Text Notes 8100 1950 2    50   ~ 0
20awg
Text Notes 8100 1300 2    50   ~ 0
20awg
Text Notes 8950 3350 1    50   ~ 0
20awg
Text Notes 9250 3350 1    50   ~ 0
20awg
Text Notes 7500 3800 2    50   ~ 0
16awg
Text Notes 7500 4100 2    50   ~ 0
16awg
Text Notes 7500 4500 2    50   ~ 0
20awg
Text Notes 7500 4800 2    50   ~ 0
20awg
Wire Wire Line
	8150 4950 8150 4900
Wire Wire Line
	8150 4350 8150 4400
Wire Wire Line
	5300 1350 5100 1350
Wire Wire Line
	5100 1500 5300 1500
Wire Wire Line
	5100 1800 5300 1800
Text Label 5100 1800 2    50   ~ 0
M3CS
Text Label 5100 1350 2    50   ~ 0
M3PWM
Text Label 5100 1500 2    50   ~ 0
M3SLP
Wire Wire Line
	4650 3700 4450 3700
Wire Wire Line
	4450 4000 4650 4000
Wire Wire Line
	4450 4450 4650 4450
Wire Wire Line
	4650 4750 4450 4750
Wire Wire Line
	4450 4900 4650 4900
Text Label 4450 4900 2    50   ~ 0
M2CS
Text Label 4450 4750 2    50   ~ 0
M2PWM
Text Label 4450 4450 2    50   ~ 0
M2SLP
Text Label 4450 4000 2    50   ~ 0
M1PWM
Text Label 4450 3700 2    50   ~ 0
M1SLP
Wire Wire Line
	4450 4150 4650 4150
Text Label 4450 4150 2    50   ~ 0
M1CS
Wire Wire Line
	9150 3700 9500 3700
Connection ~ 9150 3700
Wire Wire Line
	9000 4100 9500 4100
Connection ~ 9000 4100
Wire Wire Line
	7750 3700 9150 3700
Wire Wire Line
	7750 4100 9000 4100
NoConn ~ 7750 5700
Wire Wire Line
	9150 1150 9150 3700
Wire Wire Line
	7600 1150 9150 1150
Wire Wire Line
	7600 1350 7600 1150
Wire Wire Line
	7150 1350 7600 1350
Wire Wire Line
	9000 2050 9000 4100
Wire Wire Line
	7600 2050 9000 2050
Wire Wire Line
	7600 1800 7600 2050
Wire Wire Line
	7150 1800 7600 1800
Wire Wire Line
	7750 4000 7150 4000
Wire Wire Line
	7750 4100 7750 4000
Wire Wire Line
	7750 3850 7150 3850
Wire Wire Line
	7750 3700 7750 3850
Wire Wire Line
	7750 1850 8150 1850
Wire Wire Line
	7750 1650 7750 1850
Wire Wire Line
	7150 1650 7750 1650
Wire Wire Line
	7750 1350 8150 1350
Wire Wire Line
	7750 1500 7750 1350
Wire Wire Line
	7150 1500 7750 1500
$Comp
L Device:Battery BATT
U 1 1 5F60160F
P 9500 3900
F 0 "BATT" H 9392 3854 50  0000 R CNN
F 1 "11.1V 3S LiPo" H 9392 3945 50  0000 R CNN
F 2 "" V 9500 3960 50  0001 C CNN
F 3 "~" V 9500 3960 50  0001 C CNN
	1    9500 3900
	-1   0    0    1   
$EndComp
Wire Wire Line
	7750 3000 8150 3000
Wire Wire Line
	7750 3150 7750 3000
Wire Wire Line
	7150 3150 7750 3150
Wire Wire Line
	7750 3500 8150 3500
Wire Wire Line
	7750 3300 7750 3500
Wire Wire Line
	7150 3300 7750 3300
Wire Wire Line
	7750 4350 8150 4350
Wire Wire Line
	7750 4550 7750 4350
Wire Wire Line
	7150 4550 7750 4550
Wire Wire Line
	7750 4950 8150 4950
Wire Wire Line
	7750 4700 7750 4950
Wire Wire Line
	7150 4700 7750 4700
$Comp
L Motor:Motor_DC Flywheel_M2
U 1 1 5F5FDC93
P 8150 4600
F 0 "Flywheel_M2" H 8308 4596 50  0000 L CNN
F 1 "Motor_DC" H 8308 4505 50  0000 L CNN
F 2 "" H 8150 4510 50  0001 C CNN
F 3 "~" H 8150 4510 50  0001 C CNN
	1    8150 4600
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC Flywheel_M1
U 1 1 5F5FD0DC
P 8150 3200
F 0 "Flywheel_M1" H 8308 3196 50  0000 L CNN
F 1 "Motor_DC" H 8308 3105 50  0000 L CNN
F 2 "" H 8150 3110 50  0001 C CNN
F 3 "~" H 8150 3110 50  0001 C CNN
	1    8150 3200
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC Belt_M1
U 1 1 5F5FC042
P 8150 1650
F 0 "Belt_M1" H 7992 1554 50  0000 R CNN
F 1 "Motor_DC" H 7992 1645 50  0000 R CNN
F 2 "" H 8150 1560 50  0001 C CNN
F 3 "~" H 8150 1560 50  0001 C CNN
	1    8150 1650
	-1   0    0    1   
$EndComp
$Comp
L Nemesis-Mod:Pololu_G2_HighPower_18v18 Flywheel_Driver?
U 1 1 5F5E95CF
P 5900 3900
AR Path="/5F58C475/5F5E95CF" Ref="Flywheel_Driver?"  Part="1" 
AR Path="/5F5E95CF" Ref="M1-M2"  Part="1" 
F 0 "M1-M2" H 5900 5165 50  0000 C CNN
F 1 "Pololu G2 HighPower 18v18" H 5900 5074 50  0000 C CNN
F 2 "" H 5850 5100 50  0001 C CNN
F 3 "" H 5850 5100 50  0001 C CNN
	1    5900 3900
	1    0    0    -1  
$EndComp
$Comp
L Nemesis-Mod:Pololu_5V_Step_Down_Regulator REG1
U 1 1 5F5E95D5
P 8150 6700
F 0 "REG1" H 8328 7379 50  0000 L CNN
F 1 "Pololu 5V Step Down Regulator" H 8328 7288 50  0000 L CNN
F 2 "" H 8000 6750 50  0001 C CNN
F 3 "" H 8000 6750 50  0001 C CNN
	1    8150 6700
	1    0    0    -1  
$EndComp
NoConn ~ 4650 2950
NoConn ~ 4650 3100
NoConn ~ 4650 3250
NoConn ~ 4650 3400
NoConn ~ 4650 3550
NoConn ~ 4650 3850
NoConn ~ 4650 4300
NoConn ~ 4650 4600
NoConn ~ 5800 5200
NoConn ~ 5950 5200
$Comp
L Nemesis-Mod:Pololu_G2_HighPower_18v17 Belt_Feed_Driver?
U 1 1 5F5E95EA
P 6250 1400
AR Path="/5F58C475/5F5E95EA" Ref="Belt_Feed_Driver?"  Part="1" 
AR Path="/5F5E95EA" Ref="M3"  Part="1" 
F 0 "M3" H 6225 2015 50  0000 C CNN
F 1 "Pololu G2 HighPower 18v17" H 6225 1924 50  0000 C CNN
F 2 "" H 6250 1950 50  0001 C CNN
F 3 "" H 6250 1950 50  0001 C CNN
	1    6250 1400
	1    0    0    -1  
$EndComp
NoConn ~ 5300 1650
NoConn ~ 5300 1950
NoConn ~ 5300 2100
NoConn ~ 5300 1200
Wire Wire Line
	6250 5200 6250 5550
Wire Wire Line
	6250 5550 8050 5550
Wire Wire Line
	8050 5550 8050 5700
Wire Wire Line
	6400 5200 6400 5400
Wire Wire Line
	6400 5400 7900 5400
Wire Wire Line
	7900 5400 7900 5700
Text GLabel 8200 5700 1    50   Output ~ 0
5V
Text Notes 9400 4200 2    50   ~ 0
12awg
Wire Wire Line
	3400 6150 3200 6150
Wire Wire Line
	1800 6150 1600 6150
Text Label 1600 6150 2    50   ~ 0
REV_DOWN
Text Label 3200 6150 2    50   ~ 0
FIRE_DOWN
Text GLabel 2200 6250 2    50   Input ~ 0
3V
Text GLabel 3800 6250 2    50   Input ~ 0
3V
$Comp
L Switch:SW_SPDT SW2
U 1 1 5F6463A0
P 3600 6150
F 0 "SW2" H 3600 6435 50  0000 C CNN
F 1 "Firing SPDT Trigger" H 3600 6344 50  0000 C CNN
F 2 "" H 3600 6150 50  0001 C CNN
F 3 "~" H 3600 6150 50  0001 C CNN
	1    3600 6150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPDT SW1
U 1 1 5F645A37
P 2000 6150
F 0 "SW1" H 2000 6435 50  0000 C CNN
F 1 "Rev SPDT Trigger" H 2000 6344 50  0000 C CNN
F 2 "" H 2000 6150 50  0001 C CNN
F 3 "~" H 2000 6150 50  0001 C CNN
	1    2000 6150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F69805A
P 1950 7050
AR Path="/5F5F6E0E/5F69805A" Ref="SW?"  Part="1" 
AR Path="/5F69805A" Ref="SW3"  Part="1" 
F 0 "SW3" H 1950 7335 50  0000 C CNN
F 1 "Reset SW Button" H 1950 7244 50  0000 C CNN
F 2 "" H 1950 7250 50  0001 C CNN
F 3 "~" H 1950 7250 50  0001 C CNN
	1    1950 7050
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R1
U 1 1 5F698060
P 1500 7350
F 0 "R1" H 1568 7396 50  0000 L CNN
F 1 "10K" H 1568 7305 50  0000 L CNN
F 2 "" H 1500 7350 50  0001 C CNN
F 3 "~" H 1500 7350 50  0001 C CNN
	1    1500 7350
	1    0    0    -1  
$EndComp
Text GLabel 1250 7450 0    50   Input ~ 0
3V
Wire Wire Line
	1250 7450 1500 7450
Wire Wire Line
	1500 7250 1500 7150
Wire Wire Line
	1500 7050 1750 7050
Wire Wire Line
	1250 7150 1500 7150
Connection ~ 1500 7150
Wire Wire Line
	1500 7150 1500 7050
Wire Wire Line
	2150 7050 2350 7050
Text Label 1250 7150 2    50   ~ 0
RESET_DOWN
$Comp
L power:GNDREF #PWR?
U 1 1 5F5EA087
P 1050 1350
F 0 "#PWR?" H 1050 1100 50  0001 C CNN
F 1 "GNDREF" H 1055 1177 50  0000 C CNN
F 2 "" H 1050 1350 50  0001 C CNN
F 3 "" H 1050 1350 50  0001 C CNN
	1    1050 1350
	-1   0    0    1   
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 5F5EA7BC
P 4950 950
F 0 "#PWR?" H 4950 700 50  0001 C CNN
F 1 "GNDREF" H 4955 777 50  0000 C CNN
F 2 "" H 4950 950 50  0001 C CNN
F 3 "" H 4950 950 50  0001 C CNN
	1    4950 950 
	-1   0    0    1   
$EndComp
Wire Wire Line
	1500 1500 1050 1500
Wire Wire Line
	1050 1500 1050 1350
Wire Wire Line
	5300 1050 4950 1050
Wire Wire Line
	4950 1050 4950 950 
$Comp
L power:GNDREF #PWR?
U 1 1 5F5FC40A
P 6100 5500
F 0 "#PWR?" H 6100 5250 50  0001 C CNN
F 1 "GNDREF" H 6105 5327 50  0000 C CNN
F 2 "" H 6100 5500 50  0001 C CNN
F 3 "" H 6100 5500 50  0001 C CNN
	1    6100 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 5200 6100 5500
$Comp
L power:GNDREF #PWR?
U 1 1 5F600FD0
P 3600 3950
F 0 "#PWR?" H 3600 3700 50  0001 C CNN
F 1 "GNDREF" H 3605 3777 50  0000 C CNN
F 2 "" H 3600 3950 50  0001 C CNN
F 3 "" H 3600 3950 50  0001 C CNN
	1    3600 3950
	-1   0    0    1   
$EndComp
Wire Wire Line
	3350 4050 3600 4050
Wire Wire Line
	3600 4050 3600 3950
$Comp
L power:GNDREF #PWR?
U 1 1 5F61012E
P 4200 5950
F 0 "#PWR?" H 4200 5700 50  0001 C CNN
F 1 "GNDREF" H 4205 5777 50  0000 C CNN
F 2 "" H 4200 5950 50  0001 C CNN
F 3 "" H 4200 5950 50  0001 C CNN
	1    4200 5950
	-1   0    0    1   
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 5F610CDE
P 2100 5150
F 0 "#PWR?" H 2100 4900 50  0001 C CNN
F 1 "GNDREF" H 2105 4977 50  0000 C CNN
F 2 "" H 2100 5150 50  0001 C CNN
F 3 "" H 2100 5150 50  0001 C CNN
	1    2100 5150
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 5F610FC3
P 2600 5950
F 0 "#PWR?" H 2600 5700 50  0001 C CNN
F 1 "GNDREF" H 2605 5777 50  0000 C CNN
F 2 "" H 2600 5950 50  0001 C CNN
F 3 "" H 2600 5950 50  0001 C CNN
	1    2600 5950
	-1   0    0    1   
$EndComp
$Comp
L power:GNDREF #PWR?
U 1 1 5F6112BA
P 2350 7050
F 0 "#PWR?" H 2350 6800 50  0001 C CNN
F 1 "GNDREF" H 2355 6877 50  0000 C CNN
F 2 "" H 2350 7050 50  0001 C CNN
F 3 "" H 2350 7050 50  0001 C CNN
	1    2350 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 6050 2600 6050
Wire Wire Line
	2600 6050 2600 5950
Wire Wire Line
	3800 6050 4200 6050
Wire Wire Line
	4200 6050 4200 5950
Wire Wire Line
	1800 4950 2100 4950
Wire Wire Line
	2100 4950 2100 5150
$EndSCHEMATC