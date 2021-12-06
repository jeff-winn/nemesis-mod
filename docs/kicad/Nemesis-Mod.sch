EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "Nemesis Mod"
Date "2020-09-13"
Rev "v1.1"
Comp "https://github.com/jeff-winn/Nemesis-Mod"
Comment1 "For more information please visit the project website:"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
NoConn ~ 1300 1050
NoConn ~ 1300 2550
NoConn ~ 1300 2700
NoConn ~ 1300 2850
NoConn ~ 1300 3000
NoConn ~ 1300 3150
NoConn ~ 1300 3300
Text GLabel 1300 1200 0    50   Output ~ 0
3V
NoConn ~ 1300 1350
Text GLabel 2700 1950 2    50   Input ~ 0
5V
NoConn ~ 2700 1650
NoConn ~ 2700 1800
NoConn ~ 8750 5350
NoConn ~ 8750 5500
NoConn ~ 8750 5650
Text GLabel 8750 5800 2    50   Input ~ 0
SDA
Text GLabel 2700 3300 2    50   BiDi ~ 0
SDA
Text GLabel 8750 5950 2    50   Input ~ 0
SCL
Text GLabel 8750 6400 2    50   Input ~ 0
3V
NoConn ~ 8750 6100
Text GLabel 2700 3150 2    50   BiDi ~ 0
SCL
Text GLabel 3200 5650 3    50   Input ~ 0
3V
NoConn ~ 2800 5150
NoConn ~ 2800 5350
Text Label 850  2250 0    50   ~ 0
RESET_DOWN
Wire Wire Line
	1300 2250 850  2250
$Comp
L Nemesis-Mod:Nerf_Hopper_Lock LOCK1
U 1 1 5F60175A
P 3200 5250
F 0 "LOCK1" H 3200 5665 50  0000 C CNN
F 1 "Nerf Hopper Lock" H 3200 5574 50  0000 C CNN
F 2 "" H 3200 5550 50  0001 C CNN
F 3 "" H 3200 5550 50  0001 C CNN
	1    3200 5250
	1    0    0    -1  
$EndComp
Text Label 4100 5350 2    50   ~ 0
SOFT_LOCK1
Wire Wire Line
	3600 5350 4100 5350
Text Label 850  2400 0    50   ~ 0
SOFT_LOCK1
Wire Wire Line
	850  2400 1300 2400
Text Label 3250 2400 2    50   ~ 0
M3PWM
Text Label 3250 2850 2    50   ~ 0
M2PWM
Text Label 3250 3000 2    50   ~ 0
M1PWM
Text Label 3250 2700 2    50   ~ 0
M1SLP
Text Label 3250 2550 2    50   ~ 0
M2SLP
Wire Wire Line
	1300 1650 850  1650
Wire Wire Line
	2700 2400 3250 2400
Wire Wire Line
	2700 2550 3250 2550
Wire Wire Line
	2700 2700 3250 2700
Wire Wire Line
	2700 2850 3250 2850
Wire Wire Line
	2700 3000 3250 3000
Text Label 850  2100 0    50   ~ 0
M3SLP
Wire Wire Line
	1300 2100 850  2100
Text Label 3250 2250 2    50   ~ 0
FIRE_DOWN
Wire Wire Line
	2700 2100 3250 2100
Wire Wire Line
	2700 2250 3250 2250
Text Notes 9750 3200 2    50   ~ 0
12awg
Text Notes 7750 3000 2    50   ~ 0
20awg
Text Notes 7750 2650 2    50   ~ 0
20awg
Text Notes 8350 1800 2    50   ~ 0
20awg
Text Notes 8350 1150 2    50   ~ 0
20awg
Text Notes 9200 2900 1    50   ~ 0
20awg
Text Notes 9500 2900 1    50   ~ 0
20awg
Text Notes 7750 3350 2    50   ~ 0
16awg
Text Notes 7750 3650 2    50   ~ 0
16awg
Text Notes 7750 4050 2    50   ~ 0
20awg
Text Notes 7750 4350 2    50   ~ 0
20awg
Wire Wire Line
	8400 4500 8400 4450
Wire Wire Line
	8400 3900 8400 3950
Wire Wire Line
	5550 1200 5200 1200
Wire Wire Line
	5200 1350 5550 1350
