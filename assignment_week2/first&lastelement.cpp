#include <iostream>
#include <vector>
using namespace std;

int findLeftmostIndex(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int findRightmostIndex(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

vector<int> searchRange(const vector<int>& nums, int target) {
    vector<int> result(2, -1);
    result[0] = findLeftmostIndex(nums, target);
    if (result[0] != -1) {
        result[1] = findRightmostIndex(nums, target);
    }
    return result;
}

int main() {
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = searchRange(nums1, target1);
    cout << "[" << result1[0] << ", " << result1[1] << "]" << endl; // Output: [3, 4]

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = searchRange(nums2, target2);
    cout << "[" << result2[0] << ", " << result2[1] << "]" << endl; // Output: [-1, -1]

    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> result3 = searchRange(nums3, target3);
    cout << "[" << result3[0] << ", " << result3[1] << "]" << endl; // Output: [-1, -1]

    return 0;
}
