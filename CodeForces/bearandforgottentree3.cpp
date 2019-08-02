#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,d,h;

void make_tree(){
  ll v,lev;

  if(d==h){
    v=1;
    while(v<h+1){
      cout<<v<<" "<<v+1<<"\n";
      v++;
    }
    if(v<n){
      v++;
      fr(i,v,n+1) cout<<2<<" "<<i<<"\n";
    }
  }

  else{
    v=1;
    while(v<h+1){
      cout<<v<<" "<<v+1<<"\n";
      v++;
    }
    v++;
    cout<<1<<" "<<v<<"\n";
    lev=1;
    while(lev<d-h){
      cout<<v<<" "<<v+1<<"\n";
      v++;
      lev++;
    }
    if(v<n){
      v++;
      fr(i,v,n+1) cout<<1<<" "<<i<<"\n";
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>d>>h;

  if(n==2) cout<<1<<" "<<2;
  else{
    if(d==1 || d>2*h) cout<<-1;
    else make_tree();
  }

  return 0;
}
