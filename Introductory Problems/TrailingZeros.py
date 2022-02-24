n = int(input())

cur  = 5
res = 0
while n//cur > 0:
	res+=n//cur
	cur*=5
print(res)

