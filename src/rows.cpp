#include "rows.h"

Rows::Rows() {}

Rows::Rows(const vector<vector<string>>& data, bool first_row_header) {
    if (first_row_header == true) {
        m_data = data;
        m_header = m_data.front();
        m_have_header = true;
        m_data.erase(m_data.begin());
    } else {
        m_data = data;
    }
}

Rows::Rows(const vector<vector<string>>& data, const vector<string>& header) {
    m_data = data;
    m_header = header;
    m_have_header = true;
}

void Rows::add_row(const vector<string>& row) {
    m_data.push_back(row);
}

void Rows::set_header(const vector<string>& header) {
    m_header = header;
    m_have_header = true;
}

bool Rows::have_header() const {
    return m_have_header;
}

const vector<string>& Rows::get_header() const {
    return m_header;
}

const vector<vector<string>>& Rows::get_data() const {
    return m_data;
}




