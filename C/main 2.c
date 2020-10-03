/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int a, b, c, d, sum=0;
scanf("%d %d",&a,&b);

for(;a<=b;a++,sum=0)
{

       for(c=1;c<a;c++)
        {
            if(a%c==0)
            {
                sum=sum+c;
                
            }
        
        }        
            if(sum==a)
            {
                printf("perfect no. is = %d\n ",sum);
            }
            
}        

    return 0;
}
