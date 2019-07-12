nbits = 128
n = 7
r = (2 ** (2 * nbits)) % n

def mmul(a, b):
	s = 0
	for i in range(nbits):
		if (a & (1 << i)):
			s += b
		if (s & 1):
			s = (s + n) >> 1
		else:
			s = s >> 1

		if (s >= (1 << nbits)):
			s -= (1 << nbits)

	if (s >= n):
		s -= n	

	return s

left  = 0x3
right = 0x12

print mmul(left, right) 
"""
_left = mmul(left, r)
print '_left: ', hex(_left), '\n\n'
_right = mmul(right, r)
print '_right: ', hex(_right), '\n\n'
_result = mmul(_left, _right)
print '_result: ', hex(_result), '\n\n'
print 'result: ',hex(mmul(_result, 1)), '\n\n'
"""