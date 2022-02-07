import time
import sys

a = sys.argv
print(a)

b = time.strptime(a[1][1:],"%d-%m-%Y %H:%M:%S")

print((time.time()-time.mktime(b))/3600)