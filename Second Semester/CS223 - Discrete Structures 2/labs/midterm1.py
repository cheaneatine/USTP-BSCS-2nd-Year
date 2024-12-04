from itertools import permutations

word = 'HONESTY'
permutations_list = list(permutations(word))

for perm in permutations_list:
    print(''.join(perm))