       
# takes a list of strings, and returns the longest string in the list.
def returnLongestString(strList):
    longestStr = ""
    for s in strList:
        if len(s) >= len(longestStr):
            longestStr = s
    return longestStr

# Returns the longest Common substring of s1 and s2
def longestCommonSubstring(s1, s2):
    if s1 == "" or s2 == "":
        return ""
    loseIt1 = longestCommonSubstring(s1[1:], s2)
    loseIt2 = longestCommonSubstring(s1, s2[1:])
    if s1[0:] == s2[0:]: # if the first chars are the same
        useIt = s1[0] + longestCommonSubstring(s1[1:], s2[1:])
        return returnLongestString([useIt, loseIt1, loseIt2])
    else: # if the first chars are different
        return returnLongestString([loseIt1, loseIt2])
        


# Some simple tests!
print("Should be \"\"")
print(longestCommonSubstring("", ""))

print("Should be a")
print(longestCommonSubstring("a", "a"))

print("Should be a")
print(longestCommonSubstring("ab", "ba"))

print("Should be abc")
print(longestCommonSubstring("abc", "dabc"))

print("Should be ab")
print(longestCommonSubstring("adbd", "dddab"))