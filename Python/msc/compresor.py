#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Para su uso se debe instalar:
pip3 install Pillow
"""

import os
from PIL import Image

image_ext = [".jpg", ".jpeg", ".png", ".tiff", ".bmp"]
download = "/home/c05m4r/Pictures/"

if __name__ == "__main__":
    for filename in os.listdir(download):
        name, extension = os.path.splitext(download + filename)
        if extension in image_ext:
            picture = Image.open(download + filename)
            picture.save(download + "min_" + filename, optimize=True, quality=30)
            os.remove(download + filename)
