#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from easyhash import Easyhash
import tkinter as tk
from tkinter import Frame, Text
from tkinter import Tk
from tkinter import ttk
from tkinter.filedialog import askopenfilename  

if __name__ == '__main__':
    easyhash = Easyhash()    
    root = Tk()
    root.geometry("600x200")
    root.title("Easyhash")
    root.resizable(False, False)

    container = Frame(root)
    container.grid(padx=10, pady=10)

    filecont = Frame(container)
    filecont.grid(row=0, column=0, padx=2, pady=2)

    checkcont = Frame(container)
    checkcont.grid(row=1, column=0, padx=2, pady=2)

    copycont = Frame(container)
    copycont.grid(row=2, column=0, padx=2, pady=2)

    txt_filename = Text(filecont, width = 20, height = 1)
    txt_filename.insert('end', 'Select file')
    txt_filename.grid(row=0, column=1, padx=10)
    xs = ttk.Scrollbar(filecont, orient = 'horizontal', command=txt_filename.xview)
    txt_filename['xscrollcommand'] = xs.set
    xs.grid(row=1, column=1, sticky = 'we')


    def update_filename():
        easyhash.set_filename(askopenfilename())
        new_filename = easyhash.get_filename()
        txt_filename.delete('1.0', 'end')
        txt_filename.insert('end', new_filename)

    btn_open = ttk.Button(filecont)
    btn_open['text'] = 'Open'
    btn_open['command'] = update_filename
    btn_open.grid(row=0, column=0, padx=10)

    hashes = (  
        "md5",
        "sha1",
        "sha224",
        "sha256",
        "sha384",
        "sha512",
        "blake2b",
        "blake2s",
        "sha3_224",
        "sha3_256",
        "sha3_384",
        "sha3_512",
        "adler32",
        "crc32"
    )
    selected_hash = tk.StringVar()
    cb_hash = ttk.Combobox(checkcont)
    cb_hash['textvariable'] = selected_hash
    cb_hash['values'] = hashes
    cb_hash['state'] = 'readonly'
    cb_hash.grid(row=0, column=2, padx=10)

    txt_hash = Text(copycont, width = 20, height = 1)
    txt_hash.insert('end', 'Select hash')
    txt_hash.grid(row=0, column=1, padx=10)
    xs = ttk.Scrollbar(copycont, orient = 'horizontal', command=txt_hash.xview)
    txt_hash['xscrollcommand'] = xs.set
    xs.grid(row=1, column=1, sticky = 'we')

    def update_hash():
        txt_hash.config(state = 'normal')
        txt_hash.delete('1.0', 'end')
        hash = easyhash.get_hash(cb_hash.get())
        txt_hash.insert('end', hash)
        txt_hash.config(state = 'disabled')


    def copy_hash():
        hash = easyhash.get_hash(cb_hash.get())
        root.clipboard_clear()
        root.clipboard_append(hash)

    btn_check = ttk.Button(checkcont)
    btn_check['text'] = 'Check'
    btn_check['command'] = update_hash
    btn_check.grid(row=0, column=0, padx=10, pady=5)

    btn_copy = ttk.Button(copycont)
    btn_copy['text'] = 'Copy'
    btn_copy['command'] = copy_hash
    btn_copy.grid(row=0, column=0, padx=10, pady=5)

    root.mainloop()