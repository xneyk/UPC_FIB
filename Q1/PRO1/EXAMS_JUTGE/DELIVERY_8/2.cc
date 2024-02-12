#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Raw_Data {
    string subject;
    string teacher;
    string day;
    int begin;
    int end;
};

struct Slot {
 vector<string> listsubjects;
 vector<string> listteachers;
};

typedef vector<vector<Slot> > TableSlots;



void printSlotClass (const TableSlots& table, int i, int j) {                                  
    int subjects_slot = table[i][j].listsubjects.size();
    int contador_espacios = 9;
    while (subjects_slot / 10 > 0) subjects_slot /= 10, --contador_espacios;
    for (int x = 0; x < contador_espacios; ++x) cout << ' ';
    cout << table[i][j].listsubjects.size();
}

void printSlotTeacher (vector <string> slot_profes, int& remplazos) {       
    int profes_repetidos = 0;
    sort( slot_profes.begin(), slot_profes.end() );
    for (int x = 1; x < slot_profes.size(); ++x) if (slot_profes[x] == slot_profes[x - 1]) ++remplazos, ++profes_repetidos;
    int uniqueTeachers = slot_profes.size() - profes_repetidos, contador_espacios = 9;
    while (uniqueTeachers / 10 > 0) uniqueTeachers /= 10, --contador_espacios;
    for (int x = 0; x < contador_espacios; ++x) cout << ' ';
    cout << slot_profes.size() - profes_repetidos;
}

int f1 (int x, int y, int a) {
    if (a == 0) {
        if (x < y) return x;
        return y;
    }
    if (a == 1) {
        if (x > y) return x;
        return y;
    }
    return a;
}

int index_day (string a) {
    if (a == "monday") return 0;
    if (a == "tuesday") return 1;
    if (a == "wednesday") return 2;
    if (a == "thursday") return 3;
    return 4;
}
int main() {
    string auxiliar;
    vector<Raw_Data> data_set;
    int begin = 24, end = 0, remplazos = 0;
    while (cin >> auxiliar) {
        Raw_Data aux;
        auxiliar = aux.subject;
        cin >> aux.teacher >> aux.day >> aux.begin >> aux.end;
        data_set.push_back (aux);
        begin = f1 (begin, aux.begin, 0);
        end = f1 (end, aux.end, 1);
    }
    
   TableSlots table (end - begin, vector<Slot> (5, Slot () ) );                   
    for (int i = 0; i < data_set.size(); ++i) {
        for (int a = data_set[i].begin - begin; a < data_set[i].end - begin; ++a) {
            table[a][index_day(data_set[i].day)].listsubjects.push_back (data_set[i].subject);
            table[a][index_day(data_set[i].day)].listteachers.push_back (data_set[i].teacher);
        }
    }

    /**
     * PRINT TABLES OUTPUT
    */

    cout << "number of subjects per slot:" << endl;
    //Table Header
    cout << " h    monday   tuesday wednesday  thursday    friday" << endl;
    for (int i = 0; i < table.size(); ++i) {
        int h_now = begin + i;
        if (h_now < 10) cout << ' ';
        cout << h_now;
        for (int j = 0; j < 5; ++j) printSlotClass (table, i, j);
        cout << endl;
    }
    cout << "number of teachers per slot:" << endl;
    //Table Header
    cout << " h    monday   tuesday wednesday  thursday    friday" << endl;
    for (int i = 0; i < table.size(); ++i) {
        int h_now = begin + i;
        if (h_now < 10) cout << ' ';
        cout << h_now;
        for (int j = 0; j < 5; ++j) printSlotTeacher (table[i][j].listteachers, remplazos);
        cout << endl;
    }
    cout << "number of replacements needed to avoid conflicts:" << endl << remplazos << endl;
}



