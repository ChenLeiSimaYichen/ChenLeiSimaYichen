#include<iostream>
using namespace std;
int p,q,r;
long long conv(long long x,long long b){
	long long ret=0,c=1;
	while(x){
		if(x%10>=b){
			return 0;
		}
		ret+=x%10*c;
		x/=10;
		c*=b;
	}
}
int main(){
	cin>>p>>q>>r;
	for(int i=2;i<=40;i++){
		if(conv(r,i))&&conv(p,i)*conv(q,i)==conv(r,i){
			cout<<i;
			return 0;
		}
	}
	cout<<0;
	return 0;
}