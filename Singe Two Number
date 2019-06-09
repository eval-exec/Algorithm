func singleNumber(nums []int) int {
    sort.Ints(nums)
    // 0 1 2 3 4 5 6
    length := len(nums)
    for i := 1 ; i <=  length - 2; i += 2 {
        if nums[i] != nums[i - 1] {
            return nums[i - 1]
        }
    }
    
    return nums[length - 1]
}
