#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

// ✅ Generate unique 8-digit IDs with prefix 220 (e.g. 220xxxxx)
vector<int> generateStudentIDs(int size) {
    vector<int> ids;
    unordered_set<int> usedIDs;

    while (ids.size() < size) {
        int suffix = rand() % 100000;       // Last 5 digits
        int id = 22000000 + suffix;         // Full 8-digit ID starting with 220

        if (usedIDs.find(id) == usedIDs.end()) {
            ids.push_back(id);
            usedIDs.insert(id);
        }
    }

    return ids;
}

// Linear Search
int linearSearch(const vector<int>& arr, int target, int& steps, bool verbose = true) {
    steps = 0;
    for (int i = 0; i < arr.size(); i++) {
        steps++;
        if (verbose)
            cout << "Linear Search: Checking index " << i << " → " << arr[i] << endl;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binarySearch(const vector<int>& arr, int target, int& steps, bool verbose = true) {
    int left = 0, right = arr.size() - 1;
    steps = 0;

    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        if (verbose)
            cout << "Binary Search: Checking index " << mid << " → " << arr[mid] << endl;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Print student IDs
void printIDs(const vector<int>& ids) {
    for (int id : ids) {
        cout << id << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));
    cout << "🔍  Welcome to FindMe – The Student ID Searcher 🔍\n";

    int n;
    cout << "\nEnter number of student IDs to generate (max 100000): ";
    cin >> n;

    if (n > 100000) {
        cout << "❌ Maximum number of unique student IDs with prefix '220' is 100000.\n";
        return 1;
    }

    vector<int> ids = generateStudentIDs(n);
    cout << "\nGenerated Student IDs:\n";
    printIDs(ids);

    string action;
    int searchID, choice;

    cout << "\nEnter the student ID to search: ";
    cin >> searchID;

    do {
        cout << "\nChoose Search Method:\n";
        cout << "1. Linear Search (unsorted data)\n";
        cout << "2. Binary Search (sorted data)\n";
        cout << "Enter choice (1 or 2): ";
        cin >> choice;

        int resultIndex = -1;
        int stepsVerbose = 0;
        int stepsTimed = 0;
        long long timeTaken = 0;

        if (choice == 1) {
            cout << "\n---- Performing Linear Search ----\n";
            resultIndex = linearSearch(ids, searchID, stepsVerbose, true);

            auto start = high_resolution_clock::now();
            linearSearch(ids, searchID, stepsTimed, false);
            auto stop = high_resolution_clock::now();
            timeTaken = duration_cast<microseconds>(stop - start).count();

        } else if (choice == 2) {
            cout << "\n[Sorting array before Binary Search...]\n";
            vector<int> sortedIDs = ids;
            sort(sortedIDs.begin(), sortedIDs.end());

            cout << "Sorted Student IDs:\n";
            printIDs(sortedIDs);

            cout << "\n---- Performing Binary Search ----\n";
            resultIndex = binarySearch(sortedIDs, searchID, stepsVerbose, true);

            auto start = high_resolution_clock::now();
            binarySearch(sortedIDs, searchID, stepsTimed, false);
            auto stop = high_resolution_clock::now();
            timeTaken = duration_cast<microseconds>(stop - start).count();

        } else {
            cout << "❌ Invalid choice!\n";
            continue;
        }

        cout << "\n======= Search Result =======\n";
        if (resultIndex != -1) {
            cout << "✅ Student ID " << searchID << " found at index " << resultIndex << endl;
        } else {
            cout << "❌ Student ID " << searchID << " not found." << endl;
        }
        cout << "Steps taken: " << stepsTimed << endl;
        cout << "Time taken: " << timeTaken << " microseconds\n";

        cout << "\nType 'X' to exit or 'C' to search again: ";
        cin >> action;

    } while (action != "X" && action != "x");

    cout << "\n👋 Thank you for using FindMe – Goodbye!\n";
    return 0;
}
