

def TOH(a, b, c, n):
	if n > 0:
		TOH(a, c, b, n-1)
		print(a, c)
		TOH(b, a, c, n-1) 



TOH('A', 'B', 'C', 4)