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
  ll t;
  cin>>t;

  ll n;
  string start,x;
  while(t--){
    cin>>n>>start;
    vector<queue<char> > v;
    fr(i,0,n){
      cin>>x;
      queue<char> q;
      fr(j,0,SZ(x)) q.push(x[j]);
      v.PB(q);
    }

    bool flag=true,found;
    char cur=((start=="Dee")?'0':'1');
    while(flag){
      found=false;
      fr(i,0,n){
        if(SZ(v[i]) && v[i].front()==cur){
          found=true;
          v[i].pop();
          while(SZ(v[i]) && v[i].front()!=cur) v[i].pop();
          break;
        }
      }
      if(!found) flag=false;
      else cur=((cur=='0')?'1':'0');
    }
    cout<<((cur=='1')?"Dee":"Dum")<<"\n";
  }

  return 0;
}
