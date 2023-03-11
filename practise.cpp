#include <iostream>
#include <vector>
using namespace std;

int num_subarrays_less_than_k(vector<int>& arr, int k) {
    int count = 0;
    int left = 0;
    int subarray_sum = 0;
    vector<int> prefix_sum(arr.size() + 1);
    for (int i = 1; i < prefix_sum.size(); i++) {
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
    }
    for (int right = 0; right < arr.size(); right++) {
        subarray_sum += arr[right];
        while (subarray_sum >= k) {
            subarray_sum -= arr[left];
            left++;
        }
        count += right - left + 1;
    }
    return count;
}

int main() {
    vector<int> arr = {3, -2, 4, -1, 2, -7, 5, -3, 6};
    int k = 4;
    int result = num_subarrays_less_than_k(arr, k);
    cout << "Number of subarrays with sum less than " << k << ": " << result << endl;
    return 0;
}
