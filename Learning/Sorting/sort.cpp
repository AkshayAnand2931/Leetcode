#include<vector>
#include<iostream>

using namespace std;

vector<int> selectionSort(vector<int> v) {
    int size = v.size();
    for(int i = 0; i < size - 1; i++) {
        int min_index = i;
        for(int j = i; j < size; j++) {
            if(v[j] < v[min_index]) {
                min_index = j;
            }
        }
        if(i != min_index) {
            swap(v[i], v[min_index]);
        }
    }
    return v;
}

vector<int> bubbleSort(vector<int> v) {
    int size = v.size();
    bool swaps = false;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swaps = true;
            }
        }
        if(swaps == false) {
            return v;
        }
    }
    return v;
}

vector<int> insertionSort(vector<int> v) {
    int size = v.size();
    for(int i = 1; i < size; i++) {
        int j = i - 1;
        int key = v[i];
        while(j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
            
        }
        v[j+1] = key;
    }
    return v;
}

void merge(vector<int> &v, int low, int mid, int high) {
    vector<int> temp;

    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high) {
        if(v[left] <= v[right]) {
            temp.push_back(v[left]);
            left++;
        }
        else {
            temp.push_back(v[right]);
            right++;
        }
    }
    while(left <= mid) {
        temp.push_back(v[left]);
        left++;
    } 
    while(right <= high) {
        temp.push_back(v[right]);
        right++;
    }

    for(int i = low; i <= high; i++) {
        v[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &v, int low, int high) {
    if(low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}

int partition(vector<int> &v, int low, int high) {
    int pivot = v[low];
    int i = low;
    int j = high;
    while(i < j) {
        while(v[i] <= pivot && i < high) {
            i++;
        }
        while(v[j] > pivot && j > low) {
            j--;
        }
        if(i < j) {
            swap(v[i], v[j]);
        }
    }
    swap(v[low], v[j]);
    return j;
}

void quickSort(vector<int> &v, int low, int high) {
    if(low < high) {
        int partitionIndex = partition(v, low, high);
        quickSort(v, low, partitionIndex - 1);
        quickSort(v, partitionIndex + 1, high);
    }
}

int main() {
    vector<int> v = {5, 4, 1, 10, 19, 4};
    // v = selectionSort(v);
    // v = bubbleSort(v);
    // v = insertionSort(v);
    // mergeSort(v, 0 , v.size() - 1);
    // quickSort(v, 0, v.size() - 1);
    for(auto it: v) {
        cout << it << endl;
    }
    return 0;
}