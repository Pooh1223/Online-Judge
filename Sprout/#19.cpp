#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int len,code[100005],queue = 1,stack[100005],top = 0;
		bool ck = 0;
		cin >> len;
		for(int i = 0;i < len;i++) cin >> code[i];
		for(int i = 0;i < len;i++){
			if(queue <= len && queue <= code[i]){
				while(queue <= code[i]){
					stack[top++] = queue++;
					if(stack[top - 1] == code[i]){
						top--;
						break;
					} 
				}	
			}
			else{
				if(stack[top - 1] != code[i]){
					ck = 1;
					break;
				}
				else top--;
			}
		}
		if(ck) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}
