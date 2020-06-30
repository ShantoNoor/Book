from datetime import date

def next_birthday(y, m, d):
	today = str(date.today())
	today = [int(a) for a in today.split('-')]

	n_birthday = [0, 0, 0]
	n_birthday[0] = today[0]
	n_birthday[1] = m
	n_birthday[2] = d

	if m < today[1]:
		n_birthday[0] += 1

	return n_birthday

bd = [int(a) for a in input('Enter your birthday(as YYYY MM DD): ').split()]
print('Next birthday [YYYY, MM, DD] = ', next_birthday(bd[0], bd[1], bd[2]))