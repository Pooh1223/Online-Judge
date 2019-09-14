#include <cstdio>
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
int main(){
	int n;
	while(getint(n)){
		int i = n % 20;
			if(!i)printf("(10,5)\n");
			else if(i == 1)printf("(15,6)\n");
			else if(i == 2)printf("(15,12)\n");
			else if(i == 3)printf("(12,15)\n");
			else if(i == 4)printf("(6,15)\n");				
			else if(i == 5)printf("(5,10)\n");
			else if(i == 6)printf("(6,5)\n");
			else if(i == 7)printf("(12,5)\n");
			else if(i == 8)printf("(15,8)\n");
			else if(i == 9)printf("(15,14)\n");
			else if(i == 10)printf("(10,15)\n");
			else if(i == 11)printf("(5,14)\n");
			else if(i == 12)printf("(5,8)\n");
			else if(i == 13)printf("(8,5)\n");
			else if(i == 14)printf("(14,5)\n");
			else if(i == 15)printf("(15,10)\n");
			else if(i == 16)printf("(14,15)\n");
			else if(i == 17)printf("(8,15)\n");
			else if(i == 18)printf("(5,12)\n");
			else if(i == 19)printf("(5,6)\n");
	}
	return 0;
}
