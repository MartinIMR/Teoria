import random
import matplotlib.pyplot as plt
x = random.sample(range(1000), 100)
xbins = [0, len(x)]

plt.bar(range(0,100), x)

#plt.hist(x, bins=xbins, color = 'blue') 
#Does not make the histogram correct. It counts the occurances of the individual counts. 

#plt.plot(x)
#plot works but I need this in histogram format
plt.show()
