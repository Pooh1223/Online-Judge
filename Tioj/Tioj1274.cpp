#include <cstdio>
int __t; char __c;
inline int rit() {
  __t = 0;
  do {
    __c = getchar();
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while (__c >= '0' && __c <= '9');
  return __t;
}
int main(){
	int n;
	n = rit();
	if(n == 1) printf("3\n");
	else if(n == 2) printf("4\n");
	else printf("14\n");
	return 0;
}