Text Label 5200 1200 0    50   ~ 0
M3PWM
Text Label 5200 1350 0    50   ~ 0
M3SLP
Wire Wire Line
	4900 3250 4500 3250
Wire Wire Line
	4500 3550 4900 3550
Wire Wire Line
	4500 4000 4900 4000
Wire Wire Line
	4900 4300 4500 4300
Text Label 4500 4300 0    50   ~ 0
M2PWM
Text Label 4500 4000 0    50   ~ 0
M2SLP
Text Label 4500 3550 0    50   ~ 0
M1PWM
Wire Wire Line
	9400 3250 9750 3250
Connection ~ 9400 3250
Wire Wire Line
	9250 3650 9750 3650
Connection ~ 9250 3650
Wire Wire Line
	8000 3250 9400 3250
Wire Wire Line
	8000 3650 9250 3650
Wire Wire Line
	7850 1000 9400 1000
Wire Wire Line
	7850 1200 7850 1000
Wire Wire Line
	7400 1200 7850 1200
Wire Wire Line
	7850 1900 9250 1900
Wire Wire Line
	7850 1650 7850 1900
Wire Wire Line
	7400 1650 7850 1650
Wire Wire Line
	8000 3550 7400 3550
Wire Wire Line
	8000 3650 8000 3550
Wire Wire Line
	8000 3400 7400 3400
Wire Wire Line
	8000 3250 8000 3400
Wire Wire Line
	8000 1700 8400 1700
Wire Wire Line
	8000 1500 8000 1700
Wire Wire Line
	7400 1500 8000 1500
Wire Wire Line
	8000 1200 8400 1200
Wire Wire Line
	8000 1350 8000 1200
Wire Wire Line
	7400 1350 8000 1350
$Comp
L Device:Battery BATT1
U 1 1 5F60160F
P 9750 3450
F 0 "BATT1" H 9642 3404 50  0000 R CNN
F 1 "11.1V 3S LiPo" H 9642 3495 50  0000 R CNN
F 2 "" V 9750 3510 50  0001 C CNN
F 3 "~" V 9750 3510 50  0001 C CNN
	1    9750 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	8000 2550 8400 2550
Wire Wire Line
	8000 2700 8000 2550
Wire Wire Line
	7400 2700 8000 2700
Wire Wire Line
	8000 3050 8400 3050
Wire Wire Line
	8000 2850 8000 3050
Wire Wire Line
	7400 2850 8000 2850
Wire Wire Line
	8000 3900 8400 3900
Wire Wire Line
	8000 4100 8000 3900
Wire Wire Line
	7400 4100 8000 4100
Wire Wire Line
	8000 4500 8400 4500
Wire Wire Line
	8000 4250 8000 4500
Wire Wire Line
	7400 4250 8000 4250
$Comp
L Motor:Motor_DC Flywheel_M2
U 1 1 5F5FDC93
P 8400 4150
F 0 "Flywheel_M2" H 8558 4146 50  0000 L CNN
F 1 "Motor_DC" H 8558 4055 50  0000 L CNN
F 2 "" H 8400 4060 50  0001 C CNN
F 3 "~" H 8400 4060 50  0001 C CNN
	1    8400 4150
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC Flywheel_M1
U 1 1 5F5FD0DC
P 8400 2750
F 0 "Flywheel_M1" H 8558 2746 50  0000 L CNN
F 1 "Motor_DC" H 8558 2655 50  0000 L CNN
F 2 "" H 8400 2660 50  0001 C CNN
F 3 "~" H 8400 2660 50  0001 C CNN
	1    8400 2750
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC Belt_M1
U 1 1 5F5FC042
P 8400 1500
F 0 "Belt_M1" H 8242 1404 50  0000 R CNN
F 1 "Motor_DC" H 8242 1495 50  0000 R CNN
F 2 "" H 8400 1410 50  0001 C CNN
F 3 "~" H 8400 1410 50  0001 C CNN
	1    8400 1500
	-1   0    0    1   
