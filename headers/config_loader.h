#pragma once
#ifndef BREAKOUT_CONFIG_LOADER_H
#define BREAKOUT_CONFIG_LOADER_H

#include <iostream>
#include <optional>
#include <filesystem>
#include <fstream>
#include <vector>
#include <tuple>
#include <memory>

#include "texts.h"
#include "rectangle.h"

using std::vector;

class Loader {
public:
    static void parse_text(vector<std::shared_ptr<Displayable*>>& , const std::string& );
    static void text_loader(vector<std::shared_ptr<Displayable*>>& , const std::string& );
};


#endif //BREAKOUT_CONFIG_LOADER_H
