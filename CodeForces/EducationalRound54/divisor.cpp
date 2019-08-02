#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

bool prime_num(ll n){
  // corner cases
  if(n<=1)return false;
  if(n<=3)return true;

  // Below code is checked so that we can skip middle 5 numbers in the later while loop
  if(n%2==0 || n%3==0)return false;

  ll i=5;
  while(i*i<=n){
      if(n%i==0 || n%(i+2)==0)return false;
      i+=6;
  }

  return true;
}

ll F(ll n){
  //cout<<"n:"<<n<<"\n";
  if(n==0) return 0;
  if(n%2==0) return n/2;
  if(prime_num(n)) return 1;

  for(ll i=3;i<=sqrt(n);i+=2){
    if(n%i==0) return 1+F(n-i);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  cout<<F(n);

  //cout<<" "<<sqrt(n);

  return 0;
}
