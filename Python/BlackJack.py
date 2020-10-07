import random
suits=['diamond','heart','club','spade']
rank=['ace','two','three','four','five','six','seven','eight','nine','ten','king','queen','jack']
values={'two':2,'three':3,'four':4,'five':5,'six':6,'seven':7,'eight':8,'nine':9,'ten':10,'king':10,'queen':10,'jack':10}
l=[]
class cards():
    def c_list(p=1):
        for x in suits:
            for y in rank:
                l.append(y+' of '+x)
                
class deck():
    def shuffle(p=1):
        random.shuffle(l)
    def deal(p=1):
        return l.pop()

def player():
    d=deck()
    card1_of_player=d.deal()
    card2_of_player=d.deal()
    
    print('1 card of player:{}'.format(card1_of_player))
    print('2 card of player:{}'.format(card2_of_player))
    if card1_of_player.split()[0]=='ace':  
        ask=int(input("want ace as 1 or 13:"))
        sum_of_player=ask+values[card2_of_player.split()[0]]
    elif card2_of_player.split()[0]=='ace':
        ask=int(input("want ace as 1 or 13:"))
        sum_of_player=ask+values[card1_of_player.split()[0]]
    elif card1_of_player.split()[0]=='ace' and card2_of_player.split()[0]=='ace':
        ask=int(input("want ace as 1 or 13:"))
        ask1=int(input("want ace as 1 or 13:"))
        sum_of_player=ask+ask1
        
    else:    
        sum_of_player=values[card1_of_player.split()[0]]+values[card2_of_player.split()[0]]
    return sum_of_player   

card2_of_dealer=0    
def dealer():
    global card2_of_dealer
    d=deck()
    card1_of_dealer=d.deal()
    card2_of_dealer=d.deal()
    print('1 card of dealer:{}'.format(card1_of_dealer))
    print('2 card of dealer:<hidden>')
    if card1_of_dealer.split()[0]=='ace':
        if card2_of_dealer.split()[0]<'nine':
            ask=13
        else :
            ask=1
        sum_of_dealer=ask+  values[card2_of_dealer.split()[0]]
    elif card2_of_dealer.split()[0]=='ace':
        if card1_of_dealer.split()[0]<'nine':
            ask=13
            sum_of_dealer=ask+  values[card1_of_dealer.split()[0]]
        else:
            ask=1
            sum_of_dealer=ask+  values[card1_of_dealer.split()[0]]
    elif card2_of_dealer.split()[0]=='ace' and card1_of_dealer.split()[0]=='ace':    
        sum_of_dealer=14
    else:        
        sum_of_dealer=values[card1_of_dealer.split()[0]]+values[card2_of_dealer.split()[0]]
    return sum_of_dealer

def isbust_player(sum_of_player):
    if sum_of_player>21:
        return 1 
    if sum_of_player==21:
        return -1
    return 0    
 
def isbust_dealer(sum_of_dealer):
    if sum_of_dealer>21:
        return 1
    if sum_of_dealer==21:
        return -1
    return 0    

def main():
    print('Welcome to black jack')
    
    while True:
        c=cards()
        c.c_list()
        d=deck()
        d.shuffle()
        sum_of_player=player()
        sum_of_dealer=dealer()
        if sum_of_player==21:
            print("player is blackjack")
        else:    
            while True:
                flag=isbust_player(sum_of_player)
                print('sum of player cards:{}'.format(sum_of_player))
                if flag==1:
                    print("player busts COMPUTER WON")
                    break
                    
                elif flag==-1:
                    print("PLAYER WON(as sum is 21)")
                    break
                
                player_input=input('hit or stand:')
                if player_input.lower()=='hit':
                    card=d.deal()
                    print("player's next card:{}".format(card))
                    if card.split()[0]=='ace':
                        ask=int(input("want ace as 1 or 13:{}"))
                        sum_of_player+=ask
                    else:    
                        sum_of_player+=values[card.split()[0]]
                else:
                    break
                
            
            if flag==0:
                print("2 card of dealer:{}".format(card2_of_dealer))  
                while True:
                    flag=isbust_dealer(sum_of_dealer) 
                    if flag==1:
                        print('computer busts PLAYER WON')
                        break
                    elif flag==-1:
                        print("COMPUTER WON(as sum is 21)")
                        break
                    if sum_of_dealer<17:
                        card=d.deal()
                        print("dealer's next card:{}".format(card))
                        if card.split()[0]=='ace':
                            if sum_of_dealer<9:
                                ask=13
                            else:
                                ask=1
                            sum_of_dealer+=ask    
                        else:
                            sum_of_dealer+=values[card.split()[0]]
                    
                    else:
                        if sum_of_player>sum_of_dealer:
                            print("PLAYER WON(sum of player is larger so computer lost)")
                        elif sum_of_player<sum_of_dealer:
                            print('COMPUTER WON(sum of computer is larger so player lost)')
                        elif sum_of_player==sum_of_dealer:
                            print("TIE")
                        break    
        user=input('do u want to play again? y or n:' )
        if user.lower()=='n':
            break
        else:
            print('\nWelcome to blackjack')
main()        
        
        
        

