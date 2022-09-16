#pragma once
#ifndef BREAKOUT_CONFIG_LOADER_H
#define BREAKOUT_CONFIG_LOADER_H

#include <iostream>
#include <optional>
#include <filesystem>
#include <fstream>
#include <vector>
#include <tuple>
#include <map>

#include "texts.h"
#include "rectangle.h"

using std::vector;

class Loader {
public:
    static void parse_config(const std::string&, std::map<std::string, uint16_t>& );
    static void parse_text(vector<Displayable*>& , const std::string& );
    static void text_loader(vector<Displayable*>& , const std::string& );
};


#endif //BREAKOUT_CONFIG_LOADER_H
