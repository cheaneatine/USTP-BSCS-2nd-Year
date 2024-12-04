import random

# Define the functions f(x) and g(x)
def f(x):
    return x - 2

def g(x):
    return x + 2

# Step 1: Generate 10 random integers from 0 to 10
inputs = [random.randint(0, 10) for _ in range(10)]

# Step 2: Calculate outputs of f(x) and g(x) for each input
output_f = [f(x) for x in inputs]
output_g = [g(x) for x in inputs]

# Step 3: Calculate the product of f(x) and g(x) for each input
output_multiplication = [f(x) * g(x) for x in inputs]

# Step 4: Calculate the composition of g o f for each input
output_composition = [g(f(x)) for x in inputs]

# Display results
print("Input:", inputs)
print("OutputF:", output_f)
print("OutputG:", output_g)
print("FmultiplicationG:", output_multiplication)
print("GcompositionF:", output_composition)