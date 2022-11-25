#include <bits/stdc++.h>

class QuickSort{
    public:
    std::vector<int> &arr;
    int size;

    QuickSort(std::vector<int> &arr, int size): arr(arr), size(size){}

    void getArray() {
        for(int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    void getSize() {
        std::cout << size << std::endl;
    }

    void sort(int left, int right) {
        if(left < right) {
            int pivot = partition(left, right);
            partition(left, pivot-1);
            partition(pivot+1, right);
        }
        return;
    }

    int partition(int left, int right) {
        int waiter = left;
        for(int ptr = left; ptr < right; ++ptr) {
            if(arr[ptr] <= arr[right]) {
                std::swap(arr[ptr], arr[waiter++]);
            }
        }
        std::swap(arr[waiter], arr[right]);
        return waiter;
    }
};

int main() {
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    QuickSort *obj = new QuickSort(arr, n);
    obj->sort(0, n-1);
    obj->getArray();
    return 0;
}