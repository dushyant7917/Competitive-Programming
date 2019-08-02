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
#define INF 2e9
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n,m;
char a[N][N],b[N][N],c[N][N];

ll cc(char c){
  if(c=='R') return 5;
  else return 3;
}

ll fn(){
  ll cost1=0,cost2=0;
  fr(i,0,n){
    fr(j,0,m){
      if(a[i][j]!=b[i][j]) cost1+=cc(a[i][j]);
      if(a[i][j]!=c[i][j]) cost2+=cc(a[i][j]);
    }
  }

  return min(cost1,cost2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  string row;
  while(t--){
    cin>>n>>m;

    fr(i,0,n){
      cin>>row;
      fr(j,0,m){
        a[i][j]=row[j];
      }
    }

    fr(i,0,n){
      fr(j,0,m){
        if(j%2==0 && i%2==0) b[i][j]='R',c[i][j]='G';
        if(j%2==0 && i%2==1) b[i][j]='G',c[i][j]='R';
        if(j%2==1 && i%2==0) b[i][j]='G',c[i][j]='R';
        if(j%2==1 && i%2==1) b[i][j]='R',c[i][j]='G';
      }
    }

    cout<<fn()<<"\n";
  }

  return 0;
}
