#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time 
import pywhatkit
import pyautogui
import pynput
from pynput.keyboard import Key, Controller

keyboard = Controller()


def send_whatsapp_message(msg: str, h: int, m: int, no: str):
    try:
        pywhatkit.sendwhatmsg(
            phone_no=no, 
            message=msg,
            tab_close=True,
            time_hour=h,
            time_min=m
        )
        time.sleep(10)
        pyautogui.click()
        time.sleep(2)
        keyboard.press(Key.enter)
        keyboard.release(Key.enter)
        print("Message sent!")
    except Exception as e:
        print(str(e))


if __name__ == "__main__":
    send_whatsapp_message(msg="Feliz cumpleaños!", h=4, m=0)