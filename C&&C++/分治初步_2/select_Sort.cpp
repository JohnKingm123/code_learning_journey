#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<iostream>
using namespace std;

template <typename T> void swap(T *a,T *b)
{
T t;
t=*a;
*a=*b;
*b=t;
}//交换函数

template <typename T> void sel_Sort(T a[],int size)
{
int k=0;
	
for(int i=0;i<size-1;i++)
{	k=i;
	for(int j=i+1;j<size;j++)
	{	
		if(a[k]>a[j])	//此处可改为<变降序排序
		{
		k=j;
		}
	}
swap(&a[k],&a[i]);

}


}//选择法升序序排序

template <typename T> void dip(T a[],int size)
{
	for(int i=0;i<size;i++)
	{
	cout <<a[i];
	cout <<' ';
	}
	cout <<'\n';	//我不知道c语言怎么模板打印，这里直接用c++的打印方式
}

int main(int argc, char *argv[])
{
//int a=1;
//int b=2;
//swap(&a,&b);
//printf("%d %d",a,b);
char a[10]={'a','d','f','A','d','d','G','Y','p','a'};
int b[10]={12,23,12,9,32,45,43,6,45,68};
sel_Sort(a,10);
dip(a,10);
sel_Sort(b,10);
dip(b,10);//数据可改
float c[10]={1.2123f,3.412312f,5.2123f,4.0123f,45.0321f,43.3123f,12.2432f,32.3412f,2.3212f,1.23421f};
sel_Sort(c,10);

for(int i=0;i<10;i++)
{
printf("%4.4f ",c[i]);
}
cout <<'\n';
int *d[10];
sel_Sort(d,10);
for(int i=0;i<10;i++)
{
printf("%d ",d[i]);
}
cout <<'\n';
return 0;
}