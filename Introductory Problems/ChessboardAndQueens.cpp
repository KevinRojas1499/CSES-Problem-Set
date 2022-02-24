#include <bits/stdc++.h>
#define ll long long

using namespace std;

char board[8][8];
ll tot = 0;
int usedCols[8];
int usedDiags[15];
int usedOtherDiag[15];


void solve(int i){
	if(i == 8){
		tot++;
		return;
	}
	for(int j = 0; j<8; j++){
		if(board[i][j] == '*'){
			continue;
		}
		ll diag = i+j;
		ll otherDiag = i-j+8;
		if(!usedCols[j] && !usedDiags[diag] && !usedOtherDiag[otherDiag]){
			usedCols[j] = 1;
			usedDiags[diag] = 1;
			usedOtherDiag[otherDiag] = 1;
			solve(i+1);
			usedCols[j] = 0;
			usedDiags[diag] = 0;
			usedOtherDiag[otherDiag] = 0;
		}
	}
}

int main(){
	
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			cin>>board[i][j];
		}
	}
	
	for(int i = 0; i<8; i++){
		usedCols[i] = 0;
	}
	for(int i = 0; i<15; i++){
		usedDiags[i] = 0;
		usedOtherDiag[i] = 0;
	}
	solve(0);
	cout<<tot<<"\n";
	
}
