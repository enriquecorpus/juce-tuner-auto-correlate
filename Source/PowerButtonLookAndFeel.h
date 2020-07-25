/*
  ==============================================================================

    PowerButtonLookAndFeel.h
    Created: 23 Jul 2020 10:57:17am
    Author:  ver

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

using namespace juce;

class PowerButtonLookAndFeel :
    //public LookAndFeel_V2
    public LookAndFeel_V4
{
public:
    PowerButtonLookAndFeel()
    {
        setColour(ToggleButton::ColourIds::tickColourId, Colour::fromRGB(214, 199, 113));
        setColour(ToggleButton::ColourIds::tickDisabledColourId, Colour::fromRGB(201, 201, 201));
    }

    void drawToggleButton(Graphics& g, ToggleButton& button,
        bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override {
        auto fontSize = jmin(15.0f, (float)button.getHeight() * 0.75f);
        auto tickWidth = fontSize * 1.1f;

        drawTickBox(g, button, 0, 0,
            (float)button.getWidth(), (float)button.getHeight(),
            button.getToggleState(),
            button.isEnabled(),
            shouldDrawButtonAsHighlighted,
            shouldDrawButtonAsDown);

        g.setColour(button.findColour(ToggleButton::textColourId));
        g.setFont(fontSize);

        if (!button.isEnabled())
            g.setOpacity(0.5f);

        g.drawFittedText(button.getButtonText(),
            button.getLocalBounds().withTrimmedLeft(roundToInt(tickWidth) + 10)
            .withTrimmedRight(2),
            Justification::centredLeft, 10);
    }

    void drawTickBox(Graphics& g, Component& component, float x, float y, float w, float h,
        bool ticked, bool isEnabled,
        bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override {

        ignoreUnused(isEnabled, shouldDrawButtonAsHighlighted, shouldDrawButtonAsDown);
        Rectangle<float> tickBounds(x + 10, y + 10, w - 20, h - 20);

        g.drawRoundedRectangle(tickBounds, 4.0f, 1.0f);

        g.setColour(component.findColour(ToggleButton::tickDisabledColourId));

        if (ticked)
        {

            DropShadow shadow(component.findColour(ToggleButton::tickColourId), 10, Point<int>(0, 0));
            shadow.drawForRectangle(g, Rectangle<int>(7, 7, w - 14, h - 14));

            g.setColour(component.findColour(ToggleButton::tickColourId));
        }

        g.fillRoundedRectangle(tickBounds, 4.0f);

        std::unique_ptr<XmlElement> svg_xml_1(XmlDocument::parse(BinaryData::power_svg));
        std::unique_ptr<Drawable> svg_drawable_play(Drawable::createFromSVG(*svg_xml_1));

        svg_drawable_play.get()->drawWithin(g, Rectangle<float>(x + 13.5, y + 13.5, w - 27, h - 27), RectanglePlacement::stretchToFit, 1);
    }
};