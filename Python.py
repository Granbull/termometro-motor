import serial

while True:
    try:
        arduino = serial.Serial('COM7', 9600)
        print('Arduino conectado com sucesso')
        break
    except:
        pass

while True: #Loop principal
    entradaSerial = str(arduino.readline())[2:-5].split(';')
    menorTemp = entradaSerial[0]
    temperatura = entradaSerial[1]
    maiorTemp = entradaSerial[2]
    print(f"A temperatura atual é de {temperatura}, com mínima de {menorTemp} e máxima de {maiorTemp}.")
    arduino.flush()