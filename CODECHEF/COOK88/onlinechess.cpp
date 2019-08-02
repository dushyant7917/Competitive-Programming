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

struct Player{
  ll id;
  ll r;
  ll lr;
  ll mr;
  ll tm;
  string rated;
  string col;
};

bool match(struct Player p1,struct Player p2){
  if(p1.tm!=p2.tm) return false;
  if(p1.rated!=p2.rated) return false;
  if(p1.r<p2.lr || p1.r>p2.mr || p2.r<p1.lr || p2.r>p1.mr) return false;
  if(p1.col=="random" && p1.col!=p2.col) return false;
  if(p2.col=="random" && p2.col!=p1.col) return false;
  if(p1.col=="white" && p2.col!="black") return false;
  if(p1.col=="black" && p2.col!="white") return false;
  if(p2.col=="white" && p1.col!="black") return false;
  if(p2.col=="black" && p1.col!="white") return false;

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;

    deque<struct Player> q;
    stack<struct Player> st;

    struct Player p[n];

    fr(i,0,n){
      cin>>p[i].r>>p[i].lr>>p[i].mr>>p[i].tm>>p[i].rated>>p[i].col;
      p[i].id=i+1;

      if(q.empty()){
        cout<<"wait\n";
        q.push_back(p[i]);
      }
      else{
        struct Player x;
        bool flag=true;
        while(flag && q.size()>0){
          x=q.front();
          if(match(p[i],x)){
            cout<<x.id<<"\n";
            q.pop_front();
            flag=false;
            break;
          }
          else{
            st.push(x);
            q.pop_front();
          }
        }
        while(st.size()>0){
          x=st.top();
          q.push_front(x);
          st.pop();
        }
        if(flag){
          cout<<"wait\n";
          q.push_back(p[i]);
        }
      }
    }
  }

  return 0;
}
