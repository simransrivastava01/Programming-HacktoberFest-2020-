//C Program to print n odd numbers given by user from fibonacci numbers.

#include<stdio.h>

void main()
{
    int i,num=0,ans=0,val1=1,val2=0;
    printf("Enter total odd fibonacci numbers to be printed: \n");
    scanf("%d",&num);

    for(i=1;num!=0;i++)
    {
        // Cannot include 0 because it is an even number, therefore removing any possibility of printing 0 from the fibonacci sequence.
        if(i==1)
        {
            ans = i;
            printf("%d,",ans);
            num--;
        }
        if(i>1)
        {
            ans = val2 + val1;
            if(ans%2!=0)
            {
                printf("%d,",ans);
                num--;
            }
            val2 = val1;
            val1 = ans;
        }
    }
    printf("\n");
}