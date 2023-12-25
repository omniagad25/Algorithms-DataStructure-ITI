#include <iostream>

using namespace std;

void MergeSort(int arr[],int start,int end);
void Merge(int arr[],int start,int mid,int end);

int main()
{
    int size;
    cout << "Enter number of numbers : ";
    cin >> size;
    int *numbers = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter an integer number: ";
        cin >> numbers[i];
    }
    MergeSort(numbers, 0,size-1);
    cout << "The array elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }

    delete [] numbers;
    return 0;
}


void Merge(int arr[],int start,int mid,int end)
{
    int size1=mid-start+1;
    int size2=end-mid;
    int* A1=new int [size1];
    int* A2=new int[size2];
    int i,j;
    for(int i=0; i<size1; i++)
    {
        A1[i]=arr[start+i];
    }
    for(int j=0; j<size2; j++)
    {
        A2[j]=arr[mid+1+j];
    }
    i=j=0;
    int k=start;
    while((i<size1)&&(j<size2))
    {
        if(A1[i]<A2[j])
        {
            arr[k]=A1[i];
            i++;
        }
        else
        {
            arr[k]=A2[j];
            j++;
        }
        k++;
    }
    while (i<size1)
    {
        arr[k]=A1[i];
        k++;
        i++;
    }
    while (j<size2)
    {
        arr[k]=A2[j];
        k++;
        j++;
    }
}

void MergeSort(int arr[],int start,int end)
{
    if(start<end)
    {
        int mid=(start + end)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);
        Merge(arr,start,mid,end);
    }
}
