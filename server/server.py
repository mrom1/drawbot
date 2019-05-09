import serial, time, socket
arduino = serial.Serial('COM1', 115200, timeout=.1)
time.sleep(1) #give the connection a second to settle


host = socket.gethostname()
port = 5000

server_socket = socket.socket()
server_socket.bind((host, port))

server_socket.listen(2)
conn, address = server_socket.accept()  # accept new connection
print("Connection from: " + str(address))

while True:
    socket_data = conn.recv(1024).decode()
    arduino_data = arduino.read()
    if arduino_data:
        print(arduino_data)

    if socket_data:
        print("From connected user: " + str(socket_data) + "\n\n")
        # todo: validate
        print("Sending to Arduino...")
        arduino.write(socket_data)

conn.close()
