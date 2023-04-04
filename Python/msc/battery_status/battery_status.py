#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import schedule
import time
import psutil
import pyautogui


def show_status():
    """A simple code to show status battery automatically."""
    battery = psutil.sensors_battery()
    if battery.percent < 15:
        msg = f'Low battery\nBattery percent: {round(battery.percent, 2)}\nPower plugged in : {battery.power_plugged}'
        pyautogui.alert(text=msg)

def main():
    schedule.every(1).minutes.do(show_status)
    while True:
        schedule.run_pending()
        time.sleep(1)

if __name__ == '__main__':
    main()