#include <stdio.h> 
#include <stdlib.h> 
#include<vector>
#include<iostream>
#define  defal 99 //未处理棋盘标识 
using namespace std; 
typedef vector<int> vint1; //相当于一维整数数组类型
typedef vector<vint1> vint2; //相当于二维整数数组类型
 
 int tile = 0; //棋牌编号
int zsize = 4; //棋盘大小
 int pos =0; 
 
 
 void disp1(vint1 v1) { //输出一维整数数组
 	for(int i=0;i<v1.size();i++) 
	 {
	 
	 printf("%5d",v1[i]); 
	 }
 	puts(""); 
 } 
 
 void disp2d(vint2 v2) { //输出二维整数数组
 	

	 
	 for(int i=0;i<v2.size();i++) 
 	{
	 
	 	 for(int k=0;k<pos;k++)
	 {putchar('\t');}	
	 
	 disp1(v2[i]); 
	 }
 } 

//--------------------------------------------------------------------------- 
//构建zsize*zsize 并全部元素初始化为 defal 

 vint2 board (zsize,vint1(zsize,defal));  

//--------------------------------------------------------------------------- 
void push()
{
printf("入栈\n");
pos++;
}
 
void pop()
{
	
printf("出栈\n");	
pos--;
}

//出栈入栈 

//--------------------------------------------------------------------------- 
void dispboard(int tt,int tr,int tc,int dr,int dc,int size) { 
 printf("=========牌号:%d 棋盘大小:%d 棋盘坐标[%d,%d],特殊方块[%d,%d]当前位置%d\n",tt,size,tr,tc,dr,dc,pos); 
 disp2d(board); 
 printf("\n");  
} //棋盘输出 
//--------------------------------------------------------------------------- 
void chessBoard(int tt,int tr, int tc, int dr, int dc, int size) { 
 dispboard(tt,tr,tc,dr,dc,size); getchar(); 
 
 if(1==size) { printf("*********递归到底了。\n"); getchar(); return; } 
 
  push();
 int t = tile++; 
 int s = size/2; 
 
 if(dr < tr+s && dc < tc+s) { 
 printf(" 左上\n"); 
 chessBoard(t,tr,tc,dr,dc,s); 
 } 
 else { 
 printf("非左上\n"); board[tr+s-1][tc+s-1] = t; 
 chessBoard(t,tr,tc,tr+s-1,tc+s-1,s); 
 } 
 if(dr < tr+s && dc >= tc+s ) { 
 printf(" 右上\n"); 
 chessBoard(t,tr,tc+s,dr,dc,s); 
 } 
 else { 
 printf("非右上\n"); board[tr+s-1][tc+s] = t; 
 chessBoard(t,tr,tc+s,tr+s-1,tc+s,s); 
 } 
 if(dr >= tr+s && dc < tc+s) { 
 printf(" 左下\n"); 
 chessBoard(t,tr+s,tc,dr,dc,s); 
 } 
 else { 
 printf("非左下\n"); board[tr+s][tc+s-1] = t; 
 chessBoard(t,tr+s,tc,tr+s,tc+s-1,s); 
 } 
 if(dr >= tr+s && dc >= tc+s) { 
 printf(" 右下\n"); 
 chessBoard(t,tr+s,tc+s,dr,dc,s); 
 } 
 else { 
 printf("非右下\n"); board[tr+s][tc+s] = t; 
 chessBoard(t,tr+s,tc+s,tr+s,tc+s,s); 
 }
 
pop();
} 
//--------------------------------------------------------------------------- 
int main() { 
 //定义棋盘的左上角方格、特殊方格的行号和列号以及棋盘大小
 int tx=0,ty=0,dx=0,dy=0; 
 board[dx][dy]=0; 
 chessBoard(tile,tx,ty,dx,dy,zsize); 
 system("pause"); 
 return 0; 
}
