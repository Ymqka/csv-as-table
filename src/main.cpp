#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "rows.h"

using namespace std;

ostream& operator<<(ostream& os, const vector<string>& v) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); it++ ) {
        if (it+1 == v.end()) {
            os << *it;
        } else {
            os << *it << ", ";
        }
    }
    
    os << "]";

    return os;
}

ostream& operator<<(ostream& os, const vector<vector<string>>& v) {
    for(auto it = v.begin(); it != v.end(); it++ ) {
        if(it+1 == v.end()) {
            cout << *it;
        } else {
            cout << *it << endl;
        }
    }
    

    return os;
}

vector<string> parse_line(string line, char delimiter = ',') {
    vector<string> rv;
    
    stringstream s_stream(line);
    string word;

    while(getline(s_stream, word, delimiter)) {
        rv.push_back(word);
    }

    return rv;
}

ostream& operator<<(ostream& os, const Rows& rows) {
    bool have_header = rows.have_header();
    if(have_header == true) {

    } else {
        const vector<vector<string>> data = rows.get_data();
        cout << data;
    }
    return os;
}

int main() {

    ifstream input("input.txt");
    string line;
    Rows rows;
    while(getline(input,line)) {
        auto v = parse_line(line);
        rows.add_row(v);
    }

    cout << rows << endl;

    return 0;
}
