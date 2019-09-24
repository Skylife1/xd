#!/usr/bin/python
import httplib
import urllib
import mraa
import time
import math

key = "X230HLOMFKIA19FV" ##api key


a = mraa.Aio(1)
hz = a.read()
freq = ((1023.0/hz)-2.9)*1000
param = urllib.urlencode({'field1':freq, 'key':key})

b = mraa.Aio(0)
dB = b.read()
param2 = urllib.urlencode({'field2':dB, 'key':key})


headers = {"Content-typZZe": "application/x-www-form-urlencoded","Accept": "text/plain"}


conn = httplib.HTTPConnection("api.thingspeak.com:80")


conn.request("POST","/update", param2 , headers)



response = conn.getresponse()


print freq
print dB
print response.status, response.reason
data = response.read()


conn.close()


print "Frecuencia " + str(freq)
print "Decibeles " + str(dB)
