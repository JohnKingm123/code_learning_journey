#include <mem.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream> 
using namespace std; 
//--------------------------------------------------------------------------- 
const int N = 8; 
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
void disp2d(T **p,int n,int c,const char *fmt="%8d") { 
 for(int i=0;i<n;i++) { 
 for(int j=0;j<c;j++) printf(fmt,p[i][j]); 
 putchar('\n'); 
 } 
} 
void disp(int **tbl,int n,char *info){ 
 puts(info); 
 disp2d(tbl,n,n,"%3d"); 
 printf("\n"); 
} 
//--------------------------------------------------------------------------- 
void arrange(int **a,int start,int end){ 
 int m = end/2; 
 if(end>=4){ 
 arrange(a,start,m); 
 arrange(a,start+m,m); 
 } 
 // 复制左下角
 for(int i=m;i<end;i++){ 
 for(int j=start;j<start+m;j++){ 
 a[i][j]=a[i-m][j+m]; 
 } 
 } 
 disp(a,N,"复制左下角:"); 
 // 复制右下角
 for(int i=m;i<end;i++){ 
 for(int j=start+m;j<start+end;j++){ 
 a[i][j]=a[i-m][j-m]; 
 } 
 } 
 disp(a,N,"复制右下角:"); 
} 
//--------------------------------------------------------------------------- 
int main(){ 
 int **tbl= crt2d(N,N,0); 
 for(int i=0;i<N;i++) tbl[0][i] = i+1; 
 arrange(tbl,0,N); 
 disp(tbl,N,"最终输出:"); 
 system("pause"); 
 return 0; 
} 
//