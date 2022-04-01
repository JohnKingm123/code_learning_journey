#include <mem.h> 
#include <stdio.h> 
#include <stdlib.h> 
using namespace std; 
int tile = 0; //���Ʊ��
int zsize = 4; //���̴�С
int **board = NULL; //����ָ��ָ���ָ�����ڶ�̬�Ĵ������ڴ洢���ƺŵ�����
//--------------------------------------------------------------------------- 
//��̬������ά���飬n �����У�c ������
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
 printf("=========�ƺ�:%d ���̴�С:%d ��������[%d,%d],���ⷽ��[%d,%d]\n",tt,size,tr,tc,dr,dc); 
 disp2d(board,zsize,zsize); 
 printf("\n"); 
} 
//--------------------------------------------------------------------------- 
void chessBoard(int tt,int tr, int tc, int dr, int dc, int size) { 
 dispboard(tt,tr,tc,dr,dc,size); getchar(); 
 if(1==size) { printf("*********�ݹ鵽���ˡ�\n"); getchar(); return; } 
 int t = tile++; 
 int s = size/2; 
 if(dr < tr+s && dc < tc+s) { 
 printf(" ����\n"); 
 chessBoard(t,tr,tc,dr,dc,s); 
 } 
 else { 
 printf("������\n"); board[tr+s-1][tc+s-1] = t; 
 chessBoard(t,tr,tc,tr+s-1,tc+s-1,s); 
 } 
 if(dr < tr+s && dc >= tc+s ) { 
 printf(" ����\n"); 
 chessBoard(t,tr,tc+s,dr,dc,s); 
 } 
 else { 
 printf("������\n"); board[tr+s-1][tc+s] = t; 
 chessBoard(t,tr,tc+s,tr+s-1,tc+s,s); 
 } 
 if(dr >= tr+s && dc < tc+s) { 
 printf(" ����\n"); 
 chessBoard(t,tr+s,tc,dr,dc,s); 
 } 
 else { 
 printf("������\n"); board[tr+s][tc+s-1] = t; 
 chessBoard(t,tr+s,tc,tr+s,tc+s-1,s); 
 } 
 if(dr >= tr+s && dc >= tc+s) { 
 printf(" ����\n"); 
 chessBoard(t,tr+s,tc+s,dr,dc,s); 
 } 
 else { 
 printf("������\n"); board[tr+s][tc+s] = t; 
 chessBoard(t,tr+s,tc+s,tr+s,tc+s,s); 
 } 
} 
//--------------------------------------------------------------------------- 
int main() { 
 //�������̵����ϽǷ������ⷽ����кź��к��Լ����̴�С
 int tx=0,ty=0,dx=0,dy=0; 
 board = crt2d<int>(zsize,zsize,99); 
 board[dx][dy]=0; 
 chessBoard(tile,tx,ty,dx,dy,zsize); 
 system("pause"); 
 return 0; 
}
