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
#define TS(x) to_string(x)

struct SS{
  ll a,b,c;
};

vector<ll> F(ll n){
  vector<ll> v;

  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      if(n/i==i) v.PB(i);
      else{
        v.PB(i);
        v.PB(n/i);
      }
    }
  }

  return v;
}

bool check(ll x,ll y,ll z,ll v){
  if(1<=x && x<=y && y<=z && v%(x*y*z)==0) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll a,b,c,v,ans;
  while(t--){
    cin>>a>>b>>c;

    v=a*b*c;

    vector<ll> f1=F(a),f2=F(b),f3=F(c);

    sort(f1.begin(),f1.end());
    sort(f2.begin(),f2.end());
    sort(f3.begin(),f3.end());

    ans=0;
    set<string> s;

    ll x,y,z;

    fr(i,0,SZ(f1)){
      fr(j,0,SZ(f2)){
        fr(k,0,SZ(f3)){
          if(check(f1[i],f2[j],f3[k],v)){
            //cout<<TS(f1[i])<<"\n";
            s.insert(TS(f1[i])+TS(f2[j])+TS(f3[k]));
            //cout<<f1[i]<<" "<<f2[j]<<" "<<f3[k]<<"\n";
            ans++;
          }
          else if(check(f2[j],f3[k],f1[i],v)){
            s.insert(TS(f2[j])+TS(f3[k])+TS(f1[i]));
            //cout<<f2[j]<<" "<<f3[k]<<" "<<f1[i]<<"\n";
            ans++;
          }
          else if(check(f3[k],f1[i],f2[j],v)){
            s.insert(TS(f3[k])+TS(f1[i])+TS(f2[j]));
            //cout<<f3[k]<<" "<<f1[i]<<" "<<f2[j]<<"\n";
            ans++;
          }
          else {}
        }
      }
    }

    cout<<SZ(s)<<"\n";
  }

  return 0;
}
