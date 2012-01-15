

/*
 * Name :sharad Dixit
 * Institute :IIIT -A
 */


#include <stdio.h>

void heapify( int arr[],int bound)
{
	int root;
	int lchild;
	int mchild;
	int rchild;
	int i;
	int temp;

	for ( i = bound/2;i >=1;i--){

//		root=a[i];
		lchild=2*i;
		rchild=2*i+1;
		if ( lchild  <= bound && rchild<=bound) {

			if(arr[rchild] >= arr[lchild])
				mchild = rchild;
			else
				mchild = lchild;
		}


		else{
			mchild= lchild;
		}

//printf("value of arr[mchild] %d",arr[mchild]);


//printf("value of arr[i] %d",arr[i]);

		if (arr[i] < arr[mchild])
		{
			temp = arr[i];
			arr[i] = arr[mchild];
			arr[mchild] = temp;
		}

	}

	temp = arr[1];
	arr[1] = arr[bound];
	arr[bound] = temp;
	return;
}



int main()
{
	int a [100];
	int i=1,j;
	int number;

	scanf("%d",&number);

	while ( i <= number){ 
		scanf("%d",&a[i]);
		i++;
	}

	for ( j = 0; j < number; j++) {
		heapify( a, number-j  );
	}


	for ( j = 1; j <=number; j++) {
		printf("---->%d\n",a[j]);
	}
}
