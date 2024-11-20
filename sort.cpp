#include <iostream>
#include <vector> 
#include <string>

using namespace std;

//Merge Sort Implementation
//Time Complexity: Nlog(N)

void merge(vector<int>& arr, int low, int mid, int high){ //merges two vectors together, sorting as they merge
    int lowN = mid - low + 1; //size of left and right vectors
    int highN = high - mid;

    int lInd = 0; //indices for left, right, and main vectors
    int rInd = 0;
    int aInd = low;

    vector<int> left(lowN), right(highN); //split arr into left and right vectors
    for(int i = 0; i < lowN; i++){
        left[i] = arr[low + i]; 
    }
    for(int i = 0; i < highN; i++){
        right[i] = arr[mid + i + 1];
    } 


    while (lInd < lowN && rInd < highN) { //picks the lower element between left and right arrays each iteration, merging into original array

        if (left[lInd] <= right[rInd]) {
            arr[aInd++] = left[lInd++];
        } else {
            arr[aInd++] = right[rInd++];
        }
    }

    while (lInd < lowN) { //adds remaining elements from left or right to original array
        arr[aInd++] = left[lInd++];
    }

    while (rInd < highN) {
        arr[aInd++] = right[rInd++];
    }
}

void mergeSort(vector<int>& arr, int low, int high){ //recursively mergesorts the array by splitting it in halves repeatedly
    if(low >= high){ //recursive base case
        return;
    }
    else{
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high); 
    }
}

vector<int> getInputVector() { //interface for gathering input vector elements
    vector<int> arr;
    string input;

    cout << "Enter numbers one by one and type 'done' when finished:\n";
    while (true) { //input numbers seperated by enters until user types 'done'
        cin >> input;
        
        if (input == "done") {
            break;
        }

        try {
            int num = stoi(input);  // Convert the string input to an integer
            arr.push_back(num);
        } catch (invalid_argument&) { //if any input other than a number or 'done' is entered, show error
            cout << "Invalid input. Please enter a valid number or type 'done' to finish.\n";
        }
    }

    return arr;
}

void sort(vector<int>& numbers){ //mergeSort wrapper function so it takes 1 input
    mergeSort(numbers, 0, numbers.size()-1);
}

double sortAndFindMedian(vector<int>& numbers){ //sorts an array and finds the median
    sort(numbers); //sorts vector
    int n = numbers.size();
    if(n % 2 == 0){
        return (static_cast<double>(numbers[n / 2 - 1]) + static_cast<double>(numbers[n / 2])) / 2.0; //median if n is even
    }
    else{
        return static_cast<double>(numbers[n / 2]); //median if n is odd
    }
    return 0;
}
int main(){
    vector<int> arr = getInputVector();
    int n = arr.size();
    if(n == 0){
        cout << "Input vector is empty.";
        return 0;
    }

    cout << "Input vector:\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    double median = sortAndFindMedian(arr);

    cout << "\nSorted vector: \n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "\nMedian: " << median;


    return 0;
}