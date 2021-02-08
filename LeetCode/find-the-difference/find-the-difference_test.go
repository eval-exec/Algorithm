package find_the_difference

import (
	"math/rand"
	"testing"
	"time"
)

func Test_findTheDifference(t *testing.T) {
	var count int

	for count < 1000 {
		test(t)
		count++
	}

	v := findTheDifference("a","aa")
	t.Log(string(v))
}

var start = 'a'
var end = 'z'

var chars []byte

func init() {
	for i := start; i <= end; i++ {
		chars = append(chars, byte(i))
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

var r = rand.New(rand.NewSource(time.Now().UnixNano()))

func randPick() byte {
	ix := r.Uint32() % uint32(len(chars))
	i := int(ix)
	return chars[i]
}

func randi(l int) int {
	var i int
	ex := r.Uint32() % uint32(l)
	i = int(ex)

	return i

}

func test(t *testing.T) {

	length := randi(40) + 10

	mask := randPick()

	str := make([]byte, length)
	dst := make([]byte, length)

	for m := 0; m < length; m++ {

		for {
			x := randPick()
			if x == mask {
				continue
			}
			str[m] = x
			break
		}
	}

	copy(dst, str)
	maski := randi(length)
	dst[maski] = mask
	t.Log("str", string(str))
	t.Log("dst", string(dst))
	t.Log("mask", string(mask))
	t.Log("maski", maski)
	t.Log("length", length)
	if got := findTheDifference(string(str), string(dst)); mask != got {
		t.Log("no ok")
		t.Errorf("\n%s\n%s\n%s\n%s.\n", string(str), string(dst), string(mask), string(got))
	} else {
		t.Log("ok")
	}
	t.Log()
	t.Log()
	t.Log()
}
