/* https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1/?track=ppc-arrays&batchId=221*/

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define f(i, a, n) for(int i = a; i < n; i++)
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mod 1000000007
int gcd(int a, int b) { if (!b) return a; return gcd(b, a % b); }  
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
using namespace std;

int removeDuplicates(int a[],int n){

    int cmp = a[0];
    int i = 1;
    for(int k = 1; k < n ; k++){
        if(cmp != a[k]){
            a[i] = a[k];
            cmp = a[i];
            i++;
        }
    }
    return i;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int t;cin >>t;
  while(t--){
      int n;cin >>n;
      int a[n];
      for(int i=0;i<n;i++)
        cin >> a[i];

        int ns = removeDuplicates(a,n);

        for(int i=0;i<ns;i++){
            cout << a[i] << " ";
        }
        cout << endl;
  }
}

