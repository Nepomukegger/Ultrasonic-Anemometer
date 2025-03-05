//
// Created by nepom on 04.03.2025.
//

#include <cmath>
#include "config.h"

namespace Calculate {
    void windSpeed() {
        //For the calculation of the wind speed sensor 1 is in direction x+ sensor 2 is in direction y+
        //sensor 3 is in direction x- and sensor 4 is in direction y-
        //we calculate the wind speed in x and y direction and then geometrically add them


        results["windSpeedX"] = SENSOR_DISTANCE/(sin(SENSOR_MOUNT_ANGLE)*cos(SENSOR_MOUNT_ANGLE))*(1/runtime["3-1"]-1/runtime["1-3"]);
        results["windSpedY"] = SENSOR_DISTANCE/(sin(SENSOR_MOUNT_ANGLE)*cos(SENSOR_MOUNT_ANGLE))*(1/runtime["4-2"]-1/runtime["2-4"]);

        results["trueWindSpeed"] = sqrt(pow(results["windSpeedX"], 2) + pow(results["windSpeedY"], 2));
    }


    void windDirection() {
        //For the calculation of the wind direction we use the arctan function
        //we calculate the wind direction in radians and then convert it to degrees

        if(results["windSpeedX"] > 0) {
            results["windDirection"] = atan(results["windSpeedY"]/results["windSpeedX"]);
        } else if(results["windSpeedX"] < 0) {
            if(results["windSpeedY"] >= 0) {
                results["windDirection"] = atan(results["windSpeedY"]/results["windSpeedX"]) + M_PI;
            } else {
                results["windDirection"] = atan(results["windSpeedY"]/results["windSpeedX"]) - M_PI;
            }
        } else if(results["windSpeedX"] == 0) {
            if(results["windSpeedY"] > 0) {
                results["windDirection"] = M_PI/2;
            } else if(results["windSpeedY"] < 0) {
                results["windDirection"] = -M_PI/2;
            } else {
                results["windDirection"] = 0;
            }
        }
        results["windDirection"] = results["windDirection"] * 180 / M_PI;
    }


    void Temperature() {
        //To get the temperature the Speed of sound is calculated and then the temperature is calculated
        results["speedOfSoundX"] = SENSOR_DISTANCE/sin(SENSOR_MOUNT_ANGLE)*(1/runtime["3-1"]+1/runtime["1-3"]);
        results["speedOfSoundY"] = SENSOR_DISTANCE/sin(SENSOR_MOUNT_ANGLE)*(1/runtime["4-2"]+1/runtime["2-4"]);
        results["speedOfSoundAvg"] = (results["speedOfSoundX"] + results["speedOfSoundY"])/2;

        results["Temperature"] = 273.15*(0.0000090998227809513409726345579419841*pow(results["speedOfSoundAvg"], 2) - 1);
    }
}