#include <cstdio>

struct yee{
	int a;
	int b;
	int c;
};

int main(){
	yee gg;
	gg.a = 7;
	gg.b = 1;
	gg.c = 2;
	yee ggg;
	ggg.a = 8;
	ggg.b = 7;
	ggg.c = 6;
	ggg = gg;
	printf("%d %d %d",ggg.a,ggg.b,ggg.c);
	return 0;
}
