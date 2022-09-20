#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 40;
int x, y, fruitX, fruitY, score;
int arrX[100], arrY[100];
int n=0;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;


void Setup(){
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw(){
	system("cls");
	
	for(int i=0; i<width; i++){
		for(int j=0; j<height; j++){
			if(i==0||j==0||i==width-1||j==height-1){
				cout<<"#";
			}else if(i==x && j==y){
				cout<<"O";
			}else if(i==fruitX && j==fruitY){
				cout<<"F";
			}else{
				bool printf = false;
				for(int k=0; k<n; k++){
					if(i==arrX[k] && j==arrY[k]){
						cout<<"o";
						printf = true;
					}
				}
				
				if(!printf){
					cout<<" ";
				}
			}
		}
		cout<<endl;
	}
	
	cout<<"Score: "<<score<<endl;
}

void Input(){
	if(_kbhit()){
		switch(_getch()){
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'w':	
				dir = UP;
				break;		
		}
	}
}

void Logic(){
	int prevX = arrX[0];
	int prevY = arrY[0];
	int prev2X, prev2Y;
	arrX[0]=x;
	arrY[0]=y;
	
	for(int i=1; i<n; i++){
		prev2X = arrX[i];
		prev2Y = arrY[i];
		arrX[i] = prevX;
		arrY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	
	switch(dir){
		case LEFT:
			y--;
			break;
		case RIGHT:
			y++;
			break;
		case DOWN:
			x++;
			break;
		case UP:
			x--;
			break;
	}
	
//	if(x<=0 || y<=0 || x>=width-1 || y>=height-1){
//		gameOver = true;
//	}

	if(x>=width-1) x=1; else if(x<=0) x=width-2;
	if(y>=height-1) y=1; else if(y<=0) y=height-2;
	
	for(int i=0; i<n; i++){
		if(arrX[i]==x && arrY[i]==y){
			gameOver = true;
		}
	}
	
	if(x==fruitX && y==fruitY){
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		n++;
	}
}

int main(){
	Setup();
	
	while(!gameOver){
		Draw();
		Input();
		Logic();
		Sleep(50);
	}
	 
	
	return 0;
}