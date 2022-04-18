#include<stdio.h>
#include<string.h>

union Data
{
    int i;
    float f;
    char str[20];
};//共构体，将一系列不同数据类型的成员储存在同一位置，但同时只能·有一个成员有值

int main (){
    union Data data;
    data.i =10;
    data.f =220.5;
    strcpy(data.str,"Helloworld!");
    
    printf("%d\n",data.i);
    printf("%f\n",data.f);
    printf("%s\n",data.str);
    
   /**
    * printf("%d %s %str\n",data.i,data.f,data.str);
    * 可以过编译，但是一次只能由一个成员有值，故卡死
    */
    
    
    
    
    
    return 0;
}
