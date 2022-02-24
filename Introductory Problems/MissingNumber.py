n = int(input())

nums = [int(x) for x in input().split()]

arr = [0]*(n+1)
arr[0] = 1

for x in nums:
	arr[x] = 1
for i in range(n+1):
	if arr[i] == 0:
		print(i)
		
