#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef float dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
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

ll nx[8]={-1,-1,0,1,1,1,0,-1};
ll ny[8]={0,1,1,1,0,-1,-1,-1};

float area(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
  return abs((float)(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
}

bool check(ll px,ll py,ll cx,ll cy,ll x1,ll y1,ll x2,ll y2){
  float a1=area(px,py,cx,cy,x1,y1);
  float a2=area(px,py,cx,cy,x2,y2);
  float a3=area(px,py,x2,y2,x1,y1);
  float a=area(x2,y2,cx,cy,x1,y1);

  if(!a1 || !a2 || !a3 || !a) return false;

  return (a==a1+a2+a3);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t,tt;
  cin>>t;
  tt=t;

  ll n;
  ll sx,sy,cx,cy,px,py,np,p,q;
  while(t--){
    cin>>n;

    ll x[n],y[n];
    sx=sy=0;
    fr(i,0,n){
      cin>>x[i]>>y[i];
      sx+=x[i];
      sy+=y[i];
    }

    cx=sx/n;
    cy=sy/n;

    vector<pii> ans;

    if(n<20 && (tt>=1 && tt<=100)){
      np=0;
      ll a[3],b[3];
      a[0]=x[0];
      b[0]=y[0];

      bool flag=false;

      fr(i,1,n-1){
        a[1]=x[i];
        b[1]=y[i];
        a[2]=x[i+1];
        b[2]=y[i+1];

        map<pii,ll> visited;
        queue<pii> qu;

        fr(j,0,3){
          fr(k,0,8){
            p=a[j]+nx[k];
            q=b[j]+ny[k];
            if(visited[pii(p,q)]==0){
              visited[pii(p,q)]=1;
              if(check(p,q,a[0],b[0],a[1],b[1],a[2],b[2])){
                qu.push(pii(p,q));
                ans.PB(pii(p,q));
                np++;
                if(np==n/10){
                  flag=true;
                  break;
                }
              }
            }
          }
          if(flag) break;
        }
        if(flag) break;
      }
    }

    else{
      np=1;
      ans.PB(pii(cx,cy));

      fr(i,0,n){
      px=(cx+x[i%n]+x[(i+1)%n])/3;
      py=(cy+y[i%n]+y[(i+1)%n])/3;
        if(check(px,py,cx,cy,x[i%n],y[i%n],x[(i+1)%n],y[(i+1)%n])){
          ans.PB(pii(px,py));
          np++;
        }
      }
    }

    if(ans.size()>=n/10){
      fr(i,0,n/10) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    else cout<<-1<<"\n";
  }

  return 0;
}
