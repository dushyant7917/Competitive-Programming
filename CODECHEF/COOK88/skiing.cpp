#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 1000000001
#define N 1009
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll visited[N][N];
ll n,m;
ll a[N][N];

void init(){
  fr(i,0,n) fr(j,0,m) visited[i][j]=0;
}

void move(ll r,ll c){
  if(r>=n || c>=m) return;
  if(r<0 || c<0) return;
  if(visited[r][c]==1) return;

  visited[r][c]=1;

  if(a[r-1][c]<=a[r][c]) move(r-1,c);
  if(a[r+1][c]<=a[r][c]) move(r+1,c);
  if(a[r][c-1]<=a[r][c]) move(r,c-1);
  if(a[r][c+1]<=a[r][c]) move(r,c+1);
}

ll fn(priority_queue<pair<ll,pair<ll,ll> > > pq){
  ll cnt=0;

  pair<ll,pair<ll,ll> > x;
  ll r,c;
  while(pq.empty()==false){
    x=pq.top();
    r=x.second.first;
    c=x.second.second;
    if(visited[r][c]==0){
      move(r,c);
      cnt++;
    }
    pq.pop();
  }

  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>n>>m;

    priority_queue<pair<ll,pair<ll,ll> > > pq;

    fr(i,0,n){
      fr(j,0,m){
        cin>>a[i][j];
        pq.push(MP(a[i][j],MP(i,j)));
      }
    }

    init();
    cout<<fn(pq)<<"\n";
  }

  return 0;
}
