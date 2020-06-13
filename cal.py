for a in range(1, 10):
	for b in range(1, 10):
		for c in range(1, 10):
			for d in range(1, 10):
				for e in range(1, 10):
					for f in range(1, 10):
						for g in range(1, 10):
							for h in range(1, 10):
								for i in range(1, 10):
									for j in range(1, 10):
										for k in range(1, 10):
											x1 = a*100+6*10+b
											x2 = c*10+7
											y1 = 3*1000+d*100+e*10+4
											y2 = 5*1000+f*100+g*10+h
											z = 5*10000+i*1000+j*100+k*10+4

											if x1*x2 == y1+y2 and y1+y2 == z:
												print(a, b, c, d, e, f, g, h, i, j, k)
												break