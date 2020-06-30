from datetime import datetime
def next_bd(y, m, d):
	today = datetime. today()
	bd_of_current_yr = datetime (today.year, m, d)
	if bd_of_current_yr < today:
		return f'Next Bday: {d}/{m}/{today.year + 1}'
	elif bd_of_current_yr == today:
		return 'Today is your birthday day'
	else:
		return bd_of_current_yr

print(next_bd(2000, 2, 29))