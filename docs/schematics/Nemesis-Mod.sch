EESchema Schematic File Version 4
LIBS:Nemesis-Mod-cache
EELAYER 29 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "Nemesis Mod"
Date "2019-05-22"
Rev "v1.0"
Comp "https://github.com/jeff-winn/Nemesis-Mod"
Comment1 "For more information please visit the project website:"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Nemesis-Mod:Adafruit_Feather_M0 MCU
U 1 1 5CE64CEC
P 2900 4250
F 0 "MCU" H 2900 5665 50  0000 C CNN
F 1 "Adafruit_Feather_M0" H 2900 5574 50  0000 C CNN
F 2 "" H 3550 2950 50  0001 C CNN
F 3 "" H 3550 2950 50  0001 C CNN
	1    2900 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BATT
U 1 1 5CE683D1
P 8800 3650
F 0 "BATT" H 8650 3650 50  0000 R CNN
F 1 "3S LiPo Battery" H 8650 3750 50  0000 R CNN
F 2 "" V 8800 3710 50  0001 C CNN
F 3 "~" V 8800 3710 50  0001 C CNN
	1    8800 3650
	-1   0    0    1   
$EndComp
$Comp
L Motor:Motor_DC Flywheel_M1
U 1 1 5CE6FA2E
P 7550 2950
F 0 "Flywheel_M1" H 7708 2946 50  0000 L CNN
F 1 "Motor_DC" H 7708 2855 50  0000 L CNN
F 2 "" H 7550 2860 50  0001 C CNN
F 3 "~" H 7550 2860 50  0001 C CNN
	1    7550 2950
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC Flywheel_M2
U 1 1 5CE70E23
P 7550 4350
F 0 "Flywheel_M2" H 7708 4346 50  0000 L CNN
F 1 "Motor_DC" H 7708 4255 50  0000 L CNN
F 2 "" H 7550 4260 50  0001 C CNN
F 3 "~" H 7550 4260 50  0001 C CNN
	1    7550 4350
	1    0    0    -1  
$EndComp
$Comp
L Nemesis-Mod:Pololu_G2_HighPower_18v18 Motor_Driver1
U 1 1 5CE740FA
P 5700 3650
F 0 "Motor_Driver1" H 5700 4915 50  0000 C CNN
F 1 "Pololu_G2_HighPower_18v18" H 5700 4824 50  0000 C CNN
F 2 "" H 5650 4850 50  0001 C CNN
F 3 "" H 5650 4850 50  0001 C CNN
	1    5700 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 4450 7200 4450
Wire Wire Line
	7200 4450 7200 4650
Wire Wire Line
	7200 4650 7550 4650
Wire Wire Line
	6950 4300 7200 4300
Wire Wire Line
	7200 4300 7200 4150
Wire Wire Line
	7200 4150 7550 4150
Wire Wire Line
	6950 3050 7200 3050
Wire Wire Line
	7200 3050 7200 3250
Wire Wire Line
	7200 3250 7550 3250
Wire Wire Line
	6950 2900 7200 2900
Wire Wire Line
	7200 2900 7200 2750
Wire Wire Line
	7200 2750 7550 2750
$Comp
L Nemesis-Mod:Pololu_5V_Step_Down_Regulator Voltage_Regulator
U 1 1 5CE79472
P 6150 6550
F 0 "Voltage_Regulator" H 5650 6600 50  0000 L CNN
F 1 "Pololu_5V_Step_Down_Regulator" H 5450 6700 50  0000 L CNN
F 2 "" H 6000 6600 50  0001 C CNN
F 3 "" H 6000 6600 50  0001 C CNN
	1    6150 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4950 6050 5550
Wire Wire Line
	5900 5550 5900 5250
Wire Wire Line
	5900 5250 6200 5250
Wire Wire Line
	6200 5250 6200 4950
Wire Wire Line
	6200 5550 6200 5400
Wire Wire Line
	6200 5400 3800 5400
Wire Wire Line
	3800 5400 3800 4000
Wire Wire Line
	3800 4000 3600 4000
Wire Wire Line
	5900 4950 5900 5150
Wire Wire Line
	5900 5150 3900 5150
Wire Wire Line
	3900 5150 3900 2700
Wire Wire Line
	3900 2700 2000 2700
Wire Wire Line
	2000 2700 2000 3550
Wire Wire Line
	2000 3550 2200 3550
Wire Wire Line
	3600 4600 4350 4600
Wire Wire Line
	4350 4600 4350 4200
Wire Wire Line
	4350 4200 4450 4200
Wire Wire Line
	3600 4750 4300 4750
Wire Wire Line
	4300 4750 4300 3450
Wire Wire Line
	4300 3450 4450 3450
Wire Wire Line
	3600 4900 4250 4900
Wire Wire Line
	4250 4900 4250 4500
Wire Wire Line
	4250 4500 4450 4500
Wire Wire Line
	3600 5050 4200 5050
Wire Wire Line
	4200 5050 4200 3750
Wire Wire Line
	4200 3750 4450 3750
Wire Wire Line
	4450 3900 4250 3900
Wire Wire Line
	4250 3900 4250 2650
Wire Wire Line
	4250 2650 1900 2650
Wire Wire Line
	1900 2650 1900 3700
Wire Wire Line
	1900 3700 2200 3700
Wire Wire Line
	2200 3850 1800 3850
Wire Wire Line
	1800 3850 1800 2600
Wire Wire Line
	1800 2600 4150 2600
Wire Wire Line
	4150 2600 4150 4650
Wire Wire Line
	4150 4650 4450 4650
