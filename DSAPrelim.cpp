#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <chrono>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
      
        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}

vector<int> countsort(vector<int>& arr) {
    int n = arr.size();

    // find the maximum element
    int maxval = 0;
    for (int i = 0; i < n; i++)
        maxval = max(maxval, arr[i]);

    // create and initialize count array
    vector<int> count(maxval + 1, 0);

    // count frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // compute prefix sum
    for (int i = 1; i <= maxval; i++)
        count[i] += count[i - 1];

    // build output array
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    return ans;
}

void insertionsort(vector<int>& arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {

        // Assume the current position holds
        // the minimum element
        int min_idx = i;

        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {

                // Update min_idx if a smaller
                // element is found
                min_idx = j; 
            }
        }

        // Move minimum element to its
        // correct position
        swap(arr[i], arr[min_idx]);
    }
}

int main() 
{
    // Test arrays for sorting algorithms
    vector<int> testArr = {25, 21, 45, 44, 30, 23, 50, 35, 56, 60};
    vector<int> largeArr, mediumArr;
    
    // Create medium size array (100 elements)
    for(int i = 0; i < 100; i++) {
        mediumArr.push_back(100 - i);
    }
    
    // Create large size array (1000 elements)
    for(int i = 0; i < 1000; i++) {
        largeArr.push_back(1000 - i);
    }
    
    cout << "========================================\n";
    cout << "SORTING ALGORITHMS TIME COMPLEXITY ANALYSIS\n";
    cout << "========================================\n\n";
    
    // Test with small array (10 elements)
    cout << "TEST 1: Small Array (10 elements)\n";
    cout << "Original: ";
    for(int x : testArr) cout << x << " ";
    cout << "\n\n";
    
    // 1. Bubble Sort (Small)
    vector<int> bubbleTest = testArr;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(bubbleTest);
    auto end = chrono::high_resolution_clock::now();
    auto bubbleSmall = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Bubble Sort Result: ";
    for(int x : bubbleTest) cout << x << " ";
    cout << "\nTime: " << bubbleSmall << " microseconds\n\n";
    
    // 2. Counting Sort (Small)
    vector<int> countTest = testArr;
    start = chrono::high_resolution_clock::now();
    vector<int> countResult = countsort(countTest);
    end = chrono::high_resolution_clock::now();
    auto countSmall = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Counting Sort Result: ";
    for(int x : countResult) cout << x << " ";
    cout << "\nTime: " << countSmall << " microseconds\n\n";
    
    // 3. Insertion Sort (Small)
    vector<int> insertTest = testArr;
    start = chrono::high_resolution_clock::now();
    insertionsort(insertTest, insertTest.size());
    end = chrono::high_resolution_clock::now();
    auto insertSmall = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Insertion Sort Result: ";
    for(int x : insertTest) cout << x << " ";
    cout << "\nTime: " << insertSmall << " microseconds\n\n";
    
    // 4. Selection Sort (Small)
    vector<int> selectionTest = testArr;
    start = chrono::high_resolution_clock::now();
    selectionSort(selectionTest);
    end = chrono::high_resolution_clock::now();
    auto selectionSmall = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Selection Sort Result: ";
    for(int x : selectionTest) cout << x << " ";
    cout << "\nTime: " << selectionSmall << " microseconds\n\n";
    
    // Test with medium array (100 elements)
    cout << "========================================\n";
    cout << "TEST 2: Medium Array (100 elements)\n";
    cout << "========================================\n\n";
    
    // 1. Bubble Sort (Medium)
    vector<int> bubbleMedium = mediumArr;
    start = chrono::high_resolution_clock::now();
    bubbleSort(bubbleMedium);
    end = chrono::high_resolution_clock::now();
    auto bubbleMed = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Bubble Sort Time: " << bubbleMed << " microseconds\n\n";
    
    // 2. Counting Sort (Medium)
    vector<int> countMedium = mediumArr;
    start = chrono::high_resolution_clock::now();
    vector<int> countMediumResult = countsort(countMedium);
    end = chrono::high_resolution_clock::now();
    auto countMed = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Counting Sort Time: " << countMed << " microseconds\n\n";
    
    // 3. Insertion Sort (Medium)
    vector<int> insertMedium = mediumArr;
    start = chrono::high_resolution_clock::now();
    insertionsort(insertMedium, insertMedium.size());
    end = chrono::high_resolution_clock::now();
    auto insertMed = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Insertion Sort Time: " << insertMed << " microseconds\n\n";
    
    // 4. Selection Sort (Medium)
    vector<int> selectionMedium = mediumArr;
    start = chrono::high_resolution_clock::now();
    selectionSort(selectionMedium);
    end = chrono::high_resolution_clock::now();
    auto selectionMed = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Selection Sort Time: " << selectionMed << " microseconds\n\n";
    
    // Test with large array (1000 elements)
    cout << "========================================\n";
    cout << "TEST 3: Large Array (1000 elements)\n";
    cout << "========================================\n\n";
    
    // 1. Bubble Sort (Large)
    vector<int> bubbleLarge = largeArr;
    start = chrono::high_resolution_clock::now();
    bubbleSort(bubbleLarge);
    end = chrono::high_resolution_clock::now();
    auto bubbleLg = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Bubble Sort Time: " << bubbleLg << " microseconds\n\n";
    
    // 2. Counting Sort (Large)
    vector<int> countLarge = largeArr;
    start = chrono::high_resolution_clock::now();
    vector<int> countLargeResult = countsort(countLarge);
    end = chrono::high_resolution_clock::now();
    auto countLg = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Counting Sort Time: " << countLg << " microseconds\n\n";
    
    // 3. Insertion Sort (Large)
    vector<int> insertLarge = largeArr;
    start = chrono::high_resolution_clock::now();
    insertionsort(insertLarge, insertLarge.size());
    end = chrono::high_resolution_clock::now();
    auto insertLg = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Insertion Sort Time: " << insertLg << " microseconds\n\n";
    
    // 4. Selection Sort (Large)
    vector<int> selectionLarge = largeArr;
    start = chrono::high_resolution_clock::now();
    selectionSort(selectionLarge);
    end = chrono::high_resolution_clock::now();
    auto selectionLg = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Selection Sort Time: " << selectionLg << " microseconds\n\n";
    
    // Summary and Analysis
    cout << "========================================\n";
    cout << "SUMMARY & TIME COMPLEXITY ANALYSIS\n";
    cout << "========================================\n\n";
    cout << "Small Array (10 elements):\n";
    cout << "  Bubble Sort:     " << bubbleSmall << " μs\n";
    cout << "  Counting Sort:   " << countSmall << " μs\n";
    cout << "  Insertion Sort:  " << insertSmall << " μs\n";
    cout << "  Selection Sort:  " << selectionSmall << " μs\n\n";
    
    cout << "Medium Array (100 elements):\n";
    cout << "  Bubble Sort:     " << bubbleMed << " μs\n";
    cout << "  Counting Sort:   " << countMed << " μs\n";
    cout << "  Insertion Sort:  " << insertMed << " μs\n";
    cout << "  Selection Sort:  " << selectionMed << " μs\n\n";
    
    cout << "Large Array (1000 elements):\n";
    cout << "  Bubble Sort:     " << bubbleLg << " μs\n";
    cout << "  Counting Sort:   " << countLg << " μs\n";
    cout << "  Insertion Sort:  " << insertLg << " μs\n";
    cout << "  Selection Sort:  " << selectionLg << " μs\n\n";
    
    cout << "========================================\n";
    cout << "CONCLUSION\n";
    cout << "========================================\n\n";
    cout << "Time Complexity Analysis:\n";
    cout << "  • Bubble Sort:    O(n²) - Slowest, especially with large data\n";
    cout << "  • Selection Sort: O(n²) - Similar to Bubble, consistent performance\n";
    cout << "  • Insertion Sort: O(n²) avg, but O(n) best case - Better for nearly sorted\n";
    cout << "  • Counting Sort:  O(n+k) - Fastest for small range of integers\n\n";
    cout << "RECOMMENDATION:\n";
    cout << "  → Counting Sort is the IDEAL algorithm for this dataset\n";
    cout << "     (integers with limited range, fastest execution time)\n";
    cout << "  → For general comparison-based sorting: Insertion Sort\n";
    cout << "     (better for nearly sorted data, simple implementation)\n\n";

    // ========== STACK AND QUEUE OPERATIONS ==========
    cout << "\n========================================\n";
    cout << "STACK AND QUEUE OPERATIONS\n";
    cout << "========================================\n\n";
    
    int arr[10] = {25, 21, 45, 44, 30, 23, 50, 35, 56, 60};
    stack<int> st;
    queue<int> q;
    int result[14] = {0};  // Array to hold popped elements, initialized to 0
    int index = 0;   // Index to track position in result array

    cout << "Unsorted Array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
        st.push(arr[i]);
        q.push(arr[i]);
    }

    cout << "\n\nStack Popping (3 at a time):\n";

    int stackPopped = 0;
    while (!st.empty() && stackPopped < 7) 
    {
        for (int i = 0; i < 3 && !st.empty() && stackPopped < 7; i++) 
        {
            cout << st.top() << " ";
            result[index++] = st.top();
            st.pop();
            stackPopped++;                   
        }                  
    }

    cout << "\n";

    cout << "Queue Popping (3 at a time):\n";
    int queuePopped = 0;
    while (!q.empty() && queuePopped < 7) 
    {
        for (int i = 0; i < 3 && !q.empty() && queuePopped < 7; i++) 
        {
            cout << q.front() << " "; 
            result[index++] = q.front();
            q.pop();
            queuePopped++;                   
        }                  
    }

    cout << "\n";

    cout << "\nData Merging / Combined Result:\n";
    for (int i = 0; i < index; i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}