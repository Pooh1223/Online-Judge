#include <cstdio>
using namespace std;
bool used[20005];
int num[20005],index[20005],solve[20005],cnt = 0;
int n,m;
template<class T>
bool rit(T& ___){
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
void back(int n,int len,int a[]){
	if(n == len){
		cnt = ((cnt % m) + 1) % m;
		return;
	} 
	for(int i = 0;i < len;i++){
		if(!used[i]){
			used[i] = 1;
			solve[n] = a[i];
			if(solve[n] == index[n]){
				used[i] = 0;
				continue;
			}
			else{
				back(n + 1,len,a);
				used[i] = 0;
			}
		}
	}
}

int main(){
	rit(n); rit(m);
	for(int i = 0;i < 20005;i++) used[i] = 0;
	int g = 0;
	for(int i = 0,j;i < n;++i){
		rit(j);
		if(j == -1){
			index[g] = i + 1;
			g++;
		}
		else used[j] = 1;
	}
	for(int i = 1,j = 0;i <= n;++i){
		if(!used[i]){
			num[j] = i;
			j++;
		}
	}
	for(int i = 0;i < 20005;i++) used[i] = 0;
	back(0,g,num);
	printf("%d\n",cnt);
	return 0;
} 
