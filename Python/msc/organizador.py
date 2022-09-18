#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os


download = "/home/c05m4r/Downloads/"

picture = "/home/c05m4r/Pictures/"
document = "/home/c05m4r/Documents/"
music = "/home/c05m4r/Music/"
video = "/home/c05m4r/Videos/"

image_ext = [".jpg", ".jpeg", ".png", ".gif", ".bmp"]
document_ext = [".pdf", ".txt", ".doc", ".docx", ".odt", ".rtf", ".wps", ".xls", ".html", ".xml", ".htm", ".xps", ".csv", ".ods", ".odp", ".pptx", ".ppt"]
audio_ext = [".mp3"]
video_ext = [".mp4"]

if __name__ == "__main__":
    for filename in os.listdir(download):
        name, extension = os.path.splitext(download + filename)

        if extension in image_ext:
            os.rename(download + filename, picture + filename)

        elif extension in document_ext:
            os.rename(download + filename, document + filename)

        elif extension in audio_ext:
            os.rename(download + filename, music + filename)

        elif extension in video_ext:
            os.rename(download + filename, video + filename)