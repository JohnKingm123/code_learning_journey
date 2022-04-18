#include<stdio.h>

int main (){

    FILE *fp =NULL;

    fp =fopen("./test.txt","w+");//linux文件路径逻辑同这里（废话linux内核就是C写的）
    fprintf(fp, "Hello_World\n");
    fputs("This is a little test\n",fp);
    fclose(fp);

    return 0;
}