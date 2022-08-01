#include <iostream> 
#include"stdlib.h"
using namespace std; 
template<class T> 
class MinHeap { 
private: 
 T *heap; //元素数组，0 号位置也储存元素
 int CurrentSize; //目前元素个数
 int MaxSize; //可容纳的最多元素个数
 //自上往下调整，使关键字小的节点在上
 void FilterDown(const int start,const int end); 
 void FilterUp(int start); //自下往上调整
public: 
 MinHeap(int n=1000); 
 ~MinHeap(); 
 bool Insert(const T &x); //插入元素
 T RemoveMin(); //删除最小元素
 T GetMin(); //取最小元素
 bool IsEmpty() const; 
 bool IsFull() const; 
 void Clear(); 
}; 
 
template<class T> 
MinHeap<T>::MinHeap(int n) { 
 MaxSize=n; 
 heap=new T[MaxSize]; 
 CurrentSize=0; 
} 
template<class T> 
MinHeap<T>::~MinHeap() { 
 delete []heap; 
} 
template<class T> 
void MinHeap<T>::FilterUp(int start) { //自下往上调整
 int j=start,i=(j-1)/2; //i 指向 j 的双亲节点
 T temp=heap[j]; 
 while(j>0) { 
 if(heap[i]<=temp) break; 
 else { 
 heap[j]=heap[i]; 
 j=i; 
 i=(i-1)/2; 
 } 
 } 
 heap[j]=temp; 
} 
template<class T> //自上往下调整，使关键字小的节点在上
void MinHeap<T>::FilterDown(const int start,const int end) { 
 int i=start,j=2*i+1; 
 T temp=heap[i]; 
 while(j<=end) { 
 if( (j<end) && (heap[j]>heap[j+1]) ) j++; 
 if(temp<=heap[j]) break; 
 else { 
 heap[i]=heap[j]; 
 i=j; 
 j=2*j+1; 
 } 
 } 
 heap[i]=temp; 
} 
template<class T> 
bool MinHeap<T>::Insert(const T &x) { 
 if(CurrentSize==MaxSize) return false; 
 heap[CurrentSize]=x; 
 FilterUp(CurrentSize); 
 CurrentSize++; 
 return true; 
} 
template<class T> 
T MinHeap<T>::RemoveMin( ) { 
 T x=heap[0]; 
 heap[0]=heap[CurrentSize-1]; 
 CurrentSize--; 
 FilterDown(0,CurrentSize-1); //调整新的根节点
 return x; 
} 
template<class T> 
T MinHeap<T>::GetMin() { 
 return heap[0]; 
} 
template<class T> 
bool MinHeap<T>::IsEmpty() const { 
 return CurrentSize==0; 
} 
template<class T> 
bool MinHeap<T>::IsFull() const { 
 return CurrentSize==MaxSize; 
} 
template<class T> 
void MinHeap<T>::Clear() { 
 CurrentSize=0; 
} 
//--------------------------------------------------------------------------- 
class UnionFind { 
public: 
 UnionFind(int); 
 ~UnionFind(); 
public: 
 int Find(int); 
 void Union(int, int); 
private: 
 int EleNum; 
 int *Parents; 
 int *Rank; 
}; 
UnionFind::UnionFind(int n) { 
 EleNum = n; 
 Parents = new int[EleNum]; 
 Rank = new int[EleNum]; 
 for(int i = 0; i < EleNum; i++) { 
 Parents[i] = -1; 
 Rank[i] = 1; 
 } 
} 
UnionFind::~UnionFind() { 
 delete[] Parents; 
 delete[] Rank; 
} 
int UnionFind::Find(int i) { 
 int r = i; 
 while(Parents[r] != -1) r = Parents[r]; 
 while(r != i) { 
 int q = Parents[i]; 
 Parents[i] = r; 
 i = q; 
 } 
 return r; 
} 
void UnionFind::Union(int i, int j) { 
 int a = Find(i); 
 int b = Find(j); 
 if(a == b) return; 
 if(Rank[a] > Rank[b]) { 
 Parents[b] = a; 
 Rank[a] += Rank[b]; 
 } 
 else { 
 Parents[a] = b; 
 Rank[b] += Rank[a]; 
 } 
} 
//--------------------------------------------------------------------------- 
const int N = 12; //图的边数
const int M = 7; //图的顶点数
//--------------------------------------------------------------------------- 
template <class Type> 
class EdgeNode { 
 friend ostream& operator <<(ostream&,EdgeNode<Type>); 
public: 
 operator Type() const { return weight; } 
 int u; 
 Type weight; 
 int v; 
}; 
//--------------------------------------------------------------------------- 
template <class Type> 
bool Kruskal(int n,int e,EdgeNode<Type> E[],EdgeNode<Type> t[]) { 
 MinHeap<EdgeNode<Type> > H(e); 
 //初始化最小堆
 for(int i=1; i<=e; i++) H.Insert(E[i]); 
 UnionFind U(n); 
 int k = 1; 
 while(e && k<n-1) { 
 EdgeNode<int> x; 
 x = H.RemoveMin(); 
 e--; 
 //返回 u 中包含顶点 V 的连通分支的名字
 int a = U.Find(x.u); 
 int b = U.Find(x.v); 
 if(a!=b) { 
 t[k++] = x; 
 U.Union(a,b); 
 } 
 } 
 return (k==n-1); 
} 
//--------------------------------------------------------------------------- 
int main() 
{ 
system("chcp 65001");

 EdgeNode<int> t[N+1]; 
 //存储连通带权图所有边的两端顶点，权) 
 EdgeNode<int> E[N+1] = { {0,0,0}, 
 {1,23,2}, {1,28,6}, 
 {1,36,7}, {2,20,3}, 
 {2,1,7}, {3,4,7}, 
 {3,15,4}, {4,9,7}, 
 {4,3,5}, {5,16,7},
 {5,17,6},{6,25,7}
 }; 
 cout<<"连通带权图所有边的两端顶点，权分别为："<<endl; 
 for(int i=1; i<=N; i++) { 
 cout<<"u:"<<E[i].u<<",weight:"<<E[i].weight<<",v:"<<E[i].v; 
 cout<<endl; 
 } 
 if(Kruskal(M+1,N,E,t)) { 
 cout<<"Kruskal 算法最小生成树选择结果为:"<<endl; 
 for(int i=1; i<M; i++) { 
 cout<<"u:"<<t[i].u<<",weight:"<<t[i].weight<<",v:"<<t[i].v; 
 cout<<endl; 
 } 
 } 
 system("pause"); 
 return 0; 
} 
//---------------------------------------------------------------------------