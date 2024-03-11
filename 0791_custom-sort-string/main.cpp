/*
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

 

Example 1:

Input:  order = "cba", s = "abcd" 

Output:  "cbad" 

Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:

Input:  order = "bcafg", s = "abcd" 

Output:  "bcad" 

Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.

Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "bacd" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.


*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
    public:
	string customSortString(string order, string s)
	{
		// use a counter map for s
		unordered_map<char, int> char_counts;

		for (char c : s) {
			char_counts[c]++;
		}

		string result = "";
		// for each character in order, add it to the result string the number of times it appears in s
		for (char c : order) {
			if (char_counts.find(c) != char_counts.end()) {
				result += string(char_counts[c], c);
				char_counts.erase(c);
			}
		}
		// add the remaining characters
		// auto: type inference C++11
		for (auto it : char_counts) {
			result += string(
				it.second,
				it.first); // string(n, c) creates a string with n copies of c
		}

		return result;
	}
};

#include <algorithm>
class Solution2 {
    public:
	string customSortString(string order, string s)
	{
		// by sort with custom compare function
		// show skill of using lambda function and algorithm sort
		//     sort: added in C++98
		//         template <class RandomAccessIterator, class Compare>
		//         void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
		//     lambda function: added in C++11
		//         [capture](parameters) -> return_type {body}
		//         capture: [] or [var] or [&var] or [this]
		//                  [&]: capture by reference for all variables
		//         parameters: (type1 var1, type2 var2)
		//         do not need to specify return_type if it can be deduced (yes for this case)
		sort(s.begin(), s.end(), [&](char a, char b) {
			return order.find(a) < order.find(b);
		});

		return s;
	}
};

// implement with priority queue
//     priority_queue: added in C++98
//         template <class T, class Container, class Compare>
//         class priority_queue;
//     map: added in C++98

#include <queue>
#include <map>
class Solution3 {
    public:
	string customSortString(string order, string s)
	{
		map<char, int> order_map;
		int rank = 0;
		for (char &c : order) {
			order_map[c] = rank--;
		}

		// pair of rank and character, and use the rank as the priority
		priority_queue<pair<int, char> > p;
		for (char &c : s) {
			p.push({ order_map[c],
				 c }); // push the pair of rank and character
		}

		string result = "";
		while (!p.empty()) {
			result += p.top().second;
			p.pop();
		}

		return result;
	}
};

/*
 implement with bitset
     bitset: added in C++98

        template< std::size_t N >
        class bitset;
*/

#include <bitset>
class Solution4 {
    public:
	string customSortString(string order, string s)
	{
		// 26 bits, each bit represents a character
		//     0: not in order (default)
		//     1: in order (set by b.set())
		bitset<26> b;
        int freq[26] = {0};

		for (char &c : order) {
			b.set(c - 'a');
		}

		string result = "";

        // for each s, if not in order: add to result
        //                if in order: add to freq
        for (char &c : s) {
            if (b.test(c - 'a')) {
                freq[c - 'a']++;
            } else {
                result += c;
            }
        }

        // for each order, add to result the number of times it appears in s
        for (char &c : order) {
            result += string(freq[c - 'a'], c);
        }

        return result;
	}
};

int main(int argc, char const *argv[])
{
	// Input: "cba", s = abcd -> Output: "cbad"
	string order = "cba";
	string s = "abcd";
	Solution4 sol;
	cout << sol.customSortString(order, s) << endl;

	// Input order = "bcafg", s = "abcd" -> Output: "bcad" or "bcda" or "bacd" or "badc" or "bdac" or "bdca"
	order = "bcafg";
	s = "abcd";
	cout << sol.customSortString(order, s) << endl;

	return 0;
}
