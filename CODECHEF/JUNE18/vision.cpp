// reference -> http://paulbourke.net/geometry/circlesphere/index.html#linesphere
// reference -> http://paulbourke.net/geometry/circlesphere/raysphere.c

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
#define INF 10e16
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

struct Point{
  dbl x,y,z;
};

dbl intersection(Point p1,Point p2,Point p3,dbl r){
  double a,b,c,D;

  a=(p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y) + (p2.z-p1.z)*(p2.z-p1.z);
  b=2*((p2.x-p1.x)*(p1.x-p3.x) + (p2.y-p1.y)*(p1.y-p3.y) + (p2.z-p1.z)*(p1.z-p3.z));
  c=p3.x*p3.x + p3.y*p3.y + p3.z*p3.z + p1.x*p1.x + p1.y*p1.y + p1.z*p1.z;
  c-=2*(p3.x*p1.x + p3.y* p1.y + p3.z* p1.z) + r*r;

  D=b*b - 4*a*c;

  return D;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  Point P,Q,R;
  dbl qx,qy,qz,dx,dy,dz,r,ans;
  dbl low,high,mid,val;

  while(t--){
    cin>>P.x>>P.y>>P.z>>qx>>qy>>qz>>dx>>dy>>dz>>R.x>>R.y>>R.z>>r;

    low=0.0;
    high=(dbl)pow(10,9);

    fr(i,0,1005){
      mid=(low+high)*0.5;
      Q.x=qx+dx*mid;
      Q.y=qy+dy*mid;
      Q.z=qz+dz*mid;

      val=intersection(P,Q,R,r);
      ans=mid;
      if(val==0.0) break;
      else if(val>0.0) low=mid;
      else high=mid;
    }

    cout<<fixed<<setprecision(10)<<ans<<"\n";
  }

  return 0;
}
