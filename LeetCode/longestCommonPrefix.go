func longestCommonPrefix(strs []string) string {
    var ret []byte
    var lenstr = len(strs)
    if lenstr == 0 {
        return ""
    }
    var length = len(strs[0])
    for _, item := range strs {
        lenitem := len(item)
        if lenitem < length {
            length = lenitem
        }
    }
    for i := 0 ; i < length  ; i++ {
        for j :=1; j < lenstr; j++ {
            if strs[0][i] != strs[j][i] {
                return string(ret)
            }
        }
        ret = append(ret, byte(strs[0][i]))
    }
    return string(ret)
}
