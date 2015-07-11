#pragma once

#include "ofMain.h"


class ofxControlUtils {
    
public:

    
    ofxControlUtils();
    ~ofxControlUtils();
    
    bool ticker(bool toggle, int interval);
    int counter(bool increment, int maxValue);
    int timer(int maxTime);
    bool triggerOnEqual(int input, int compare);
    bool stateCheck(float input, float thresh);
    bool stateCheck(float input, float minThresh, float maxThresh);
    float rampToggle(bool toggle, float speedUp, float speedDown);
    float smoothData(vector<float> inputData, const int smoothAmt);
    
    //Note: In order for this to work it is a bit messy bc you need
    //to keep the function code right here
    
    //template <typename T> bool stateCheck(T input, T thresh);
    //template <typename T> bool stateCheck(T input, T minThresh, T maxThresh);
    
private:
    
    int intialDuration, intervalThresh;
    int count;
    int startTime, endTime;
    bool checkStateThresh, checkStateRange, checkStateTrigger; // Might need mutltiple bools for this
    float rampUpStart, rampDownStart;
    //Note: add rampPendulum?
    
    
};
