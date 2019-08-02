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

void pp(ll n,ll a[5][51]){
  cout<<"PARKING\n";
  fr(i,1,5){
    fr(j,1,n+1){
      cout<<a[i][j]<<" ";
    }
    cout<<"\n";
  }
  cout<<"\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;

  ll a[5][51];
  fr(i,1,5) fr(j,1,n+1) cin>>a[i][j];

  vector<pair<ll,pair<ll,ll> > > moves;
  ll steps=0;

  while(k){
    fr(i,1,n+1){
      if(a[2][i]==0) continue;
      else if(a[1][i]==a[2][i]){
        moves.PB(MP(a[2][i],MP(1,i)));
        k--;
        a[2][i]=0;
      }
      else if(i<n && a[2][i+1]==0){
        moves.PB(MP(a[2][i],MP(2,i+1)));
        a[2][i+1]=a[2][i];
        a[2][i]=0;
      }
      else if(i==n && a[3][i]==0){
        moves.PB(MP(a[2][i],MP(3,i)));
        a[3][i]=a[2][i];
        a[2][i]=0;
      }
      else {}
    }

    rf(i,n,1){
      if(a[3][i]==0) continue;
      else if(a[4][i]==a[3][i]){
        moves.PB(MP(a[3][i],MP(4,i)));
        k--;
        a[3][i]=0;
      }
      else if(i>1 && a[3][i-1]==0){
        moves.PB(MP(a[3][i],MP(3,i-1)));
        a[3][i-1]=a[3][i];
        a[3][i]=0;
      }
      else if(i==1 && a[2][i]==0){
        moves.PB(MP(a[3][i],MP(2,i)));
        a[2][i]=a[3][i];
        a[3][i]=0;
      }
      else {}
    }

    steps++;
    if(steps>20000) break;
  }

  if(k>0 || SZ(moves)>20000) cout<<-1;
  else{
    ll c,x,y;
    cout<<SZ(moves)<<"\n";
    fr(i,0,SZ(moves)){
      c=moves[i].fi;
      x=moves[i].se.fi;
      y=moves[i].se.se;
      cout<<c<<" "<<x<<" "<<y<<"\n";
    }
  }

  return 0;
}
