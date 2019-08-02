#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin>>s;

  ll f[3]={0};

  fr(i,0,SZ(s)){
    if(s[i]=='a'){
      f[0]++;
      if(f[2] || f[1]){
        cout<<"NO";
        return 0;
      }
    }
    if(s[i]=='b'){
      f[1]++;
      if(f[2] || !f[0]){
        cout<<"NO";
        return 0;
      }
    }
    if(s[i]=='c'){
      f[2]++;
      if(!f[0] || !f[1]){
        cout<<"NO";
        return 0;
      }
    }
  }

  if(f[0] && f[1] && f[2] && (f[2]==f[0] || f[2]==f[1])) cout<<"YES";
  else cout<<"NO";

  return 0;
}
