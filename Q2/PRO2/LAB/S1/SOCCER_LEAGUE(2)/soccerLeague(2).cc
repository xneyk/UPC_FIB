#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Team {
   int id;
   int points;
   int goals_in_favor;
   int goals_against;
};

void read_match(vector<Team>& teams, int i, int j) {
   int local_goals, visitor_goals;
   cin >> local_goals >> visitor_goals;
   
   int match_result = local_goals - visitor_goals;
   // i represents local team
   teams[i].goals_in_favor += local_goals;
   teams[i].goals_against += visitor_goals;
   // j represents visitor team
   teams[j].goals_in_favor += visitor_goals;
   teams[j].goals_against += local_goals;

   if (match_result > 0) teams[i].points += 3;
   else if (match_result < 0) teams[j].points += 3;
   else {
      ++teams[i].points;
      ++teams[j].points;
   }
}

/**
 * PRE: teams.size() = n;
 * POST: teams contains n teams, each team with an id assigned and all other components = 0;
*/
void ini_teams(vector<Team>& teams, int n) {
   for (int i = 0; i < n; ++i) {
      Team team;
      team.id = i+1;
      team.points = team.goals_in_favor = team.goals_against = 0;
      teams[i] = team;
   }
}

/**
 * PRE: t1,t2 points, goals_in_favor, goals_against are valid (not undefined)
 * POST: returns true if t1 is better than t2
*/
bool better_team(Team t1, Team t2) {
   if (t1.points != t2.points) return t1.points > t2.points;
   else if (t1.goals_in_favor - t1.goals_against != t2.goals_in_favor - t2.goals_against) {
      return t1.goals_in_favor - t1.goals_against > t2.goals_in_favor - t2.goals_against;
   }
   else return t1.id < t2.id;
}

/**
 * PRE: teams are sortered with the clasification. (following better_team() order)
 * POST: print the clasification in the terminal
*/
void print_clasification(const vector<Team>& teams, int n) {
   for (int i = 0; i < n; ++i) {
      cout << teams[i].id << ' ';
      cout << teams[i].points << ' ';
      cout << teams[i].goals_in_favor << ' ';
      cout << teams[i].goals_against << endl;
   }
}

int main() {
   int n, m;
   cin >> n >> m;
   vector<Team> teams(n);
   
   ini_teams(teams, n);

   for (int i = 0; i < m; ++i) { //read all the journeys
      int a, b;
      for (int i = 0; i < n/2; ++i) {
         cin >> a >> b;
         read_match(teams, a, b);
      }
   }

   print_clasification(teams, n);
}