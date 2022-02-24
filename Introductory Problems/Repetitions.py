word = input()

best = 0
curLetter = word[0]
curCount = 0

for x in word:
	if x == curLetter:
		curCount+=1
	else:
		best = max(best,curCount)
		curLetter = x
		curCount = 1
best = max(best,curCount)
print(best)
