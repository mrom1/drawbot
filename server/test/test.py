import serial, time
arduino = serial.Serial('dev/ttyACM0', 115200, timeout=.1)
time.sleep(1) #give the connection a second to settle

with open('test/circle.nc') as f:
    for line in f:
        arduino.write(line)
        time.sleep(1)
