#include <Arduino.h>

float calculateMean(float data[], int length){
    float total = 0;
    for(int i =0; i< length; i++){
        total+=data[i];
    }

    float mean = total/ length;
    return mean;
}

float calculateStd(float data[], int length, float mean){
    float sumOfSquares = 0;
    for(int i =0; i< length; i++){
        sumOfSquares+= pow(data[i], 2);
    }

    float std =  pow(sumOfSquares/length - pow(mean, 2)*length, 0.5);
    return std;
}