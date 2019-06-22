nbits = 256
n = (1 << 256) - (1 << 224) + (1 << 192) + (1 << 96) - 1
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

		if (s >= (1 << 256)):
			s -= (1 << 256)

		print hex(s)

	if (s >= n):
		s -= n	

	return s

left  = 0x4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5
right = 0x4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5

_left = mmul(left, r)
print '_left: ', hex(_left), '\n\n'
_right = mmul(right, r)
print '_right: ', hex(_right), '\n\n'
_result = mmul(_left, _right)
print '_result: ', hex(_result), '\n\n'
print 'result: ',hex(mmul(_result, 1)), '\n\n'