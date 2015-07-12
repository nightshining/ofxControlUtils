# ofxControlUtils
Addon for commonly used utility functions

###bool ticker(bool toggle, int interval);

- Return a boolean value for every interval.

###int counter(bool increment, int maxValue);

- Whenever this function receives 'true' it increments an int starting at '0' and ending at int maxValue.

###int timer(int maxTime); 

- A milliseconds timer that resets on every 'int maxTime'.

###bool triggerOnEqual(int input, int compare);

- A simple logic statement that returns a very brief 'true' value then resets to 'false' until comparision is equal again.
 
### bool stateCheck(float input, float thresh);

- If the 'input' is greater than 'thresh' this function returns a very brief 'true'.

###bool stateCheck(float input, float minThresh, float maxThresh);

- If 'input' is less than 'minThresh' return brief 'true' or if 'input' is greater than 'maxThresh'

###float rampToggle(bool toggle, float speedUp, float speedDown);

- Ramp up 0.0 - 1.0 with specified time if 'true'.
- Ramp down 1.0 - 0.0 with specified time if 'false.

###float smoothData(vector<float> inputData, const int smoothAmt);

- Function for smoothing and return a float value.
