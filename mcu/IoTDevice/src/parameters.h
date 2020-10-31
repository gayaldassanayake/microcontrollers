#ifndef ENV_H
#define ENV_H

struct Parameters
{
    int id;
    float temperature_mean;
    float humidity_mean;
    float pressure_mean;
    float light_mean;

    float temperature_std;
    float humidity_std;
    float pressure_std;
    float light_std;

    char* update_time;
};

#endif