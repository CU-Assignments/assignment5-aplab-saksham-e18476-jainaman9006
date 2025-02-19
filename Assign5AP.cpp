//Name:- Jain Aman
//UID:-22BCS14831
//Section:-637
//Group:-"B"


//Problem:-01
#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) {
            mid++;
        } 
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (0, 1, or 2): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sortColors(nums);

    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}




// Problem:-02

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Partition function for Quickselect
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];  // Choosing last element as pivot
    int i = left;
    
    for (int j = left; j < right; j++) {
        if (nums[j] >= pivot) { // Larger elements to the left
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]); // Place pivot in correct position
    return i;
}

// Quickselect function
int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left == right) return nums[left];

    int pivotIndex = partition(nums, left, right);

    if (pivotIndex == k) return nums[pivotIndex];   // Found kth largest
    else if (pivotIndex > k) return quickSelect(nums, left, pivotIndex - 1, k);
    else return quickSelect(nums, pivotIndex + 1, right, k);
}

// Function to find the kth largest element
int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k - 1);
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    cout << "Kth largest element: " << findKthLargest(nums, k) << endl;

    return 0;
}

