#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef set<string>::const_iterator C_It;

int main() {
   string command;
   map<string,set<string>> subject_to_student;
   map<string,set<string>> student_to_subject;

   while (cin >> command) {
      string student, subject;
      if (command == "ENROLL") {
         cin >> student >> subject;
         student_to_subject[student].insert(subject);
         subject_to_student[subject].insert(student);
      }
      else if (command == "QUIT") {
         cin >> student >> subject;
         student_to_subject[student].erase(subject);
         subject_to_student[subject].erase(student);
      }
      else if (command == "SUBJECTSOFSTUDENT") {
         cin >> student;
         for (C_It i = student_to_subject[student].begin(); i != student_to_subject[student].end(); ++i) {
            if (i != student_to_subject[student].begin()) cout << ' ';
            cout << *i;
         }
         cout << endl;
      }
      else if (command == "STUDENTSOFSUBJECT") {
         cin >> subject;
         for (C_It i = subject_to_student[subject].begin(); i != subject_to_student[subject].end(); ++i) {
            if (i != subject_to_student[subject].begin()) cout << ' ';
            cout << *i;
         }
         cout << endl;
      }
   }
}