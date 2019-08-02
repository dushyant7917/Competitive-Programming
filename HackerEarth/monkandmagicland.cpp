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

ll gcd[51][51];

ll hcf(ll a,ll b){
  if(!a || !b){
    gcd[a][b]=0;
    return gcd[a][b];
  }

  if(a==b){
    gcd[a][b]=a;
    return gcd[a][b];
  }

  if(a>b){
    if(gcd[a][b]==-1){
      gcd[a][b]=hcf(a-b,b);
      return gcd[a][b];
    }
    else{
      return gcd[a][b];
    }
  }
  else{
    if(gcd[a][b]==-1){
      gcd[a][b]=hcf(a,b-a);
      return gcd[a][b];
    }
    else return gcd[a][b];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fr(i,0,51) fr(j,0,51) {
    gcd[i][j]=-1;
  }
  fr(i,0,51) fr(j,0,51) {
    if(i<j) gcd[i][j]=hcf(i,j);
    else if(i==j) gcd[i][j]=i;
    else gcd[i][j]=gcd[j][i];
  }

  ll t;
  cin>>t;

  ll n,m,k;
  while(t--){
    cin>>n>>m>>k;

    ll x[n],c[m],z[m];
    fr(i,0,n) cin>>x[i];
    fr(i,0,m) cin>>c[i];
    fr(i,0,m) cin>>z[i];

    vector<ll> chests(n);
    ll one=1;

    fr(i,0,n){
      fr(j,0,m){
        if(gcd[i][j]!=1){
          chests[i]|=one<<j;
          cout<<chests[i]<<" ";
        }
      }
    }

    cout<<"\n";
  }

  return 0;
}
