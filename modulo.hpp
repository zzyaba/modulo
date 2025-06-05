#include<bits/stdc++.h>
using namespace std;
template<typename T=long long,T mmod=998244353>
struct modulo{
	constexpr static T mod=mmod;
	vector<T>fac={1,1},inv={1,1},ifc={1,1};
	inline T factorial(const T&x){
		while(fac.size()<=x){
			fac.push_back(fac.back()*fac.size()%mod);
		}
		return fac[x];
	}
	inline T inverse(const T&x){
		while(inv.size()<=x){
			inv.push_back(inv[mod%inv.size()]*(mod-mod/inv.size())%mod);
		}
		return inv[x];
	}
	inline T invfact(const T&x){
		while(inv.size()<=x){
			inv.push_back(inv[mod%inv.size()]*(mod-mod/inv.size())%mod);
		}
		while(ifc.size()<=x){
			ifc.push_back(ifc.back()*inv[ifc.size()]%mod);
		}
		return ifc[x];
	}
	inline T arrange(const T&x,const T&y){
		return factorial(x)*invfact(y-x)%mod;
	}
	inline T combine(const T&x,const T&y){
		return factorial(x)*invfact(y-x)%mod*invfact(y)%mod;
	}
	inline T sum(T x,const T&y){
		return(x+=y)>=mod?x-mod:x;
	}
	inline T sub(T x,const T&y){
		return(x-=y)<0?x+mod:x;
	}
	inline T mul(const T&x,const T&y){
		return x*y%mod;
	}
	inline T div(const T&x,const T&y){
		return x*inverse(y)%mod;
	}
	inline T norm(T x){
		return(x%=mod)<0?x+mod:x;
	}
};
signed main(){
	modulo<>md;
}
