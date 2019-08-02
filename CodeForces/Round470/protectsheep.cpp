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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll r,c;

ll nr[]={-1,0,1,0};
ll nc[]={0,1,0,-1};

bool valid(ll x,ll y){
  if(0<=x && x<r && 0<=y && y<c) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>r>>c;
  char a[r][c];
  ll cnt_w=0;
  fr(i,0,r){
    fr(j,0,c){
      cin>>a[i][j];
      if(a[i][j]=='W') cnt_w++;
    }
  }

  if(cnt_w==0){
    cout<<"Yes\n";
    fr(i,0,r){
      fr(j,0,c){
        cout<<a[i][j];
      }
      cout<<"\n";
    }
  }
  else{
    bool flag=true;
    fr(i,0,r){
      fr(j,0,c){
        if(a[i][j]=='S'){
          fr(k,0,4){
            if(valid(i+nr[k],j+nc[k]) && a[i+nr[k]][j+nc[k]]=='W') flag=false;
            else if(valid(i+nr[k],j+nc[k]) && a[i+nr[k]][j+nc[k]]=='.') a[i+nr[k]][j+nc[k]]='D';
            else {}
          }
        }
      }
    }

    if(flag){
      cout<<"Yes\n";
      fr(i,0,r){
        fr(j,0,c){
          cout<<a[i][j];
        }
        cout<<"\n";
      }
    }
    else cout<<"No";
  }

  return 0;
}
