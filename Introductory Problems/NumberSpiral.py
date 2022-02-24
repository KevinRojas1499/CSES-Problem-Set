t = int(input())

for i in range(t):
	[y,x] = [int(a) for a in input().split()]
	if x>y and x%2 == 0:
		print((x-1)**2+y)
	elif x>y and x%2 != 0:
		print(x**2-y+1)
	elif x<y and y%2 != 0:
		print((y-1)**2+x)
	else:
		print(y**2-x+1)
		
