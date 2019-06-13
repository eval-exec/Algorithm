func romanToInt(s string) int {
        var maps =  map[string]int{
         "I": 1,
         "V":  5,
         "X":  10,
         "L":  50,
        "C":  100,
         "D": 500,
         "M": 1000,  
    }
    var last int
    var sum int
    for i := len(s) - 1; i >= 0; i-- {
        if maps[string(s[i])] >= last {
            sum = sum + maps[string(s[i])]
            last = maps[string(s[i])]
        } else {
            sum = sum - maps[string(s[i])]
        }
    }
    return sum   
}
