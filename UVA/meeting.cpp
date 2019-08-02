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

ll dist[100][100];

void sd(ll n){
  fr(k,0,n){
    fr(i,0,n){
      fr(j,0,n){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  ll x,y,d;
  ll sa,sb,sc;
  while(cin>>n){
    cin>>m;

    fr(i,0,n){
      fr(j,0,n){
        dist[i][j]=INF;
      }
    }

    fr(i,0,m){
      cin>>x>>y>>d;
      dist[x][y]=d;
      dist[y][x]=d;
    }

    ll speeds[3];
    fr(i,0,3) cin>>speeds[i];
    sort(speeds,speeds+3);

    sd(n);

    ll md=0;
    fr(i,0,n){
      fr(j,0,n){
        if(i!=j) md=max(md,dist[i][j]);
      }
    }

    cout<<ceil((float)md/(float)speeds[0]);

    cout<<"\n";
  }

  return 0;
}
