
# coding: utf-8

# In[1]:

##importamos numpy y matplot
import numpy
import matplotlib.pyplot as pyplot

import warnings
warnings.filterwarnings("ignore")


# In[2]:

#graficar las trayectorias
for i in range(7):
    trayectoria=numpy.loadtxt(('dinamica_'+str(10+10*i)),float,delimiter=',')
    pyplot.plot(trayectoria[:,1],trayectoria[:,2])
##leer el archivo de la trayectoria a 45 grados:
trayectoria=numpy.loadtxt(('primera_parte'),float,delimiter=',')
pyplot.plot(trayectoria[:,1],trayectoria[:,2])
pyplot.xlabel('x')
pyplot.ylabel('y')
pyplot.legend(('$\lambda$'+'=10','$\lambda$'+'=20','$\lambda$'+'=30','$\lambda$'+'=40','$\lambda$'+'=50','$\lambda$'+'=60','$\lambda$'+'=70','$\lambda$'+'=45'), loc='upper left')
pyplot.savefig('primer_punto.png')


# In[3]:

##graficar la placa con el agujero:
##como el dominio no es cuadrado, importamos la libreria AXES 3D:
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm



# In[4]:

##leemos las coordenadas de los puntos
coor_puntos=numpy.loadtxt('puntos.txt',float,delimiter=',')


# In[5]:

##leemos los datos de las temperaturas para los tres casos estudiados:
T_1=numpy.loadtxt('bordes_10C.txt',float,delimiter=',',usecols=range(36))
T_2=numpy.loadtxt('bordes_abiertos.txt',float,delimiter=',',usecols=range(36))
T_3=numpy.loadtxt('bordes_periodicos.txt',float,delimiter=',',usecols=range(36))
dt1=3
dt2=dt1
dt3=10
step1=10000
step2=100000
step3=100000
x=coor_puntos[:,0]
y=coor_puntos[:,1]




# In[6]:

##generamos las graficas solicitadas: las graficas se numeraran como T1_inicia, T1_final, T_1_intermediot_tantos segundos, 
#haciendo 1 referencia al caso.
##primer casO:
names=('inicial','t_10000s','t_20000s','final')
for i in range(4):
    T_graf=T_1[3333*i,:]
    fig = pyplot.figure()
    ax = fig.gca(projection='3d')
    ax.plot_trisurf(x,y,T_graf,cmap=pyplot.cm.hot)
    fig.savefig('T1_'+names[i]+'.png')
 
        





