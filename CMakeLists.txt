cmake_minimum_required(VERSION 3.15)
project(JuceQtLearning VERSION 0.0.1)

find_package(JUCE CONFIG REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick QuickControls2 Core5Compat)

qt_standard_project_setup()

juce_add_plugin(JuceQtLearning
        COMPANY_NAME "JuceQtLearning Company"
        PRODUCT_NAME "JuceQtLearning"
        BUNDLE_ID "io.JuceQtLearning"
        FORMATS AU VST3 Standalone
        COPY_PLUGIN_AFTER_BUILD TRUE
)

target_sources(JuceQtLearning
        PRIVATE
        # headers
        src/PluginProcessor.h
        src/PluginEditor.h
        src/JuceQComponent.h
        src/QMLApplication.h

        # Models
        src/Models/GainModel.h

        # Controllers
        src/Controllers/GainController.h

        # sources
        src/PluginProcessor.cpp
        src/PluginEditor.cpp
        src/JuceQComponent.cpp
        src/QMLApplication.cpp

        # Models
        src/Models/GainModel.cpp
)

target_compile_definitions(JuceQtLearning
        PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(JuceQtLearning
        PRIVATE
        juce::juce_audio_utils
        Qt6::Core
        Qt6::Gui
        Qt6::Quick
        Qt6::QuickControls2
        Qt6::Core5Compat
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

# Ease up on juce_recommended_warning_flags a bit
target_compile_options(juce_recommended_warning_flags INTERFACE
        -Wno-gnu-zero-variadic-macro-arguments
        -Wno-switch-enum
        -Wno-missing-prototypes
)

qt_add_resources(JuceQtLearning "qml" FILES
        src/QML/main.qml
        src/QML/Definitions.qml
        src/QML/Knob.qml
        src/QML/SharedFunctions.js
        src/Images/button.png
)
qt_import_qml_plugins(JuceQtLearning)
