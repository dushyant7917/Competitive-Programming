#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
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

ll next_2_pow_n(ll n){
  if(n==0) return 0;
  else if(!(n&(n-1))) return n;
  else{
    ll cnt=0;
    while(n!=0){
      n>>=1;
      cnt++;
    }
    return (1<<cnt);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string n;
  ll num,d;
  while(cin>>n && n!="00e0"){
    num=(10*(n[0]-'0')+(n[1]-'0'))*pow(10,n[3]-'0');
    d=next_2_pow_n(num);
    if(d==num) cout<<1<<"\n";
    else{
      d=d/2;
      cout<<2*(num-d)+1<<"\n";
    }
  }

  return 0;
}
