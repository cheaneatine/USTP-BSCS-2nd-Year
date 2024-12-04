import itertools

def main():
    # Input PINCODE
    PIN = input("Enter your four-digit PINCODE: ")

    # Generate all distinct four-digit combinations
    CODES = [''.join(map(str, combo)) for combo in itertools.product(range(10), repeat=4)]

    # Loop through each combination and check for a match with the PIN
    for code in CODES:
        if code == PIN:
            print("OPEN")
            break
    else:
        print("PINCODE not found.")

if __name__ == "__main__":
    main()