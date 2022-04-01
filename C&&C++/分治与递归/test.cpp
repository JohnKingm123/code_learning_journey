#include<stdio.h>
#include<stdlib.h>
#include<mem.h>
#include<vector>
using namespace std;
typedef vector<int> vint1; //相当于一维整数数组类型
typedef vector<vint1> vint2; //相当于二维整数数组类型




int main() { 
 //定义棋盘的左上角方格、特殊方格的行号和列号以及棋盘大小
 int tx=0,ty=0,dx=0,dy=0; 
 vint2 board(2,vint1 (2));
 board[dx][dy]=0; 
 //chessBoard(tile,tx,ty,dx,dy,zsize); 
 system("pause"); 
 return 0; 
}
