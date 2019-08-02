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
#define N 55
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
char a[N][N];

set<ll> rows,cols;

void process(ll r,ll c){
  rows.insert(r);
  cols.insert(c);
  a[r][c]='*';

  fr(i,0,n) if(a[i][c]=='#') process(i,c);
  fr(i,0,m) if(a[r][i]=='#') process(r,i);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  fr(i,0,n) fr(j,0,m) cin>>a[i][j];

  vector<pii> v;

  fr(i,0,n){
    fr(j,0,m){
      if(a[i][j]=='#'){
        process(i,j);

        set<ll>::iterator x,y;

        for(x=rows.begin();x!=rows.end();x++){
          for(y=cols.begin();y!=cols.end();y++){
            if(a[(*x)][(*y)]!='*'){
              cout<<"No";
              return 0;
            }
            //cout<<(*x)+1<<" "<<(*y)+1<<"\n";
          }
        }

        //cout<<"\n";
        rows.clear();
        cols.clear();
      }
    }
  }

  cout<<"Yes";

  return 0;
}
