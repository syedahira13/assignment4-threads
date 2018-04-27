#include <iostream>
#include <string.h>
#include<pthread.h>
#include<stdlib.h>
int i;
int j;
using namespace std;
void* myFunc(void* arr)
{

   int *array=(int*) arr;
   int sum=0;
	for(i;i<j;i++)
{
		sum=sum+array[i];
}
return ( (void*) sum);
}


int main()
{
int arr[1000];
for(int k=0;k<1000;k++)
arr[k]=k;
int sumarr[10]={0};
int sum=0;
i=0;
j=100;
  pthread_t threads[10];
for(int k=0;k<10;k++)
{
  pthread_create(&threads[k], NULL, &myFunc, &arr);
 pthread_join(threads[k], (void**) &sumarr[k]);
	j=j+100;
}

  for(int k=0;k<10;k++)
	sum=sum+sumarr[k];
cout<<"SUM="<<sum<<endl;
}

