set(PROJECT matsys_controls)

set(SOURCES
    assetpicker.cpp
    baseassetpicker.cpp
    colorpickerpanel.cpp
    curveeditorpanel.cpp
    gamefiletreeview.cpp
    manipulator.cpp
    matsyscontrols.cpp
    mdlpanel.cpp
    mdlpicker.cpp
    mdlsequencepicker.cpp
    picker.cpp
    potterywheelpanel.cpp
    proceduraltexturepanel.cpp
    QCGenerator.cpp
    sequencepicker.cpp
    tgapreviewpanel.cpp
    vmtpicker.cpp
    vmtpreviewpanel.cpp
    vtfpicker.cpp
    vtfpreviewpanel.cpp
    vmtpanel.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})