$EndComp
$Comp
L Nemesis-Mod:Pololu_G2_HighPower_18v18 M1-M?
U 1 1 5F5E95CF
P 6150 3450
AR Path="/5F58C475/5F5E95CF" Ref="M1-M?"  Part="1" 
AR Path="/5F5E95CF" Ref="M1-M1"  Part="1" 
F 0 "M1-M1" H 6150 4715 50  0000 C CNN
F 1 "Pololu G2 HighPower 18v18" H 6150 4624 50  0000 C CNN
F 2 "" H 6100 4650 50  0001 C CNN
F 3 "" H 6100 4650 50  0001 C CNN
	1    6150 3450
	1    0    0    -1  
$EndComp
NoConn ~ 4900 2500
NoConn ~ 4900 2650
NoConn ~ 4900 2800
NoConn ~ 4900 2950
NoConn ~ 4900 3100
NoConn ~ 4900 3400
NoConn ~ 4900 3850
NoConn ~ 4900 4150
NoConn ~ 6050 4750
NoConn ~ 6200 4750
$Comp
L Nemesis-Mod:Pololu_G2_HighPower_18v17 M?
U 1 1 5F5E95EA
P 6500 1250
AR Path="/5F58C475/5F5E95EA" Ref="M?"  Part="1" 
AR Path="/5F5E95EA" Ref="M1"  Part="1" 
F 0 "M1" H 6475 1865 50  0000 C CNN
F 1 "Pololu G2 HighPower 18v17" H 6475 1774 50  0000 C CNN
F 2 "" H 6500 1800 50  0001 C CNN
F 3 "" H 6500 1800 50  0001 C CNN
	1    6500 1250
	1    0    0    -1  
$EndComp
NoConn ~ 5550 1500
NoConn ~ 5550 1800
NoConn ~ 5550 1950
NoConn ~ 5550 1050
Text GLabel 4500 1200 2    50   Output ~ 0
5V
Text Notes 9650 3750 2    50   ~ 0
12awg
Wire Wire Line
	3100 4200 2600 4200
Wire Wire Line
	1450 4150 1000 4150
Text Label 1000 4150 0    50   ~ 0
REV_DOWN
Text Label 2600 4200 0    50   ~ 0
FIRE_DOWN
Text GLabel 1850 4250 2    50   Input ~ 0
3V
Text GLabel 3500 4300 2    50   Input ~ 0
3V
$Comp
L Switch:SW_SPDT SW3
U 1 1 5F6463A0
P 3300 4200
F 0 "SW3" H 3300 4550 50  0000 C CNN
F 1 "Firing SPDT Trigger" H 3300 4450 50  0000 C CNN
F 2 "" H 3300 4200 50  0001 C CNN
F 3 "~" H 3300 4200 50  0001 C CNN
	1    3300 4200
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPDT SW2
U 1 1 5F645A37
P 1650 4150
F 0 "SW2" H 1650 4500 50  0000 C CNN
F 1 "Rev SPDT Trigger" H 1650 4400 50  0000 C CNN
F 2 "" H 1650 4150 50  0001 C CNN
F 3 "~" H 1650 4150 50  0001 C CNN
	1    1650 4150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F69805A
P 1600 5050
AR Path="/5F5F6E0E/5F69805A" Ref="SW?"  Part="1" 
AR Path="/5F69805A" Ref="SW1"  Part="1" 
F 0 "SW1" H 1600 5335 50  0000 C CNN
F 1 "Reset" H 1600 5244 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 1600 5250 50  0001 C CNN
F 3 "~" H 1600 5250 50  0001 C CNN
F 4 "367 (Adafruit)" H 1600 5050 50  0001 C CNN "MPID"
	1    1600 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R1
U 1 1 5F698060
P 1150 5350
F 0 "R1" H 1218 5396 50  0000 L CNN
F 1 "10K" H 1218 5305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P5.08mm_Vertical" H 1150 5350 50  0001 C CNN
F 3 "~" H 1150 5350 50  0001 C CNN
	1    1150 5350
	1    0    0    -1  
$EndComp
Text GLabel 1150 5450 3    50   Input ~ 0
3V
Wire Wire Line
	1150 5250 1150 5150
Wire Wire Line
	1150 5050 1400 5050
Wire Wire Line
	600  5150 1150 5150
Connection ~ 1150 5150
Wire Wire Line
	1150 5150 1150 5050
