#include <iostream>
#include <vector>
#include <queue>
#include <stack> 
#include <chrono>
using namespace std;

void showqueue(queue<int> Queue1) {
    if (Queue1.empty()) {
        cout << "ERROR: Queue is empty!" << endl;
        return;
    }
    while (!Queue1.empty()) {
        cout << Queue1.front() << " ";
        Queue1.pop();
    }
}

void showstack(stack<int> Stack1) {
    if (Stack1.empty()) {
        cout << "ERROR: Stack is empty!" << endl;
        return;
    }
    while (!Stack1.empty()) {
        cout << Stack1.top() << " ";
        Stack1.pop();
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) {
        cout << "ERROR: Array is empty!" << endl;
        return;
    }
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
      

        if (!swapped)
            break;
    }
}

void chronos(){   priority_queue<string> pq;

            auto start = chrono::high_resolution_clock::now();

            for (int i = 0; i < 50000; i++) {
            pq.push("Task_" + to_string(i));
        }   

            auto end = chrono::high_resolution_clock::now();

            cout << "Insertion time (ns): "
            << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
            << endl;
    }

vector<int> countsort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) {
        cout << "ERROR: Array is empty!" << endl;
        return arr;
    }

    int maxval = 0;
    for (int i = 0; i < n; i++)
        maxval = max(maxval, arr[i]);

     vector<int> count(maxval + 1, 0);

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= maxval; i++)
        count[i] += count[i - 1];

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    return ans;
}

void merge(vector<int>& arr, int left, 
                     int mid, int right){
                         
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if (arr.size() == 0) {
        cout << "ERROR: Array is empty!" << endl;
        return;
    }
    
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void insertionsort(vector<int>& arr, int n) {
    if (n == 0) {
        cout << "ERROR: Array is empty!" << endl;
        return;
    }
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){

    vector<int> arr = {45, 28, 59, 31, 52, 22, 48, 35, 56, 27};
    int n = arr.size();
    cout << "Original array:"<< endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    
    stack<int> stackmerge;
    cout << "Stack after popping 3 elements: " << endl;
    for (int i = 0; i < arr.size(); i++)
        stackmerge.push(arr[i]);
        for (int i = 0; i < 3; i++) {
            if (!stackmerge.empty())
                stackmerge.pop();
            else
                cout << "ERROR: Cannot pop from empty stack!" << endl;
        }
    showstack (stackmerge);
    cout << endl;

    cout << "Queue after popping 3 elements: " << endl;
    queue<int> queuemerge;

    for (int i = 0; i < arr.size(); i++)
        queuemerge.push(arr[i]);
        for (int i = 0; i < 3; i++) {
            if (!queuemerge.empty())
                queuemerge.pop();
            else
                cout << "ERROR: Cannot pop from empty queue!" << endl;
        }
    showqueue (queuemerge);
    cout << endl;
    
    vector<int> datamerging;

        stack<int> tempstack = stackmerge;
        while (!tempstack.empty()) {
            datamerging.push_back(tempstack.top());
            tempstack.pop();
            }
            
        queue<int> tempQueue = queuemerge; 
        while (!tempQueue.empty()) {
            datamerging.push_back(tempQueue.front());
            tempQueue.pop();
       }

        if (datamerging.empty()) {
            cout << "ERROR: Merged data array is empty!" << endl;
        } else {
            cout << "merged data: " << endl;
            for (int i = 0; i < datamerging.size(); i++)
                cout << datamerging[i] << " ";
            cout << endl;
        }
       
        vector<pair<string, long long>> sortTimes;

        auto start1 = chrono::high_resolution_clock::now();
        countsort(datamerging);
        auto end1 = chrono::high_resolution_clock::now();
        long long countTime = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
        cout << "countsort output: ";
        for (int num : datamerging)
            cout << num << " ";
        cout << " | Time: " << countTime << " ns" << endl;
        sortTimes.push_back({"Countsort", countTime});
        cout << endl;

        auto start2 = chrono::high_resolution_clock::now();
        mergeSort(datamerging, 0, datamerging.size() - 1);
        auto end2 = chrono::high_resolution_clock::now();
        long long mergeTime = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
        cout << "mergesort output: ";
        for (int num : datamerging)
            cout << num << " ";
        cout << " | Time: " << mergeTime << " ns" << endl;
        sortTimes.push_back({"Mergesort", mergeTime});
        cout << endl;

        auto start3 = chrono::high_resolution_clock::now();
        bubbleSort(datamerging);
        auto end3 = chrono::high_resolution_clock::now();
        long long bubbleTime = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();
        cout << "bubblesort output: ";
        for (int num : datamerging)
            cout << num << " ";
        cout << " | Time: " << bubbleTime << " ns" << endl;
        sortTimes.push_back({"Bubblesort", bubbleTime});
        cout << endl;

        auto start4 = chrono::high_resolution_clock::now();
        insertionsort(datamerging, datamerging.size());
        auto end4 = chrono::high_resolution_clock::now();
        long long insertionTime = chrono::duration_cast<chrono::nanoseconds>(end4 - start4).count();
        cout << "insertionsort output: ";
        for (int num : datamerging)
            cout << num << " ";
        cout << " | Time: " << insertionTime << " ns" << endl;
        sortTimes.push_back({"Insertionsort", insertionTime});
        cout << endl;

        for (int i = 0; i < sortTimes.size() - 1; i++) {
            for (int j = 0; j < sortTimes.size() - i - 1; j++) {
                if (sortTimes[j].second > sortTimes[j + 1].second) {
                    pair<string, long long> temp = sortTimes[j];
                    sortTimes[j] = sortTimes[j + 1];
                    sortTimes[j + 1] = temp;
                }
            }
        }

        cout << "\n=== SPEED COMPARISON (Fastest to Slowest) ===" << endl;
        for (int i = 0; i < sortTimes.size(); i++) {
            cout << (i+1) << ". " << sortTimes[i].first << ": " << sortTimes[i].second << " ns" << endl;
        }
        cout << endl;
        cout << "Best prof = Daddy Umbay" << endl << "+5 po sir pls po" << endl;

    return 0;
}
    