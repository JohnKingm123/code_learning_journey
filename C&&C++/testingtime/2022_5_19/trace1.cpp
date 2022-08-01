#include <iostream> 
#include"stdlib.h"
using namespace std; 
template<class Typew,class Typep> 
class Knap { 
public: 
 Typep Bound(int i); 
 void Backtrack(int i); 
 Typew c; //背包容量
 int n; //物品数
 Typew *w; //物品重量数组
 Typep *p; //物品价值数组
 Typew cw; //当前重量
 Typep cp; //当前价值
 Typep bestp;//当前最优价值
}; 
template <class Type> 
inline void Swap(Type &a,Type &b) { 
 Type temp = a; 
 a = b; 
 b = temp; 
} 
template<class Type> 
void BubbleSort(Type a[],int n) { 
 //记录一次遍历中是否有元素的交换
 bool exchange; 
 for(int i=0; i<n-1;i++) { 
 exchange = false ; 
 for(int j=i+1; j<=n-1; j++) { 
 if(a[j]<=a[j-1]) { 
 Swap(a[j],a[j-1]); 
 exchange = true; 
 } 
 } 
 //如果这次遍历没有元素的交换,那么排序结束
 if(false == exchange) break ; 
 } 
} 
template<class Typew,class Typep> 
void Knap<Typew,Typep>::Backtrack(int i) { 
 if(i>n) {//到达叶子节点
 bestp = cp; 
 return; 
 } 
 if(cw + w[i] <= c) {//进入左子树
 cw += w[i]; 
 cp += p[i]; 
 Backtrack(i+1); 
 cw -= w[i]; 
 cp -= p[i]; 
 } 
 if(Bound(i+1)>bestp) {//进入右子树
 Backtrack(i+1); 
 } 
} 
template<class Typew, class Typep> 
Typep Knap<Typew, Typep>::Bound(int i) {// 计算上界
 Typew cleft = c - cw; // 剩余容量
 Typep b = cp; 
 // 以物品单位重量价值递减序装入物品
 while (i <= n && w[i] <= cleft) { 
 cleft -= w[i]; 
 b += p[i]; 
 i++; 
 } 
 //装满背包
 if (i <= n) b += p[i]/w[i] * cleft; 
 return b; 
} 
class Object { 
template<class Typew,class Typep> 
friend Typep Knapsack(Typep[],Typew [],Typew,int); 
public: 
 int operator <= (Object a)const { 
 return (d>=a.d); 
 } 
private: 
 int ID; 
 float d; 
}; 
template<class Typew,class Typep> 
Typep Knapsack(Typep p[],Typew w[],Typew c,int n) { 
 //为 Knap::Backtrack 初始化
 Typew W = 0; 
 Typep P = 0; 
 Object *Q = new Object[n]; 
 for(int i=1; i<=n; i++) { 
 Q[i-1].ID = i; 
 Q[i-1].d = 1.0 * p[i]/w[i]; 
 P += p[i]; 
 W += w[i]; 
 } 
 if(W <= c) {//装入所有物品
 return P; 
 } 
 //依物品单位重量价值排序
 BubbleSort(Q,n); 
 Knap<Typew,Typep> K; 
 K.p = new Typep[n+1]; 
 K.w = new Typew[n+1]; 
 for(int i=1; i<=n; i++) { 
 K.p[i] = p[Q[i-1].ID]; 
 K.w[i] = w[Q[i-1].ID]; 
 } 
 K.cp = 0; 
 K.cw = 0; 
 K.c = c; 
 K.n = n; 
 K.bestp = 0; 
 //回溯搜索
 K.Backtrack(1); 
 delete []Q; 
 delete []K.w; 
 delete []K.p; 
 return K.bestp; 
} 
int main() { 
    system("chcp 65001");
 int n = 5;//物品数
 int c = 10;//背包容量
 int p[] = {0,6,3,5,4,6};//物品价值 下标从 1 开始
 int w[] = {0,2,2,6,5,4};//物品重量 下标从 1 开始
 cout<<"背包容量为："<<c<<endl; 
 cout<<"物品重量和价值分别为："<<endl; 
 for(int i=1; i<=n; i++) cout<<"("<<w[i]<<","<<p[i]<<") "; 
 cout<<endl; 
 cout<<"背包能装下的最大价值为："<<Knapsack(p,w,c,n)<<endl; 
 system("pause"); 
 return 0; 
} 