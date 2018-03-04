Recently, you have found your interest in string theory. Here is an interesting question about strings.

You are given a string S of length n consisting of the first k lowercase letters.

You are required to find two non-empty substrings (note that substrings must be consecutive) of S, such that the two substrings don't share any same letter. Here comes the question, what is the maximum product of the two substring lengths?

Input

The first line contains an integer T, meaning the number of the cases. 1 <= T <= 50.

For each test case, the first line consists of two integers n and k. (1 <= n <= 2000, 1 <= k <= 16).

The second line is a string of length n, consisting only the first k lowercase letters in the alphabet. For example, when k = 3, it consists of a, b, and c.

Output

For each test case, output the answer of the question.

Sample Input
4
25 5
abcdeabcdeabcdeabcdeabcde
25 5
aaaaabbbbbcccccdddddeeeee
25 5
adcbadcbedbadedcbacbcadbc
3 2
aaa

Sample Output
6
150
21
0