/*
  ==============================================================================

    AppInc.h
    Created: 22 Jul 2020 9:36:14am
    Author:  ver

  ==============================================================================
*/

#pragma once



#include <JuceHeader.h>
using namespace juce;


#define MaxInputChannels            6
//#define MaxInputChannels          4


#define MainOutputHeaderText        ("Main Output")
#define FxReturnHeaderText          ("FX Return")
#define MonitorOutputHeaderText     ("Monitor Output")



const Colour Color_darkdarkgrey{ 0xff202020 };
const Colour Color_extremedarkgrey{ 0xff101010 };
const Colour Color_verydarkorange{ 0xff553300 };


#define ButtonOutlineColorID        ComboBox::outlineColourId


#define UI_Color1                   juce::Colours::orange

#define UI_Color2                   juce::Colours::darkorange

#define UI_Color3                   Color_verydarkorange

#define UI_Color4                   Color_verydarkorange

#define Button_Border_Color         juce::Colours::orange

#define Button_Background_Color     UI_Color2

#define Button_Selected_Color       UI_Color1

#define UI_TextColor                juce::Colours::white

#define AppBackgroundColor          juce::Colours::black

//#define CtrlBackgroundColor       Color_darkdarkgrey
#define CtrlBackgroundColor         Color_extremedarkgrey



//#include "VUMeterCls.h"
//
//
//#include "MenuUtils.h"

#define Mixer_Width                 830
#define Mixer_Height                465


class FxSelectionWin;
class FXSelectorCls;
class MyAudioDevSelComp;
class AudioDevSelWin;
class DeviceSelectorCls;
class InputChannelCls;
class TrackMgrCls;
class TrackViewCls;
class MasterSectionCls;
class MixerCls;


#include "AppLookAndFeel.h"
#include "PowerButtonLookAndFeel.h"
