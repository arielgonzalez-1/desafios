#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Instalacion:
https://tkdocs.com/tutorial/install.html

sudo apt-get install python3-tk
sudo dnf insatall python3-tkinter
"""

from tkinter import *
from tkinter import ttk

root = Tk()
root.title = "Calc"

"""
def pressed_button(self, widget):
    if label == "AC":
        self.entry.set_text("")
    elif label == "=":
        try:
            result = str(eval(text_entry))
        except SyntaxError:
            result = "Syntax Error"
        except ZeroDivisionError:
            result = "Zero Division Error"
        finally:
            self.entry.set_text(result)
    else:
        text_entry += label
        self.entry.set_text(text_entry)
"""

inp = Entry(root, font=("Arial 20"))
inp.grid(row=0, column=0, columnspan=4, padx=10, pady=10)

btn0 = Button(root, text="0", width=5, height=2)
btn1 = Button(root, text="1", width=5, height=2)
btn2 = Button(root, text="2", width=5, height=2)
btn3 = Button(root, text="3", width=5, height=2)
btn4 = Button(root, text="4", width=5, height=2)
btn5 = Button(root, text="5", width=5, height=2)
btn6 = Button(root, text="6", width=5, height=2)
btn7 = Button(root, text="7", width=5, height=2)
btn8 = Button(root, text="8", width=5, height=2)
btn9 = Button(root, text="9", width=5, height=2)
btnBkt1 = Button(root, text="(", width=5, height=2)
btnBkt2 = Button(root, text=")", width=5, height=2)
btnPt = Button(root, text=".", width=5, height=2)
btnAC = Button(root, text="AC", width=5, height=2)
btnEQ = Button(root, text="=", width=5, height=2)
btnDIV = Button(root, text="/", width=5, height=2)
btnMUL = Button(root, text="*", width=5, height=2)
btnSUB = Button(root, text="-", width=5, height=2)
btnADD = Button(root, text="+", width=5, height=2)

btnAC.grid(row=1, column=0, padx=5, pady=5)
btnBkt1.grid(row=1, column=1, padx=5, pady=5)
btnBkt2.grid(row=1, column=2, padx=5, pady=5)
btnDIV.grid(row=1, column=3, padx=5, pady=5)

btn7.grid(row=2, column=0, padx=5, pady=5)
btn8.grid(row=2, column=1, padx=5, pady=5)
btn9.grid(row=2, column=2, padx=5, pady=5)
btnMUL.grid(row=2, column=3, padx=5, pady=5)

btn6.grid(row=3, column=0, padx=5, pady=5)
btn5.grid(row=3, column=1, padx=5, pady=5)
btn4.grid(row=3, column=2, padx=5, pady=5)
btnSUB.grid(row=3, column=3, padx=5, pady=5)

btn1.grid(row=4, column=0, padx=5, pady=5)
btn2.grid(row=4, column=1, padx=5, pady=5)
btn3.grid(row=4, column=2, padx=5, pady=5)
btnADD.grid(row=4, column=3, padx=5, pady=5)

btn0.grid(row=5, column=0, columnspan=2, padx=5, pady=5)
btnPt.grid(row=5, column=2, padx=5, pady=5)
btnEQ.grid(row=5, column=3, padx=5, pady=5)

root.mainloop()