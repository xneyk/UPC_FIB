//X13635 Media Library (II)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Track {
   string artist, title, genre;
   int year;
};

vector<Track> read_tracks(int n) {
   vector<Track> v(n);
   for (int i = 0; i < n; ++i) {
      cin >> v[i].artist >> v[i].title >> v[i].genre >> v[i].year;
   }
   return v;
}

void print_track(const Track &t) {
   cout << t.artist;
   cout << " (" << t.year;
   cout << ") " << t.title << " (" << t.genre << ")" << endl;
}

bool betterSong(Track a, Track b) {
   if (a.artist != b.artist) return a.artist < b.artist;
   else if (a.year != b.year) return a.year < b.year;
   else return a.title < b.title;
}

int main() {
   int n;
   cin >> n;
   vector<Track> library = read_tracks(n);
   sort(library.begin(), library.end(), betterSong);

   //QUERY SECTION
   string query_genre;
   while (cin >> query_genre) {
      for (int i = 0; i < n; ++i) {
         if (library[i].genre == query_genre) print_track(library[i]);
      }
   }
}