n = int(input())

arr = [int(x) for x in input().split()]

res = 0
for i in range(1,len(arr)):
	change =  max(0,-arr[i]+arr[i-1]);
	res+= change
	arr[i]+=change 
	
print(res)
