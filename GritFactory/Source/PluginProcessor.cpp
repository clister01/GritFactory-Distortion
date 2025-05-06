#include "PluginProcessor.h"
#include "PluginEditor.h"

GritFactoryAudioProcessor::GritFactoryAudioProcessor() {
    // Initialize parameters
    apvts.state = juce::ValueTree("Params");
}

void GritFactoryAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    auto type = apvts.getRawParameterValue("type")->load();
    auto inputGain = juce::Decibels::decibelsToGain(apvts.getRawParameterValue("input")->load());
    
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel) {
        auto* samples = buffer.getWritePointer(channel);
        for (int i = 0; i < buffer.getNumSamples(); ++i) {
            float x = samples[i] * inputGain;
            
            // Apply distortion
            switch (static_cast<int>(type)) {
                case 0: x = tapeSat.process(x); break;  // Tape
                case 1: x = tubeSat.process(x); break;  // Tube
                // Add other modes here
            }
            
            samples[i] = x;
        }
    }
}