set(PROJECT dme_controls)

set(SOURCES
    attributeslider.cpp
    AssetBuilder.cpp
    attributeassetpickerpanel.cpp
    AttributeBasePickerPanel.cpp
    AttributeBoolChoicePanel.cpp
    AttributeColorPickerPanel.cpp
    attributedetailtypepickerpanel.cpp
    AttributeElementPanel.cpp
    AttributeElementPickerPanel.cpp
    AttributeFilePickerPanel.cpp
    AttributeIntChoicePanel.cpp
    AttributeInterpolatorChoicePanel.cpp
    AttributeMDLPickerPanel.cpp
    AttributeSequencePickerPanel.cpp
    attributeshaderpickerpanel.cpp
    AttributeSoundPickerPanel.cpp
    AttributeStringChoicePanel.cpp
    attributesurfacepropertypickerpanel.cpp
    AttributeTextEntry.cpp
    AttributeTextPanel.cpp
    AttributeWidgetFactory.cpp
    BaseAttributeChoicePanel.cpp
    BaseAttributeDoubleChoicePanel.cpp
    BaseAttributePanel.cpp
    ChannelGraphPanel.cpp
    dmecombinationsystemeditorpanel.cpp
    dmecontrols.cpp
    dmedageditpanel.cpp
    dmedagrenderpanel.cpp
    dmelogeditpanel.cpp
    dmemdlpanel.cpp
    dmepanel.cpp
    dmepicker.cpp
    dmepresetgroupeditorpanel.cpp
    DmeSourceDCCFilePanel.cpp
    DmeSourceSkinPanel.cpp
    ElementPropertiesTree.cpp
    FileListManager.cpp
    filtercombobox.cpp
    particlesystempanel.cpp
    particlesystempropertiespanel.cpp
    soundpicker.cpp
    soundrecordpanel.cpp

    BaseAnimationSetEditor.cpp
	BaseAnimSetAttributeSliderPanel.cpp
	BaseAnimSetControlGroupPanel.cpp
	BaseAnimSetPresetFaderPanel.cpp
	presetpicker.cpp
	${SRCDIR}/public/phonemeconverter.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE DMECONTROLS_LIB)