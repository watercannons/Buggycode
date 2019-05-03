def palindrome(s):
    if len(s) <= 1: # Base Case
        return True
    if s[0] == s[-1]: # Recursive Case
        return palindrome(s[0:-1])
    return False

# Some simple tests!
print("Should be True:")
print(palindrome(""))
print(palindrome("a"))
print(palindrome("aa"))
print(palindrome("aba"))
print(palindrome("abccba"))

print("Should be False:")
print(palindrome("ab"))
print(palindrome("abca"))
print(palindrome("aab"))
print(palindrome("abcaba"))