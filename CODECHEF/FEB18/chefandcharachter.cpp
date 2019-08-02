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

string s;

bool check(ll l,ll r){
  ll cc,hc,ec,fc;
  cc=hc=ec=fc=0;

  fr(i,l,r+1){
    if(s[i]=='c') cc++;
    else if(s[i]=='h') hc++;
    else if(s[i]=='e') ec++;
    else if(s[i]=='f') fc++;
    else {}
  }

  if(cc==1 && hc==1 && ec==1 && fc==1) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll cnt;
  while(t--){
    cin>>s;

    if(SZ(s)<4) cout<<"normal\n";
    else{
      cnt=0;
      fr(i,0,SZ(s)-4+1){
        if(check(i,i+3)) cnt++;
      }

      if(cnt) cout<<"lovely "<<cnt<<"\n";
      else cout<<"normal\n";
    }
  }

  return 0;
}
