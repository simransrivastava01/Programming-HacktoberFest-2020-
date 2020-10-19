#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void printpa(int *s,int i,int j,char &name)
{
    if(i==j)
        {cout << name++;
        return;
        }

        cout<<"(";
        printpa(s,i,*((s+i*7)+j),name);
        printpa(s,*((s+i*7)+j) + 1,j,name);
        cout<<")";

}


int matOrder(int array[], int n) {
   int minMul[n][n];
   int s[n][n];

   for (int i=1; i<n; i++)
      minMul[i][i] = 0;

   for (int length=2; length<n; length++) {
      for (int i=1; i<n-length+1; i++) {
         int j = i+length-1;
         minMul[i][j] = INT_MAX;
         for (int k=i; k<=j-1; k++) {

            int q = minMul[i][k] + minMul[k+1][j] + array[i- 1]*array[k]*array[j];
            if (q < minMul[i][j])
               {minMul[i][j] = q;
               s[i][j]=k;}

         }
      }
   }

   for(int i=1;i<n;i++){
    for(int j=1;j<n;j++)

    {
        if(i>j)
        cout<<0<<"\t";
        else
        cout<<minMul[i][j]<<"\t";
    }
     cout<<endl;
   }
   cout<<endl;

  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++)

    {
        if(i>=j)
        cout<<0<<"\t";
        else
        cout<<s[i][j]<<"\t";
    }
     cout<<endl;
   }
   cout<<endl;
       char name = 'A';
   cout << "Parenthesization: ";
   printpa((int *)s, 1, n-1,name);
   cout<<endl;
   cout<<endl;
   cout << "Minimum number of matrix multiplications: " << minMul[1][n-1]<<endl;
   cout<<endl;
}


int main() {
   int arr[] = {30,35,15,5,10,20,25};
   int size = 7;
   clock_t s,e;
float time;
s=clock();
matOrder(arr, size);
e=clock();
time=float(e-s)/float(CLOCKS_PER_SEC);
cout<<"Time: "<<time<<endl;

}
