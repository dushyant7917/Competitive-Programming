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
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin>>s;

  ll cnt=0;
  bool flag=false;

  fr(i,0,SZ(s)){
    if(s[i]=='2') flag=true;
    if(s[i]=='1') cnt++;
  }

  if(flag){
    flag=false;
    fr(i,0,SZ(s)){
      if(!flag && s[i]=='2'){
        flag=true;
        fr(j,0,cnt) cout<<1;
      }
      if(!flag && s[i]=='0') cout<<0;
      if(flag && s[i]!='1') cout<<s[i];
    }
  }
  else{
    fr(i,0,SZ(s)) if(s[i]=='0') cout<<0;
    fr(i,0,cnt) cout<<1;
  }

  return 0;
}
