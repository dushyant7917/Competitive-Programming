#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define N 200005
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

  vector<ll> v[N];
  ll ind,ms;
  ms=ind=0;

  fr(i,0,SZ(s)){
    if(s[i]=='0'){
      ind++;
      v[ind].PB(i+1);
    }
    else{
      if(ind==0){
        cout<<-1;
        return 0;
      }
      else{
        v[ind].PB(i+1);
        ind--;
      }
    }
    ms=max(ms,ind);
  }

  if(ms!=ind){
    cout<<-1;
    return 0;
  }
  else{
    cout<<ms<<"\n";
    fr(i,1,ms+1){
      cout<<SZ(v[i])<<" ";
      fr(j,0,SZ(v[i])){
        cout<<v[i][j]<<" ";
      }
      cout<<"\n";
    }
  }

  return 0;
}
