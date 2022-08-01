#include <iostream> 
#include"stdlib.h"
using namespace std; 
//--------------------------------------------------------------------------- 
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
template<class T> 
struct BTNode { 
 T data; 
 BTNode<T> *lChild,*rChild; 
 BTNode() { lChild=rChild=NULL; } 
 BTNode(const T &val,BTNode<T> *Childl=NULL,BTNode<T> *Childr=NULL) { 
 data=val; 
 lChild=Childl; 
 rChild=Childr; 
 } 
 BTNode<T>* CopyTree() { 
 BTNode<T> *nl,*nr,*nn; 
 if(&data==NULL) 
 return NULL; 
 nl=lChild->CopyTree(); 
 nr=rChild->CopyTree(); 
 nn=new BTNode<T>(data,nl,nr); 
 return nn; 
 } 
}; 
//--------------------------------------------------------------------------- 
template<class T> 
class BinaryTree { 
private: 
 void Destroy(BTNode<T> *&r); 
 void PreOrder(BTNode<T> *r); 
 void InOrder(BTNode<T> *r); 
 void PostOrder(BTNode<T> *r); 
 int Height(const BTNode<T> *r)const; 
 int NodeCount(const BTNode<T> *r)const; 
public: 
 BTNode<T> *root; 
 BinaryTree(); 
 ~BinaryTree(); 
 void Pre_Order(); 
 void In_Order(); 
 void Post_Order(); 
 int TreeHeight()const; 
 int TreeNodeCount()const; 
 void DestroyTree(); 
 void MakeTree(T pData,BinaryTree<T> leftTree,BinaryTree<T> rightTree); 
 void Change(BTNode<T> *r); 
}; 
 
template<class T> 
BinaryTree<T>::BinaryTree() { 
 root=NULL; 
} 
template<class T> 
BinaryTree<T>::~BinaryTree() {} 
template<class T> 
void BinaryTree<T>::Pre_Order() { 
 PreOrder(root); 

} 
template<class T> 
void BinaryTree<T>::In_Order() { 
 InOrder(root); 
} 
template<class T> 
void BinaryTree<T>::Post_Order() { 
 PostOrder(root); 
} 
 
template<class T> 
int BinaryTree<T>::TreeHeight()const { 
 return Height(root); 
} 
template<class T> 
int BinaryTree<T>::TreeNodeCount()const { 
 return NodeCount(root); 
} 
template<class T> 
void BinaryTree<T>::DestroyTree() { 
 Destroy(root); 
} 
template<class T> 
void BinaryTree<T>::PreOrder(BTNode<T> *r) { 
 if(r!=NULL) { 
 cout<<r->data<<' '; 
 PreOrder(r->lChild); 
 PreOrder(r->rChild); 
 } 
} 
template<class T> 
void BinaryTree<T>::InOrder(BTNode<T> *r) { 
 if(r!=NULL) { 
 InOrder(r->lChild); 
 cout<<r->data<<' '; 
 InOrder(r->rChild); 
 } 
} 
 
template<class T> 
void BinaryTree<T>::PostOrder(BTNode<T> *r) { 
 if(r!=NULL) { 
 PostOrder(r->lChild); 
 PostOrder(r->rChild); 
 cout<<r->data<<' '; 
 } 
} 
 
template<class T> 
int BinaryTree<T>::NodeCount(const BTNode<T> *r)const { 
 if(r==NULL) return 0; 
 else return 1+NodeCount(r->lChild)+NodeCount(r->rChild); 
} 
 
template<class T> 
int BinaryTree<T>::Height(const BTNode<T> *r)const { 
 if(r==NULL) return 0; 
 else { 
 int lh,rh; 
 lh=Height(r->lChild); 
 rh=Height(r->rChild); 
 return 1+(lh>rh?lh:rh); 
 } 
} 
 
template<class T> 
void BinaryTree<T>::Destroy(BTNode<T> *&r) { 
 if(r!=NULL) { 
 Destroy(r->lChild); 
 Destroy(r->rChild); 
 delete r; 
 r=NULL; 
 } 
} 
template<class T> //将二叉树 bt 所有结点的左右子树交换
void BinaryTree<T>::Change(BTNode<T> *r) { 
 BTNode<T> *p; 
 if(r) { 
 p=r->lChild; 
 r->lChild=r->rChild; 
 r->rChild=p; //左右子女交换
 Change(r->lChild); //交换左子树上所有结点的左右子树
 Change(r->rChild); //交换右子树上所有结点的左右子树
 } 
} 
 
template<class T> 
void BinaryTree<T>::MakeTree(T pData,BinaryTree<T> leftTree,BinaryTree<T> rightTree) { 
 root = new BTNode<T>(); 
 root->data = pData; 
 root->lChild = leftTree.root; 
 root->rChild = rightTree.root; 
} 
//--------------------------------------------------------------------------- 
template<class Type> 
class Huffman { 
 friend BinaryTree<int> HuffmanTree(Type[],int); 
 public: 
 operator Type() const { return weight; } 
 BinaryTree<int> tree; 
 Type weight; 
}; 
template<class Type> 
BinaryTree<int> HuffmanTree(Type f[],int n) { 
 //生成单节点树
 Huffman<Type> *w = new Huffman<Type>[n+1]; 
 BinaryTree<int> z,zero; 
 for(int i=1; i<=n; i++) { 
 z.MakeTree(i,zero,zero); 
 w[i].weight = f[i]; 
 w[i].tree = z; 
 } 
 //建优先队列
 MinHeap<Huffman<Type> > Q(n); 
 for(int i=1; i<=n; i++) Q.Insert(w[i]); 
 //反复合并最小频率树
 Huffman<Type> x,y; 
 for(int i=1; i<n; i++) { 
 x = Q.RemoveMin(); 
 y = Q.RemoveMin(); 
 z.MakeTree(0,x.tree,y.tree); 
 x.weight += y.weight; 
 x.tree = z; 
 Q.Insert(x); 
 } 
 x = Q.RemoveMin(); 
 delete[] w; 
 return x.tree; 
} 
//--------------------------------------------------------------------------- 
int main() { 
    system("chcp 65001");
     const int N = 4; 
 char c[] = {'0','j','i','n','m'}; 
 int f[] = {0,10,18,28,13}; //下标从 1 开始
 BinaryTree<int> t = HuffmanTree(f,N); 
 cout<<"各字符出现的对应频率分别为："<<endl; 
 for(int i=1; i<=N; i++) cout<<c[i]<<":"<<f[i]<<" "; 
 cout<<endl; 
 cout<<"生成二叉树的前序遍历结果为："<<endl; 
 t.Pre_Order(); 
 cout<<endl; 
 cout<<"生成二叉树的中序遍历结果为："<<endl;  
 t.In_Order(); 
 cout<<endl; 
 t.DestroyTree(); 
 system("pause"); 
 return 0; 
} 
//--------------------------------------------------------------------------- 