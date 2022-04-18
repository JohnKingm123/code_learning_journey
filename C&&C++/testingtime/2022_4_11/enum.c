/*枚举类型*/
#include<stdio.h>
enum Day
{
    Mon=1,Tue,Wed,Thu,Fri,Sat,Sun
};//默认以 int ,unsigned int 类型分配

int main (){

    enum Day day;
    for(day = Mon;day<=Sun;day++){
    printf("%d\n",day);
    }
    
    return 0;
}