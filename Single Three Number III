func singleNumber(nums []int) int {
    length := len(nums)
    sort.Ints(nums)
    // [0] 1 2 3 4
    for i := 2 ; i < length ; i += 3 {
        if nums[i] == nums[i + 1] {
            return nums[i - 2]
        }
    }
    return nums[length - 1]
}
