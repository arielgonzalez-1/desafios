//https://stackoverflow.com/questions/31720408/how-to-make-quick-sort-recursive
#include <iostream>

using namespace std;
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    //taking the last element as pivot
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    const int N = 10;
    int arr[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        arr[i] = rand()%100 + 1;
        cout << arr[i] << " ";
    }
    cout << endl;

    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);

    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
