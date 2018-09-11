import matplotlib.pyplot as plt

with open('datos.txt') as archivo:
    lineas = archivo.readlines()
    primos = [linea.split()[0] for linea in lineas]
    unos = [linea.split()[1] for linea in lineas]


plt.title('Unos en cada primo en binario')
plt.xlabel('Primos')
plt.ylabel('Numero de unos totales')

#xbins = [0,unos]

plt.bar(primos, unos, bottom = 0)
plt.show()

#plt.hist(x, bins=xbins, color = 'blue') 
#Does not make the histogram correct. It counts the occurances of the individual counts. 
#plt.plot(x)
#plot works but I need this in histogram format
#plt.show()

