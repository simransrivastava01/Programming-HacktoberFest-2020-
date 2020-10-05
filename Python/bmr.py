import re
import math
import string
print("------------------------------------WELCOME TO BMR CALCULATOR------------------------------------\n\n")

print("This program will help you to calculate your\nBMR(Basal Metabolic Rate) which will tell you \nminimum number of calories you required a day. \n\n")
print ("Enter Your Gender (Enter Male or Female)")
Gender = input()
Gender = str(Gender)
print ("Enter your Height(in Centimeters)")
height = input()
print ("Enter your Weight(in Kgs)")
weight = input()
print ("Enter your Age")
age = input()
if (Gender.upper() == "MALE"):
    num = 10* float(weight) + 6.25* float(height) \
        - 5 * float(age) + 5
elif (Gender.upper() == "FEMALE"):
    num = 10* float(weight) + 6.25* float(height) \
        - 5 * float(age) -161
num = int(round(num))
print("So you are required with ",num,"calories/a day")
print("------------------ Thank you for using BMR CALCULATOR and have a HAPPY diet :) --------------------")