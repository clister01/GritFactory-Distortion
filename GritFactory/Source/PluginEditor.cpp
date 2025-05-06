void GritFactoryAudioProcessorEditor::timerCallback() {
    // Update VU meter
    float peak = audioProcessor.getPeakLevel();
    updateVUMeter(peak);
}

void GritFactoryAudioProcessorEditor::updateVUMeter(float level) {
    vuMeter.setText(juce::String(level, 1) + " dB", juce::dontSendNotification);
    vuMeter.setColour(juce::Label::textColourId, 
        level > 0.0f ? juce::Colours::red : juce::Colour(210, 170, 80));
}