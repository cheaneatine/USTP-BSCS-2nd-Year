import itertools

def generate_lucky_numbers():
    # Generate all possible combinations of 6 numbers chosen from 1 to 45
    lucky_numbers = list(itertools.combinations(range(1, 46), 6))
    return lucky_numbers

def main():
    # Generate all possible combinations of lucky numbers
    LUCKY_NUMBERS = generate_lucky_numbers()

    # Print the total number of combinations
    print(f"Total combinations of lucky numbers: {len(LUCKY_NUMBERS)}")

    # Let's pick one combination randomly
    import random
    taya_i_ni = random.choice(LUCKY_NUMBERS)

    # Print the chosen combination
    print("TAYA-I NI:", taya_i_ni)

if __name__ == "__main__":
    main()