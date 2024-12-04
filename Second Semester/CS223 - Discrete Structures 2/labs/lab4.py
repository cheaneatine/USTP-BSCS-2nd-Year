from math import comb

# Define the binomial expressions and their corresponding x, y, and n values
expressions = [
    {"expression": "(x + 2y)⁵", "x": 1, "y": 2, "n": 5},
    {"expression": "(2x - 2y)⁶", "x": 2, "y": -2, "n": 6},
    {"expression": "(x + 3y)⁷", "x": 1, "y": 3, "n": 7},
    {"expression": "(-3x - y)⁸", "x": -3, "y": -1, "n": 8},
    {"expression": "(4x + 3y)¹⁰", "x": 4, "y": 3, "n": 10},
    {"expression": "(-5x - 2y)¹²", "x": -5, "y": -2, "n": 12},
    {"expression": "(3x + y)¹⁴", "x": 3, "y": 1, "n": 14},
    {"expression": "(-x - 2y)¹⁶", "x": -1, "y": -2, "n": 16},
    {"expression": "(2x + y)¹⁸", "x": 2, "y": 1, "n": 18},
    {"expression": "(2x - 4y)²⁰", "x": 2, "y": -4, "n": 20}
]

# Function to compute coefficients of binomial expansion
def compute_coefficients(x, y, n):
    coefficients = []
    for i in range(n + 1):
        coefficients.append(comb(n, i) * (x ** (n - i)) * (y ** i))
    return coefficients

# Compute coefficients for each expression
coefficients_list = [compute_coefficients(exp["x"], exp["y"], exp["n"]) for exp in expressions]

# Print the results
for i, coefficients in enumerate(coefficients_list, start=1):
    print(f"Binomial expression {i}: {coefficients}")