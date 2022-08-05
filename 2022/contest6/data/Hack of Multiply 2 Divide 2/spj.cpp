// #include"testlib.h"
#include<cmath>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
using namespace std;
const int N=1e5+50,iinf=1e9;
const long long Inf=1e18;
int n,a[N],b[N],mx,dat[N][20],lo[N*4];int anss=1e9;
struct states{
    long long g;int h,p;
    bool friend operator <(states a,states b){
        if(a.g!=b.g)return a.g<b.g;
        if(a.h!=b.h)return a.h<b.h;
        return a.p<b.p;
    }
}f[N][20],ansr;
struct node{
  int x,cos;
};
vector<node>v[N];
void WA()
{
	puts("WA");
	exit(0);
}
void AC()
{
	char trash[1000];
	if (scanf("%s", trash) != -1)
	{
		WA();
	}
	else
	{
		puts("AC");
		exit(0);
	}
}
int main() {
	//freopen("c://test//6248.out", "r", stdin); freopen("c://test//spj.out", "w", stdout);
  // freopen("data.txt","r",stdin);
  if(scanf("%d",&n)!=1)WA();
  if(n<1||n>100000)WA();
  // n = ouf.readInt(1,100000,"n");
  // cout<<n<<endl;
  for(int i=1,x;i<=n;i++){
    if(scanf("%d",&a[i])!=1)WA();
    if(a[i]<1||a[i]>100000)WA();
    // a[i] = ouf.readInt(1,100000,"a[i]");
    // mx=max(mx,a[i]);
  }
  mx=131071;
  ansr=(states){Inf,iinf,iinf};
  for(int i=2;i<N*4;i++)lo[i]=lo[i>>1]+1;
  for(int i=1;i<=n;i++){
    b[0]=a[i];int mn=0;
    for(int j=1;b[j-1];j++){
      b[j]=b[j-1]/2;mn=j-1;
    }
    v[i].pb((node){0,mn+1});
    for(int j=mn;b[mn]<=mx;j--)
      for(int k=mn-j;k>=max(0,-j)&&b[j+k]<=mx;k--){
        v[i].pb((node){b[j+k],k+j+k}),b[j+k]*=2;
        if(b[j+k]>mx&&!dat[i][j+k])
          dat[i][j+k]=b[j+k],f[i][j+k]=(states){k+j+k+1,lo[b[j+k]],b[j+k]};
      }
  }
  for(int i=n-1;i;i--)
    for(int j=0;dat[i][j];j++){
      states ff=(states){Inf,iinf,iinf};
      for(int k=0;dat[i+1][k];k++){
        states fff=(states){f[i+1][k].g+(dat[i+1][k]<dat[i][j]?n-i:0),f[i+1][k].h+(dat[i+1][k]<dat[i][j]?1:0),f[i+1][k].p};
        ff=min(ff,fff);
      }
      f[i][j].g+=ff.g,f[i][j].h=ff.h;f[i][j].p=ff.p;
    }
  for(int i=2;i<=n;i++){
    int k=0;int mn=v[i-1][0].cos;
    for(int j=0;j<v[i].size();j++){
      while(k+1<v[i-1].size()&&v[i-1][k+1].x<=v[i][j].x)
        mn=min(mn,v[i-1][++k].cos);
      v[i][j].cos+=mn;
    }
    while(k+1<v[i-1].size()&&v[i-1][k+1].x<=mx)
      mn=min(mn,v[i-1][++k].cos);
    for(int j=0;dat[i][j];j++){
      ansr=min(ansr,(states){mn+f[i][j].g,f[i][j].h,f[i][j].p});
    }
  }
  for(int i=0;i<v[n].size();i++){
    if(v[n][i].cos<ansr.g)ansr.g=v[n][i].cos,ansr.h=ansr.p=0,anss=v[n][i].x;
    else if(v[n][i].cos==ansr.g&&v[n][i].x<anss)ansr.h=ansr.p=0,anss=v[n][i].x;
  }
  if(ansr.h>=127)AC();
  else WA();
  return 0;
}