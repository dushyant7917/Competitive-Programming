#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define N 300001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

string dec_to_binary(ll n){
  stack<char> st;
  string ans="";

  while(n>0){
    st.push(n%2);
    n/=2;
  }

  fr(i,0,30-SZ(st)) ans+='0';

  while(SZ(st)){
    ans+=(st.top()+'0');
    st.pop();
  }

  return ans;
}

ll binary_to_dec(string bit){
  ll ans=0;
  ll n=SZ(bit);

  fr(i,0,SZ(bit)){
    ans+=(bit[i]-'0')*(pow(2,n-i-1));
  }

  return ans;
}

struct Trie{
  struct Trie *child[2]; // reference to 0 or 1
  bool is_EOW; // flag for indicating end of word or not
};

Trie* get_node(){
  Trie* ptr = new Trie;

  ptr->is_EOW=false;

  ptr->child[0]=ptr->child[1]=NULL;

  return ptr;
}

// inserts a word in the trie data structure
void insert(Trie*& root,string word){
  if(root==NULL) root=get_node();

  Trie* ptr=root;

  ll pos;
  fr(i,0,word.size()){
    pos=word[i]-'0';
    if(ptr->child[pos]==NULL) ptr->child[pos]=get_node();
    ptr=ptr->child[pos];
  }

  ptr->is_EOW=true;
}

string search(Trie* root,string word){
  Trie* ptr=root;
  string ans="";

  fr(i,0,word.size()){
    if(ptr->child[word[i]-'0']!=NULL){
      ans+=word[i];
      ptr=ptr->child[word[i]-'0'];
    }
    else{
      ans+=((word[i]=='0')?'1':'0');
      ptr=ptr->child[1-(word[i]-'0')];
    }
  }

  return ans;
}

bool has_child(Trie* node){
  fr(i,0,2) if(node->child[i]!=NULL) return true;
  return false;
}

bool delete_word(Trie*& root,string word,ll ind){
  if(root==NULL) return false;

  if(ind==SZ(word)){
    if(root->is_EOW){
      root->is_EOW=false;
      if(!has_child(root)) return true;
      return false;
    }
  }
  else{
    ll pos=word[ind]-'0';

    if(root->child[pos]==NULL) return false;

    if(delete_word(root->child[pos],word,ind+1)){
      delete root->child[pos];
      root->child[pos]=NULL;
      return (!root->is_EOW && !has_child(root));
    }
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll a[n],k[n];
  fr(i,0,n) cin>>a[i];
  fr(i,0,n) cin>>k[i];

  Trie* root=NULL;

  fr(i,0,n) insert(root,dec_to_binary(k[i]));

  string ans;
  fr(i,0,n){
    ans=search(root,dec_to_binary(a[i]));
    cout<<(a[i]^binary_to_dec(ans))<<" ";
    delete_word(root,ans,0);
  }

  return 0;
}
