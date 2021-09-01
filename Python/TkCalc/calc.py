#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Instalacion:
https://tkdocs.com/tutorial/install.html

sudo apt-get install python3-tk
sudo dnf insatall python3-tkinter
"""

import tkinter as tk
from tkinter import ttk

class Calc(tk.Frame):

    def __init__(self, master=None):
        super().__init__(master)
        self.title = "Calc"
        self.geometry = "600x200"
        self.master = master
        self.pack()
        self.create_widgets()

    def create_widgets(self):
        self.inp = ttk.Entry(root, font=("Arial 20"))
        self.inp.grid(row=0, column=0, padx=10, pady=10)

root = tk.Tk()
app = Calc(master=root)
app.mainloop()