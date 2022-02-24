n = int(input())


for k in range(1,n+1):
	a = k*k;
	res = a*(a-1)//2-4*(k-1)*(k-2)
	print(res)
		
