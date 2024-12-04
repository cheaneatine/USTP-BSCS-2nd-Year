import random

# Define the functions
def f(x):
    return 4 * x

def g(x):
    return 2 * x - 3

# Step 1: Generate 10 random integers from 0 to 10
inputs = [random.randint(0, 10) for _ in range(10)]

# Step 2: Generate outputs for f(x) and g(x)
OutputF = [f(x) for x in inputs]
OutputG = [g(x) for x in inputs]

# Step 3: Find the output of the difference of f(x) - g(x)
FsubtractionG = [f(x) - g(x) for x in inputs]

# Step 4: Find the output of the quotient of f(x) / g(x)
FdivisionG = [f(x) / g(x) if g(x) != 0 else float('inf') for x in inputs]

# Step 5: Find the output of the composition of (f o g)(x)
FcomposeG = [f(g(x)) for x in inputs]

# Print the results
print("Input:", inputs)
print("OutputF:", OutputF)
print("OutputG:", OutputG)
print("FsubtractionG:", FsubtractionG)
print("FdivisionG:", FdivisionG)
print("FcomposeG:", FcomposeG)