def moveZeroes(nums):
    # do not return anything
    i = 0
    j = 0
    # iterate over whole list
    while i < len(nums):
        if j < len(nums):
            # if the ith element is 0
            if nums[i] == 0:
                del nums[i]
                nums.append(0)
            else:
                i += 1
            j += 1
        else:
            break

