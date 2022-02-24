t = int(input())

for i in range(t):
	[a,b] = [int(x) for x in input().split()]
	if (2*a-b)%3 == 0:
		y = (2*a-b)//3
		x = a-2*y
		if x>=0 and y>=0:
			print("YES")
		else:
			print("NO")
	else:
		print("NO")
