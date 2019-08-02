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
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll q;
  cin>>q;

  char t;
  ll l=0,r=0,id,pos[N];

  fr(i,0,q){
    cin>>t>>id;

    if(!i){
      pos[id]=0;
      l--;
      r++;
    }

    else{
      if(t=='L') pos[id]=l--;
      else if(t=='R') pos[id]=r++;
      else cout<<min(abs(pos[id]-l),abs(pos[id]-r))-1<<"\n";
    }
  }

  return 0;
}
