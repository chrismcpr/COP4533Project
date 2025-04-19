#include <iostream>
#include <vector>

using namespace std;

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

    vector<int> sort = {23, 8, 33, 90, 12, 4, 27, 9, 14};

    vector<int> sorted = MergeSort(sort);

    for (int i = 0; i < sort.size(); i++) {

        cout << sorted[i] << " ";

    }


    return 0;
}











