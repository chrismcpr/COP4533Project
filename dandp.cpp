#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
using namespace std;


// Use -lpsapi in terminal when creating file Example: "g++ file.cpp -o name -lpsapi"
#ifdef _WIN32
#include <windows.h>
#include <psapi.h>

void peakMemoryUsage(){
    PROCESS_MEMORY_COUNTERS mem;
    GetProcessMemoryInfo(GetCurrentProcess(), &mem, sizeof(mem));
    SIZE_T peak = mem.PeakWorkingSetSize;
    cout << "Peak Memory Usage: " << peak / 1024 << "KB" << endl;
}
#else
// for linux and macOS users
#include <sys/resource.h>

void peakMemoryUsage(){
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    cout << "Peak Memory Usage: " << usage.ru_maxrss / 1024 << "KB" << endl;
}
#endif

vector<int> listGenerator(int size, int rangeMin = 0, int rangeMax = 100){
    vector<int> list;
    list.reserve(size);

    for (int i = 0; i < size; i++){
        int num = rangeMin + (rand() % (rangeMax - rangeMin + 1));
        list.push_back(num);
    }

    return list;
}

vector<int> Merge(vector<int> leftArray, vector<int> rightArray) {

    vector<int> sorted;

    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            sorted.push_back(leftArray[leftIndex]);
            leftIndex = leftIndex + 1;
        } else {
            sorted.push_back(rightArray[rightIndex]);
            rightIndex = rightIndex + 1;
        }
    }

    while (leftIndex < leftArray.size()) {
        sorted.push_back(leftArray[leftIndex]);
        leftIndex = leftIndex + 1;
    }
    while (rightIndex < rightArray.size()) {
        sorted.push_back(rightArray[rightIndex]);
        rightIndex = rightIndex + 1;
    }

    return sorted;


}

vector<int> MergeSort(vector<int> values) {

    if (values.size() <= 1) {
        return values;
    }

    int middle = (values.size() + 1) / 2;
    vector<int> left;
    vector<int> right;

    for (int i = 0; i < middle; i++) {
        left.push_back(values[i]);
    }

    for (int i = middle; i < values.size(); i++) {
        right.push_back(values[i]);
    }

    vector<int> leftHalf = MergeSort(left);
    vector<int> rightHalf = MergeSort(right);

    vector<int> result = Merge(leftHalf, rightHalf);

    return result;

    
}

int main () {

    vector<int> sort = listGenerator(100, 20000, 200000);

    auto start = chrono::high_resolution_clock::now();

    vector<int> sorted = MergeSort(sort);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    for (int i = 0; i < sort.size(); i++) {

        cout << sorted[i] << " ";

    }

    cout << "\n" << "Time: " << duration.count() << " seconds" << endl;

    peakMemoryUsage();


    return 0;
}











