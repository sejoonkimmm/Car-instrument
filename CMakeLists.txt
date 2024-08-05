cmake_minimum_required(VERSION 3.16)

project(instrument-cluster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 NAMES Qt6 Qt5 REQUIRED COMPONENTS Quick SerialBus)

qt_standard_project_setup()

qt_add_executable(appinstrumentcluster
    src/main.cpp
)

qt_add_qml_module(appinstrumentcluster
    URI instrumentcluster
    VERSION 1.0
    QML_FILES
        src/Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appinstrumentcluster PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appinstrumentcluster
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appinstrumentcluster
    PRIVATE Qt6::Quick Qt6::SerialBus
)

include(GNUInstallDirs)
install(TARGETS appinstrumentcluster
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
