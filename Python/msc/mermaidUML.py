#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import base64
import io
import requests as r
from PIL import Image
from matplotlib import pyplot as plt

graph = 'graph TD\nA[Christmas] -->|Get money| B(Go shopping)\nB --> C{Let me think}\nC -->|One| D[Laptop]\nC -->|Two| E[iPhone]\nC -->|Three| F[fa:fa-car Car]'

graphbytes = graph.encode("ascii")
base64_bytes = base64.b64encode(graphbytes)
base64_string = base64_bytes.decode("ascii")
img = Image.open(io.BytesIO(r.get('https://mermaid.ink/img/' + base64_string).content))
#plt.imshow(img)
plt.savefig("myimage.png")
