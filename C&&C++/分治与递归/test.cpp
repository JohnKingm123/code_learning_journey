#include<stdio.h>
#include<stdlib.h>
#include<mem.h>
#include<vector>
using namespace std;
typedef vector<int> vint1; //�൱��һά������������
typedef vector<vint1> vint2; //�൱�ڶ�ά������������




int main() { 
 //�������̵����ϽǷ������ⷽ����кź��к��Լ����̴�С
 int tx=0,ty=0,dx=0,dy=0; 
 vint2 board(2,vint1 (2));
 board[dx][dy]=0; 
 //chessBoard(tile,tx,ty,dx,dy,zsize); 
 system("pause"); 
 return 0; 
}
