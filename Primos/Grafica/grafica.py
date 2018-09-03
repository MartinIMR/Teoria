import matplotlib.pyplot as plt
import numpy as np
import matplotlib.ticker as ticker
import sys
import operator 

with open('datos.txt') as archivo:
    lineas = archivo.readlines()
    X = [linea.split()[0] for linea in lineas]
    Y = [linea.split()[1] for linea in lineas]


plt.scatter(X,Y)
#plt.yscale('exp')
#plt.ylim(0,6000000)
#plt.xlim(0,20)
#plt.yticks(np.arange(min(Y),max(Y)+1,'1.0'))
#ay = plt.subplot()
#ay.plot(X,Y)
#start, end = ay.get_ylim()
plt.title('Relacion de numero de unos para determinada longitud de cadena')
plt.xlabel('Longitud de cadena')
plt.ylabel('Numero de unos totales')
plt.show()



