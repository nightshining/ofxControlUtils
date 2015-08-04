#include "ofxControlUtils.h"


ofxControlUtils::ofxControlUtils(){
    
    //Set Metro Variables
    intialDuration = 1000; //Set metro default every '1 sec'
    intervalThresh = ofGetElapsedTimeMillis() + intialDuration;
    
    //Set Counter Variables
    count = 0;
    
    //Set Timer Variables
    startTime = ofGetElapsedTimeMillis();
    endTime = 1000; //change every second
    
    //Set Check State Util Variable
    checkStateThresh = false;
    checkStateRange = false;
    checkStateTrigger = false;
    
    ramp = 0.0;
    
    
}

ofxControlUtils::~ofxControlUtils(){
    
}

bool ofxControlUtils::ticker(bool toggle, int interval) {
    
    // This function recieves a 'bool toggle' to make it run or stop
    // It recieves an 'int interval' '1000' = return a '1'  every '1' second
    
    if (toggle) {
        
        bool trigger;
        
        if (ofGetElapsedTimeMillis() > intervalThresh) {
            
            int difference = intervalThresh - ofGetElapsedTimeMillis();
            intervalThresh = ofGetElapsedTimeMillis() + interval;
            
            trigger = true;
            
        } else {
            
            trigger = false;
        }
        
        return trigger;
        
    }
    
    return false;
}


int ofxControlUtils::counter(bool increment, int maxValue) {
    
    //Every time this function receives a '1' it increments and returns an 'int' value
    
    if (increment) {
        
        count++;
        
        if (count > maxValue) {
            count = 0;
        }
    }
    return count;
}

int ofxControlUtils::timer(int maxTime){
    
    //Set a timer that resets at every 'int maxTime'
    
    int timer = ofGetElapsedTimeMillis() - startTime;
    
    endTime = maxTime;

    if (timer >= endTime) {
    
        startTime = ofGetElapsedTimeMillis();
    
    }
    
    return timer;
}


bool ofxControlUtils::stateCheck(float input, float thresh){
    
    // Check if some 'int input' is below or above
    // an 'int thresh' and return a false or true respectively

    bool toggle = false;
    
    if (checkStateThresh == false) { //&& ofGetSystemTime() <= 1
        
        if (input > thresh ) {
            
            //cout << "on" << endl;
            
            toggle = true;
            
            checkStateThresh = !checkStateThresh; // this just flips is each time this statement happens
        }
        
    }
    
    if (checkStateThresh == true ) { //&& ofGetSystemTime() <= 1
        
        if (input < thresh) {
            
            //cout << "off" << endl;

            toggle = false;
            
            checkStateThresh = !checkStateThresh;
        }
        
    }
    
    return toggle;
    
}

bool ofxControlUtils::stateCheck(float input, float minThresh, float maxThresh){
    
    // Check if some 'int input' is between min and max value
    // if it is return a '1'
    
    bool toggle = false;
    
    if (checkStateRange == false) { //&& ofGetSystemTime() <= 1
        
        if (input < minThresh || input > maxThresh) {
            
            //cout << "on" << endl;
            
            toggle = true;
            
            checkStateRange = !checkStateRange; // this just flips is each time this statement happens
        }
        
    }
    
    
    if (checkStateRange == true ) { //&& ofGetSystemTime() <= 1
        
        if (input > minThresh && input <= maxThresh ) {
            
            //cout << "off" << endl;
            
            toggle = false;
            
            checkStateRange = !checkStateRange;
        }
        
    }
    
    return toggle;
    
}

bool ofxControlUtils::triggerOnEqual(int input, int compare) {
    
    // Check if some 'int input' is equal to 'int compare'
    // if it is return a '1'
    
    bool toggle = false;
    
    if (checkStateTrigger == false) {
        
        if (input == compare) {
            
            //cout << "on" << endl;
            
            toggle = true;
            
            checkStateTrigger = !checkStateTrigger; // this just flips is each time this statement happens
        }
        
    }
    
    if (checkStateTrigger == true ) {
        
        if (input != compare) {
            
            //cout << "off" << endl;
            
            toggle = false;
            
            checkStateTrigger = !checkStateTrigger;
        }
        
    }
    
    return toggle;
    
}

float ofxControlUtils::rampToggle(bool toggle, float speedUp, float speedDown){
    
    if (toggle) {
        
        ramp = ofLerp(ramp, 1.0, speedUp);
            
    } else {
        
        ramp = ofLerp(ramp, 0.0, speedDown);
        
    }
    
    if (ramp <= 0.01) {
        ramp = 0.0;
    }
    
    return ramp;
}

float ofxControlUtils::smoothData(vector<float> inputData, const int smoothAmt) {
    
    float averageVal;
    
    for (int i = 0; i < smoothAmt; i++)
    {
        averageVal += inputData[i];
        
    }
    
    averageVal = averageVal / inputData.size();
    
    return averageVal;

}
