package teemo_atacking

func findPoisonedDuration(timeSeries []int, duration int) int {
	var lastT int
	var sumT int
	if len(timeSeries) == 0 || duration == 0 {
		return 0
	}

	for i, t := range timeSeries {
		if i == 0 {
			lastT = t
			continue
		}

		sep := t - lastT
		if sep >= duration {
			sumT += duration
		} else {
			sumT += sep
		}
		lastT = t

	}
	sumT += duration
	return sumT
}
