#pragma once
#include <JuceHeader.h>

class TapeSat {
public:
    float process(float x) {
        return std::tanh(x * drive) / std::tanh(drive);
    }
    void setDrive(float d) { drive = juce::jmap(d, 1.0f, 10.0f); }
private:
    float drive = 1.0f;
};