Text Label 600  5150 0    50   ~ 0
RESET_DOWN
NoConn ~ 5550 1650
NoConn ~ 4900 4450
NoConn ~ 4900 3700
Text Label 4500 3250 0    50   ~ 0
M1SLP
NoConn ~ 1300 1800
NoConn ~ 1300 1950
Text Label 850  1650 0    50   ~ 0
BT_INT
Text GLabel 6650 4750 3    50   Output ~ 0
11V
Text GLabel 3550 1200 0    50   Input ~ 0
11V
NoConn ~ 6350 4750
$Comp
L power:GND #PWR07
U 1 1 61B28A20
P 3550 1400
F 0 "#PWR07" H 3550 1150 50  0001 C CNN
F 1 "GND" H 3555 1227 50  0000 C CNN
F 2 "" H 3550 1400 50  0001 C CNN
F 3 "" H 3550 1400 50  0001 C CNN
	1    3550 1400
	0    1    -1   0   
$EndComp
$Comp
L power:GND #PWR010
U 1 1 61B321A6
P 6500 4750
F 0 "#PWR010" H 6500 4500 50  0001 C CNN
F 1 "GND" H 6505 4577 50  0000 C CNN
F 2 "" H 6500 4750 50  0001 C CNN
F 3 "" H 6500 4750 50  0001 C CNN
	1    6500 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 61B382E1
P 3500 4100
F 0 "#PWR05" H 3500 3850 50  0001 C CNN
F 1 "GND" V 3505 3972 50  0000 R CNN
F 2 "" H 3500 4100 50  0001 C CNN
F 3 "" H 3500 4100 50  0001 C CNN
	1    3500 4100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 61B3C94D
P 1850 4050
F 0 "#PWR04" H 1850 3800 50  0001 C CNN
F 1 "GND" V 1855 3922 50  0000 R CNN
F 2 "" H 1850 4050 50  0001 C CNN
F 3 "" H 1850 4050 50  0001 C CNN
	1    1850 4050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 61B3EF26
P 1800 5050
F 0 "#PWR03" H 1800 4800 50  0001 C CNN
F 1 "GND" V 1805 4922 50  0000 R CNN
F 2 "" H 1800 5050 50  0001 C CNN
F 3 "" H 1800 5050 50  0001 C CNN
	1    1800 5050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR011
U 1 1 61B4326A
P 8750 6250
F 0 "#PWR011" H 8750 6000 50  0001 C CNN
F 1 "GND" V 8755 6122 50  0000 R CNN
F 2 "" H 8750 6250 50  0001 C CNN
F 3 "" H 8750 6250 50  0001 C CNN
	1    8750 6250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 61B45500
P 3600 5150
F 0 "#PWR08" H 3600 4900 50  0001 C CNN
F 1 "GND" V 3605 5022 50  0000 R CNN
F 2 "" H 3600 5150 50  0001 C CNN
F 3 "" H 3600 5150 50  0001 C CNN
	1    3600 5150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR02
U 1 1 61B47443
P 1300 1500
F 0 "#PWR02" H 1300 1250 50  0001 C CNN
F 1 "GND" V 1305 1372 50  0000 R CNN
F 2 "" H 1300 1500 50  0001 C CNN
F 3 "" H 1300 1500 50  0001 C CNN
	1    1300 1500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR09
U 1 1 61B49114
P 5550 900
F 0 "#PWR09" H 5550 650 50  0001 C CNN
F 1 "GND" V 5555 772 50  0000 R CNN
F 2 "" H 5550 900 50  0001 C CNN
F 3 "" H 5550 900 50  0001 C CNN
	1    5550 900 
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_02x14_Odd_Even H1
U 1 1 61B4EED6
P 1950 6800
F 0 "H1" H 2000 7550 50  0000 C CNN
F 1 " " H 2000 7526 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x14_P2.54mm_Vertical" H 1950 6800 50  0001 C CNN
F 3 "~" H 1950 6800 50  0001 C CNN
	1    1950 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 6400 1250 6400
Text GLabel 1750 6200 0    50   Input ~ 0
3V
Wire Wire Line
	1750 6300 1150 6300
Text Label 1250 6400 0    50   ~ 0
REV_DOWN
$Comp
L power:GND #PWR01
U 1 1 61B6E553
P 1150 6150
F 0 "#PWR01" H 1150 5900 50  0001 C CNN
F 1 "GND" H 1155 5977 50  0000 C CNN
F 2 "" H 1150 6150 50  0001 C CNN
F 3 "" H 1150 6150 50  0001 C CNN
	1    1150 6150
	-1   0    0    1   
