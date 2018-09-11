import matplotlib.pyplot as plt

with open('datos.txt') as archivo:
    lineas = archivo.readlines()
    cadena = [linea.split()[0] for linea in lineas]
    unos = [linea.split()[1] for linea in lineas]


plt.title('Unos en cada cadena en binario')
plt.xlabel('Numero de cadena')
plt.ylabel('Numero de unos')

xbins = [0,unos]
plt.bar(cadena, unos, bottom = 0)
plt.show()

#plt.hist(x, bins=xbins, color = 'blue') 
#Does not make the histogram correct. It counts the occurances of the individual counts. 
#plt.plot(cadena)
#plot works but I need this in histogram format
#plt.show()
