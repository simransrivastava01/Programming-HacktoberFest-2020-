#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void polynomial(int *a, int *b, int*c, int start, int end)
{
    if(start == end)
    {
        c[2*start] += a[start]*b[start];
        return;
    }
    int i, j, mid = (start + end)/2;
    polynomial(a, b, c, start, mid);
    polynomial(a, b, c, mid+1, end);
    for(i=start; i<=mid; i++)
    {
        for(j=mid+1; j<=end; j++)
        {
            c[i + j] += a[i]*b[j];
            c[i + j] += a[j]*b[i];
        }
    }

}

int main()
{
    int n, i;
    printf("Enter the degree of polynomials: ");
    scanf("%d", &n);
    int a[n+1], b[n+1];
    int *c = (int *)calloc(2*n+1, sizeof(int));
    for(i=0; i<=n; i++)
    {
        printf("Enter the coefficient of x^%d of polynomial 1: ", i);
        scanf("%d", &a[i]);
    }
    for(i=0; i<=n; i++)
    {
        printf("Enter the coefficient of x^%d of polynomial 2: ", i);
        scanf("%d", &b[i]);
    }

    polynomial(&a, &b, c, 0, n);

    printf("\nRESULT: ");
    for(i=0; i<2*n+1; i++)
    {
    	if(i==2*n)
    		printf("%d.x^%d\n", *(c+i), i);
    	else
    		printf("%d.x^%d  +  ", *(c+i), i);
    }

    return 0;
}
