#include <cstdio>
#include <string>

int main(){
	char board[9];
	int cnto = 0,cntx = 0;
	bool wrong = 0;
	for(int i = 0;i < 9;i++){
		scanf("%c",&board[i]);
		if(board[i] == '\n'){i--; continue;} 
		if(board[i] == 'O') cnto++;
		else if(board[i] == 'X') cntx++;
		else if(board[i] == '.');
		else wrong = 1;
	}
	if(cnto - cntx != 1 && cnto - cntx != 0) wrong = 1;
	else if(cnto - cntx == 0){
		if(board[0] == board[1] && board[1] == board[2] && board[0] == 'O')wrong = 1;
		if(board[3] == board[4] && board[4] == board[5] && board[3] == 'O')wrong = 1;
		if(board[6] == board[7] && board[7] == board[8] && board[6] == 'O')wrong = 1;
		if(board[0] == board[3] && board[3] == board[6] && board[0] == 'O')wrong = 1;
		if(board[1] == board[4] && board[4] == board[7] && board[1] == 'O')wrong = 1;
		if(board[2] == board[5] && board[5] == board[8] && board[2] == 'O')wrong = 1;
		if(board[0] == board[4] && board[4] == board[8] && board[0] == 'O')wrong = 1;
		if(board[2] == board[4] && board[4] == board[6] && board[2] == 'O')wrong = 1;
	}
	else if(cnto - cntx == 1){	
		if(board[0] == board[1] && board[1] == board[2] && board[0] == 'X')wrong = 1;
		if(board[3] == board[4] && board[4] == board[5] && board[3] == 'X')wrong = 1;
		if(board[6] == board[7] && board[7] == board[8] && board[6] == 'X')wrong = 1;
		if(board[0] == board[3] && board[3] == board[6] && board[0] == 'X')wrong = 1;
		if(board[1] == board[4] && board[4] == board[7] && board[1] == 'X')wrong = 1;
		if(board[2] == board[5] && board[5] == board[8] && board[2] == 'X')wrong = 1;
		if(board[0] == board[4] && board[4] == board[8] && board[0] == 'X')wrong = 1;
		if(board[2] == board[4] && board[4] == board[6] && board[2] == 'X')wrong = 1;
	}
	if(wrong) printf("IMPOSSIBLE");
	else printf("POSSIBLE");
	return 0;
}
