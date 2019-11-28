EESchema Schematic File Version 4
LIBS:Nemesis-Mod-cache
EELAYER 29 0
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
$Comp
L Device:Battery BATT
U 1 1 5CE683D1
P 9800 3550
F 0 "BATT" H 9700 3550 50  0000 R CNN
F 1 "3S LiPo Battery" H 9700 3650 50  0000 R CNN
F 2 "" V 9800 3610 50  0001 C CNN
F 3 "~" V 9800 3610 50  0001 C CNN
	1    9800 3550
	-1   0    0    1   
$EndComp
$Comp
L Motor:Motor_DC Flywheel_M1
U 1 1 5CE6FA2E
P 8400 2850
F 0 "Flywheel_M1" H 8558 2846 50  0000 L CNN
F 1 "Motor_DC" H 8558 2755 50  0000 L CNN
F 2 "" H 8400 2760 50  0001 C CNN
F 3 "~" H 8400 2760 50  0001 C CNN
	1    8400 2850
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC Flywheel_M2
U 1 1 5CE70E23
P 8400 4250
F 0 "Flywheel_M2" H 8558 4246 50  0000 L CNN
F 1 "Motor_DC" H 8558 4155 50  0000 L CNN
F 2 "" H 8400 4160 50  0001 C CNN
F 3 "~" H 8400 4160 50  0001 C CNN
	1    8400 4250
	1    0    0    -1  
$EndComp
$Comp
L Nemesis-Mod:Pololu_G2_HighPower_18v18 Motor_Driver1
U 1 1 5CE740FA
P 6550 3550
F 0 "Motor_Driver1" H 6550 4815 50  0000 C CNN
F 1 "Pololu_G2_HighPower_18v18" H 6550 4724 50  0000 C CNN
F 2 "" H 6500 4750 50  0001 C CNN
F 3 "" H 6500 4750 50  0001 C CNN
	1    6550 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4350 8050 4350
Wire Wire Line
	8050 4350 8050 4550
Wire Wire Line
	8050 4550 8400 4550
Wire Wire Line
	7800 4200 8050 4200
Wire Wire Line
	8050 4200 8050 4050
Wire Wire Line
	8050 4050 8400 4050
Wire Wire Line
	7800 2950 8050 2950
Wire Wire Line
	8050 2950 8050 3150
Wire Wire Line
	8050 3150 8400 3150
Wire Wire Line
	7800 2800 8050 2800
Wire Wire Line
	8050 2800 8050 2650
Wire Wire Line
	8050 2650 8400 2650
$Comp
L Nemesis-Mod:Pololu_5V_Step_Down_Regulator Voltage_Regulator
U 1 1 5CE79472
P 7000 6450
F 0 "Voltage_Regulator" H 6500 6500 50  0000 L CNN
F 1 "Pololu_5V_Step_Down_Regulator" H 6300 6600 50  0000 L CNN
F 2 "" H 6850 6500 50  0001 C CNN
F 3 "" H 6850 6500 50  0001 C CNN
	1    7000 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 4850 6900 5450
Wire Wire Line
	6750 5450 6750 5100
Wire Wire Line
	6750 5100 7050 5100
Wire Wire Line
	7050 5100 7050 4850
Wire Wire Line
	2850 3450 3050 3450
Wire Wire Line
	4450 4500 5200 4500
Wire Wire Line
	5200 4500 5200 4100
Wire Wire Line
	5200 4100 5300 4100
Wire Wire Line
	4450 4650 5150 4650
Wire Wire Line
	5150 4650 5150 3350
Wire Wire Line
	5150 3350 5300 3350
Wire Wire Line
	4450 4800 5100 4800
Wire Wire Line
	5100 4800 5100 4400
Wire Wire Line
	5100 4400 5300 4400
Wire Wire Line
	4450 4950 5050 4950
Wire Wire Line
	5050 4950 5050 3650
Wire Wire Line
	5050 3650 5300 3650
Wire Wire Line
	5300 3800 5100 3800
Wire Wire Line
	5100 3800 5100 2550
Wire Wire Line
	2750 3600 3050 3600
Wire Wire Line
	3050 3750 2650 3750
Wire Wire Line
	2650 2500 5000 2500
Wire Wire Line
	5000 2500 5000 4550
Wire Wire Line
	5000 4550 5300 4550
Wire Wire Line
	8050 3350 8050 3500
Wire Wire Line
	8050 3500 7800 3500
Wire Wire Line
	7800 3650 8050 3650
Wire Wire Line
	8050 3650 8050 3750
$Comp
L Nemesis-Mod:Pololu_G2_HighPower_18v17 Motor_Driver2
U 1 1 5CE6ED10
P 6900 1550
F 0 "Motor_Driver2" H 6875 2165 50  0000 C CNN
F 1 "Pololu_G2_HighPower_18v17" H 6875 2074 50  0000 C CNN
F 2 "" H 6900 2100 50  0001 C CNN
F 3 "" H 6900 2100 50  0001 C CNN
	1    6900 1550
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC Belt_M1
U 1 1 5CE7132F
P 8650 1500
F 0 "Belt_M1" H 8808 1496 50  0000 L CNN
F 1 "Motor_DC" H 8808 1405 50  0000 L CNN
F 2 "" H 8650 1410 50  0001 C CNN
F 3 "~" H 8650 1410 50  0001 C CNN
	1    8650 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 1650 8350 1650
