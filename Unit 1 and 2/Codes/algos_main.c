#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"algos_header.h"

int main()
{	
	int *a,ch;
	int i,j;
	double t;
	clock_t begin,end;

	printf("1)Selection sort\t2)Bubble sort\t3)Quick sort\t4)Merge sort\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:

		for(i=100000;i<=1000000;i=i+50000)
		{
			a=(int*) malloc(i*sizeof(int));
			comp=0;
			for(j=0;j<i;j++)
				a[j]=rand();
			begin = clock();
			selection_sort(a,i);
			end = clock();
			t=(double)(end-begin) / CLOCKS_PER_SEC;
			printf("No. of element to element comparisons =  %ld\n",comp);
			printf("Execution time =  %f\n",t);
	
			FILE *fp1 = fopen("selectionsort_comp.txt","a");
			FILE *fp2 = fopen("selectionsort_exec.txt","a");
			fprintf(fp1,"\n%d,%ld",i,comp);
			fprintf(fp2,"\n%d,%f",i,t);	
			fclose(fp1);
			fclose(fp2);
			free(a);
		}
		break;

		case 2:

		for(i=100000;i<=1000000;i=i+50000)
		{
			a=(int*) malloc(i*sizeof(int));
			comp=0;
			for(j=0;j<i;j++)
				a[j]=rand();		
			begin = clock();
			bubble_sort(a,i);
			end = clock();
			t=(double)(end-begin) / CLOCKS_PER_SEC;
			printf("No. of element to element comparisons =  %ld\n",comp);
			printf("Execution time =  %f\n",t);
			FILE *fp1 = fopen("bubblesort_comp.txt","a");
			FILE *fp2 = fopen("bubblesort_exec.txt","a");
			fprintf(fp1,"\n%d,%ld",i,comp);
			fprintf(fp2,"\n%d,%f",i,t);	
			fclose(fp1);
			fclose(fp2);
			free(a);
		}	
		break;

		case 3:

		for(i=100000;i<=1000000;i=i+50000)
		{
			a=(int*) malloc(i*sizeof(int));
			comp=0;
			for(j=0;j<i;j++)
				a[j]=rand();
			begin = clock();
			quick_sort(a,0,i-1);
			end = clock();
			t=(double)(end-begin) / CLOCKS_PER_SEC;
			printf("No. of element to element comparisons =  %ld\n",comp);
			printf("Execution time =  %f\n",t);
			FILE *fp1 = fopen("quicksort_comp.txt","a");
			FILE *fp2 = fopen("quicksort_exec.txt","a");
			fprintf(fp1,"\n%d,%ld",i,comp);
			fprintf(fp2,"\n%d,%f",i,t);	
			fclose(fp1);
			fclose(fp2);
			free(a);
		}	
		break;

		case 4:

		for(i=100000;i<=1000000;i=i+50000)
		{
			a=(int*) malloc(i*sizeof(int));
			comp=0;
			for(j=0;j<i;j++)
				a[j]=rand();
			begin = clock();
			merge_sort(a,0,i-1);
			end = clock();
			t=(double)(end-begin) / CLOCKS_PER_SEC;
			printf("No. of element to element comparisons =  %ld\n",comp);
			printf("Execution time =  %f\n",t);
			FILE *fp1 = fopen("mergesort_comp.txt","a");
			FILE *fp2 = fopen("mergesort_exec.txt","a");
			fprintf(fp1,"\n%d,%ld",i,comp);
			fprintf(fp2,"\n%d,%f",i,t);	
			fclose(fp1);
			fclose(fp2);
			free(a);
		}	
		break;

		default:
		printf("Invalid option\n");

	}

	
}