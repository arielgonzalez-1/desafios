#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# You need install psutil and pyautogui with pip3
# Please, run this script with crontab
import psutil
import pyautogui

def show_status():
    """A simple code to show status battery automatically."""
    battery = psutil.sensors_battery()
    if battery.percent < 15:
        msg = f'Low battery\nBattery percent: {round(battery.percent, 2)}\nPower plugged in : {battery.power_plugged}'
        pyautogui.alert(text=msg)

def main():
    show_status()

if __name__ == '__main__':
    main()