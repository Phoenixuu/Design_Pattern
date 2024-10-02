#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

class Board;

class Player{
public: 
	virtual void makeMove(Board& board, char currentPlayer) = 0;
};

class HumanPlayer : public Player{
public:
	void makeMove(Board& board, char currentPlayer) override;
};

class AIPlayer : public Player {
public:
	void makeMove(Board& board, char currentPlayer) override;
};

class Board {
private:
	std::vector<vector<char>> board;
	const int size = 3;
public:
	Board(){
		board = vector<vector<char>>(size, vector<char>(size, ' '));
	}
	void display() const{
		for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                cout << board[r][c] << " ";
            }
            cout << endl;
        }
	}
	bool checkWin(char player){
		for (int i = 0; i < size; i++){
			if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
				return true;
			}
			if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
				return true;
			}
		}
		if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			return true;
		} else if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
			return true;
		}
		return false;
	}
    bool makeMove(int row, int col, char player) {
        if (board[row][col] == ' ') {
            board[row][col] = player;
            return true;
        }
        return false;
    }
    bool checkFull() {
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                if (board[r][c] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
};

void HumanPlayer::makeMove(Board& board, char currentPlayer) {
	int r, c;
	// //get player input
	// cout << "Current Player is " <<currentPlayer << endl;
	while(true){
		cout << "Enter r c from 0-2 for row and collum: ";
		cin >> r >> c; //A B	
		if(r < 0 || r > 2 || c < 0 || c > 2){
			cout << "Invalid input, try again" << endl;
		} else if (!board.makeMove(r,c,currentPlayer)) {
			cout << "Tile is full, try again." << endl;
		} else{
			break;
		}
	}
};

void AIPlayer::makeMove(Board& board, char currentPlayer) {
	int row, col;
	bool validMove = false;

	//Try random moves until finding an empty cell
	while(!validMove) {
		row = rand() % 3;
		col = rand() % 3;
		validMove = board.makeMove(row, col, 'O');
	}
};

int main() {
	Board board;
	HumanPlayer playerX;
	AIPlayer playerO;

	char currentPlayer = 'X';
	char winner = ' ';
	bool GameOver = false;

	while(!GameOver) {
		board.display();

		if(currentPlayer == 'X'){
			cout << "Player X's turn:" << endl;
			playerX.makeMove(board,currentPlayer);
		} else{
			cout << "Player O (AI) turn:" <<endl;
			playerO.makeMove(board,currentPlayer);
		}

		//Check winner
		if(board.checkWin(currentPlayer)){
			winner = currentPlayer;
			GameOver = true;
		} else if(board.checkFull()){
			GameOver = true;
		}
		currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
	}

	board.display();

	if (winner != ' ') {
		cout << "Player " << winner << " is the winner!" << endl;
	} else {
		cout << "Tie!" << endl;
	}
	
	return 0;
}

