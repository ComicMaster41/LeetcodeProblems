
def maxSubArray(nums):
    # we are going to implement Kadane's algorithm

    # the way it works is simple. Instead of creating a series of subarrays
    # and doing a brute force method
    # we are instead going to create the list

    # the rules for creating the list is we first need two variables

    # res to hold the sum of the numbers
    # max_ending to also have the summation of the number, and compare if it is positive

    # we want to start from the beginning
    res = nums[0]
    max_ending = nums[0]

    for i in range(1, len(nums)):
        # find the max of max_ending and adding the ith number with the previous number
        max_ending = max(max_ending + nums[i], nums[i])
        # update res to be the max between itself and max_ending
        res = max(res, max_ending)

    return res

max_summation = maxSubArray([-2,1,-3,4,-1,2,1,-5,4]) # -> 6 The subarray [4,-1,2,1] has the largest sum 6
print(max_summation)

