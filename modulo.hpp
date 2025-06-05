#include<bits/stdc++.h>
using namespace std;
#define T T
#define N 100001
T T,n,m,t,x,y,ans,M,a[N],p[N],b[N],o[N];
priority_queue<T,vector<T>,greater<T>>q;
void exgcd(T a,T b,T&x,T&y){
	if(b==0){
		x=1;
		y=0;
	}else{
		exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
}
signed main(){
	#ifdef ONLINE_JUDGE
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	#else
	freopen("1.in","r",stdin);
	#endif
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(T i=1;i<=n;i++){
			cin>>a[i];
		}
		for(T i=1;i<=n;i++){
			cin>>p[i];
		}
		for(T i=1;i<=n;i++){
			cin>>o[i];
		}
		while(m--){
			cin>>x;
			q.push(x);
		}
		for(T i=1;i<=n;i++){
			b[i]=q.top();
			q.pop();
			q.push(o[i]);
		}
		ans=0;
		M=1;
		for(T i=1;i<=n;i++){
			exgcd(md(b[i]*M),p[i],x,y);
			x=md(x);
			if((a[i]-b[i]*ans)%__gcd(x,y)){
				ans=-1;
				break;
			}
			p[i]/=__gcd(x,y);
			ans+=(a[i]-b[i]*ans)/__gcd(x,y)*x%p[i]*M;
			M*=p[i];
			ans%=M;
		}
		cout<<ans<<endl;
	}
}
