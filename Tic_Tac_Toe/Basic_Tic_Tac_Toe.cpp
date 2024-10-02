#include<string>
#include<iostream>
using namespace std;

int main(){
	char board[3][3] {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	const char playerX = 'X';
	const char playerO = 'O';
	char currentPlayer = playerX;
	int r = -1; 
	int c = -1; 
	char winner = ' ';

	for(int i = 0; i < 9; i++){
		//print game board
		cout << "   |   |   " << endl;
		cout << " " << board[0][0] << " | " << board[0][1] << " | " <<board[0][2] << endl;
		cout << "___|___|___" << endl;
		cout << "   |   |   " << endl;
		cout << " " << board[1][0] << " | " << board[1][1] << " | " <<board[1][2] << endl;
		cout << "___|___|___" << endl;
		cout << "   |   |   " << endl;
		cout << " " << board[2][0] << " | " << board[2][1] << " | " <<board[2][2] << endl;
		cout << "___|___|___" << endl;
	
		if(winner != ' '){
			break;
		}

		//get player input
		cout << "Current Player is " <<currentPlayer << endl;
		while(true){
			cout << "Enter r c from 0-2 for row and collum: ";
			cin >> r >> c; //A B	
			if(r < 0 || r > 2 || c < 0 || c > 2){
				cout << "Invalid input, try again" << endl;
			} else if (board[r][c] != ' ') {
				cout << "Tile is full, try again." << endl;
			} else{
				break;
			}
			// reset values
			r = -1;
			c = -1;
			cin.clear(); // clear error flags
			cin.ignore(10000, '\n');
		}
		

		board[r][c] = currentPlayer;
		currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
		//check horizontal
		for (int r = 0; r < 3; r++){
			if(board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]){
				winner = board[r][0];
				break;
			}
		}
		//check vertical
		for (int c = 0; c < 3; c++){
			if(board[c][0] != ' ' && board[c][0] == board[c][1] && board[c][1] == board[c][2]){
				winner = board[c][0];
				break;
			}
		}

		if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			winner = board[0][0];
		} else if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
			winner = board[0][2];
		}
	}

	if (winner != ' ') {
		cout << "Player " << winner << " is the winner!" << endl;
	} else{
		cout << "Tie!" << endl;
	}
}