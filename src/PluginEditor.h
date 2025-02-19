#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

#include "JuceQComponent.h"
#include "PluginProcessor.h"
#include "QMLApplication.h"

#include <QGuiApplication>


class PluginEditor final : public juce::AudioProcessorEditor {
public:
    explicit PluginEditor(AudioPluginAudioProcessor &);
    ~PluginEditor() override;

    void resized() override;
    void childBoundsChanged(Component *child) override;

    void paint(juce::Graphics &) override;

private:
    AudioPluginAudioProcessor &processorRef;

    QGuiApplication mQtApp;
    JuceQComponent mJuceQComponent;
    QMLApplication qmlApplication;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
