def NULL_not_found(object: any) -> int:
	if object is None:
		print(f"Nothing: None {type(object)}")
	elif isinstance(object, float):
		print(f"Cheese: nan {type(object)}")
	elif object == 0 and type(object) == int:
		print(f"Zero: 0 {type(object)}")
	elif isinstance(object, str) and object == '':
		print(f"Empty: {type(object)}")
	elif object == False and type(object) == bool:
		print(f"Fake: False {type(object)}")
	else:
		print("Type not found")
	return 1