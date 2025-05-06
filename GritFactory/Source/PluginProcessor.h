#pragma once
#include <JuceHeader.h>
#include "Circuits/TapeSat.h"
#include "Circuits/TubeDiode.h"

class GritFactoryAudioProcessor : public juce::AudioProcessor {
public:
    GritFactoryAudioProcessor();
    ~GritFactoryAudioProcessor() override;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    juce::AudioProcessorValueTreeState apvts{*this, nullptr, "Params", createParameterLayout()};

private:
    TapeSat tapeSat;
    TubeDiode tubeSat;
    bool lastPunishState = false;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GritFactoryAudioProcessor)
};