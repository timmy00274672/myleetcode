/*
20. Valid Parentheses
Easy
Topics
Companies
Hint
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false

https://leetcode.com/problems/valid-parentheses/description/
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// =================================
#pragma GCC optimize("O3", "unroll-loops")
bool isValid(char *s)
{
	int len = strlen(s);
	if (len == 0) {
		return true;
	}
	if (len % 2 != 0) {
		return false;
	}
	char stack[len];
	int top = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			stack[top++] = s[i];
		} else {
			if (top == 0) {
				return false;
			}
			if (s[i] == ')' && stack[top - 1] != '(') {
				return false;
			}
			if (s[i] == ']' && stack[top - 1] != '[') {
				return false;
			}
			if (s[i] == '}' && stack[top - 1] != '{') {
				return false;
			}
			top--;
		}
	}
	return top == 0;
}
int main(int argc, char const *argv[])
{
	printf("() -> %d\n", isValid("()"));
	printf("()[]{} -> %d\n", isValid("()[]{}"));
	printf("(] -> %d\n", isValid("(]"));
	printf("([)] -> %d\n", isValid("([)]"));
	printf("{[]} -> %d\n", isValid("{[]}"));
	
	return 0;
}
