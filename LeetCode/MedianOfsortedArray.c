#include <stdio.h>
#include <limits.h>  // For INT_MIN and INT_MAX

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the median of two sorted arrays
double findMedianSortedArrays(int *nums1, int n1, int *nums2, int n2) {
    // Ensure nums1 is the smaller array
    if (n1 > n2) {
        return findMedianSortedArrays(nums2, n2, nums1, n1);
    }

    int total = n1 + n2;
    int left = (total + 1) / 2;
    int low = 0, high = n1;

    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 < n2)
            r2 = nums2[mid2];
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            // Correct partition found
            if (total % 2 == 1)
                return (double)max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return 0.0; // Should never reach here if arrays are sorted
}

// Example usage
int main() {
    int nums1[] = {1, 3, 8};
    int nums2[] = {7, 9, 10, 11};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int n2 = sizeof(nums2) / sizeof(nums2[0]);

    double median = findMedianSortedArrays(nums1, n1, nums2, n2);
    printf("Median = %.2f\n", median);

    return 0;
}
