#include <stdio.h>
#include <stdint.h>

/**
 * n ln(n) time recursive algorithm
 */
int MaxSumSubarray(int* v, int left, int right, int* maxLeft, int* maxRight)
{
  if (!v) {
    *maxLeft = -1;
    *maxRight = -1;
    return 0;
  }

  if (left == right) {
    *maxLeft = left;
    *maxRight = right;
    return v[left];
  }

  int mid = left + (right - left) / 2;
  int leftMaxSumLeft, leftMaxSumRight;
  int rightMaxSumLeft, rightMaxSumRight;

  // Compute the maximum sum subarray in the left and right halves
  int maxSumLeft = MaxSumSubarray(v, left, mid, &leftMaxSumLeft, &leftMaxSumRight);
  int maxSumRight = MaxSumSubarray(v, mid + 1, right, &rightMaxSumLeft, &rightMaxSumRight);

  // Compute the maximum sum subarray that includes the midpoint
  int maxSum = INT32_MIN;
  int midMaxSumLeft;
  int midMaxSumRight = mid;
  int runningSum = 0;

  for (int i = mid; i >= left; --i) {
    runningSum += v[i];
    if (runningSum > maxSum) {
      maxSum = runningSum;
      midMaxSumLeft = i;
    }
  }

  runningSum = maxSum;
  for (int i = mid + 1; i <= right; ++i) {
    runningSum += v[i];
    if (runningSum > maxSum) {
      maxSum = runningSum;
      midMaxSumRight = i;
    }
  }

  // Compare the three and return the largest sum subarray
  if (maxSumLeft > maxSumRight && maxSumLeft > maxSum) {
    *maxLeft = leftMaxSumLeft;
    *maxRight = leftMaxSumRight;
    return maxSumLeft;
  } else if (maxSumRight > maxSum) {
    *maxLeft = rightMaxSumLeft;
    *maxRight = rightMaxSumRight;
    return maxSumRight;
  }

  *maxLeft = midMaxSumLeft;
  *maxRight = midMaxSumRight;
  return maxSum;
}

/**
 * Linear time non-recursive algorithm
 */
int MaxSumSubarray2(int* v, int n, int* maxLeft, int* maxRight)
{
  if (!v) {
    *maxLeft = -1;
    *maxRight = -1;
    return 0;
  }

  int max = INT32_MIN;
  int segmentSum = 0;
  *maxLeft = 0;
  *maxRight = 0;

  int left, right;
  for (left = 0, right = 0; right < n ; ) {
    segmentSum += v[right];
    if (segmentSum > max) {
      max = segmentSum;
      *maxLeft = left;
      *maxRight = right;
    }
    ++right;

    // Start a new segment
    if (segmentSum <= 0) {
      left = right;
      segmentSum = 0;
    }
  }

  return max;
}

int main()
{
  int v[] = {-2, -5, 6, -2, -3, 1, 5, -6};
  int left, right;
  int maxSum = MaxSumSubarray(v, 0, 7, &left, &right);
  printf("Sum: %d\tLeft: %d\tRight: %d\n", maxSum, left, right);
  maxSum = MaxSumSubarray2(v, 8, &left, &right);
  printf("Sum: %d\tLeft: %d\tRight: %d\n", maxSum, left, right);

  return 0;
}
