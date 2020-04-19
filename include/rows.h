#ifndef ROWS_H_
#define ROWS_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Rows {
public:
    Rows();
    Rows(const vector<vector<string>>& data, bool first_row_header = false);
    Rows(const vector<vector<string>>& data, const vector<string>& header);
    void add_row(const vector<string>& row);
    void set_header(const vector<string>& header);
    bool have_header() const;
    const vector<string>& get_header() const ;
    const vector<vector<string>>& get_data() const;
    void PrintTable() ;
private:
    bool m_have_header = false;
    vector<string> m_header;
    vector<vector<string>> m_data;
};

#endif