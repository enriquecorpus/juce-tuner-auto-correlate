/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Pitchdetect_autocorrelateAudioProcessorEditor::Pitchdetect_autocorrelateAudioProcessorEditor (Pitchdetect_autocorrelateAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setLookAndFeel(&aLAF);
    
    addAndMakeVisible (infoLabel);
    infoLabel.setLookAndFeel(&aLAF);
    infoLabel.setText ("A4", juce::dontSendNotification);
    infoLabel.setColour (juce::Label::textColourId, juce::Colours::orange);
    infoLabel.setJustificationType (juce::Justification::centred);
    infoLabel.setFont (juce::Font (70.0f, juce::Font::bold));
    
    
    addAndMakeVisible(sliderFlat);
    sliderFlat.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    sliderFlat.setRange(0, 50.00);
    sliderFlat.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    
    addAndMakeVisible(sliderSharp);
    sliderSharp.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    sliderSharp.setRange(0, 50.00);
    sliderSharp.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);

    
    
    addAndMakeVisible(power);
    power.setLookAndFeel(&pbLAF);
    power.onClick = [this] {
       //Do something with the ui
    };

    setSize (492, 162);
    startTimer (50);
}

Pitchdetect_autocorrelateAudioProcessorEditor::~Pitchdetect_autocorrelateAudioProcessorEditor()
{
}

//==============================================================================
void Pitchdetect_autocorrelateAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
   g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour(juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText("TUNER", 10, 10, getWidth(), 30, juce::Justification::topLeft, 1);
    
    g.setColour(juce::Colours::grey);
    g.setFont (Font (30.00f, Font::italic));
    g.drawText ("b",
                20, 90, 200, 30,
                Justification::centred, true);

    g.setColour(juce::Colours::grey);
    g.setFont (Font (30.00f, Font::italic));
    g.drawText ("#",
                262, 90, 200, 30,
                Justification::centred, true);

    
}

void Pitchdetect_autocorrelateAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
        infoLabel.setBounds (0,  40, getWidth(),  70);
        power.setBounds(10, 40, 50, 50);
    
        sliderFlat.setBounds(70, 20, 100, 100);
        sliderSharp.setBounds(315, 20, 100, 100);
}

template <typename T1, typename T2>
T1 findClosestKey(const std::map<T1, T2> & data, T1 key)
{
    if (data.size() == 0) {
        throw std::out_of_range("Received empty map.");
    }

    auto lower = data.lower_bound(key);

    if (lower == data.end()) // If none found, return the last one.
        return std::prev(lower)->first;

    if (lower == data.begin())
        return lower->first;

    // Check which one is closest.
    auto previous = std::prev(lower);
    if ((key - previous->first) < (lower->first - key))
        return previous->first;

    return lower->first;
}
void Pitchdetect_autocorrelateAudioProcessorEditor::timerCallback()
{
        Pitchdetect_autocorrelateAudioProcessor& ourProcessor = getProcessor();
        double key = ourProcessor.pitch / 2;
        
        if(key <= 0.0f)
        {
          //  infoLabel.setText("--",juce::dontSendNotification);
            return;
        }
       
        //TODO PUT CORRECT MAPPING HERE
        std::map<double, std::string> data = {{16.35, "C0"}, {18.35, "D0"}, {210.60, "E0"}};
        double nearestKey = findClosestKey(data, key);
        double cents = key - nearestKey;

    
        infoLabel.setText((String)data[nearestKey] + " cents: " + (String)cents,juce::dontSendNotification);
        }
