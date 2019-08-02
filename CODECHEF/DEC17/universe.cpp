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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c,d,e,f,g) min(a,min(b,min(c,min(d,min(e,min(f,g))))))

ll X,Y,Z,A,B,C;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>X>>Y>>Z>>A>>B>>C;

    ll cost[X+1][Y+1][Z+1];

    cost[0][0][0]=0;

    fr(p,1,X+1) cost[p][0][0]=A+cost[p-1][0][0];
    fr(q,1,Y+1) cost[0][q][0]=A+cost[0][q-1][0];
    fr(r,1,Z+1) cost[0][0][r]=A+cost[0][0][r-1];

    fr(p,1,X+1) fr(q,1,Y+1) cost[p][q][0]=min(B+cost[p-1][q-1][0],min(A+cost[p-1][q][0],A+cost[p][q-1][0]));
    fr(p,1,X+1) fr(r,1,Z+1) cost[p][0][r]=min(B+cost[p-1][0][r-1],min(A+cost[p-1][0][r],A+cost[p][0][r-1]));
    fr(q,1,Y+1) fr(r,1,Z+1) cost[0][q][r]=min(B+cost[0][q-1][r-1],min(A+cost[0][q-1][r],A+cost[0][q][r-1]));

    fr(p,1,X+1){
      fr(q,1,Y+1){
        fr(r,1,Z+1){
          cost[p][q][r]=MIN(A+cost[p-1][q][r],A+cost[p][q-1][r],A+cost[p][q][r-1],B+cost[p-1][q-1][r],B+cost[p][q-1][r-1],B+cost[p-1][q][r-1],C+cost[p-1][q-1][r-1]);
        }
      }
    }

    cout<<cost[X][Y][Z]<<"\n";
  }

  return 0;
}
