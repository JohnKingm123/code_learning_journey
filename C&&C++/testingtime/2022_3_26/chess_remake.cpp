#include <stdio.h> 
#include <stdlib.h> 
#include<vector>
#include<iostream>
#define  defal 99 //δ�������̱�ʶ 
using namespace std; 
typedef vector<int> vint1; //�൱��һά������������
typedef vector<vint1> vint2; //�൱�ڶ�ά������������
 
 int tile = 0; //���Ʊ��
int zsize = 4; //���̴�С
 int pos =0; 
 
 
 void disp1(vint1 v1) { //���һά��������
 	for(int i=0;i<v1.size();i++) 
	 {
	 
	 printf("%5d",v1[i]); 
	 }
 	puts(""); 
 } 
 
 void disp2d(vint2 v2) { //�����ά��������
 	

	 
	 for(int i=0;i<v2.size();i++) 
 	{
	 
	 	 for(int k=0;k<pos;k++)
	 {putchar('\t');}	
	 
	 disp1(v2[i]); 
	 }
 } 

//--------------------------------------------------------------------------- 
//����zsize*zsize ��ȫ��Ԫ�س�ʼ��Ϊ defal 

 vint2 board (zsize,vint1(zsize,defal));  

//--------------------------------------------------------------------------- 
void push()
{
printf("��ջ\n");
pos++;
}
 
void pop()
{
	
printf("��ջ\n");	
pos--;
}

//��ջ��ջ 

//--------------------------------------------------------------------------- 
void dispboard(int tt,int tr,int tc,int dr,int dc,int size) { 
 printf("=========�ƺ�:%d ���̴�С:%d ��������[%d,%d],���ⷽ��[%d,%d]��ǰλ��%d\n",tt,size,tr,tc,dr,dc,pos); 
 disp2d(board); 
 printf("\n");  
} //������� 
//--------------------------------------------------------------------------- 
void chessBoard(int tt,int tr, int tc, int dr, int dc, int size) { 
 dispboard(tt,tr,tc,dr,dc,size); getchar(); 
 
 if(1==size) { printf("*********�ݹ鵽���ˡ�\n"); getchar(); return; } 
 
  push();
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
 
pop();
} 
//--------------------------------------------------------------------------- 
int main() { 
 //�������̵����ϽǷ������ⷽ����кź��к��Լ����̴�С
 int tx=0,ty=0,dx=0,dy=0; 
 board[dx][dy]=0; 
 chessBoard(tile,tx,ty,dx,dy,zsize); 
 system("pause"); 
 return 0; 
}
