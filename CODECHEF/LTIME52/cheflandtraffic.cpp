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

void floyd_warshalls(ll n){
  ll a[n+1][n+1],b[n+1][n+1];
  ll dist_a[n][n],dist_b[n][n];

  fr(i,1,n+1){
    fr(j,1,n+1){
      a[i][j]=INF;
      b[i][j]=INF;
    }
  }
  ll x,y,w;
  fr(i,0,n-1){
    cin>>x>>y>>w;
    a[x][y]=w;
    a[y][x]=w;
  }
  fr(i,0,n-1){
    cin>>x>>y>>w;
    b[x][y]=w;
    b[y][x]=w;
  }

  fr(i,1,n+1){
    fr(j,1,n+1){
      dist_a[i][j]=a[i][j];
      dist_b[i][j]=b[i][j];
    }
  }

  fr(k,1,n+1){
    fr(i,1,n+1){
      fr(j,1,n+1){
        dist_a[i][j]=min(dist_a[i][j],dist_a[i][k]+dist_a[k][j]);
        dist_b[i][j]=min(dist_b[i][j],dist_b[i][k]+dist_b[k][j]);
      }
    }
  }

  ll sum=0;
  fr(i,1,n+1){
    fr(j,i+1,n+1){
      sum+=min(dist_a[i][j],dist_b[i][j]);
    }
  }
  cout<<sum<<"\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;

    floyd_warshalls(n);
  }

  return 0;
}
