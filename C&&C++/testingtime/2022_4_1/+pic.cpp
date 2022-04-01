#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void estab(char **pic,int n,int nx,int ny){

int len=(int)pow(2,n-2);

pic[nx][ny]='+';//确立中心

for(int i=nx-2*len+1;i<nx+2*len;i++)
{
if(pic[i][ny]=='O'){pic[i][ny]='|';}//初始化的妙用
}
for(int i=ny-2*len+1;i<ny+2*len;i++)
{
if(pic[nx][i]=='O'){pic[nx][i]='-';}
}//纵横延伸

if(n==1){return;}


estab(pic,n-1,nx-len,ny-len);//左上
estab(pic,n-1,nx+len,ny-len);//右上
estab(pic,n-1,nx-len,ny+len);//左下
estab(pic,n-1,nx+len,ny+len);//右下

return ;
}//解决方法

void display(char **pic,int m){

for(int i=1;i<m;i++){
    for(int j=1;j<m;j++){
        printf("%c",pic[i][j]);
    }
putchar('\n');
}
}//打印

void ini(char **pic,int m){
    
for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
        pic[i][j]='O';
    }
}
}//初始化，后面有大用







/*主函数*/
int main(){
int n;//棋盘幂
scanf("%d",&n);
int m=(int)pow(2,n);
int nx=m/2;
int ny=m/2;

char **pic;
pic = (char**)malloc(sizeof(char*)*m);

for(int i=0;i<m;i++){
pic[i]=(char*)malloc(sizeof(char)*m);
}

//----------------------------------动态申请二维数组，实际使用[1,15]
ini(pic,m);//初始化
estab(pic,n,nx,ny);//传入大图规模和中心点
display(pic,m);//打印
//-----------------------------------
for(int i=0;i<m;i++){
free(pic[i]);
}
free(pic);//释放内存
system("pause");
return 0;
}