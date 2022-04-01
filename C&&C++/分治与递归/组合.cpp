#include <iostream> 
#include <vector> 
using namespace std; 
class Solution { 
protected: 
 typedef vector<int> vint1; //�൱��һά������������
 typedef vector<vint1> vint2; //�൱�ڶ�ά������������
 void disp1(vint1 v1) { //���һά��������
 for(int i=0;i<v1.size();i++) printf("%5d",v1[i]); 
 puts(""); 
 } 
 
 void disp2(vint2 v2) { //�����ά��������
 for(int i=0;i<v2.size();i++) disp1(v2[i]); 
 } 
 
private: 
 int n,k; 
 vint2 ans; //��ϵļ���
 vint1 pth; //ÿ�ε�����·�� ��ÿһ�ε����
 int _dep; //�ݹ�ʱ���������߽����
 
 void blank(int dif=0) { printf("%*s",_dep*4+dif,""); } 
 
 void dispbt(int pos) { //������ݽ��
 blank(10); 
 printf("����ʱ������%2d�����ݡ�--->�����",pos); 
 disp1(pth); 
 } 
 
 void dispush(int pos,int it) { 
 _dep++; blank(); 
 printf("PUSH ��ʼ��%2d ������%2d\n",pos,it); 
 } 
 void dispop(int pos,int it) { 
 blank(); _dep--; 
 printf("POP ��ʼ��%2d ������%2d\n\n",pos,it); 
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
 pth.push_back(i); //���浱ǰ·���������
 backtrack(i+1); //�ݹ�
 pth.pop_back(); //�޳��������Ԫ��
 dispop(pos,i); 
 } 
 } 
 void disp() { disp2(ans); } 
}; 
int main() { 
 system("chcp 65001"); 
 Solution sl(4,2); //��� 4 ��������ѡ 2 ���������
 sl.backtrack(1); //�ӵ�һ������ʼ��Ϊ�ݹ�������
 sl.disp(); 
}

