#include <iostream>
using namespace std;
int heap[1000005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,cnt = 0;
	cin >> t;
	while(t--){
		int id;
		cin >> id;
		if(id == 1){
			int num;
			cin >> num;
			heap[cnt++] = num;
			int n = cnt - 1;
			while(1){
				if(n == 0) break;
				if(heap[n] < heap[(n - 1) / 2]){
					swap(heap[n],heap[(n - 1) / 2]);
					n = (n - 1) / 2;
				}
				else break;
			}
		}
		else{
			if(cnt == 0) printf("empty!\n");
			else{
				printf("%d\n",heap[0]);
				cnt--;
				heap[0] = heap[cnt];
				heap[cnt] = 0;
				int n = 0;
				while(1){
					if(n >= cnt) break;
					bool ck1 = 0;
					bool ck2 = 0;
					if(heap[n] > heap[2 * n + 1] && 2 * n + 1 <= cnt - 1) ck1 = 1;
					if(heap[n] > heap[2 * n + 2] && 2 * n + 2 <= cnt - 1) ck2 = 1;
					if(ck1 == 1 && ck2 == 1){
						if(heap[2 * n + 1] > heap[2 * n + 2]){
							swap(heap[n],heap[2 * n + 2]);
							n = 2 * n + 2;
						}
						else{
							swap(heap[n],heap[2 * n + 1]);
							n = 2 * n + 1;
						}
					}
					else if(ck1 == 1 && ck2 == 0){
						swap(heap[n],heap[2 * n + 1]);
						n = 2 * n + 1;
					}
					else if(ck1 == 0 && ck2 == 1){
						swap(heap[n],heap[2 * n + 2]);
						n = 2 * n + 2;
					}
					else break;
				}
			}
		}
	}
	return 0;
}