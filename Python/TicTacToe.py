#Tic Tac Toe
import os
c=0
b=["1","2","3","4","5","6","7","8","9"]
def pattern():
	print(" ",b[0]," | ",b[1]," | ",b[2])
	print("-----------------")
	print(" ",b[3]," | ",b[4]," | ",b[5])
	print("-----------------")
	print(" ",b[6]," | ",b[7]," | ",b[8])
os.system("clear")
name1=input("enter name for player 1 : ")
name2=input("enter name for player 2 : ")
os.system("clear")
print("WELCOME")
print(name1," & ",name2)
while 1:
	os.system("clear")
	pattern()
	if c%2==0:
		print(name1,end=" ")
		pos=int(input("enter the position at which you want to place your mark : "))
		b[pos-1]="x"
		c+=1
	else:
		print(name2,end=" ")
		pos=int(input("enter the position at which you want to place your mark : "))
		b[pos-1]="o"
		c+=1
	if (b[0]=="x" and b[1]=="x" and b[2]=="x") or (b[0]=="x" and b[3]=="x" and b[6]=="x") or (b[0]=="x" and b[4]=="x" and b[8]=="x") or(b[4]=="x" and b[1]=="x" and b[7]=="x") or (b[6]=="x" and b[4]=="x" and b[2]=="x") or (b[8]=="x" and b[2]=="x" and b[5]=="x") or (b[3]=="x" and b[4]=="x" and b[5]=="x") or (b[6]=="x" and b[7]=="x" and b[8]=="x"):
		os.system("clear")
		pattern()
		print(name1," wins!!!")
		break
	elif (b[0]=="o" and b[1]=="o" and b[2]=="o") or (b[0]=="o" and b[3]=="o" and b[6]=="o") or (b[0]=="o" and b[4]=="o" and b[8]=="o") or(b[4]=="o" and b[1]=="o" and b[7]=="o") or (b[6]=="o" and b[4]=="o" and b[2]=="o") or (b[8]=="o" and b[2]=="o" and b[5]=="o") or (b[3]=="o" and b[4]=="o" and b[5]=="o") or (b[6]=="o" and b[7]=="o" and b[8]=="o"):
		os.system("clear")
		pattern()
		print(name2," wins!!!")
		break
	elif c==9:
		os.system("clear")
		pattern()
		print("it is a draw")
		break
	if input("press any key to continue..."):
		pass
