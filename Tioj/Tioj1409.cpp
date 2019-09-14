#include <bits/stdc++.h>
using namespace std;
template<class T>
bool getint(T& ___){
  T _=0,__=1; char tc;
  do
  {
    tc=getchar();
    if(tc==EOF) return false;
  }while((tc<'0'||tc>'9')&&tc!='-');
  if(tc=='-') tc=getchar(),__=-1;
  while(tc>='0'&&tc<='9') _=_*10+(tc-'0'),tc=getchar();
  ___=_*__;
  return true;
}
long long num[1000003];
int main(){
	int n;
	while(getint(n)){
		unsigned long long sum = 0;
		for(int i = 0;i < n;++i){
			getint(num[i]);
			sum += num[i];
		}
		bool ck = 0;
		for(int i = 0;i < n;++i){
			if(sum - num[i] <= num[i]){
				printf("NO\n");
				ck = 1;
				break;
			} 
		}
		if(!ck) printf("YES\n");
	}
	return 0;
}