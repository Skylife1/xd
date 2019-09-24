#!/usr/bin/python
import httplib
import urllib
import mraa
import time
import math

key = "X230HLOMFKIA19FV" ##api key
f = open( "lecturas.json", "w+")

a = mraa.Aio(1)
hz = a.read()
freq = ((1023.0/hz)-2.9)*1000
param = urllib.urlencode({'field1':freq, 'key':key})

b = mraa.Aio(0)
dB = b.read()
param2 = urllib.urlencode({'field2':dB, 'key':key})


headers = {"Content-typZZe": "application/x-www-form-urlencoded","Accept": "text/plain"}
## headers2 = {"Content-typZZe": "application/x-www-form-urlencoded","Accept": "text/plain"}

conn = httplib.HTTPConnection("api.thingspeak.com:80")
## conn2 = httplib.HTTPConnection("api.thingspeak.com:80")

conn.request("POST","/update", param , headers)

## conn2.request("POST","/update", param2, headers2)

response = conn.getresponse()
## response2 = conn2.getresponse()

print freq
print dB
print response.status, response.reason
data = response.read()
## data2 = response2.read()

conn.close()
## conn2.close()

f.write('{"frecuencia": '+ '"'  + str(freq) + '",' + '"decibeles": ' + 
'"' 
+ str(dB) + '"}' )

f.close()

print "Frecuencia " + str(freq)
print "Decibeles " + str(dB)
