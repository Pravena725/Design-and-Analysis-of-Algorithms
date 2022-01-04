#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"algos_header.h"

void selection_sort(int *a, int n)
{
	int i,j,min_pos,temp;
	for(i=0;i<n-1;i++)
	{
		min_pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min_pos])
				min_pos=j;
			comp++;
		}
		temp=a[i];
		a[i]=a[min_pos];
		a[min_pos]=temp;
		
	}
}

void bubble_sort(int *a, int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			comp++;
		}		
	}
}

int quicksort_partition(int *a,int low,int high)
{
	int piv,i,j,temp;
	piv=a[low];
	i=low;
	j=high+1;
	while(i<j)
	{
		i+=1;
		j-=1;
		while(i<=high && a[i]<piv)
		{
			i+=1;
			comp++;
		}
		while(a[j]>piv)
		{
			j-=1; 
			comp++;
		}
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}	
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;

	temp=a[low];
	a[low]=a[j];
	a[j]=temp;	
	
	return j;
}		
void quick_sort(int *a,int low,int high)
{
	int j;
	if(low<high)
	{
		j=quicksort_partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);
	}
}

void merge(int *a, int low, int mid, int high)
{
	int *b = (int*)malloc(sizeof(int)*(high+1));
	int i,j,k;
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		comp++;
		k++;
	}
	while(i<=mid)
	{
		b[k]=a[i];
		k++;
		i++;
	}
	while(j<=high)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=low;i<=high;i++)
		a[i]=b[i];
	free(b);
}
void merge_sort(int *a, int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

