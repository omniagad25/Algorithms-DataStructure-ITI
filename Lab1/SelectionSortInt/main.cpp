/*#include <iostream>

using namespace std;

void swapReference(int &x, int &y);


int main()
{
    int n;
    printf("Please enter the size of array you want to sort: \n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Please enter the element number %d: ",i+1);
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swapReference(arr[i], arr[minIndex]);

    }
    for(int i=0;i<n;i++){
        printf("After being sorted, element number %d is %d\n", i+1, arr[i]);
    }
    return 0;
}

void swapReference(int &x,int &y){
    int temp;
    temp = x;
    x=y;
    y=temp;
}



*/

#include <iostream>
#include <string>
using namespace std;

void swapReference(int &x,int &y);

void selectionSort(int arr[], int n);

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
    selectionSort(numbers, size);
        cout << "The array elements are: ";
        for (int i = 0; i < size; i++)
        {
            cout << numbers[i] << " ";
        }

        delete [] numbers;
        return 0;

}


void swapReference(int &x,int &y){
    int temp;
    temp = x;
    x=y;
    y=temp;
}

void selectionSort(int arr[], int n)
{
    int min_idx;
    for (int i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swapReference(arr[min_idx], arr[i]);
    }
}
