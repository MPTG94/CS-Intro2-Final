#include <stdio.h>

//#define N 4
#define N 7

int findLongestCircle(int mat[N][N]);
int findLongestCircleAux(int mat[N][N], int visited[], int marked[N][N], int longest, int currLen, int current);

int main() {
    // Simple circle
//    int matrix[N][N] = {{0, 1, 0, 1},
//                        {1, 0, 1, 1},
//                        {0, 1, 0, 1},
//                        {1, 1, 1, 0}};

    // Circle with separated node
//    int matrix[N][N] = {{0, 1, 1, 0},
//                        {1, 0, 1, 0},
//                        {1, 1, 0, 1},
//                        {0, 0, 1, 0}};

    // star shape
//    int matrix[N][N] = {{0, 1, 1, 1},
//                        {1, 0, 0, 0},
//                        {1, 0, 0, 0},
//                        {1, 0, 0, 0}};


//    int matrix[N][N] = {{0, 1, 0, 1, 0, 0},
//                        {1, 0, 1, 0, 0, 0},
//                        {1, 0, 1, 0, 1, 1},
//                        {0, 0, 0, 1, 0, 1},
//                        {0, 0, 0, 1, 1, 0}};

    int matrix[N][N] = {{0, 1, 0, 1, 0, 0, 0} ,
                        {1, 0, 1, 0, 0, 0, 0 },
                        {0, 1, 0, 1, 0, 0, 0 },
                        {1, 0, 1, 0, 0, 0, 1 },
                        {0, 0, 0, 0, 0, 1, 1 },
                        {0, 0, 0, 0, 1, 0, 1 },
                        {0, 0, 0, 1, 1, 1, 0}};

    int result = findLongestCircle(matrix);
    printf("the length of longest circle: %d\n", result);
    return 0;
}

int findLongestCircle(int mat[N][N]) {
    // Array for visited vertices in the current search
    int visited[N] = {0};
    int marked[N][N] = {{0}};
    int longest = 0;
    int currLen = 0;
    int result = findLongestCircleAux(mat, visited, marked, longest, currLen, 0);
    return result;
}

int findLongestCircleAux(int mat[N][N], int visited[], int marked[N][N], int longest, int currLen, int current) {
    if (visited[current] == 1) {
        // we already visited in this iteration, meaning this is a circle
        return currLen;
    }

    // marking current vertex as visited
    visited[current] = 1;
    for (int j = 0; j < N; ++j) {

        if (mat[current][j] == 1 && !marked[current][j]) {
            // this is a non directed graph, the matrix is symmetrical, so if we visit mat[i][j], we do not want
            // to visit mat[j][i] in that iteration (we will be stepping back to the previous vertex, and that is not a circle
            marked[current][j] = 1;
            marked[j][current] = 1;
            int temp = findLongestCircleAux(mat, visited, marked, longest, ++currLen, j);
            if (temp > longest) {
                longest = temp;
            }
            marked[current][j] = 0;
            marked[j][current] = 0;
            --currLen;
        }
    }
    visited[current] = 0;

    return longest;
}