#include <iostream>
#include <vector>

using namespace std;

// Function to find the majority element in a subarray
int findMajorityElement(vector<int> &nums, int left, int right)
{
    if (left == right)
        return nums[left];

    // Divide the array into two halves
    int mid = left + (right - left) / 2;
    int leftMajority = findMajorityElement(nums, left, mid);
    int rightMajority = findMajorityElement(nums, mid + 1, right);

    // If both halves have the same majority element, return it
    if (leftMajority == rightMajority)
        return leftMajority;

    // Otherwise, count occurrences of both elements
    int leftCount = 0, rightCount = 0;
    for (int i = left; i <= right; ++i)
    {
        if (nums[i] == leftMajority)
            leftCount++;
        else if (nums[i] == rightMajority)
            rightCount++;
    }

    // Return the majority element
    return (leftCount > rightCount) ? leftMajority : rightMajority;
}

// Function to validate if the given element is a majority element
bool isMajorityElement(vector<int> &nums, int candidate)
{
    int count = 0;
    for (int num : nums)
    {
        if (num == candidate)
            count++;
    }
    return count > nums.size() / 2;
}

// Function to find the majority element
int majorityElement(vector<int> &nums)
{
    int candidate = findMajorityElement(nums, 0, nums.size() - 1);
    if (isMajorityElement(nums, candidate))
        return candidate;
    return -1; // If majority element doesn't exist
}

int main()
{
    vector<int> nums = {3, 2, 3, 1, 3, 4, 3, 8, 3};

    cout << "Given array: [";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    int majority = majorityElement(nums);

    if (majority != -1)
        cout << "Majority element: " << majority << " (appears " << (nums.size() / 2 + 1) << " times)" << endl;
    else
        cout << "No majority element found" << endl;

    return 0;
}

/*

Best Case: O(n log n) - When the majority element is the same in all the halves.

Average Case: O(n log n) - Same as the best case.

Worst Case: O(n log n) - This is the complexity of the divide-and-conquer algorithm.
However, the actual running time may vary depending on the distribution of the majority
element and the splits of the array.

*/