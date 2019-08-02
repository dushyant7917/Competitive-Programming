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
#define N 100005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,mx,mn,gmx[4],from,to;
// n -> number of students
// m -> number of requests
// mx -> max number of students allowed in a group
// mn -> min number of students allowed in a group
// gmx[1] -> max student of grade 1 allowed in a group
// gmx[2] -> max student of grade 2 allowed in a group
// gmx[3] -> max student of grade 3 allowed in a group

map<string,ll> mp;
map<ll,ll> grade,group;
map<ll,string> name;
ll cnt[N][4];
set<ll> grp[N];
set<ll>::iterator itr;

bool check(ll ind1,ll ind2){
  ll gc[4]={0};

  for(itr=grp[ind2].begin();itr!=grp[ind2].end();itr++) gc[grade[*itr]]++;
  fr(i,1,4) if(cnt[ind1][i]+gc[i]>gmx[i]) return false;

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>mn>>mx>>gmx[1]>>gmx[2]>>gmx[3];

  string s,r;
  ll g,ind=0;

  fr(i,0,n){
    cin>>s>>g;
    mp[s]=++ind;
    name[ind]=s;
    grade[mp[s]]=g;
    group[mp[s]]=-1;
  }

  // processing requests
  g=0;
  fr(i,1,n+1) fr(j,1,4) cnt[i][j]=0;

  fr(i,0,m){
    cin>>s>>r;

    if(group[mp[s]]==group[mp[r]] && group[mp[s]]==-1){
      if(grade[mp[s]]==grade[mp[r]] && gmx[grade[mp[s]]]<2) continue;
      if(mx<2) continue;

      ++g;
      group[mp[s]]=group[mp[r]]=g;
      grp[g].insert(mp[s]);
      grp[g].insert(mp[r]);
      cnt[g][grade[mp[s]]]++;
      if(s!=r) cnt[g][grade[mp[r]]]++;
    }

    else if(group[mp[s]]==group[mp[r]] && group[mp[s]]!=-1) continue;

    else if(group[mp[s]]!=-1 && group[mp[r]]==-1){
      if(cnt[group[mp[s]]][grade[mp[r]]]==gmx[grade[mp[r]]]) continue;
      if(SZ(grp[group[mp[s]]])==mx) continue;

      grp[group[mp[s]]].insert(mp[r]);
      cnt[group[mp[s]]][grade[mp[r]]]++;
      group[mp[r]]=group[mp[s]];
    }

    else if(group[mp[s]]==-1 && group[mp[r]]!=-1){
      if(cnt[group[mp[r]]][grade[mp[s]]]==gmx[grade[mp[s]]]) continue;
      if(SZ(grp[group[mp[r]]])==mx) continue;
      grp[group[mp[r]]].insert(mp[s]);
      cnt[group[mp[r]]][grade[mp[s]]]++;
      group[mp[s]]=group[mp[r]];
    }

    else if(group[mp[s]]!=-1 && group[mp[r]]!=-1 && group[mp[s]]!=group[mp[r]]){
      bool flag=false;

      if(!flag && (SZ(grp[group[mp[r]]])+SZ(grp[group[mp[s]]]))<=mx && check(group[mp[r]],group[mp[s]])){
        from=group[mp[s]];
        to=group[mp[r]];
        for(itr=grp[from].begin();itr!=grp[from].end();itr++){
          grp[to].insert(*itr);
          group[*itr]=to;
          cnt[to][grade[*itr]]++;
        }
        grp[from].clear();
        flag=true;
        //cout<<name[mp[s]]<<"'s group merged into "<<name[mp[r]]<<"'s group\n";
      }

      if(!flag && (SZ(grp[group[mp[r]]])+SZ(grp[group[mp[s]]]))<=mx && check(group[mp[s]],group[mp[r]])){
        from=group[mp[r]];
        to=group[mp[s]];
        for(itr=grp[from].begin();itr!=grp[from].end();itr++){
          grp[to].insert(*itr);
          group[*itr]=to;
          cnt[to][grade[*itr]]++;
        }
        grp[from].clear();
        flag=true;
        //cout<<name[mp[r]]<<"'s group merged into "<<name[mp[s]]<<"'s group\n";
      }
    }

    else {}

    /*
    fr(i,1,g+1){
      cout<<"grp:"<<i<<"\n";
      for(itr=grp[i].begin();itr!=grp[i].end();itr++) cout<<name[*itr]<<" "; cout<<"\n";
    }
    cout<<"********\n";
    */
  }

  ll ms=0;
  fr(i,1,g+1) if(SZ(grp[i])>ms) ms=SZ(grp[i]);

  // displaying answer
  if(ms<mn) cout<<"no groups";
  else{
    vector<string> ans;

    fr(i,1,g+1){
      if(SZ(grp[i])==ms){
        for(itr=grp[i].begin();itr!=grp[i].end();itr++) ans.PB(name[*itr]);
      }
    }

    sort(ans.begin(),ans.end());
    fr(i,0,SZ(ans)) cout<<ans[i]<<"\n";
  }

  return 0;
}
