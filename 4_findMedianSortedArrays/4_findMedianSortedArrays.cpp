// 4_findMedianSortedArrays.cpp : 定义控制台应用程序的入口点。
//
/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	if (m>n)
	{
		return findMedianSortedArrays(nums2, nums1);
	}

	int LMax1, LMax2, RMin1, RMin2;
	int l = 0, r = 2 * m;
	int mid1, mid2;
	while (l<=r)
	{
		mid1 = (l + r) / 2;
		mid2 = m + n - mid1;
		LMax1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
		RMin1 = (mid1 == 2 * m) ? INT_MAX : nums1[mid1 / 2];
		LMax2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
		RMin2 = (mid2 == 2 * n) ? INT_MAX : nums2[mid2 / 2];

		if (LMax1 > RMin2)
		{
			r = mid1 - 1;
		}
		else if (LMax2 > RMin1)
		{
			l = mid1 + 1;
		}
		else
			break;
	}
	return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
}



int main()
{
    return 0;
}

