import random

input = []

for i in range(20):
    x = random.randint(0, 10)
    input.append(x)

outputs_f = [x / 2 for x in input]
outputs_g = [2 * x + 3 for x in input]

f_addition_g = [f + g for f, g in zip(outputs_f, outputs_g)]

f_division_g = []
for f, g in zip(outputs_f, outputs_g):
    if g != 0:
        f_division_g.append(f / g)
    else:
        f_division_g.append("Undefined")

f_compose_g = [0.5 * (2 * x + 3) for x in input]

# Printing the results
print("Input:", input)
print("OutputF:", outputs_f)
print("OutputG:", outputs_g)
print("FadditionG:", f_addition_g)
print("FdivisionG:", f_division_g)
print("FcomposeG:", f_compose_g)