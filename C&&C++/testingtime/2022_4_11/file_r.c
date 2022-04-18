#include <stdio.h>
int main(){
   FILE *fp = NULL;
   char buff[255];//缓冲区
 
   fp = fopen("./test.txt", "r");
   fscanf(fp, "%s", buff);//读至空格，回车，行末；游标不动
   printf("1: %s\n", buff );
 
   fgets(buff, 255, (FILE*)fp);//读至行末，游标定位至下一行
   printf("2: %s\n", buff );
   
   fgets(buff, 255, (FILE*)fp);//读至航母
   printf("3: %s\n", buff );
   fclose(fp);
 
}