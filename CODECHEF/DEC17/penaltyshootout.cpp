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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll score_a,score_b,shots_a,shots_b,total_shots,rounds;
  string s,winner;
  bool flag;
  while(cin>>s){
    flag=false;

    vector<ll> a,b;
    fr(i,0,20){
      if(i%2==0) a.PB(s[i]-'0');
      else b.PB(s[i]-'0');
    }

    score_a=score_b=0;
    shots_a=shots_b=0;
    rounds=0;

    fr(i,0,10){
      score_a+=a[i];
      shots_a++;

      if(rounds<5){
        if(score_a-score_b>5-shots_b){
          winner="TEAM-A ";
          total_shots=shots_a+shots_b;
          flag=true;
          break;
        }
        if(score_b-score_a>5-shots_a){
          winner="TEAM-B ";
          total_shots=shots_a+shots_b;
          flag=true;
          break;
        }
      }

      score_b+=b[i];
      shots_b++;

      rounds++;

      if(rounds<5){
        if(score_a-score_b>5-shots_b){
          winner="TEAM-A ";
          total_shots=shots_a+shots_b;
          flag=true;
          break;
        }
        if(score_b-score_a>5-shots_a){
          winner="TEAM-B ";
          total_shots=shots_a+shots_b;
          flag=true;
          break;
        }
      }
      else{
        if(score_b>score_a){
          winner="TEAM-B ";
          total_shots=shots_a+shots_b;
          flag=true;
          break;
        }
        if(score_a>score_b){
          winner="TEAM-A ";
          total_shots=shots_a+shots_b;
          flag=true;
          break;
        }
      }
    }

    if(flag){
      cout<<winner<<total_shots<<"\n";
    }
    else{
      cout<<"TIE\n";
    }
  }

  return 0;
}
