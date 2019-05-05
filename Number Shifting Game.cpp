#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define ESC 0 
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

using namespace std;

class GamePlay {
	int Board[4][4] , move;
public:
	GamePlay() {
		int pool[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
		int index , maxIndex = 14;
		srand(time(NULL));
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(maxIndex >= 0){
					index = rand() % (maxIndex+1);
					Board[i][j] = pool[index];
					pool[index] = pool[maxIndex];
					maxIndex--;
				}
				else 
					Board[i][j] = 0;
			}
		}
		move = 500;	
	}
	
	void draw() {
		cout<<"\nMove Left : "<<move;
		cout<<"\n------------------------\n|";
		for(int i=0 ; i<4 ; i++){
			for(int j=0 ; j<4 ; j++){
				if(Board[i][j] != 0)
					printf(" %-2d | ",Board[i][j]);
				else
					printf("    | ");
			}
			cout<<"\n------------------------\n";
			if(i != 3)
				printf("|");
		}
	}
	
	int input() {
		int get;
		get = getch();
		if(get == 224){
			get = getch();
			switch(get){
				case 27:
					return(ESC);
				case 72:
					return(UP);
				case 80:
					return(DOWN);
				case 75:
					return(LEFT);
				case 77:
					return(RIGHT);
				default :
					return(5);
			}
		}		
	}

	bool checkWin() {
		int k=0 ;
		for(int i=0 ; i<4 ; i++){
			for(int j=0 ; j<4 ; j++){
				k<15 ? k++ : (k=0);
				if(Board[i][j] != k)
					return false;
			}
		}	
		return true;
	}
	
	swiftUp() {
		int temp , i , j;
		bool isZero = false;
		for(i=0; i<4 ; i++) {
			for(j=0; j<4 ; j++){
				if(Board[i][j] == 0){
					isZero = true;
					break;
				}
			}
			if(isZero)
				break;
		}
		if(!(i == 3)) {
			temp = Board[i][j];
			Board[i][j] = Board[i+1][j];
			Board[i+1][j] = temp;
			move--;
		}
	}
	
	swiftLeft() {
		int temp , i , j;
		bool isZero = false;
		for(i=0; i<4 ; i++) {
			for(j=0; j<4 ; j++){
				if(Board[i][j] == 0){
					isZero = true;
					break;
				}
			}
			if(isZero)
				break;
		}
		if(!(j == 3)) {
			temp = Board[i][j];
			Board[i][j] = Board[i][j+1];
			Board[i][j+1] = temp;
			move--;
		}
	}
	
	swiftRight() {
		int temp , i , j;
		bool isZero = false;
		for(i=0; i<4 ; i++) {
			for(j=0; j<4 ; j++){
				if(Board[i][j] == 0){
					isZero = true;
					break;
				}
			}
			if(isZero)
				break;
		}
		if(!(j == 0)) {
			temp = Board[i][j];
			Board[i][j] = Board[i][j-1];
			Board[i][j-1] = temp;
			move--;
		}
	}
	swiftDown() {
		int temp , i , j;
		bool isZero = false;
		for(i=0; i<4 ; i++) {
			for(j=0; j<4 ; j++){
				if(Board[i][j] == 0){
					isZero = true;
					break;
				}
			}
			if(isZero)
				break;		
		}
		if(!(i == 0)) {
			temp = Board[i][j];
			Board[i][j] = Board[i-1][j];
			Board[i-1][j] = temp;
		}
	}
};

int main() {
	GamePlay play;
	while(true){
		system("cls");
		play.draw();
		if(play.checkWin()){
			cout<<"\n\n==>Congractulation You Win !!!";
			getch();
			exit(0);
		}
		switch(play.input()){
			case ESC:
				exit(0);
			case UP:
				play.swiftUp();
				break;
			case LEFT:
				play.swiftLeft();
				break;
			case RIGHT:
				play.swiftRight();
				break;
			case DOWN:
				play.swiftDown();
				break;	
		}
	}
	getch();
}
