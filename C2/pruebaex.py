#!/usr/bin/python

import subprocess
import os
import time

i=1
x=1

while(x==1):
 subprocess.call(['./execute.sh'])
 time.sleep(30)
 i=i+1
 print("Ejecutando ")
 x=1

	
