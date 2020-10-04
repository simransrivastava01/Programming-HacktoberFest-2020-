# -*- coding: utf-8 -*-
"""
Created on Sun Oct 03 21:55:22 2020

@author: Vivek0004
"""

epsilon = 0.01
y = int(input())
guess = y/2.0
numGuesses = 0

while abs(guess*guess - y) >= epsilon:
    numGuesses += 1
    guess = guess - (((guess**2) - y)/(2*guess))
print('numGuesses = ' + str(numGuesses))
print('Square root of ' + str(y) + ' is about ' + str(guess))
