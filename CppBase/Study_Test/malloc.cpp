#include <iostream>
using   namespace std;

int* twoSum(int* nums, int numsSize, int target) {
    int* result = (int*)malloc(sizeof(int) * 2);
    if (result == NULL) { return NULL; }        //对空间进行为空判定，因为malloc又可能分配内存失败，这时候执行后面内容就会很危险
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                result[0] = nums[i];
                result[1] = nums[j];
                return result;
            }
        }
    }
    return NULL; 
}

int main() {
    int nums[] = { 2, 7, 11, 15 };
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int* result = twoSum(nums, numsSize, target);

    cout << result[0]<<","<< result[1] << endl;

    cin.get();
    return 0;
}