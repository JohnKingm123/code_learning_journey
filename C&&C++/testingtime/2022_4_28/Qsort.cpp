#include "stdlib.h" 
#include "stdio.h" 


int  cmprint( const void *a ,const void *b){
    int d = (*(int*)a-*(int*)b);
    return d;//升序排序
}


int  cmprchar( const void *a ,const void *b){
    int d = (*(char*)a-*(char*)b);
    return d;//升序排序
}

int  cmprp( const void *a ,const void *b){
    int d = (*(int**)a-*(int**)b);
    return d;//升序排序
}



       //对数组 d 按关键字升序进行排序
 
int main() { 
    system("chcp 65001");

int a[5]={1,6,3,7,5};
char c[5]={'a','s','l',';','k'};
int* p[5];

qsort(a,5,sizeof(int),cmprint); 
qsort(c,5,sizeof(char),cmprchar);
qsort(p,5,sizeof(int*),cmprp);


for(int i=0;i<5;i++){
    printf("%d ",a[i]);
}
putchar('\n');


for(int i=0;i<5;i++){
    printf("%c ",c[i]);
}
putchar('\n');

for(int i=0;i<5;i++){
    printf("%x ",p[i]);
}
putchar('\n');

return 0;
} 
//--------------------------------------------------------------------------- 
