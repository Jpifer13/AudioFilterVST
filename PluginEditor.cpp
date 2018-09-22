
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioFilterVstAudioProcessorEditor::AudioFilterVstAudioProcessorEditor (AudioFilterVstAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	addAndMakeVisible(Cutoff_knob = new Slider("Cutoff"));
	Cutoff_knob->setSliderStyle(Slider::Rotary);
	Cutoff_knob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	addAndMakeVisible(Drive_knob = new Slider("Drive"));
	Drive_knob->setSliderStyle(Slider::Rotary);
	Drive_knob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	addAndMakeVisible(Res_knob = new Slider("Res"));
	Res_knob->setSliderStyle(Slider::Rotary);
	Res_knob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	addAndMakeVisible(Fat_knob = new Slider("Fat"));
	Fat_knob->setSliderStyle(Slider::Rotary);
	Fat_knob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	Cutoff_Attachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "cutoff", *Cutoff_knob);
	Drive_Attachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "drive", *Drive_knob);
	Res_Attachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "res", *Res_knob);
	Fat_Attachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "fat", *Fat_knob);


    setSize (500, 200);
}

AudioFilterVstAudioProcessorEditor::~AudioFilterVstAudioProcessorEditor()
{
}

//==============================================================================
void AudioFilterVstAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void AudioFilterVstAudioProcessorEditor::resized()
{
    
	Cutoff_knob->setBounds(((getWidth() / 5) * 1) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
	Drive_knob->setBounds(((getWidth() / 5) * 2) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
	Res_knob->setBounds(((getWidth() / 5) * 3) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
	Fat_knob->setBounds(((getWidth() / 5) * 4) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);

}
