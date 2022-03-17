#include <mem.h> 
#include <stdio.h> 
#include <stdlib.h> 
using namespace std; 
int tile = 0; //棋牌编号
int zsize = 4; //棋盘大小
int **board = NULL; //定义指向指针的指针用于动态的创建用于存储骨牌号的数组
//--------------------------------------------------------------------------- 
//动态创建二维数组，n 代表行，c 代表列
template<typename T> 
T **crt2d(int n,int c,T defval) { 
 T **p = new T *[n]; 
 for(int i=0;i<n;i++) { 
 p[i]=new int[c]; 
 for(int j=0;j<c;j++) p[i][j] = defval; 
 } 
 return p; 
} 
template<typename T> 
void disp2d(T **p,int n,int c) { 
 for(int i=0;i<n;i++) { 
 for(int j=0;j<c;j++) printf("%8d",p[i][j]); 
 putchar('\n'); 
 } 
} 
//--------------------------------------------------------------------------- 
void dispboard(int tt,int tr,int tc,int dr,int dc,int size) { 
 printf("=========牌号:%d 棋盘大小:%d 棋盘坐标[%d,%d],特殊方块[%d,%d]\n",tt,size,tr,tc,dr,dc); 
 disp2d(board,zsize,zsize); 
 printf("\n"); 
} 
//--------------------------------------------------------------------------- 
void chessBoard(int tt,int tr, int tc, int dr, int dc, int size) { 
 dispboard(tt,tr,tc,dr,dc,size); getchar(); 
 if(1==size) { printf("*********递归到底了。\n"); getchar(); return; } 
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
} 
//--------------------------------------------------------------------------- 
int main() { 
 //定义棋盘的左上角方格、特殊方格的行号和列号以及棋盘大小
 int tx=0,ty=0,dx=0,dy=0; 
 board = crt2d<int>(zsize,zsize,99); 
 board[dx][dy]=0; 
 chessBoard(tile,tx,ty,dx,dy,zsize); 
 system("pause"); 
 return 0; 
} 
