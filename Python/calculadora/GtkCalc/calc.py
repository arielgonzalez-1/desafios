#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Instalacion:

https://pygobject.readthedocs.io/en/latest/getting_started.html#fedora-getting-started

sudo dnf install cairo-gobject-devel
pip3 install pycairo
pip3 install PyGObject
"""
import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

class Calc(Gtk.Window):
    buttons = [
        ['1', '2', '3', '4', '-', 'DEL'],
        ['5', '6', '7', '8', '/', 'AC'],
        ['9', '0', '%', '*', '+', '=']
    ]

    def __init__(self):
        Gtk.Window.__init__(self, title="Calc")
        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
        self.add(vbox)

        grid = Gtk.Grid()
        self.entry = Gtk.Entry()

        vbox.pack_start(self.entry, True, True, 1)
        vbox.pack_end(grid, True, True, 1)

        y = 0
        for row in self.buttons:
            x = 0
            for col in row:
                button = Gtk.Button(label=col)
                button.connect("pressed", self.__pressed_button)
                grid.attach(button, x, y, 1, 1)
                x += 1
            y += 1

    def __pressed_button(self, widget):
        label = widget.get_label()
        text_entry = self.entry.get_text()
        if label == "DEL":
            text_entry = text_entry[:-1]
            self.entry.set_text(text_entry)
        elif label == "AC":
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

win = Calc()
win.connect('destroy', Gtk.main_quit)
win.show_all()
Gtk.main()