/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class AudioFilterVstAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    AudioFilterVstAudioProcessorEditor (AudioFilterVstAudioProcessor&);
    ~AudioFilterVstAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:

	//scopedPointer is a pointer that autimatically deletes itself when you fall out of scope. Very good for memory management
	ScopedPointer<Slider> Cutoff_knob;
	ScopedPointer<Slider> Res_knob;
	ScopedPointer<Slider> Drive_knob;
	ScopedPointer<Slider> Fat_knob;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> Cutoff_Attachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> Res_Attachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> Drive_Attachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> Fat_Attachment;


    AudioFilterVstAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioFilterVstAudioProcessorEditor)
};
