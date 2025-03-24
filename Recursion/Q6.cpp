#include <iostream>
using namespace std;

// Function to get the number of digits in a number
int countDigits(int n) {
    return (n == 0) ? 0 : 1 + countDigits(n / 10);
}

// Recursive function to check if a number is a palindrome
bool isPalindromeHelper(int n, int divisor) {
    if (n < 10) return true; // Base case: single-digit numbers are palindromes

    int firstDigit = n / divisor; // Extract first digit
    int lastDigit = n % 10; // Extract last digit

    if (firstDigit != lastDigit) return false; // If mismatch, not a palindrome

    // Remove first and last digits and check the middle part
    n = (n % divisor) / 10;
    return isPalindromeHelper(n, divisor / 100);
}

// Wrapper function
bool isPalindrome(int n) {
    if (n < 0) return false; // Negative numbers are not palindromes
    int divisor = 1;
    for (int temp = n; temp >= 10; temp /= 10) {
        divisor *= 10; // Calculate divisor (10^(digits-1))
    }
    return isPalindromeHelper(n, divisor);
}

int main() {
    int num = 1221;
    if (isPalindrome(num))
        cout << num << " is a palindrome.\n";
    else
        cout << num << " is not a palindrome.\n";

    return 0;
}
