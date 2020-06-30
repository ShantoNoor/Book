
n = int(input())

lis = [0]*(n+1)
i = 0

def tree(l, h):
	if l <= h:
		m = l + (h - l) // 2

		lis[i] = m
		i += 1

		tree(l, m - 1)

		tree(m + 1, h)


tree(1, n)

for j in lis:
	print(j, end=' ')