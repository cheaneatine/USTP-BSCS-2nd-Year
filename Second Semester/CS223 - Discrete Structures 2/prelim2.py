from itertools import permutations

# Define the word
word = 'LOVE'

# Generate permutations
perms = permutations(word)

# Print all permutations
for perm in perms:
    print(''.join(perm))