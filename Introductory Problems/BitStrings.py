n = int(input())

MOD = int(1e9+7)

def exp(a,b):
	if b == 0:
		return 1
	c = exp(a,b//2)%MOD
	res = c*c
	res = res%MOD
	if b%2 == 1:
		res = res*a
		res = res%MOD
	return res

print((exp(2,n)))


