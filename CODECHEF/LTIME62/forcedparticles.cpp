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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,cnt;
char a[N][N];

void moveLeft(){
  fr(i,0,n){
    cnt=0;
    fr(j,0,m){
      if(a[i][j]=='1') cnt++;
    }
    fr(j,0,cnt) a[i][j]='1';
    fr(j,cnt,m) a[i][j]='0';
  }
}

void moveRight(){
  fr(i,0,n){
    cnt=0;
    fr(j,0,m){
      if(a[i][j]=='1') cnt++;
    }
    fr(j,0,m-cnt) a[i][j]='0';
    fr(j,m-cnt,m) a[i][j]='1';
  }
}

void moveUp(){
  fr(j,0,m){
    cnt=0;
    fr(i,0,n){
      if(a[i][j]=='1') cnt++;
    }
    fr(i,0,cnt) a[i][j]='1';
    fr(i,cnt,n) a[i][j]='0';
  }
}

void moveDown(){
  fr(j,0,m){
    cnt=0;
    fr(i,0,n){
      if(a[i][j]=='1') cnt++;
    }
    fr(i,0,n-cnt) a[i][j]='0';
    fr(i,n-cnt,n) a[i][j]='1';
  }
}

void display(){
  fr(i,0,n){
    fr(j,0,m){
      cout<<a[i][j];
    }
    cout<<"\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  char dh,dv;

  while(t--){
    cin>>n>>m;

    string s;

    fr(i,0,n){
      cin>>s;
      fr(j,0,m) a[i][j]=s[j];
    }

    cin>>s;

    if(s[0]=='L') moveLeft();
    else if(s[0]=='R') moveRight();
    else if(s[0]=='U') moveUp();
    else moveDown();

    dh=dv='#';

    fr(i,0,SZ(s)){
      if(s[i]=='L') dh='L';
      else if(s[i]=='R') dh='R';
      else if(s[i]=='U') dv='U';
      else dv='D';
    }

    if(dh=='L') moveLeft();
    if(dh=='R') moveRight();
    if(dv=='U') moveUp();
    if(dv=='D') moveDown();

    display();
  }

  return 0;
}
