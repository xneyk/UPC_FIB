// P2
#include <iostream>
#include <vector>

using namespace std;

void print_board(const vector<vector<char> > &board) {
   int n = board.size();
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cout << board[i][j];
      }
      cout << endl;
   }
}

/**
 * @param i,j represent board coordinates (i,j)
 * @param n size of squared board (n*n)
*/
bool valid_position(int i, int j, int n) {
   return 0 <= i && i < n && 0 <= j && j < n;
}

bool safe_position(int i, int j, const vector<vector<char> > &board) {
   int n = board.size();
   if (valid_position(i, j, n)) { // valid position of the board
      if (board[i][j] == 'K') return false;
      // for each neighbour cell do checks.
      for (int k = -1; k <= 1; ++k) {
         for (int l = -1; l <= 1; ++l) {
            if (valid_position(i+k, j+l, n) && board[i+k][j+l] == 'K') {
               return false;
            }
         }
      }
      return true;
   }
   return false;
}

/**
 * @param size board size (board is n*n).
 * @param current_pos current position at matrix as i*_vector_size_ + j
 * @param n current number of kings placed in the board
 * @param k number of kings to be placed.
 * @param board n*n board with the current kings placed.
*/
void peaceful_kings(int size, int current_pos, int n, int k, vector<vector<char> > &board) {
   if (n == k) {
      print_board(board);
      cout << "----------" << endl;
   } else { // n < k by construction
      for (int i = 0; i < size; ++i) {
         for (int j = 0; j < size; ++j) {
            // for each possible slot
            if (i*size+j >= current_pos && safe_position(i, j, board)) {
               // place the king
               board[i][j] = 'K';
               // go for all solutions followed by placing king at (y,x)
               peaceful_kings(size, (i*size)+j, n+1, k, board);
               // go for next choice.
               board[i][j] = '.';
            }
         }
      }
   }
}

/**
 * @param n board size (board is n*n).
 * @param k number of kings to be placed.
*/
void peaceful_kings(int n,  int k) {
   vector<vector<char> > b(n, vector<char>(n, '.')); // initially an empty board
   peaceful_kings(n, 0, 0, k, b);
}

int main() {
   int n, k;
   cin >> n >> k;

   peaceful_kings(n, k);
}