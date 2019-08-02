#include<bits/stdc++.h>

using namespace std;

typedef double dbl;
#define fr(x,a,b) for(int x=a;x<b;x++)
#define rf(x,a,b) for(int x=a;x>b;x--)
#define pii pair<int,int>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax intONG_MAX
#define gmin intONG_MIN
#define INF 2e9
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int n,m;
int block_size;

struct Query{
  int l; // left
  int r; // right
};

struct Query q[N];

bool cmp_block(struct Query q1,struct Query q2){
  if(q1.l/block_size!=q2.l/block_size) return (q1.l/block_size < q2.l/block_size);
	else return (q1.r < q2.r);
}

void F(vector<int> points[],vector<int> query[],int ind,int segment){
	fr(i,0,SZ(points[ind])){
		if(SZ(query[points[ind][i]])){
			if(query[points[ind][i]].back()==segment) query[points[ind][i]].pop_back();
			else query[points[ind][i]].PB(segment);
		}
		else query[points[ind][i]].PB(segment);
	}
}

void process(vector<int> points[],vector<int> query[]){
  int cl,cr;

  cl=0;
  cr=0;

  int l,r;
  fr(i,0,n){
    l=q[i].l;
    r=q[i].r;

		while(cl<l){
			F(points,query,cl,i);
      cl++;
    }

		while(cl>l){
			F(points,query,cl-1,i);
			cl--;
    }

    while(cr<=r){
			F(points,query,cr,i);
			cr++;
    }

    while(cr>r+1){
			F(points,query,cr-1,i);
      cr--;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		cin>>n;

		vector<int> points[n+1];

	  block_size=sqrt(n);

	  int a,b;
	  fr(i,0,n){
	    cin>>a>>b;
	    q[i].l=a;
	    q[i].r=b;
	  }

		cin>>m;

		vector<int> query[m];

		int k,x;
		fr(i,0,m){
			cin>>k;
			fr(j,0,k){
				cin>>x;
				points[x].PB(i);
			}
		}

	  sort(q,q+m,cmp_block);

	  process(points,query);

		int ans;
	  fr(i,0,m){
			query[i].PB(n);
			ans=0;
			for(int j=0;j<SZ(query[i])-1;j+=2){
				ans+=query[i][j+1]-query[i][j];
			}
			cout<<ans<<"\n";
	  }
	}

  return 0;
}
