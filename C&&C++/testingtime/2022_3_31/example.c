#include "stdlib.h" 
#include "stdio.h" 
class Jobtype{ 
public: 
 int key,index; 
 bool job; 
 int operator <=(Jobtype a) const { return(key<=a.key); } 
}; 
void BubbleSort(Jobtype *d,int n) { 
 int flag; 
 Jobtype temp; 
 for(int i=0;i<n;i++){ 
 flag = 0; 
 for(int j=n-1;j>i;j--){ 
 if(d[j]<=d[j-1]) { 
 Jobtype t = d[j]; 
 d[j] = d[j-1]; 
 d[j-1] = t; 
 flag = 1; 
 } 
 } 
 if(flag == 0){ break; } 
 } 
} 
int FlowShop(int n,int a[],int b[],int c[]) { 
 Jobtype *d = new Jobtype[n]; 
 for(int i=0; i<n; i++) { 
 d[i].key = a[i]>b[i]?b[i]:a[i]; //按 Johnson 法则取 b[i]或 a[i]值作为关键字
 d[i].job = a[i]<=b[i]; //符合 a[i]<b[i]的放入到 N1 子集标记为 true 
 d[i].index = i; 
 } 
 BubbleSort(d,n); //对数组 d 按关键字升序进行排序
 int j=0,k=n-1; 
 for(int i=0;i<n;i++) { 
 //将排过序的数组 d ，取其中作业序号属于 N1 的从前面进入
 if(d[i].job) c[j++]=d[i].index; 
 //属于 N2 的从后面进入，从而实现 N1 的非减序排序，N2 的非增序排序
 else c[k--] = d[i].index; 
 } 
 j = a[c[0]]; 
 k = j+b[c[0]]; 
 for(int i=1; i<n; i++) { 
 //M1 在执行 c[i]作业的同时，M2 在执行 c[i-1]号作业，
 //最短执行时间取决于 M1 与 M2 谁后执行完
 j += a[c[i]]; 
 //计算最优加工时间
 k = j<k?k+b[c[i]]:j+b[c[i]]; 
 } 
 delete d; 
 return k; 
} 
//--------------------------------------------------------------------------- 
const int N = 5; 
int main() { 
 int a[] = {2,4,3,6,1}; 
 int b[] = {5,2,3,1,7}; 
 int c[N]; 
 int minTime = FlowShop(N,a,b,c); 
 printf("作业在机器 1 上的运行时间为：\n"); 
 for(int i=0;i<N;i++) printf("%4d",a[i]); 
 printf("\n"); 
 printf("作业在机器 2 上的运行时间为：\n"); 
 for(int i=0;i<N;i++) printf("%4d",b[i]); 
 printf("\n"); 
 printf("完成作业的最短时间为：%4d\n",minTime); 
 printf("编号从 0 开始，作业调度的顺序为：\n"); 
 for(int i=0;i<N;i++) printf("%4d",c[i]); 
 printf("\n"); 
 system("pause"); 
 return 0; 
} 
//--------------------------------------------------------------------------- 