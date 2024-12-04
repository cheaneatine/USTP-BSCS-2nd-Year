def binomial_coefficient(n, k):
    """Function to calculate binomial coefficient (n choose k)"""
    if k == 0 or k == n:
        return 1
    if k > n:
        return 0
    numerator = 1
    denominator = 1
    for i in range(1, min(k, n - k) + 1):
        numerator *= n - i + 1
        denominator *= i
    return numerator // denominator

def binomial_expansion(expression, power):
    coefficients = []
    for k in range(power + 1):
        coefficient = binomial_coefficient(power, k) * (expression[0] ** (power - k)) * (expression[1] ** k)
        coefficients.append(coefficient)
    return coefficients

expression = (4, 3)  # (4x + 3y)
power = 10

coefficients = binomial_expansion(expression, power)
print(coefficients)