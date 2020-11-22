#include <stdio.h>
#include <stdbool.h>

#define ALPHABET 26

// Time: O(n)
// Space: O(1)

int findLongestKSuccessful(char *str, int k);

bool isKLegal(int hist[], int k);

int main() {
    char *str = "aabbaca";
//    int k = 2;
//    int k = 3;
    int k = 4;
//    char *str = "aacaa";
//    int k = 2;
//    int k = 3;
//    int k = 4;
//    char *str = "dabdcadag";
//    int k = 2;
//    int k = 3;
//    char *str = "aaaaaaaaaa";
//    int k = 2;
//    char *str = "aabbcegjftksdgdsssf";
//    int k = 2;
//    int k = 3;
//    int k = 4;
    int result = findLongestKSuccessful(str, k);
    printf("the length of longest %d-successful is: %d\n", k, result);
    return 0;
}

/**
 * Receives an input string and returns the length of the longest substring where
 * every letter appears no more than K times
 * @param str The string to find longest substring of
 * @param k The maximum number of times a single letter can appear
 * @return The length of the max substring
 */
int findLongestKSuccessful(char *str, int k) {
    char *start = str;
    char *end = str;
    int hist[ALPHABET] = {0};
    int longest = 0;
    while (*end) {
        hist[*end - 'a']++;
        if (hist[*end - 'a'] > k) {
            // We reached a point where the substring is illegal
            while (!isKLegal(hist, k)) {
                // Shortening the substring from the left side until it is legal again
                hist[*start - 'a']--;
                start++;
            }
        }
        int curr = end - start + 1;
        if (curr > longest) {
            // The current substring is the newest longest substring
            longest = curr;
        }
        end++;
    }
    return longest;
}

bool isKLegal(int hist[], int k) {
    for (int i = 0; i < ALPHABET; ++i) {
        if (hist[i] > k) {
            return false;
        }
    }
    return true;
}
