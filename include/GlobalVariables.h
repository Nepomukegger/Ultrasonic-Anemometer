#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include <map>

//global variables
extern std::map<std::string, int64_t> runtime = {
    {"1-3", 0},
    {"2-4", 1},
    {"3-1", 2},
    {"4-2", 3}
};
extern std::map<std::string, double> results = {
    {"windSpeedX", 0},
    {"windSpeedY", 0},
    {"trueWindSpeed", 0},
    {"windDirection", 0},
    {"speedOfSoundX", 0},
    {"speedOfSoundY", 0},
    {"speedOfSoundAvg", 0},
    {"Temperature", 0}
};


#endif //GLOBALVARIABLES_H
