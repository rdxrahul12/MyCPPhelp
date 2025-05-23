#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& arr) {
    int n = arr.size();
  for(int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    
}
}
int main ()
{
    vector<int> arr = {12, 11, 13, 5, 6};
    cout << "Given array: \n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << endl;
    selection_sort(arr);
    cout << "Sorted array: \n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}