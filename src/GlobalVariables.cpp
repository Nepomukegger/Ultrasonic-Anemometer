#include "GlobalVariables.h"

std::map<std::string, int64_t> runtime = {
    {"1-3", 0},
    {"2-4", 1},
    {"3-1", 2},
    {"4-2", 3}
};

std::map<std::string, double> results = {
    {"windSpeedX", 0},
    {"windSpeedY", 0},
    {"trueWindSpeed", 0},
    {"windDirection", 0},
    {"speedOfSoundX", 0},
    {"speedOfSoundY", 0},
    {"speedOfSoundAvg", 0},
    {"Temperature", 0}
};

std::unordered_map<std::string, std::pair<std::pair<int, int>, std::pair<int, int>>> SelectPins = {
    {"1-3", {{S1, LOW}, {S0, LOW}}},
    {"2-4", {{S1, LOW}, {S0, HIGH}}},
    {"3-1", {{S1, HIGH}, {S0, LOW}}},
    {"4-2", {{S1, HIGH}, {S0, HIGH}}}
};