Wire Wire Line
	8350 1650 8350 1300
Wire Wire Line
	8350 1300 8650 1300
Wire Wire Line
	7800 1500 8250 1500
Wire Wire Line
	8250 1500 8250 1800
Wire Wire Line
	8250 1800 8650 1800
Wire Wire Line
	8050 3350 9350 3350
Wire Wire Line
	8050 3750 9150 3750
Wire Wire Line
	9350 3350 9350 1200
Wire Wire Line
	9350 1200 7800 1200
Wire Wire Line
	7800 1200 7800 1350
Connection ~ 9350 3350
Wire Wire Line
	9350 3350 9800 3350
Wire Wire Line
	9150 1900 7800 1900
Wire Wire Line
	7800 1900 7800 1800
Wire Wire Line
	2550 3900 3050 3900
Wire Wire Line
	5950 1400 4850 1400
Wire Wire Line
	4850 1400 4850 4350
Wire Wire Line
	5950 1500 2450 1500
Wire Wire Line
	2450 4050 3050 4050
Wire Wire Line
	2850 1200 5950 1200
$Comp
L Switch:SW_Push_SPDT Rev_Trigger
U 1 1 5CEA8643
P 3100 6250
F 0 "Rev_Trigger" H 3100 5900 50  0000 C CNN
F 1 "SW_Push_SPDT" H 3100 6000 50  0000 C CNN
F 2 "" H 3100 6250 50  0001 C CNN
F 3 "~" H 3100 6250 50  0001 C CNN
	1    3100 6250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_SPDT Firing_Trigger
U 1 1 5CEA8EFA
P 4800 6250
F 0 "Firing_Trigger" H 4800 5900 50  0000 C CNN
F 1 "SW_Push_SPDT" H 4800 6000 50  0000 C CNN
F 2 "" H 4800 6250 50  0001 C CNN
F 3 "~" H 4800 6250 50  0001 C CNN
	1    4800 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 4050 4550 4050
Wire Wire Line
	4550 5800 2900 5800
Wire Wire Line
	2900 5800 2900 6250
Wire Wire Line
	4600 4200 4600 6250
Wire Wire Line
	2850 3450 2850 4900
Wire Wire Line
	3300 5750 3300 6150
Connection ~ 2850 3450
Wire Wire Line
	5000 5750 5000 6150
Wire Wire Line
	2850 5750 3300 5750
Connection ~ 3300 5750
Wire Wire Line
	3300 5750 5000 5750
Wire Wire Line
	2950 5700 3400 5700
Wire Wire Line
	3400 5700 3400 6350
Wire Wire Line
	3400 6350 3300 6350
Wire Wire Line
	3400 5700 5100 5700
Wire Wire Line
	5100 5700 5100 6350
Wire Wire Line
	5100 6350 5000 6350
Connection ~ 3400 5700
Text Label 9450 3850 0    50   ~ 0
12awg
Text Label 7750 3750 0    50   ~ 0
16awg
Text Label 7750 3600 0    50   ~ 0
16awg
Text Label 9450 3350 0    50   ~ 0
12awg
Text Label 9450 2750 1    50   ~ 0
20awg
Text Label 9250 2750 1    50   ~ 0
20awg
Text Label 7750 3050 0    50   ~ 0
20awg
Text Label 7750 2900 0    50   ~ 0
20awg
Text Label 7950 1750 0    50   ~ 0
20awg
Text Label 7950 1600 0    50   ~ 0
20awg
Text Label 7750 4300 0    50   ~ 0
20awg
Text Label 7750 4450 0    50   ~ 0
20awg
$Comp
L Nemesis-Mod:Adafruit_I2C_FRAM_Breakout FRAM1
U 1 1 5D0F0143
P 1300 4500
F 0 "FRAM1" H 1050 4950 50  0000 L CNN
F 1 "Adafruit_I2C_FRAM_Breakout" H 650 4850 50  0000 L CNN
F 2 "" H 1150 4950 50  0001 C CNN
F 3 "" H 1150 4950 50  0001 C CNN
	1    1300 4500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2850 4900 1800 4900
Connection ~ 2850 4900
Wire Wire Line
	2850 4900 2850 5750
Wire Wire Line
	1800 5000 2950 5000
Wire Wire Line
	2950 5000 2950 5700
Wire Wire Line
	1800 4700 2250 4700
Wire Wire Line
	2250 4700 2250 5600
Wire Wire Line
	2250 5600 4850 5600
Wire Wire Line
	4850 5600 4850 5100
Wire Wire Line
	4850 5100 4450 5100
Wire Wire Line
	1800 4600 2350 4600
Wire Wire Line
	2350 4600 2350 5500
Wire Wire Line
	2350 5500 4750 5500
Wire Wire Line
	4750 5500 4750 5250
