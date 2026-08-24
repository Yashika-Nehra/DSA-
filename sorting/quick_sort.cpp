# include <bits/stdc++.h>
using namespace std;

int part(vector<int>& arr, int l, int h)
{
    int pivot = arr[h];
    int i = l-1;

    for(int j=l; j<=h-1;j++)
    {
        if(pivot >= arr[j])
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}


void quickSort(vector<int>& arr, int l, int h)
{
    if(l<h)
    {
        int p = part(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}

int main()
{
    vector<int> arr = {1,3,4,7,9,8,2,3,5,6};
    int l = 0;
    int h = arr.size() - 1;

    quickSort(arr,l,h);

    for (int x : arr)
        cout << x << " ";

    cout<<endl;
    return 0;

}