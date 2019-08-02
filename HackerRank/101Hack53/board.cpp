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
#define N 105
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))
#define fi first
#define se second
typedef pair<ll,pair<ll,ll> > pp;

ll A;
ll n,m,x,y;
ll b[N][N];

bool check(ll i,ll j){
  if(1<=i && i<=n && 1<=j && j<=m && b[i][j]) return true;
  else return false;
}

struct ANS{
  ll x1,y1,x2,y2;
};

vector<ANS> ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>x>>y;

  A=n*m-(x+y);

  fr(i,0,n+2) fr(j,0,m+2) b[i][j]=0;
  fr(i,1,n+1) fr(j,1,m+1) b[i][j]=1;

  fr(j,1,x+1) b[1][j]=0;
  rf(j,m,m-y+1) b[n][j]=0;

  ll black=0,white=0;
  fr(i,1,n+1){
    fr(j,1,m+1){
      if(b[i][j]){
        if((i+j)%2==0) black++;
        else white++;
      }
    }
  }

  ll r,c,ind;
  /* TOP
  // ind - 0 (move right then down)
  // ind - 1 (move left then down)
  */

  /* BOTTOM
  // ind - 0 (move left then top)
  // ind - 1 (move right then top)
  */

  ll cnt=0;

  if(x<m){
    ind=0;
    r=1;
    c=x+1;
    while((ind==0 && c<=m && cnt<A/2) || (ind==1 && c>=1 && cnt<A/2)){
      b[r][c]=0;
      if(ind==0){
        if(check(r,c+1)){
          b[r][c+1]=0;
          ans.PB({r,c,r,c+1});
          cnt++;
          if(c+1==m) break;
          else{
            c=c+2;
          }
        }
        else if(check(r+1,c)){
          b[r+1][c]=0;
          ans.PB({r,c,r+1,c});
          cnt++;
          ind=1;
          r=r+1;
          c=c-1;
        }
        else{
          break;
        }
      }
      else{
        if(check(r,c-1)){
          b[r][c-1]=0;
          ans.PB({r,c,r,c-1});
          cnt++;
          if(c-1==1) break;
          else{
            c=c-2;
          }
        }
        else if(check(r+1,c)){
          b[r+1][c]=0;
          ans.PB({r,c,r+1,c});
          cnt++;
          ind=0;
          r=r+1;
          c=c+1;
        }
        else{
          break;
        }
      }
    }
  }
  else{
    ind=0;
    r=2;
    c=1;
    while((ind==0 && c<=m && cnt<A/2) || (ind==1 && c>=1 && cnt<A/2)){
      b[r][c]=0;
      if(ind==0){
        if(check(r,c+1)){
          b[r][c+1]=0;
          ans.PB({r,c,r,c+1});
          cnt++;
          if(c+1==m) break;
          else{
            c=c+2;
          }
        }
        else if(check(r+1,c)){
          b[r+1][c]=0;
          ans.PB({r,c,r+1,c});
          cnt++;
          ind=1;
          r=r+1;
          c=c-1;
        }
        else{
          break;
        }
      }
      else{
        if(check(r,c-1)){
          b[r][c-1]=0;
          ans.PB({r,c,r,c-1});
          cnt++;
          if(c-1==1) break;
          else{
            c=c-2;
          }
        }
        else if(check(r+1,c)){
          b[r+1][c]=0;
          ans.PB({r,c,r+1,c});
          cnt++;
          ind=0;
          r=r+1;
          c=c+1;
        }
        else{
          break;
        }
      }
    }
  }

  if(y<m){
    ind=0;
    r=n;
    c=m-y;
    while((ind==0 && c>=1 && cnt<A/2) || (ind==1 && c<=m && cnt<A/2)){
      b[r][c]=0;
      if(ind==0){
        if(check(r,c-1)){
          b[r][c-1]=0;
          ans.PB({r,c,r,c-1});
          cnt++;
          if(c-1==1) break;
          else{
            c=c-2;
          }
        }
        else if(check(r-1,c)){
          b[r-1][c]=0;
          ans.PB({r,c,r-1,c});
          cnt++;
          ind=1;
          r=r-1;
          c=c+1;
        }
        else{
          break;
        }
      }
      else{
        if(check(r,c+1)){
          b[r][c+1]=0;
          ans.PB({r,c,r,c+1});
          cnt++;
          if(c+1==m) break;
          else{
            c=c+2;
          }
        }
        else if(check(r-1,c)){
          b[r-1][c]=0;
          ans.PB({r,c,r-1,c});
          cnt++;
          ind=0;
          r=r-1;
          c=c-1;
        }
        else{
          break;
        }
      }
    }
  }
  else{
    ind=0;
    r=n-1;
    c=m;
    while((ind==0 && c>=1 && cnt<A/2) || (ind==1 && c<=m && cnt<A/2)){
      b[r][c]=0;
      if(ind==0){
        if(check(r,c-1)){
          b[r][c-1]=0;
          ans.PB({r,c,r,c-1});
          cnt++;
          if(c-1==1) break;
          else{
            c=c-2;
          }
        }
        else if(check(r-1,c)){
          b[r-1][c]=0;
          ans.PB({r,c,r-1,c});
          cnt++;
          ind=1;
          r=r-1;
          c=c+1;
        }
        else{
          break;
        }
      }
      else{
        if(check(r,c+1)){
          b[r][c+1]=0;
          ans.PB({r,c,r,c+1});
          cnt++;
          if(c+1==m) break;
          else{
            c=c+2;
          }
        }
        else if(check(r-1,c)){
          b[r-1][c]=0;
          ans.PB({r,c,r-1,c});
          cnt++;
          ind=0;
          r=r-1;
          c=c-1;
        }
        else{
          break;
        }
      }
    }
  }

  if(white==black && A%2==0 && A/2==SZ(ans)){
    cout<<"YES\n"<<SZ(ans)<<"\n";
    fr(i,0,SZ(ans)){
      cout<<ans[i].x1<<" "<<ans[i].y1<<" "<<ans[i].x2<<" "<<ans[i].y2<<"\n";
    }
  }
  else cout<<"NO";

  return 0;
}
