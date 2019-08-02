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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

struct Point{
  ll x,y;
};

bool onSegment(Point p,Point q,Point r){
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) return true;

  return false;
}

ll orientation(Point p, Point q, Point r){
  ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0;
  return (val > 0)? 1: 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
  ll o1 = orientation(p1, q1, p2);
  ll o2 = orientation(p1, q1, q2);
  ll o3 = orientation(p2, q2, p1);
  ll o4 = orientation(p2, q2, q1);

  if(o1 != o2 && o3 != o4)
      return true;

  if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  if (o4 == 0 && onSegment(p2, q1, q2)) return true;

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<Point> r1,r2;

  ll x,y;
  fr(i,0,4){
    cin>>x>>y;
    r1.PB({x,y});
  }
  fr(i,0,4){
    cin>>x>>y;
    r2.PB({x,y});
  }

  bool flag=false;

  fr(p,0,4){
    fr(q,0,4){
      if(p==q) continue;
      fr(r,0,4){
        fr(s,0,4){
          if(r==s) continue;
          if(doIntersect(r1[p],r1[q],r2[r],r2[s])) flag=true;
        }
      }
    }
  }

  if(flag) cout<<"YES";
  else cout<<"NO";

  return 0;
}
