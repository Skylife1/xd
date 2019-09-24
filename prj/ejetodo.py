#!/usr/bin/python

import subprocess
import os
import time

i=1
x=1

while(x==1):
 subprocess.call(['./ejecutar.sh'])
 time.sleep(30)
 i=i+1
 print("Ejecutando ciclo " + str(i))
 x=1

	
