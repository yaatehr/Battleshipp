#include <iostream>
#include <vector> 
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	char ship[8][8];
	for(int i = 0; i<8; i++){
		for(int j = 0; j<8; j++){
			ship[i][j] = 'a';
		}
	}
	int x = rand() % 8;
	int y = rand() % 8;
	int z = rand() % 2;
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
	int x2 = rand() % 8;
	int y2 = rand() % 8;
	int z2 = rand() % 2;
	while(ship[x2][y2] == 'd' || ship[x2][y2] == 'c' || ship[x2+1][y2]== 'c' || ship[x2+2][y2] == 'c' || ship[x2+1][y2] == 'd' || ship[x2+2][y2] == 'd'){
		x2 = rand() %8;
		y2 = rand() % 8;
	}
	while(ship[x2][y2] == 'd' || ship[x2][y2] == 'c' || ship[x2-1][y2]== 'c' || ship[x2-2][y2] == 'c' || ship[x2-1][y2] == 'd' || ship[x2-2][y2] == 'd'){
		x2 = rand() %8;
		y2 = rand() % 8;
	}
	while(ship[x2][y2] == 'd' || ship[x2][y2] == 'c' || ship[x2][y2+1]== 'c' || ship[x2][y2+2] == 'c' || ship[x2][y2+1] == 'd' || ship[x2][y2+2] == 'd'){
		x2 = rand() %8;
		y2 = rand() % 8;
	}
	while(ship[x2][y2] == 'd' || ship[x2][y2] == 'c' || ship[x2][y2-1]== 'c' || ship[x2][y2-2] == 'c' || ship[x2][y2-1] == 'd' || ship[x2][y2-2] == 'd'){
		x2 = rand() %8;
		y2 = rand() % 8;
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

	int x1 = rand() % 8;
	int y1 = rand() % 8;
	while(ship[x1][y1] != 'a'){
		y1 = rand() % 8;
		x1 = rand() % 8;
	}
	ship[x1][y1] = 'e';
	char board[8][8];
	for(int i =0; i<8; i++){
		for(int j = 0; j < 8; j++){
			board[i][j] = 'O';
		}
	}
	cout<< "Hello welcome to battleship. Find all three ships based on typing in their coordinates" <<endl;
	cout<< "The rows and columns are numbered one through eight left to right and top to bottom" << endl;
	cout << "You have 20 total tries to find all three ships. The ships are one two and three units long respectively" << endl;
	cout << "If you can't find all three ships in 20 tries you lose. Type in 0 if you want a friend to hide the ships." << endl;
	cout << "The computer has hidden the ships. It is your job to find them." << endl; 
	int choice = 1;
	if(choice == 1){
		int p = 0;
		while(p<20){
			cout<<"You have "<<20-p<<" tries left"<<endl;
			for(int i =0; i<8; i++){
				for(int j=0; j<8; j++){
					cout<<board[i][j];
				}
				cout<<endl;
			}
			cout<<endl;
			int row;
			int col;
			cout<<"Guess the row number"<<endl;
			cin>>row;
			while(row>8 || row<1){
				cout<<"This is not a valid option. Enter a number between 1 and 8"<<endl;
				cin>>row;
			}
			cin.ignore();
			cout<<"Guess the column number"<<endl;
			cin>>col;
			while(col>8 || col<1){
				cout<<"This is not a valid option. Enter a number between 1 and 8"<<endl;
				cin>>col;
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
				for(int i = 0; i<8; i++){
					for(int j = 0; j < 8; j++){
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
			for(int i = 0; i <8; i++){
				for(int j = 0; j<8; j++){
					if(board[i][j] == '!'){
						u++;
					}
				}
			}
			if(u==6){
				cout<<"You won congratulations, you found all three ships!"<<endl;
				for(int i =0; i<8; i++){
					for(int j=0; j<8; j++){
						cout<<board[i][j];
					}
					cout<<endl;
				}
				return 0;
			}
			p++;
		}
		if(p>=20){
			cout<<"You ran out of guesses. You lose"<<endl;
			return 0;
		}

	}
	return 0;
}	