import serial

while True:
    try:
        arduino = serial.Serial('COM7', 9600)
        print('Arduino conectado com sucesso')
        break
    except:
        pass

while True: #Loop principal
    msg = str(arduino.readline())
    msg = msg[2:-5]
    print(msg)
    arduino.flush()