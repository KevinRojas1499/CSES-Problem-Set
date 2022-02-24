n = int(input())

n1 = []
n2 = []

if (n*(n+1)//2)%2 == 1:
	print("NO")
else:
	if n%4 == 3:
		n1.append(1)
		n1.append(2)
		n2.append(3)
		
		for i in range(4,n,4):
			n1.append(i)
			n1.append(i+3)
			n2.append(i+1)
			n2.append(i+2)
	else:
		for i in range(1,n,4):
			n1.append(i)
			n1.append(i+3)
			n2.append(i+1)
			n2.append(i+2)
	print("YES")
	print(len(n1))
	for a in n1:
		print(a,end = ' ')
	print("")
	print(len(n2))
	for a in n2:
		print(a,end = ' ')
	print("")
	
	
