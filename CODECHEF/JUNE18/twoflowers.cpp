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
#define N 2001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,a[N][N];
ll dx[]={0,0,-1,1};
ll dy[]={-1,1,0,0};
ll sz_old[N*N],sz_new[N*N];
ll cmp[N][N];
ll node=0;
ll par[N*N],rnk[N*N];

ll findSet(ll x){
  if(par[x]!=x) par[x]=findSet(par[x]);
  return par[x];
}

void mergeSet(ll x,ll y){
  ll xx=findSet(x);
  ll yy=findSet(y);

  if(rnk[xx]>rnk[yy]){
    par[yy]=xx;
    sz_new[xx]+=sz_new[yy];
  }
  else{
    par[xx]=yy;
    sz_new[yy]+=sz_new[xx];
  }

  if(rnk[xx]==rnk[yy]) rnk[yy]++;
}

bool valid(ll x,ll y){
  if(x<0 || x>=n || y<0 || y>=m) return false;
  else return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  fr(i,0,n) fr(j,0,m) cin>>a[i][j];

  fr(i,0,n) fr(j,0,m) cmp[i][j]=0;

  ll x,y,xx,yy;

  fr(i,0,n){
    fr(j,0,m){
      if(cmp[i][j]) continue;

      cmp[i][j]=++node;
      queue<pii> q;
      q.push(pii(i,j));
      sz_old[node]=0;

      while(SZ(q)){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        sz_old[node]++;

        fr(k,0,4){
          xx=x+dx[k];
          yy=y+dy[k];
          if(!valid(xx,yy) || a[xx][yy]!=a[x][y] || cmp[xx][yy]) continue;
          q.push(pii(xx,yy));
          cmp[xx][yy]=node;
        }
      }
    }
  }

  ll ans=0;

  fr(i,1,node+1){
    par[i]=i;
    rnk[i]=0;
    sz_new[i]=sz_old[i];
    ans=max(ans,sz_new[i]);
  }

  map<pii,vector<pii> > edge;
  map<pii,vector<pii> >::iterator itr1;
  vector<pii>::iterator itr2;

  fr(i,0,n){
    fr(j,0,m){
      fr(k,0,4){
        xx=i+dx[k];
        yy=j+dy[k];
        if(!valid(xx,yy) || a[xx][yy]<=a[i][j]) continue;
        edge[pii(a[i][j],a[xx][yy])].PB(pii(cmp[i][j],cmp[xx][yy]));
      }
    }
  }

  for(itr1=edge.begin();itr1!=edge.end();itr1++){
    vector<ll> restore;

    for(itr2=(*itr1).second.begin();itr2!=(*itr1).second.end();itr2++){
      x=(*itr2).first;
      y=(*itr2).second;

      restore.PB(x);
      restore.PB(y);
      xx=findSet(x);
      yy=findSet(y);
      if(xx==yy) continue;
      mergeSet(xx,yy);
      ans=MAX(ans,sz_new[xx],sz_new[yy]);
    }

    fr(i,0,SZ(restore)){
      sz_new[restore[i]]=sz_old[restore[i]];
      par[restore[i]]=restore[i];
    }
  }

  cout<<ans;

  return 0;
}
