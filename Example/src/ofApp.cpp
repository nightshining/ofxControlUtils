#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(ofColor::black);
    ofSetCircleResolution(60);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int w = ofGetWidth();
    int h = ofGetHeight();
    
    string title = "ofxControlUtils";
    ofSetColor(ofColor::orangeRed);
    ofDrawBitmapString(title, w * .10, h * .05);

    
    ofSetColor(ofColor::green);
    
    //// ofxControlUtils::ticker ////
    bool tickerOn = true;
    bool ticker = control.ticker(tickerOn, 1000);
    
    string tickerPrint;
    ticker ? tickerPrint = "True" : tickerPrint = "False";

    ofDrawBitmapString("Ticker: " + tickerPrint, w * .10, h * .10);
 
    //// ofxControlUtils::counter ////
    
    ofDrawBitmapString("Counter: " + ofToString(control.counter(ticker, 3)), w * .10, h * .15);
    
    //// ofxControlUtils::timer ////

    ofDrawBitmapString("Timer: " + ofToString(control.timer(1000)), w * .10, h * .20);
    
    //// ofxControlUtils::stateCheck ////
    
    //Move your Mouse passed the half way point of the window to trigger a 'true'
    
    bool stateCheckThresh = control.stateCheck(ofGetMouseX(), ofGetWidth() / 2);
    string stateCheckThreshPrint;
    stateCheckThresh ? stateCheckThreshPrint = "True" : stateCheckThreshPrint = "False";
    
    ofDrawBitmapString("State Check: " + ofToString(stateCheckThresh), w * .10, h * .25);

    //// ofxControlUtils::triggerOnEqual ////
    
    //Press any 'key' to trigger bool
    
    bool stateCheckTrigger = control.triggerOnEqual(ofGetKeyPressed(), 0);
    string stateCheckTriggerPrint;
    stateCheckTrigger ? stateCheckTriggerPrint = "True" : stateCheckTriggerPrint = "False";
    ofDrawBitmapString("Trigger On Equal: " + stateCheckTriggerPrint, w * .10, h * .30);
    
    //// ofxControlUtils::rampUp ////
    
    //Click press and release ramp up and down at two different speeds
    
    string rampUpDebug = ofToString(ofMap(control.rampToggle(ofGetMousePressed(), 0.50, 0.05), 0.0, 1.0, 0, 255));
    ofDrawBitmapString("Ramp Toggle: " + rampUpDebug, w * .10, h * .35);

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
