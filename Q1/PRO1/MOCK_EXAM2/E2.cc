#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Here you can add more includes if you wish.
// ...

using namespace std;

struct Image {
   string name;
   int depth;
   int i, j;
   vector<string> v;
};

typedef vector<Image> ListImages;

// Auxiliary functions (you can add more functions if you wish)

// Pre: The input has a description of an image with this format:
//      - First line: name depth i j n m
//      - n lines with m characters each (the contents of v)
//        These characters are different from whitespace, as we use '.' to represent empty character.
Image readImage() {
   int n, m;
   Image img;
   cin >> img.name >> img.depth >> img.i >> img.j;

   cin >> n >> m;
   vector<string> v(n);
   img.v = v;
   for (int i = 0; i < n; ++i) {
      cin >> img.v[i];
   }
   return img;
}

// Pre: listimages contains a non-empty list of valid images.
// Post: N,M are the dimensions of the minimum board such that
//       all of those images fit in it.
//       In other words, N,M must be the minimum naturals satisfying that,
//       for each image in listimages,
//       if i,j are its location and n,m are the dimensions of its v,
//       then i+n<=N and j+m<=M must be satisfied,
void computeMinimumBoardDimensions(const ListImages &listimages, int &N, int &M) {
   int lenght = listimages.size();
   N = M = 0;
   for (int i = 0; i < lenght; ++i) {
      int img_i = listimages[i].i;
      int img_height = listimages[i].v.size();
      if ((img_i + img_height) > N) N = img_i + img_height;

      int img_j = listimages[i].j;
      int img_width = listimages[i].v[0].size();
      if ((img_j + img_width) > M) M = img_j + img_width;
   }
}

// Pre:  image is valid and board is valid and image fits in board.
// Post: image has been drawn on board. Nothing else has changed.
//       Recall that occurrences of character '.' in image are not printed on board!
void drawImage(const Image &image, vector<string> &board) {
   int row = image.v.size(); //img height 
   int col = image.v[0].size(); //img width
   
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
         if (image.v[i][j] != '.') {
            board[i+image.i][j+image.j] = image.v[i][j];
         }
      }
   }
}

// Pre:  image1, image2 represent valid images.
// Post: Returns true if one of the following conditions holds:
//         - depth of image1 is strictly bigger than depth of image2.
//         - image1 and image2 have same depth, but image1 has smaller name than image2.
bool compareImages(Image image1, Image image2) {
   if (image1.depth != image2.depth) return image1.depth > image2.depth;
   return image1.name < image2.name;
}

// Pre: listimages has a list of valid images.
// Post: prints on the output the result of drawing all of those
//       images on the minimum board such that all of them fit in,
//       and sorted by depth and name.
void drawListImages(ListImages &listimages) {
   sort(listimages.begin(), listimages.end(), compareImages);
   int N, M;
   computeMinimumBoardDimensions(listimages, N, M);
   vector<string> board(N, string(M, '.'));
   for (int i = 0; i < int(listimages.size()); i++)
      drawImage(listimages[i], board);
   for (int i = 0; i < N; i++)
      cout << board[i] << endl;
   cout << endl;
}

int main() {
   int n;
   cin >> n;
   ListImages listimages(n);
   for (int i = 0; i < n; i++) {
      listimages[i] = readImage();
   }
   drawListImages(listimages);
}