#include "stdlib.h" 
#include "stdio.h" 
template<class Type> 
inline void swap(Type &a,Type &b,Type lt[],int k,int i,char c) { 
 Type t = a; a = b; b = t; 
 printf("%c %4d%4d%4c%4c\t",c,k,i,lt[k],lt[i]); 
 printf("%10s%10s======\n",lt,&lt[k]); 
} 
template<class Type> 
inline void disp(Type lt[]) { 
 printf("===============>%s\n\n",lt); 
} 
template<class Type> 
void perm(Type list[], int k,int m) { 
 printf("=================================\n"); 
 if(k==m) { 
 swap(list[k],list[k],list,k,k,'='); 
 disp(list); 
 } 
 else { 
 for(int i=k;i<=m;i++) { 
 swap(list[k],list[i],list,k,i,'+'); 
 perm(list,k+1,m); 
 swap(list[k],list[i],list,k,i,'-'); 
 } 
 } 
} 
int main(int argc, char* argv[]) { 
 char ll[] = "abc"; 
 perm(ll,0,2); 
 system("pause"); 
 return 0; 
} 
