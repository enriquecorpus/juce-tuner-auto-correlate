/*
  ==============================================================================

    AppLookAndFeel.h
    Created: 22 Jul 2020 9:27:22am
    Author:  ver

  ==============================================================================
*/
#pragma once
class AppLookAndFeelCls :
    //public LookAndFeel_V2
    public LookAndFeel_V3
{

public:
    AppLookAndFeelCls()
    {
        //setColour(DocumentWindow::ColourIds::textColourId, UI_Color2);

        setColour(ResizableWindow::ColourIds::backgroundColourId, CtrlBackgroundColor);

        setColour(GroupComponent::ColourIds::textColourId, juce::Colours::white);
        setColour(GroupComponent::ColourIds::outlineColourId, UI_Color3);

        setColour(Toolbar::ColourIds::backgroundColourId, Color_extremedarkgrey);
        setColour(Toolbar::ColourIds::separatorColourId, UI_Color3);
        setColour(Toolbar::ColourIds::labelTextColourId, juce::Colours::white);

        setColour(PropertyComponent::ColourIds::backgroundColourId, Color_extremedarkgrey);
        setColour(PropertyComponent::ColourIds::labelTextColourId, juce::Colours::white);

        setColour(BubbleComponent::ColourIds::backgroundColourId, Color_extremedarkgrey);
        setColour(BubbleComponent::ColourIds::outlineColourId, UI_Color3);

        setColour(TreeView::ColourIds::backgroundColourId, Color_extremedarkgrey);
        setColour(TreeView::ColourIds::linesColourId, UI_Color3);
        setColour(TreeView::ColourIds::selectedItemBackgroundColourId, UI_Color1);

        setColour(ToggleButton::ColourIds::tickColourId, Button_Background_Color);
        setColour(ToggleButton::ColourIds::textColourId, juce::Colours::white);
        //setColour(ToggleButton::ColourIds::tickDisabledColourId, Button_Background_Color);

        setColour(TextButton::ColourIds::buttonColourId, Button_Background_Color);
        setColour(TextButton::ColourIds::buttonOnColourId, Button_Background_Color);
        setColour(ButtonOutlineColorID, UI_Color3);
        setColour(TextButton::ColourIds::textColourOffId, juce::Colours::black);
        setColour(TextButton::ColourIds::textColourOnId, juce::Colours::white);

        //setColour(Label::ColourIds::backgroundColourId, CtrlBackgroundColor);
        //setColour(Label::ColourIds::backgroundColourId, juce::Colours::darkgrey);
        setColour(Label::ColourIds::outlineColourId, Color_extremedarkgrey);
        setColour(Label::ColourIds::outlineWhenEditingColourId, UI_Color2);
        setColour(Label::ColourIds::textColourId, juce::Colours::white);

        setColour(ProgressBar::ColourIds::backgroundColourId, Color_extremedarkgrey);
        setColour(ProgressBar::ColourIds::foregroundColourId, UI_Color1);

        //setColour(ScrollBar::ColourIds::backgroundColourId, CtrlBackgroundColor);
        setColour(ScrollBar::ColourIds::backgroundColourId, juce::Colours::darkgrey);
        setColour(ScrollBar::ColourIds::trackColourId, UI_Color3);
        setColour(ScrollBar::ColourIds::thumbColourId, UI_Color1);

        setColour(TextEditor::ColourIds::backgroundColourId, Color_extremedarkgrey);
        setColour(TextEditor::ColourIds::outlineColourId, UI_Color3);
        setColour(TextEditor::ColourIds::highlightColourId, UI_Color2);
        setColour(TextEditor::ColourIds::highlightedTextColourId, UI_Color3);
        setColour(TextEditor::ColourIds::focusedOutlineColourId, juce::Colours::black);
        setColour(TextEditor::ColourIds::focusedOutlineColourId, juce::Colours::black);
        setColour(TextEditor::ColourIds::textColourId, juce::Colours::white);

        setColour(ListBox::ColourIds::backgroundColourId, Color_extremedarkgrey);
        //setColour(ListBox::ColourIds::backgroundColourId, juce::Colours::black);
        setColour(ListBox::ColourIds::outlineColourId, UI_Color3);
        setColour(ListBox::ColourIds::textColourId, juce::Colours::white);

        setColour(ComboBox::ColourIds::backgroundColourId, Color_extremedarkgrey);
        setColour(ComboBox::ColourIds::outlineColourId, UI_Color3);
        setColour(ComboBox::ColourIds::buttonColourId, UI_Color2);
        setColour(ComboBox::ColourIds::focusedOutlineColourId, UI_Color1);
        setColour(ComboBox::ColourIds::textColourId, juce::Colours::white);

        setColour(PopupMenu::ColourIds::backgroundColourId, AppBackgroundColor);
        //setColour(PopupMenu::ColourIds::backgroundColourId, Color_verydarkorange);
        setColour(PopupMenu::ColourIds::textColourId, juce::Colours::white);
        setColour(PopupMenu::ColourIds::highlightedBackgroundColourId, UI_Color3);
        setColour(PopupMenu::ColourIds::highlightedTextColourId, UI_Color1);
        setColour(PopupMenu::ColourIds::headerTextColourId, UI_Color2);
        setColour(PopupMenu::ColourIds::textColourId, juce::Colours::white);

        setColour(Slider::ColourIds::backgroundColourId, CtrlBackgroundColor);
        setColour(Slider::ColourIds::thumbColourId, UI_Color1);
        setColour(Slider::ColourIds::trackColourId, UI_Color2);
        setColour(Slider::ColourIds::rotarySliderFillColourId, UI_Color2);
        setColour(Slider::ColourIds::rotarySliderOutlineColourId, juce::Colours::black);
        setColour(Slider::ColourIds::textBoxBackgroundColourId, UI_Color3);
        setColour(Slider::ColourIds::textBoxTextColourId, juce::Colours::white);
        setColour(Slider::ColourIds::textBoxHighlightColourId, UI_Color1);
        setColour(Slider::ColourIds::textBoxOutlineColourId, UI_Color3);

        setColour(TooltipWindow::ColourIds::backgroundColourId, juce::Colours::black);
        setColour(TooltipWindow::ColourIds::textColourId, juce::Colours::white);
        setColour(TooltipWindow::ColourIds::outlineColourId, UI_Color3);

        setColour(TabbedButtonBar::ColourIds::tabOutlineColourId, UI_Color3);
        setColour(TabbedButtonBar::ColourIds::frontOutlineColourId, UI_Color1);
        setColour(TabbedButtonBar::ColourIds::tabTextColourId, juce::Colours::white);
        setColour(TabbedButtonBar::ColourIds::frontTextColourId, juce::Colours::white);

#if 1
        setColour(LookAndFeel_V4::ColourScheme::UIColour::windowBackground, AppBackgroundColor);
        setColour(LookAndFeel_V4::ColourScheme::UIColour::widgetBackground, CtrlBackgroundColor);
        setColour(LookAndFeel_V4::ColourScheme::UIColour::defaultFill, CtrlBackgroundColor);
        setColour(LookAndFeel_V4::ColourScheme::UIColour::highlightedFill, UI_Color2);
        setColour(LookAndFeel_V4::ColourScheme::UIColour::menuBackground, Color_verydarkorange);
        setColour(LookAndFeel_V4::ColourScheme::UIColour::outline, UI_Color3);
        setColour(LookAndFeel_V4::ColourScheme::UIColour::defaultText, juce::Colours::white);
#endif
    }

};