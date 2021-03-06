#include <iostream> 
#include <vector> 
using namespace std; 
class Solution { 
protected: 
 typedef vector<int> vint1; //相当于一维整数数组类型
 typedef vector<vint1> vint2; //相当于二维整数数组类型
 void disp1(vint1 v1) { //输出一维整数数组
 for(int i=0;i<v1.size();i++) printf("%5d",v1[i]); 
 puts(""); 
 } 
 
 void disp2(vint2 v2) { //输出二维整数数组
 for(int i=0;i<v2.size();i++) disp1(v2[i]); 
 } 
 
private: 
 int n,k; 
 vint2 ans; //组合的集合
 vint1 pth; //每次的搜索路径 即每一次的组合
 int _dep; //递归时控制输出左边界距离
 
 void blank(int dif=0) { printf("%*s",_dep*4+dif,""); } 
 
 void dispbt(int pos) { //输出回溯结果
 blank(10); 
 printf("满足时迭代：%2d，回溯。--->输出：",pos); 
 disp1(pth); 
 } 
 
 void dispush(int pos,int it) { 
 _dep++; blank(); 
 printf("PUSH 开始：%2d 迭代：%2d\n",pos,it); 
 } 
 void dispop(int pos,int it) { 
 blank(); _dep--; 
 printf("POP 开始：%2d 迭代：%2d\n\n",pos,it); 
 } 
public: 
 Solution(int nn,int kk):n(nn),k(kk),_dep(-1) {} 
 
 void backtrack(int pos) { 
 if(pth.size() == k) { 
 ans.push_back(pth); 
 dispbt(pos); 
 return; 
 } 
 
 for(int i=pos; i<=n; i++) { 
 dispush(pos,i); 
 pth.push_back(i); //保存当前路径，即组合
 backtrack(i+1); //递归
 pth.pop_back(); //剔除最后加入的元素
 dispop(pos,i); 
 } 
 } 
 void disp() { disp2(ans); } 
}; 
int main() { 
 system("chcp 65001"); 
 Solution sl(4,2); //求从 4 个数里面选 2 个数的组合
 sl.backtrack(1); //从第一个数开始作为递归的最初数
 sl.disp(); 
}

