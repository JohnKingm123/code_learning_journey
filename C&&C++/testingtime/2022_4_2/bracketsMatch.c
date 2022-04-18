/*括号匹配（栈运用）*/
#include<stdio.h>
#include<stdlib.h>
#define N 65535
typedef struct stack
{
char sym[N];//栈容量
int top;//栈顶

}stack;

int push(stack *k,char n){
if(k->top==N-1){return 0;}//满栈
k->sym[++k->top]=n;

return 1;
}

int pop(stack *k){
if(k->top<=-1){return 0;}
k->top--;
return 1;
}

int inistack(stack *k){
k->top=-1;
return 1;    
}

char getStacktop(stack *k){
char c=k->sym[k->top];
return c;
}

int empt(stack *k){
if(k->top==-1){return 1;}
return 0;
}

int main (){

char string[N]={0};
char list[N]={0};
stack bracket;
stack *k=&bracket;
inistack(k);
scanf("%s",&string);


int i=0;
int j=0;
while(string[i]){
if(string[i]=='('||string[i]==')'||string[i]=='['||string[i]==']'||string[i]=='{'||string[i]=='}'){
  list[j]=string[i];
  i++;
  j++;
  continue;  
}
i++;
}//去除非括号序列


i=0;
while(list[i]){
if(list[i]=='('||list[i]=='['||list[i]=='{'){
push(k,list[i]);
i++;
}
else{
char pp;
pp=getStacktop(k);
    if((pp=='('&&list[i]==')')||(pp=='['&&list[i]==']')||(pp=='{'&&list[i]=='}')){
    pop(k);
    i++;
    }
    else{
    printf("-1");
    return -1;
    }
}
}

if(empt(k)){
    printf("1");
    return 1;
}
 
return -1;
}