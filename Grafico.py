import pandas as pd
import matplotlib.pyplot as plt

# Lendo os dados do Excel e definindo eles como variáveis
tempr = pd.read_excel('temperatura.xlsx')
horas = tempr['Hora']
temperatura = tempr['Atual']
temp_min = tempr['Min']
temp_max = tempr['Max']

# Configuração da figura e dos eixos
fig, ax1 = plt.subplots (figsize=(10, 6))

# Gráfico de linhas para a temperatura
ax1.plot(horas, temperatura, color='green', marker='o', label='Temperatura') 
ax1.set_ylabel('Temperatura') 
ax1.tick_params (axis='y')

# Criar um segundo gráfico de linhas para a temperatura mínima
ax1.plot(horas, temp_min, color='blue', marker='o', label='Temp_Min') 

# Criar um terceiro gráfico de linhas para a temperatura máxima
ax1.plot(horas, temp_max, color='red', marker='o', label='Temp_Max') 

# Adicionar título e legenda
plt.title('Histórico de Temperatura - Atual, Mínima e Máxima') 
ax1.legend (loc='upper left')

# Exibir o gráfico 
plt.show()