#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+50;
int d=20,x=1,sum=0,c[N],num[N];
int n=1e5,now=512,dlt=512;int cnt=0;
int main(){
    for(int i=1,j=2;i<N;i<<=1,j+=2)num[i]=j;
    for(int i=1;;i++,now+=dlt){
        while(x*num[now&-now]<=sum)x++;
        if(n-(sum+x)>sum+x){
            c[x]++;
            sum+=x;cnt++;
        }
        else break;
    }
    printf("%d\n",n);
    for(int i=1;i<=n-sum;i++)printf("%d ",now);
    for(int i=x,y=now-dlt;i;i--){
    for(int j=1;j<=c[i];j++,y-=dlt)
        for(int k=1;k<=i;k++)
        printf("%d ",y);
    }
    return 0;
}