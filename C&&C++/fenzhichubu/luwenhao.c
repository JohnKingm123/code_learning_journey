 #include<stdio.h>
 void print(int *a,int N){
 	int i;
 	for(i=1;i<=N;i++){
 		printf("%d",a[i]);
	 }
	 putchar('\n');
 }
 void fun(int *a,int N,int m){
 	int temp = 0;
 	int i;
 	if(m==N){
		temp=a[i];
 		a[i]=a[m];
 		a[m]=temp;


 		print(a,N);
	 }
	else{
 	  for(i=m;i<=N;i++){
 		temp=a[i];
 		a[i]=a[m];
 		a[m]=temp;
 		fun(a,N,m+1);
 		temp=a[i];
		a[i]=a[m];
		a[m]=temp;
	  }
    }
 }
  int main(){
 	int N;
 	int i,j;
 	scanf("%d",&N);
 	int a[99]={0};
 	for(i=1,j=N;i<=N;i++,j--){
 		a[i]=j;
	 }
	fun(a,N,1);
    getchar();
    getchar();
	return 0;
 }
