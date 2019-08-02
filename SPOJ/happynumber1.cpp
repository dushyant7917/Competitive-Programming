#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll fn(ll n){
  ll sum=0;
  while(n>0){
    sum+=(n%10)*(n%10);
    n/=10;
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  if(n==1){
    cout<<0;
    return 0;
  }

  bool flag=true;
  map<ll,ll> mp;
  ll cnt=0;
  ll m;
  while(flag){
    m=fn(n);
    cnt++;
    if(m==1){
      cout<<cnt;
      break;
    }
    mp[n]++;
    if(mp[n]>1){
      cout<<-1;
      break;
    }
    n=m;
  }

  return 0;
}
