#include <iostream>
#include <vector> 
#include <string>
#include <cstdlib>
#include <fstream>
#include <typeinfo>
using namespace std;

int main(int argc, char const *argv[]){
	// Computer setting the board

	cout << "\t\t Welcome to Battleshipp. \nFind all three ships by typing in their coordinates" <<endl;
	cout<< "The rows and columns are numbered one through eight (default) left to right and top to bottom" << endl;
	cout << "You have twenty (default) total tries to find all three ships. The ships are one two and three units long respectively" << endl;
	cout << "If you can't find all three ships in twenty tries you lose.\nType in the size of the board you want to play on (8 for default)." << endl;

	int boardSize; int numGuesses;
	while(!(cin>>boardSize) || (boardSize < 6 )) {
		if(boardSize == NULL){
			boardSize = 8;
			break;
		}
		cin.clear();
		cin.ignore(999,'\n');
		cout<<"This is not a valid option. Enter a number greater than or equal to 6" <<endl;
	}
	numGuesses = boardSize * 2 + 4;
	
	cout << "The computer has hidden the ships. It is your job to find them." << endl; 
	cout << "You have " << numGuesses << " tries" << endl; 


	char ship[boardSize][boardSize];
	for(int i = 0; i<boardSize; i++){
		for(int j = 0; j<boardSize; j++){
			ship[i][j] = 'a';
		}
	}
	int x = rand() % boardSize;//starting positions
	int y = rand() % boardSize;
	int z = rand() % 2;// orientation
	if(z == 1){
		if(x-1 < 0){
			ship[x][y] = 'c';
			ship[x+1][y] = 'c';
		}
		if(x+1 > 7){
			ship[x][y] = 'c';
			ship[x-1][y] = 'c';
		}
		else{
			ship[x][y] = 'c';
			int z = rand() % 2;
			if(z == 1){
				ship[x+1][y] = 0;
			}
			if(z == 0){
				ship[x-1][y]; 
			}
		}

	}
	if(z == 0){
		if(y-1 < 0){
			ship[x][y] = 'c';
			ship[x][y+1] = 'c';
		}
		if(y+1 > 7){
			ship[x][y] = 'c';
			ship[x][y-1] = 'c';
		}
		else{
			ship[x][y] = 'c';
			z = rand() % 2;
			if(z == 1){
				ship[x][y+1] = 0;
			}
			if(z == 0){
				ship[x][y+1]; 
			}
		}

	}
	int x2 = rand() % boardSize;
	int y2 = rand() % boardSize;
	int z2 = rand() % 2;
	while(ship[x2][y2] == 'd' || ship[x2][y2] == 'c' || ship[x2+1][y2]== 'c' || ship[x2+2][y2] == 'c' || ship[x2+1][y2] == 'd' || ship[x2+2][y2] == 'd'){
		x2 = rand() %boardSize;
		y2 = rand() % boardSize;
	}
	while(ship[x2][y2] == 'd' || ship[x2][y2] == 'c' || ship[x2-1][y2]== 'c' || ship[x2-2][y2] == 'c' || ship[x2-1][y2] == 'd' || ship[x2-2][y2] == 'd'){
		x2 = rand() %boardSize;
		y2 = rand() % boardSize;
	}
	while(ship[x2][y2] == 'd' || ship[x2][y2] == 'c' || ship[x2][y2+1]== 'c' || ship[x2][y2+2] == 'c' || ship[x2][y2+1] == 'd' || ship[x2][y2+2] == 'd'){
		x2 = rand() %boardSize;
		y2 = rand() % boardSize;
	}
	while(ship[x2][y2] == 'd' || ship[x2][y2] == 'c' || ship[x2][y2-1]== 'c' || ship[x2][y2-2] == 'c' || ship[x2][y2-1] == 'd' || ship[x2][y2-2] == 'd'){
		x2 = rand() %boardSize;
		y2 = rand() % boardSize;
	}
	
	if(z == 0){
		if(x2+2 >7){
			ship[x2][y2] = 'b';
			ship[x2-1][y2] = 'b';
			ship[x2-2][y2] = 'b';
		}
		if(x2-2 < 0){
			ship[x2][y2] = 'b';
			ship[x2+1][y2] = 'b';
			ship[x2+2][y2] = 'b';
		}
		else{
			z = rand() % 2;
			if(z==0){
				ship[x2][y2] = 'b';
				ship[x2-1][y2] = 'b';
				ship[x2-2][y2] = 'b';
			}
			else{
				ship[x2][y2] = 'b';
				ship[x2+1][y2] = 'b';
				ship[x2+2][y2] = 'b';
			}
		} 
	}
	if(z == 1){
		if(y2+2 >7){
			ship[x2][y2-1] = 'b';
			ship[x2][y2] = 'b';
			ship[x2][y2-2] = 'b';
		}
		if(y2-2 < 0){
			ship[x2][y2] = 'b';
			ship[x2][y2+1] = 'b';
			ship[x2][y2+2] = 'b';
		}
		else{
			z = rand() % 2;
			if(z==0){
				ship[x2][y2] = 'b';
				ship[x2][y2-1] = 'b';
				ship[x2][y2-2] = 'b';
			}
			else{
				ship[x2][y2] = 'b';
				ship[x2][y2+1] = 'b';
				ship[x2][y2+2] = 'b';
			}
		}
	} 
	int x1 = rand() % boardSize;
	int y1 = rand() % boardSize;
	while(ship[x1][y1] != 'a'){
		y1 = rand() % boardSize;
		x1 = rand() % boardSize;
	}
	ship[x1][y1] = 'e';
	char board[boardSize][boardSize];
	for(int i =0; i<boardSize; i++){
		for(int j = 0; j < boardSize; j++){
			board[i][j] = 'O';
		}
	}// computer finishes making the board

	int p = 0;
	while(p<numGuesses){
		cout<<"You have "<<numGuesses-p<<" tries left"<<endl;
		for(int i =0; i<boardSize; i++){
			for(int j=0; j<boardSize; j++){
				cout<<board[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
		int row;
		int col;
		cout<<"Guess the row number"<<endl;
		while(!(cin>>row) || (row>boardSize || row<1)) {
			cin.clear();
			cin.ignore(999,'\n');
			cout<<"This is not a valid option. Enter a number between 1 and " << boardSize <<endl;
		}
 	// while(row>boardSize || row<1){ //|| typeid(row).name() != int){
	// 		cout<<"This is not a valid option. Enter a number between 1 and " << boardSize <<endl;
	// 		// std::system("pause");
	// 		cin>>row;
	// 	}
		cin.ignore();
		cout<<"Guess the column number"<<endl;

		while(!(cin>>col) || (col>boardSize || col<1)) {
			cin.clear();
			cin.ignore(999,'\n');
			cout<<"This is not a valid option. Enter a number between 1 and " << boardSize <<endl;
		}
		cin.ignore();
		if(ship[row-1][col-1]=='a'){
			cout<<"Wrong answer. Try again"<<endl;
			board[row-1][col-1] = 'X';
		}
		else if(board[row-1][col-1] != 'O'){
			cout<<"You already tried that, king. Now you lost a try for no reason"<<endl;
		}
		else{
			cout<<"You guessed a location right. It will display an exclamation point."<<endl;
			board[row-1][col-1] = '!';
			char temp = ship[row-1][col-1];
			ship[row-1][col-1] = 'g';
			bool temp1 = true;
			char temp2;
			for(int i = 0; i<boardSize; i++){
				for(int j = 0; j < boardSize; j++){
					char temp2 = ship[i][j];
					if(temp2 == temp){
						temp1 = false;
						break;
					}
				}
				if(temp2 == temp){
					break;
				}
			}
			if(temp1){
				cout<<"You sunk a ship"<<endl;
			}
		}
		int u = 0;
		for(int i = 0; i <boardSize; i++){
			for(int j = 0; j<boardSize; j++){
				if(board[i][j] == '!'){
					u++;
				}
			}
		}
		if(u==6){
			cout<<"You won congratulations, you found all three ships!"<<endl;
			for(int i =0; i<boardSize; i++){
				for(int j=0; j<boardSize; j++){
					cout<<board[i][j];
				}
				cout<<endl;
			}
			return 0;
		}
		p++;
	}
	cout<<"You ran out of guesses. You lose"<<endl;
		return 0;
}	