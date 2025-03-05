#include <Arduino.h>
#include <map>


std::map<std::string, int> runtimes = {
    {"1-3", 0},
    {"2-4", 1},
    {"3-1", 2},
    {"4-2", 3}
};
std::map<std::string, int> results = {
    {"windSpeed", 0},
    {"windDirection", 1},
    {"Temperature", 2}
};


void setup() {
    // write your initialization code here

}

void loop() {
// write your code here
}