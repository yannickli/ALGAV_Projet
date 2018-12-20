#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Dec 19 21:59:05 2018

@author: yannickli
"""
import matplotlib.pyplot as plt

def ConsIter():
    x = [100,200,500,1000,5000, 10000, 20000, 50000]
    
    ConsIterArbre = [0.0005346,0.0010368,0.00232,0.004548,0.024442,0.0476214,0.0921938,0.218753]
    ConsIterTab = [0.0003962,0.000684,0.0016686,0.0033824,0.0169422,0.034126,0.0674012,0.16818]
    ConsIterFileB = [0.0005526,0.0010328,0.0024862,0.0050138,0.0255936,0.0514422,0.099343,0.248033]

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
    
    UnionArbre=[0.00115,0.002304,0.006752,0.01449,0.083047,0.16265,0.339502,0.837344]
    UnionTab =[0.000109,0.000191,0.000527,0.000981,0.005091,0.010187,0.020238,0.052199]
    UnionFileB=[1.4e-05,1.1e-05,2.2e-05,3.1e-05,3.2e-05,3.2e-05,3.5e-05,4.5e-05]
    
    plt.xlabel("Taille instance")
    plt.ylabel("Temps en s")
    plt.title('Complexite Union')
    plt.plot(x, UnionArbre,'*',linestyle='-',label='UnionArbre')
    plt.plot(x, UnionTab,'^',linestyle='-',label='UnionTab')
    plt.plot(x, UnionFileB,'+',linestyle='-',label='UnionFileB')
    plt.show()
    
Union()

def Ajout():
    x = [100,200,500,1000,5000, 10000, 20000, 50000]
    
    AjoutArbre=[9.96e-07,2.047e-06,3.1602e-06,4.4524e-06,5.969e-06,7.52022e-06,9.16754e-06,1.07855e-05]
    AjoutTab =[1.26e-07,2.31e-07,3.214e-07,4.084e-07,5.0056e-07,5.942e-07,6.8749e-07,7.7819e-07]
    AjoutFileB=[1.766e-06,3.866e-06,5.6628e-06,7.456e-06,9.32228e-06,1.12071e-05,1.30595e-05,1.49158e-05]
    
    plt.xlabel("Taille instance")
    plt.ylabel("Temps en s")
    plt.title('Complexite Ajout')
    plt.plot(x, AjoutArbre,'*',linestyle='-',label='AjoutArbre')
    plt.plot(x, AjoutTab,'^',linestyle='-',label='AjoutTab')
    plt.plot(x, AjoutFileB,'+',linestyle='-',label='AjoutFileB')
    plt.show()
    
Ajout()

def SupprMin():
    x = [100,200,500,1000,5000, 10000, 20000, 50000]

    SupprMinArbre=[1.374e-06,2.899e-06,4.619e-06,6.6324e-06,9.08896e-06,1.17286e-05,1.45412e-05,1.75438e-05]
    SupprMinTab =[2.72e-07,5.83e-07,9.474e-07,1.3612e-06,1.8772e-06,2.46286e-06,3.10699e-06,3.82734e-06]
    SupprMinFileB=[7.6e-07,1.521e-06,2.2946e-06,3.0804e-06,3.90628e-06,4.79012e-06,5.67021e-06,6.56881e-06]
    
    plt.xlabel("Taille instance")
    plt.ylabel("Temps en s")
    plt.title('Complexite SupprMin')
    plt.plot(x, SupprMinArbre,'*',linestyle='-',label='SupprMinArbre')
    plt.plot(x, SupprMinTab,'^',linestyle='-',label='SupprMinTab')
    plt.plot(x, SupprMinFileB,'+',linestyle='-',label='SupprMinFileB')
    plt.show()
    
SupprMin()
