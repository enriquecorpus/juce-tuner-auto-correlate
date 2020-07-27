/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "jucetice_MeterComponent.h"

//==============================================================================
Pitchdetect_autocorrelateAudioProcessorEditor::Pitchdetect_autocorrelateAudioProcessorEditor (Pitchdetect_autocorrelateAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setLookAndFeel(&aLAF);
    
    addAndMakeVisible (noteNameLabel);
    noteNameLabel.setLookAndFeel(&aLAF);
    noteNameLabel.setText ("C#", juce::dontSendNotification);
    noteNameLabel.setColour (juce::Label::textColourId, juce::Colours::orange);
    noteNameLabel.setJustificationType (juce::Justification::centred);
    noteNameLabel.setFont (juce::Font (65.0f, juce::Font::bold));
    noteNameLabel.setBounds (235,  60, 75,  75);
    
    
   // addAndMakeVisible(sliderFlat);
    sliderFlat.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    sliderFlat.setRange(0, 50.00);
    sliderFlat.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sliderFlat.setScrollWheelEnabled (false);
    
    //addAndMakeVisible(sliderSharp);
    sliderSharp.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    sliderSharp.setRange(0, 50.00);
    sliderSharp.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sliderSharp.setScrollWheelEnabled (false);

    
    
    flatMeter.reset (new MeterComponent (MeterComponent::MeterHorizontal, 20, 2, Colours::orange, Colours::orangered, Colours::darkorange, Colour(0xFF444444)));
     addAndMakeVisible (flatMeter.get());
     flatMeter->setName ("flatMeter");

     flatMeter->setBounds (90, 35, 175, 20);
    
    
    sharpMeter.reset (new MeterComponent (MeterComponent::MeterHorizontal, 20, 2, Colours::orange, Colours::orangered, Colours::darkorange, Colour(0xFF444444)));
     addAndMakeVisible (sharpMeter.get());
     sharpMeter->setName ("sharpMeter");

     sharpMeter->setBounds (280, 35, 175, 20);
    
    
    
    addAndMakeVisible(power);
    power.setLookAndFeel(&pbLAF);
    power.setBounds(5, 40, 50, 50);
    power.onClick = [this] {
       //Do something with the ui
        sliderSharp.setEnabled(power.getToggleState());
        sliderFlat.setEnabled(power.getToggleState());
       
        if(power.getToggleState()){
            startTimer (50);
        }else {
            stopTimer();
            sliderSharp.setValue(0.0f);
            sliderFlat.setValue(0.0f);
            //TODO updateWidgetValues method
             sharpMeter->setValue(0);
            flatMeter->setValue(0);
            noteNameLabel.setText("--",juce::dontSendNotification);
        }
    };

    setSize (492, 162);
    
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
    
    
    const int flat_png_size = 590;
    Image flat = ImageCache::getFromMemory (BinaryData::flat_png, flat_png_size);
    g.drawImageAt (flat, 63, 30);
    
    const int sharp_png_size = 535;
    Image sharp = ImageCache::getFromMemory (BinaryData::sharp_png, sharp_png_size);
    g.drawImageAt (sharp, 455, 30);
    
    
     int arrleft_png_size = 486;
     int arrright_png_size = 941;
    
    Image arrleft = ImageCache::getFromMemory (BinaryData::arrleft_png, arrleft_png_size);
    Image arrright = ImageCache::getFromMemory (BinaryData::arrright_png, arrright_png_size);
    
    if(arrowColourFlags == GREEN){
        arrleft_png_size = 415;
        arrright_png_size = 875;
        
        arrleft = ImageCache::getFromMemory (BinaryData::arrleft_green_png, arrleft_png_size);
        
        arrright = ImageCache::getFromMemory (BinaryData::arrright_green_png,arrright_png_size);
        
    }
    if(arrowColourFlags == ORANGE){
        arrleft_png_size = 463;
        arrright_png_size = 956;
        
        arrleft = ImageCache::getFromMemory (BinaryData::arrleft_orange_png, arrleft_png_size);
        
        arrright = ImageCache::getFromMemory (BinaryData::arrright_orange_png,arrright_png_size);
    }
    
    g.drawImageAt (arrright, 355, 83);
    g.drawImageAt (arrleft, 170, 87);

    
    
}

void Pitchdetect_autocorrelateAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
        
        
    
        sliderFlat.setBounds(70, 20, 100, 100);
        sliderSharp.setBounds(315, 20, 100, 100);
}

double noteFromPitch(float frequency) {
    double noteNum = 12 * (log(frequency / 440) / log(2));
    noteNum = round(noteNum) + 69;
    return noteNum;
}

float frequencyFromNoteNumber(float note) {
    return 440 * pow(2, (note - 69) / 12);
}

double centsOffFromPitch(float frequency, float note) {
    float frqFromNote = frequencyFromNoteNumber(note);
    float logOfPitch = log(frequency / frqFromNote);
    return floor(1200 * logOfPitch) / log(2);
}

void Pitchdetect_autocorrelateAudioProcessorEditor::updateWidgetValues(String noteName, float pitchTune) {
    noteNameLabel.setText("--",juce::dontSendNotification);
    sliderFlat.setValue(0.0f);
    sliderSharp.setValue(0.0f);
    
    //TODO change colours of text to green
    if(pitchTune == 0.0f)
        return;
    
    if(pitchTune < 0.0f){
        sliderFlat.setValue(abs(pitchTune));
    }

    if(pitchTune > 0.0f){
        sliderSharp.setValue(pitchTune);
    }
    noteNameLabel.setText(noteName,juce::dontSendNotification);
    //TODO include new value
    arrowColourFlags = 1;
    repaint();
}
void Pitchdetect_autocorrelateAudioProcessorEditor::timerCallback()
{
        Pitchdetect_autocorrelateAudioProcessor& ourProcessor = getProcessor();
        double key = ourProcessor.pitch / 2;
        

       float val = sharpMeter->getValue();
        sharpMeter->setValue(val + .1);
        flatMeter->setValue(val + .01);
    
    
//        std::array<String, 12> not = { "C","C#","D","Eb","E","F","F#","G","G#","A","Bb","B"};
//
//        int currentKey = noteFromPitch(key);
//        int Note = frequencyFromNoteNumber(currentKey);
//        float pitchTune = centsOffFromPitch(key, currentKey);
//        String noteName = (String)not[currentKey % 12]
//
//        updateWidgetValues(noteName, pitchTune);
}
