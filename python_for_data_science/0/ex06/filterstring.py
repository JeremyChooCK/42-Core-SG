import sys

def main():
    # Check if the number of arguments is correct
    if len(sys.argv) != 3:
        print("AssertionError: the arguments are bad")
        return
    
    S = sys.argv[1]
    try:
        N = int(sys.argv[2])
    except ValueError:
        print("AssertionError: the arguments are bad")
        return

    # Split the string into words
    words = S.split()

    # Filter words longer than N using a lambda
    filtered_words = [word for word in words if (lambda w: len(w) > N)(word)]
    
    # Print the result
    print(filtered_words)

if __name__ == "__main__":
    main()