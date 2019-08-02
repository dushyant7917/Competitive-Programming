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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

bool left(char c){
  if(c=='d' || c=='f') return true;
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  dbl ans;
  while(t--){
    cin>>n;

    ans=0;
    map<string,ll> mp;
    map<string,dbl> tm;

    fr(i,0,n){
      string s;
      cin>>s;
      if(mp[s]) ans+=tm[s]/2;
      else{
        bool prv=left(s[0]),cur;
        tm[s]=0.2;
        fr(i,1,SZ(s)){
          cur=left(s[i]);
          if(prv==cur) tm[s]+=0.4;
          else tm[s]+=0.2;
          prv=cur;
        }
        ans+=tm[s];
      }
      mp[s]++;
    }

    cout<<ans*10<<"\n";
  }

  return 0;
}