$EndComp
Wire Wire Line
	1750 6600 1150 6600
Text GLabel 1750 6500 0    50   Input ~ 0
3V
Wire Wire Line
	1750 6700 1250 6700
Text Label 1250 6700 0    50   ~ 0
SOFT_LOCK1
Text GLabel 2250 6200 2    50   Input ~ 0
3V
Wire Wire Line
	1150 6150 1150 6300
Wire Wire Line
	9250 1900 9250 3650
Wire Wire Line
	9400 1000 9400 3250
Connection ~ 1150 6300
Wire Wire Line
	1150 6300 1150 6600
Wire Wire Line
	2250 6300 2900 6300
Wire Wire Line
	2900 6300 2900 7650
Wire Wire Line
	2900 7650 1150 7650
Connection ~ 1150 6600
Wire Wire Line
	2250 6400 2800 6400
Text Label 2800 6400 2    50   ~ 0
FIRE_DOWN
NoConn ~ 2250 6500
NoConn ~ 2250 6600
NoConn ~ 2250 6700
Wire Wire Line
	1750 6800 1250 6800
Text Label 1250 6900 0    50   ~ 0
M1PWM
Wire Wire Line
	1750 6900 1250 6900
Text Label 1250 6800 0    50   ~ 0
M1SLP
Wire Wire Line
	2250 6800 2800 6800
Text Label 2800 6900 2    50   ~ 0
M2PWM
Wire Wire Line
	2250 6900 2800 6900
Text Label 2800 6800 2    50   ~ 0
M2SLP
Wire Wire Line
	1750 7300 1250 7300
Text Label 1250 7400 0    50   ~ 0
M3PWM
Wire Wire Line
	1750 7400 1250 7400
Text Label 1250 7300 0    50   ~ 0
M3SLP
Wire Wire Line
	1150 7650 1150 7500
Wire Wire Line
	1750 7500 1150 7500
Connection ~ 1150 7500
Wire Wire Line
	1150 7500 1150 6600
NoConn ~ 1750 7000
NoConn ~ 1750 7100
NoConn ~ 1750 7200
NoConn ~ 2250 7500
NoConn ~ 2250 7400
NoConn ~ 2250 7300
NoConn ~ 2250 7200
NoConn ~ 2250 7100
NoConn ~ 2250 7000
Text Label 3250 2100 2    50   ~ 0
REV_DOWN
$Comp
L Nemesis-Mod:Adafruit_Feather_M4_Express MCU1
U 1 1 61C428BA
P 2000 2200
F 0 "MCU1" H 2000 3615 50  0000 C CNN
F 1 "Adafruit_Feather_M4_Express" H 2000 3524 50  0000 C CNN
F 2 "Adafruit:Adafruit_Feather_M4_Express" H 2100 650 50  0001 C CNN
F 3 "" H 2650 900 50  0001 C CNN
	1    2000 2200
	1    0    0    -1  
$EndComp
$Comp
L Nemesis-Mod:Adafruit_I2C_FRAM_Breakout F1
U 1 1 61C6969C
P 8250 5750
F 0 "F1" V 8950 5650 50  0000 C CNN
F 1 "FRAM Breakout" V 8850 5650 50  0000 C CNN
F 2 "Adafruit:Adafruit_I2C_FRAM_Breakout" H 8100 6200 50  0001 C CNN
F 3 "" H 8100 6200 50  0001 C CNN
	1    8250 5750
	0    -1   -1   0   
$EndComp
$Comp
L Nemesis-Mod:Pololu_5V_Step_Down_Regulator P1
U 1 1 61B01FC1
P 4200 1750
F 0 "P1" H 4025 2765 50  0000 C CNN
F 1 "Pololu_5V_Step_Down_Regulator" H 4025 2674 50  0000 C CNN
F 2 "Pololu:5V_Step_Down_Regulator_500mA" H 4050 1800 50  0001 C CNN
F 3 "" H 4050 1800 50  0001 C CNN
	1    4200 1750
	1    0    0    -1  
$EndComp
NoConn ~ 3550 1000
$EndSCHEMATC
