# -*- coding: utf-8 -*-
"""
Created on Fri Oct  6 17:17:03 2023

@author: renat
"""

import numpy as np
import matplotlib.pyplot as plt
#from helperMethods import helperMethods

#Obj_GPS = helperMethods();

data = np.load('2023-09-29 13-41-59.730989.npy');
#data = np.load('2023-09-29 14-00-25.416023.npy');
#data = np.load('2023-09-29 17-29-54.303650.npy');
#data = np.load('2023-09-29 17-32-32.553682.npy');
#data = np.load('2023-09-29 20-07-09.986058.npy');
#data = np.load('2023-09-29 20-09-50.347539.npy');
#data = np.load('2023-09-29 20-12-25.874768.npy');
#data = np.load('2023-09-29 20-15-43.253943.npy');
#data = np.load('2023-09-29 20-16-30.506327.npy');
#data = np.load('2023-09-29 20-18-37.682509.npy');

time = data[:,0].copy();
YPR = data[:,3:6].copy();
Lat_Long_alt = data[:,6:9].copy();
V_NED = data[:,9:12].copy();

for i in range(len(Lat_Long_alt[:,1])):
    print(f'Dado de número {i}');
    print(f'Tempo da medição a partir da inicialização: {time[i]} s')
    print(f'Posição (Latitude, Longitude, Altitude): ({Lat_Long_alt[i,0]}º , {Lat_Long_alt[i,1]}º , {Lat_Long_alt[i,2]} m)')
    V_abs = np.sqrt(V_NED[i,:] @ V_NED[i,:].T);
    print(f'Velocidade: {V_abs} m/s');
    Yaw = np.deg2rad(YPR[i,0]);
    print(f'Ângulo de orientação: {Yaw} rad ');
    if i > 0:
        dt = time[i]-time[i-1];
        a_ned = (V_NED[i,:]-V_NED[i-1,:])/dt;
        a_abs = np.sqrt(a_ned @ a_ned.T);
        print(f'Aceleração: {a_abs} m/s^2');
        YawRate = (Yaw - np.deg2rad(YPR[i-1,0]))/dt;
        print(f'Heading angle: {YawRate} rad/s');
        
    print('\n')
        
plt.figure();
plt.plot(Lat_Long_alt[:,1],Lat_Long_alt[:,0]);
plt.show();

#plt.figure();
#plt.plot(X,Y);
#plt.show();