Wire Wire Line
	4750 5250 4450 5250
Wire Wire Line
	9150 3750 9150 1900
Wire Wire Line
	9150 3750 9800 3750
Connection ~ 9150 3750
Wire Wire Line
	2050 2800 2050 2900
$Comp
L Device:R_Small_US Resistor
U 1 1 5D19815F
P 2050 3050
F 0 "Resistor" H 2100 3100 50  0000 L CNN
F 1 "10K" H 2118 3005 50  0000 L CNN
F 2 "" H 2050 3050 50  0001 C CNN
F 3 "~" H 2050 3050 50  0001 C CNN
	1    2050 3050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push RESET
U 1 1 5D15A0F1
P 1850 2800
F 0 "RESET" H 1850 3085 50  0000 C CNN
F 1 "Tactile_SW_Button" H 1850 2994 50  0000 C CNN
F 2 "" H 1850 3000 50  0001 C CNN
F 3 "~" H 1850 3000 50  0001 C CNN
	1    1850 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 3450 1650 3450
Wire Wire Line
	1650 3450 1650 2800
Wire Wire Line
	2050 2900 1900 2900
Wire Wire Line
	1900 2900 1900 4200
Connection ~ 2050 2900
Wire Wire Line
	2050 2900 2050 2950
Wire Wire Line
	1900 4200 3050 4200
Wire Wire Line
	2950 3150 3050 3150
Connection ~ 2950 3150
Connection ~ 2950 5000
Wire Wire Line
	4850 4350 4450 4350
Wire Wire Line
	4450 4200 4600 4200
Wire Wire Line
	5100 2550 2750 2550
Wire Wire Line
	5950 1700 2550 1700
Wire Wire Line
	2050 3150 2950 3150
Wire Wire Line
	4550 4050 4550 5800
Wire Wire Line
	2950 3150 2950 5000
Wire Wire Line
	2450 1500 2450 4050
Wire Wire Line
	2550 1700 2550 3900
Wire Wire Line
	2650 3750 2650 2500
Wire Wire Line
	2750 2550 2750 3600
$Comp
L Nemesis-Mod:Adafruit_nRF52_Feather MCU
U 1 1 5DBD8417
P 3750 4150
F 0 "MCU" H 3750 5565 50  0000 C CNN
F 1 "Adafruit_nRF52_Feather" H 3750 5474 50  0000 C CNN
F 2 "" H 4400 2850 50  0001 C CNN
F 3 "" H 4400 2850 50  0001 C CNN
	1    3750 4150
	1    0    0    -1  
$EndComp
$Comp
L Nemesis-Mod:Nerf_Hopper_Lock Power_Lock
U 1 1 5DDF54E1
P 8200 6650
F 0 "Power_Lock" H 8150 7750 50  0000 C CNN
F 1 "Nerf_Hopper_Lock" H 8150 7850 50  0000 C CNN
F 2 "" H 8200 7750 50  0001 C CNN
F 3 "" H 8200 7750 50  0001 C CNN
	1    8200 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 5450 7600 5450
Wire Wire Line
	7600 6250 8150 6250
Wire Wire Line
	7600 5450 7600 6250
Wire Wire Line
	2850 1200 2850 2600
Wire Wire Line
	6750 4850 6750 5050
Wire Wire Line
	6750 5050 7750 5050
Wire Wire Line
	7750 5050 7750 5750
Wire Wire Line
	8550 5750 8550 5350
Wire Wire Line
	8550 5350 4900 5350
Wire Wire Line
	4900 5350 4900 2600
Wire Wire Line
	4900 2600 2850 2600
Connection ~ 2850 2600
Wire Wire Line
	2850 2600 2850 3450
Wire Wire Line
	8550 5950 8600 5950
Wire Wire Line
	8600 5950 8600 5300
Wire Wire Line
	8600 5300 4950 5300
Wire Wire Line
	4950 5300 4950 3900
Wire Wire Line
	4950 3900 4450 3900
NoConn ~ 7750 5950
NoConn ~ 6600 5450
NoConn ~ 5300 4250
NoConn ~ 5300 3950
NoConn ~ 5300 3500
NoConn ~ 5300 3200
NoConn ~ 5300 3050
NoConn ~ 5300 2900
NoConn ~ 5300 2750
NoConn ~ 5300 2600
NoConn ~ 4450 3750
NoConn ~ 4450 3600
NoConn ~ 3050 3300
NoConn ~ 3050 3000
NoConn ~ 3050 4350
NoConn ~ 3050 4500
NoConn ~ 3050 4650
NoConn ~ 3050 4800
NoConn ~ 3050 4950
NoConn ~ 3050 5100
NoConn ~ 3050 5250
NoConn ~ 1800 4800
NoConn ~ 1800 4500
NoConn ~ 1800 4400
NoConn ~ 1800 4300
NoConn ~ 6450 4850
NoConn ~ 6600 4850
NoConn ~ 5950 1900
NoConn ~ 5950 1800
NoConn ~ 5950 1600
NoConn ~ 5950 1300
$EndSCHEMATC
