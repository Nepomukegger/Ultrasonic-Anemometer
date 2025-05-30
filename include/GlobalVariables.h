#pragma once

#include <map>
#include <unordered_map>
#include <string>
#include "config.h"

extern std::map<std::string, int64_t> runtime;
extern std::map<std::string, double> results;
extern std::unordered_map<std::string, std::pair<std::pair<int, int>, std::pair<int, int>>> SelectPins;