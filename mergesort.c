#include <stdio.h>
#include <time.h>

int a[100];
int b[1000];
void merge(int,int,int);
void merge_sort(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low,mid,high);
	}
}

void merge(int low,int mid,int high)
{
	int h,i,j,b[50],k;
	h=low;
	i=low;
	j=mid+1;

	while((h<=mid)&&(j<=high))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}

	for(k=low;k<=high;k++) a[k]=b[k];
}
int main()
{
	int num=0,i=0;
	int number;
	scanf("%d",&number);

	while (i<number){
		scanf("%d",&a[i]);
		i++;
		num++;
	}

	merge_sort(1,num-1);

	for(i=0;i<num;i++){
		printf("%d\n",a[i]);
	}

//	printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

}

