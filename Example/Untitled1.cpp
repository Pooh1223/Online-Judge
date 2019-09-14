#include <iostream>
using namespace std;

int main(){
  int i,j=0,m=0;
  while(cin>>i){
      
    while((i-j)!=1){
     int a[10];
  while(m<=3){
  cin>>a[m];
  m++;
   }
   if ((a[1]-a[0])==(a[2]-a[1]))
    a[m]=a[3]+(a[1]-a[0]);
  
   else if((a[1]/a[0])==(a[2]/a[1]))
    a[m]=a[3]*(a[1]/a[0]);

    m=0;

  while(m<=4){
  cout<<a[m]<<" ";
  m++;
}
  cout<<endl;
    m=0;
    j++;
    
    while(a[m]!=0){
    	a[m]==0;
    	m++;
	}
	m=0;
  }
 
}
  return 0;
} 
