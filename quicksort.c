#include<stdio.h>
void quicksort(int a[],int low,int high,int pivot);
int partition(int a[],int low,int high,int pivot);
int main()
{
	int n,a[10],i;
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the elements of array");
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	int pivot;
	printf("select pivot method:1-first element,2-second element,3-third element\n");
	scanf("%d",&pivot);
	quicksort(a,0,n-1,pivot);
	printf("sorted array");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
void quicksort(int a[],int low,int high,int pivot)
{
	if(low<high)
	{
		 int pi=partition(a,low,high,pivot);
		 quicksort(a,low,pi-1,pivot);
		 quicksort(a,pi+1,high,pivot);
	 }
}
 int partition(int a[],int low,int high,int pivot)
{
	 int i;
	 switch(pivot)
	 {
		        //first element as pivot
		 case 1:i=low;
		        break;
		        //middle element as pivot
		 case 2:i=low+(high-low)/2;
		        break;
		        //last element as pivot
		 case 3:i=high;
		        break;
		 default:printf("invalid pivotchoice");
		 return -1;
	 }
	 int t=a[i];
	     a[i]=a[high];
	     a[high]=t;
	     pivot=a[high];
	     i=low-1;
	 int j;
	 for(j=low;j<high;j++)
	 {
		 if(a[j]<pivot)
		 {
			 i++;
			 t=a[i];
			 a[i]=a[j];
			 a[j]=t;
		 }
	 }
	 t=a[i+1];
	 a[i+1]=a[high];
	 a[high]=t;
	 return i+1;
}

                      
		 
		 
		 
