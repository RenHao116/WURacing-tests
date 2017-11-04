import redis
import serial
r = redis.StrictRedis(host='localhost' , port=6379, db=0)
ser = serial.Serial('/dev/ttyACM0', 9600)
for x in range(1,10) :
    #r.zadd('data',float(ser.read_until(' ')),str(ser.read_until('\n')))
    r.zadd('data',x , ser.readline())


f = open('testingdata.text','w')
#f.write(str(r.zrange('data',0,-1)))
for value in r.zrange('data',0,-1):
    #f.write(key+" ")
    f.write(value)
f.close()