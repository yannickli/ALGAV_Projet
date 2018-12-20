#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Dec 19 21:59:05 2018

@author: yannickli
"""
import matplotlib.pyplot as plt

def ConsIter():
    x = [100,200,500,1000,5000, 10000, 20000, 50000]
    
    ConsIterArbre = [8.68e-05,0.0002324,0.0004234,0.0007464,0.0071914,0.0145456,0.0303476,0.0637792]
    ConsIterTab = [9.6e-06,1.7e-05,3.78e-05,7.26e-05,0.0004,0.0007904,0.0015426,0.0039764]
    ConsIterFileB = [0.000124,0.0002588,0.000685,0.0013546,0.0068424,0.0135868,0.0275114,0.0687178]

    plt.xlabel("Taille instance")
    plt.ylabel("Temps en s")
    plt.title('Complexite ConsIter')
    plt.plot(x, ConsIterArbre,'*',linestyle='-',label='ConsIterArbre')
    plt.plot(x, ConsIterTab,'^',linestyle='-',label='ConsIterTab')
    plt.plot(x, ConsIterFileB,'+',linestyle='-',label='ConsIterFileB')
    plt.legend()
    plt.show()
    
ConsIter()

def Union():
    x = [100,200,500,1000,5000, 10000, 20000, 50000]
    
    UnionArbre=[0.00030025,0.0006445,0.0018375,0.00388675,0.0231805,0.0495845,0.103665,0.267189]
    UnionTab =[2.2e-05,3.975e-05,9.1e-05,0.000176,0.0010035,0.0021495,0.00439,0.011522]
    UnionFileB=[3.5e-06,3.75e-06,7.25e-06,7.75e-06,1.05e-05,1.05e-05,1.25e-05,1.475e-05]
    
    plt.xlabel("Taille instance")
    plt.ylabel("Temps en s")
    plt.title('Complexite Union')
    plt.plot(x, UnionArbre,'*',linestyle='-',label='UnionArbre')
    plt.plot(x, UnionTab,'^',linestyle='-',label='UnionTab')
    plt.plot(x, UnionFileB,'+',linestyle='-',label='UnionFileB')
    plt.legend()  
    plt.show()
    
Union()

def Ajout():
    x = [100,200,500,1000,5000, 10000, 20000, 50000]
    
    AjoutArbre=[1.03e-06,1.144e-06,1.2116e-06,1.3928e-06,1.633e-06,1.68066e-06,1.74383e-06,1.84391e-06]
    AjoutTab =[1.14e-07,1.15e-07,9.4e-08,9.3e-08,9.52e-08,9.544e-08,9.413e-08,9.556e-08]
    AjoutFileB=[1.36e-06,1.372e-06,1.386e-06,1.3936e-06, 1.41132e-06,1.41726e-06,1.41238e-06, 1.41791e-06]
    
    plt.xlabel("Taille instance")
    plt.ylabel("Temps en s")
    plt.title('Complexite Ajout')
    plt.plot(x, AjoutArbre,'*',linestyle='-',label='AjoutArbre')
    plt.plot(x, AjoutTab,'^',linestyle='-',label='AjoutTab')
    plt.plot(x, AjoutFileB,'+',linestyle='-',label='AjoutFileB')
    plt.legend() 
    plt.show()
    
Ajout()

def SupprMin():
    x = [100,200,500,1000,5000, 10000, 20000, 50000]
    
    SupprMinArbre=[1.262e-06,1.429e-06,1.6588e-06,1.9092e-06,2.28224e-06,2.47398e-06,2.65117e-06,3.03377e-06]
    SupprMinTab =[2.56e-07,3.14e-07,3.464e-07,3.974e-07,5.14e-07,5.8694e-07,6.7029e-07,7.62296e-07]
    SupprMinFileB=[5.84e-07, 6.32e-07,6.568e-07,7.01e-07,8.5188e-07,7.9984e-07,8.0846e-07,8.25936e-07]

    plt.xlabel("Taille instance")
    plt.ylabel("Temps en s")
    plt.title('Complexite SupprMin')
    plt.plot(x, SupprMinArbre,'*',linestyle='-',label='SupprMinArbre')
    plt.plot(x, SupprMinTab,'^',linestyle='-',label='SupprMinTab')
    plt.plot(x, SupprMinFileB,'+',linestyle='-',label='SupprMinFileB')
    plt.legend() 
    plt.show()
    
SupprMin()
