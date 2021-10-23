import requests
import json

ss = 250 #sunflower sapling profit
sm = 100 #sunflower mama profit
smp = 850 #sunflower mama price
ssp = 200 #sunflower sapling price
week = sm + ss*5*2 - (smp + ssp*5*2)
month = week * 4
pvu2le = 732
totpvu = 8600/pvu2le
url = "https://www.coingecko.com/en/coins/plant-vs-undead-token/usd"
pvu2usd = requests.get(url).json()
#pvu2usd = json.load(requests.urlopen(url))
#total = pvu2usd*totpvu
print(pvu2usd)
