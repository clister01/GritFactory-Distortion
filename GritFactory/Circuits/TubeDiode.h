#pragma once
#include <JuceHeader.h>

class TubeDiode {
public:
    float process(float x) {
        // Asymmetric tube distortion
        if (x > 0) return std::atan(x * drive) / std::atan(drive);
        else return std::atan(x * drive * 0.5f) / std::atan(drive * 0.5f);
    }
    void setDrive(float d) { drive = d; }
private:
    float drive = 1.0f;
};