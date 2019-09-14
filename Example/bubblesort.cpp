#include <iostream>
using namespace std;

int bubblesort(int array[],int len){
	int sum = 0,fun[len];
	for(int i = 0;i < len;i++){
		if(!i) fun[i] = 0;
		else {
			for(int j = 1;j <= i;j++){
				if(array[j - 1] > array[j]){
					swap(array[j - 1],array[j]);
					sum++;
					j = 0;
				}
			}	
			fun[i] = sum;
			sum = 0;
		}	
	}
	for(int i = 0;i < len;i++){
		if(i == 0) cout << "Fun is : ";
		cout << fun[i] << " ";
		if(i == len - 1) cout << endl;
	}
}

int main(){
	int i;
	cout << "Iuput array length " << endl;
	while(cin >> i){
		cout << "Iuput array elements" << endl;
		int sort[i];
		for(int j = 0;j < i;j++){
			if(j == 0) cout << "Before sort : ";
			cin >> sort[j];
			if(j == i - 1) cout << endl;
		}
		bubblesort(sort,i);
		for(int k = 0;k < i;k++){
			if(k == 0) cout << "After sort : ";
			cout << sort[k] << " ";
			if(k == i - 1) cout << endl;
		}
	}
}
