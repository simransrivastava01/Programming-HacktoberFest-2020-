// checking if a number is prime in O(nloglogn) using the Sieve of Eratosthenes algorithm

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin>>n;
  vector<char> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
      if (is_prime[i] && (long long)i * i <= n) {
          for (int j = i * i; j <= n; j += i)
              is_prime[j] = false;
      }
  }
  if(is_prime[n]) cout<<n<<" is Prime\n";
  else cout<<n<<" is not Prime\n";
}
