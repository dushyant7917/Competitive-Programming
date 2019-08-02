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

ll n,m;
bool visited[300][300];
ll area[300][300];

void area_initialize(){
  fr(i,0,n)
    fr(j,0,n){
      area[i][j]=0;
    }
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);


  cin>>n>>m;

  ll v[m][3];
  ll x,y,w;
  area_initialize();
  ll p,q;
  fr(i,0,m){
    cin>>x>>y>>w;
    v[i][0]=x;
    v[i][1]=y;
    v[i][2]=w;
    fr(i,0,n)
      fr(j,0,n){
        p=abs(i-x);
        q=abs(j-y);
        if(p>q){
          area[i][j]+=(w-p>0)?(w-p):0;
        }
        else{
          area[i][j]+=(w-q>0)?(w-q):0;
        }
      }
  }

  ll mi=0;
  fr(i,0,n){
    fr(j,0,n){
      mi=max(area[i][j],mi);
    }
  }

  cout<<mi;

  return 0;
}