Wire Wire Line
	7200 3450 7200 3600
Wire Wire Line
	7200 3600 6950 3600
Wire Wire Line
	6950 3750 7200 3750
Wire Wire Line
	7200 3750 7200 3850
$Comp
L Nemesis-Mod:Pololu_G2_HighPower_18v17 Motor_Driver2
U 1 1 5CE6ED10
P 6050 1650
F 0 "Motor_Driver2" H 6025 2265 50  0000 C CNN
F 1 "Pololu_G2_HighPower_18v17" H 6025 2174 50  0000 C CNN
F 2 "" H 6050 2200 50  0001 C CNN
F 3 "" H 6050 2200 50  0001 C CNN
	1    6050 1650
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC Belt_M1
U 1 1 5CE7132F
P 7800 1600
F 0 "Belt_M1" H 7958 1596 50  0000 L CNN
F 1 "Motor_DC" H 7958 1505 50  0000 L CNN
F 2 "" H 7800 1510 50  0001 C CNN
F 3 "~" H 7800 1510 50  0001 C CNN
	1    7800 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 1750 7500 1750
Wire Wire Line
	7500 1750 7500 1400
Wire Wire Line
	7500 1400 7800 1400
Wire Wire Line
	6950 1600 7400 1600
Wire Wire Line
	7400 1600 7400 1900
Wire Wire Line
	7400 1900 7800 1900
Wire Wire Line
	7200 3450 8500 3450
Wire Wire Line
	7200 3850 8300 3850
Wire Wire Line
	8500 3450 8500 1300
Wire Wire Line
	8500 1300 6950 1300
Wire Wire Line
	6950 1300 6950 1450
Connection ~ 8500 3450
Wire Wire Line
	8500 3450 8800 3450
Wire Wire Line
	8300 3850 8300 2000
Wire Wire Line
	8300 2000 6950 2000
Wire Wire Line
	6950 2000 6950 1900
Connection ~ 8300 3850
Wire Wire Line
	8300 3850 8800 3850
Wire Wire Line
	5100 1800 1700 1800
Wire Wire Line
	1700 1800 1700 4000
Wire Wire Line
	1700 4000 2200 4000
Wire Wire Line
	5100 1500 4000 1500
Wire Wire Line
	4000 1500 4000 4450
Wire Wire Line
	4000 4450 3600 4450
Wire Wire Line
	5100 1600 1600 1600
Wire Wire Line
	1600 1600 1600 4150
Wire Wire Line
	1600 4150 2200 4150
Wire Wire Line
	2000 2700 2000 1300
Wire Wire Line
	2000 1300 5100 1300
Connection ~ 2000 2700
$Comp
L Switch:SW_Push_SPDT Rev_Trigger
U 1 1 5CEA8643
P 2250 6350
F 0 "Rev_Trigger" H 2250 6635 50  0000 C CNN
F 1 "SW_Push_SPDT" H 2250 6544 50  0000 C CNN
F 2 "" H 2250 6350 50  0001 C CNN
F 3 "~" H 2250 6350 50  0001 C CNN
	1    2250 6350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_SPDT Firing_Trigger
U 1 1 5CEA8EFA
P 4200 6350
F 0 "Firing_Trigger" H 4200 6635 50  0000 C CNN
F 1 "SW_Push_SPDT" H 4200 6544 50  0000 C CNN
F 2 "" H 4200 6350 50  0001 C CNN
F 3 "~" H 4200 6350 50  0001 C CNN
	1    4200 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 4300 3750 4300
Wire Wire Line
	3600 4150 3700 4150
Wire Wire Line
	3700 4150 3700 5900
Wire Wire Line
	1900 6350 2050 6350
Wire Wire Line
	3700 5900 1900 5900
Wire Wire Line
	1900 5900 1900 6350
Wire Wire Line
	3750 4300 3750 6350
Wire Wire Line
	3750 6350 4000 6350
Wire Wire Line
	2000 3550 2000 5850
Wire Wire Line
	2650 5850 2650 6250
Wire Wire Line
	2650 6250 2450 6250
Connection ~ 2000 3550
Wire Wire Line
	4650 5850 4650 6250
Wire Wire Line
	4650 6250 4400 6250
Wire Wire Line
	2000 5850 2650 5850
Connection ~ 2650 5850
Wire Wire Line
	2650 5850 4650 5850
Wire Wire Line
	2200 3250 2100 3250
Wire Wire Line
	2100 3250 2100 5800
Wire Wire Line
	2100 5800 2750 5800
Wire Wire Line
	2750 5800 2750 6450
Wire Wire Line
	2750 6450 2450 6450
Wire Wire Line
	2750 5800 4750 5800
Wire Wire Line
	4750 5800 4750 6450
Wire Wire Line
	4750 6450 4400 6450
Connection ~ 2750 5800
Text Label 8450 3950 0    50   ~ 0
12awg
Text Label 6900 3850 0    50   ~ 0
16awg
Text Label 6900 3700 0    50   ~ 0
16awg
Text Label 8600 3450 0    50   ~ 0
12awg
Text Label 8600 2850 1    50   ~ 0
20awg
Text Label 8400 2850 1    50   ~ 0
20awg
Text Label 6900 3150 0    50   ~ 0
20awg
Text Label 6900 3000 0    50   ~ 0
20awg
Text Label 7100 1850 0    50   ~ 0
20awg
Text Label 7100 1700 0    50   ~ 0
20awg
Text Label 6900 4400 0    50   ~ 0
20awg
Text Label 6900 4550 0    50   ~ 0
20awg
$EndSCHEMATC
