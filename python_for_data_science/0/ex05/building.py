import sys

def main():
# your tests and your error handling
	args = sys.argv[1:]
	if len(args) == 1:
		uppercount = 0
		lowercount = 0
		punctcount = 0
		spacecount = 0
		digitcount = 0
		for char in args[0]:
			if char.isupper():
				uppercount += 1
			elif char.islower():
				lowercount += 1
			elif char.isspace():
				spacecount += 1
			elif char.isdigit():
				digitcount += 1
			else:
				punctcount += 1
		print("The text contains:", len(args[0]), "characters:")
		print(uppercount, "upper letters")
		print(lowercount, "lower letters")
		print(punctcount, "punctuation marks")
		print(spacecount, "spaces")
		print(digitcount, "digits")

if __name__ == "__main__":
	main()