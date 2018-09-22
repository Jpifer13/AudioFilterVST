/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioFilterVstAudioProcessor::AudioFilterVstAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{

	state = new AudioProcessorValueTreeState(*this, nullptr);

	state->createAndAddParameter("cutoff", "Cutoff", "Cutoff", NormalisableRange<float>(0.0, 1.0, 0.0001), 1.0, nullptr, nullptr);
	state->createAndAddParameter("drive", "Drive", "Drive", NormalisableRange<float>(0.0, 1.0, 0.0001), 1.0, nullptr, nullptr);
	state->createAndAddParameter("res", "Res", "Res", NormalisableRange<float>(0.0, 1.0, 0.0001), 1.0, nullptr, nullptr);
	state->createAndAddParameter("fat", "Fat", "Fat", NormalisableRange<float>(0.0, 1.0, 0.0001), 1.0, nullptr, nullptr);

	state->state = ValueTree("cutoff");
	state->state = ValueTree("drive");
	state->state = ValueTree("res");
	state->state = ValueTree("fat");

}

AudioFilterVstAudioProcessor::~AudioFilterVstAudioProcessor()
{
}

//==============================================================================
const String AudioFilterVstAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AudioFilterVstAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AudioFilterVstAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AudioFilterVstAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AudioFilterVstAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AudioFilterVstAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AudioFilterVstAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AudioFilterVstAudioProcessor::setCurrentProgram (int index)
{
}

const String AudioFilterVstAudioProcessor::getProgramName (int index)
{
    return {};
}

void AudioFilterVstAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AudioFilterVstAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void AudioFilterVstAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AudioFilterVstAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AudioFilterVstAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

AudioProcessorValueTreeState& AudioFilterVstAudioProcessor::getState() {

	return *state;

}


//==============================================================================
bool AudioFilterVstAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AudioFilterVstAudioProcessor::createEditor()
{
    return new AudioFilterVstAudioProcessorEditor (*this);
}

//==============================================================================
void AudioFilterVstAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

	MemoryOutputStream stream(destData, false);
	state->state.writeToStream(stream);

}

void AudioFilterVstAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.

	ValueTree tree = ValueTree::readFromData(data, sizeInBytes):

		if (tree.isValid()) {

			state->state = tree;
		}

}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AudioFilterVstAudioProcessor();
}
