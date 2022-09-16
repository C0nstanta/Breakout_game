//
// Created by parallels on 9/15/22.
//
#include "../headers/config_loader.h"


void Loader::parse_config(const std::string& str, std::map<std::string, uint16_t>& m) {
    std::string val_str;
    std::string simple_text;

    size_t pos_1 = str.find(':');
    if(pos_1 != std::string::npos) {

        simple_text = str.substr(0, pos_1);
        val_str = str.substr(pos_1 + 1);
    }

    if (!val_str.empty() && !simple_text.empty()) {
        m[simple_text] = stoi(val_str);
    }
}

void Loader::text_loader(vector<Displayable*>& vec, const std::string& file_name = "greeting.txt") {
    vec.clear();
    std::ifstream file("../config/" + file_name);
    std::string tmp_str;

    while(std::getline(file, tmp_str)) {
        if (tmp_str[0] == '#') { continue; };

        parse_text(vec, tmp_str);

    }
}


void Loader::parse_text(vector<Displayable*>& vec, const std::string& str) {
    std::string x_str;
    std::string y_str;
    std::string simple_text;

    size_t pos_1 = str.find(':');
    if(pos_1 != std::string::npos) {
        size_t pos_2 = str.find(':', pos_1 + 1);
        if(pos_2 != std::string::npos) {

            x_str = str.substr(0, pos_1);
            y_str = str.substr(pos_1 + 1, pos_2 - pos_1 - 1);
            simple_text = str.substr(pos_2 + 1);
        }
    }

    if (!x_str.empty() && !y_str.empty() && !simple_text.empty()) {
        vec.push_back(new Text(std::stoi(x_str), std::stoi(y_str), simple_text));
    }
}
