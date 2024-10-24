import sys
if len(sys.argv) > 2:
	print("AssertionError: more than one argument is provided")
elif len(sys.argv) == 2:
	if sys.argv[1] == "":
		exit()
	if not (sys.argv[1].isdigit() or (sys.argv[1][0] == '-' and sys.argv[1][1:].isdigit())):
		print("AssertionError: argument is not an integer")
	else:
		if int(sys.argv[1]) % 2 == 0:
			print("I'm Even")
		else:
			print("I'm Odd")