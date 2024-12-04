#include <iostream>

using namespace std;

// Function to compute a^b using Divide-and-Conquer
long long power(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long half_power = power(a, b / 2);
    if (b % 2 == 0)
        return half_power * half_power;
    else
        return a * half_power * half_power;
}

int main()
{
    long long a = 3, b = 5;
    cout << "Compute " << a << "^" << b << endl;
    cout << "Result: " << power(a, b) << endl;
    return 0;
}

/*

Best Case: O(log n) - When the exponent b is even and the algorithm
follows the path of dividing b by 2 in each step until it reaches 0.

Average Case: O(log n) - Same as the best case.

Worst Case: O(log n) - This is the complexity of the divide-and-conquer
algorithm, which is significantly better than the naive approach of repeated
multiplication, which has a time complexity of O(n).

*/