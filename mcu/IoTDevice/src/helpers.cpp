#include <Arduino.h>
#include <vector>

using std::vector;

float calculateMean(vector<float> data){
    int length = data.size();
    float total = 0;
    for(int i =0; i< length; i++){
        total+=data.at(i);
    }

    float mean = total/ length;
    return mean;
}

float calculateStd(vector<float> data, float mean){
    int length = data.size();
    float sumOfSquares = 0;
    for(int i =0; i< length; i++){
        sumOfSquares+= pow(data.at(i), 2);
    }

    float std =  pow(sumOfSquares/length - pow(mean, 2)*length, 0.5);
    return std;
}