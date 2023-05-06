
find_package(Qt6 QUIET COMPONENTS Core)


if(NOT Qt6_FOUND AND NOT TARGET Qt6::Core)

set(QT_BUILD_TESTS OFF)
set(QT_BUILD_EXAMPLES OFF)
set(QT_FEATURE_sql OFF)
set(QT_FEATURE_network OFF)
set(QT_FEATURE_gui OFF)
#set(QT_FEATURE_regularexpression OFF)
set(QT_FEATURE_concurrent OFF)
set(QT_FEATURE_xml OFF)
set(QT_FEATURE_dbus OFF)
set(QT_FEATURE_opengl OFF)
set(QT_FEATURE_widgets OFF)
set(QT_FEATURE_testlib OFF)
set(QT_FEATURE_printsupport OFF)
#set(QT_FEATURE_commandlineparser OFF)
set(QT_FEATURE_androiddeployqt OFF)
set(QT_FEATURE_macdeployqt OFF)
set(QT_FEATURE_windeployqt OFF)
set(QT_SUPERBUILD OFF)
#set(QT_WILL_BUILD_TOOLS OFF)

include(FetchContent)
FetchContent_Declare(
        qtbase
        GIT_REPOSITORY git://code.qt.io/qt/qtbase.git
        GIT_TAG dev 
        )
FetchContent_MakeAvailable(qtbase)

endif(NOT Qt6_FOUND AND NOT TARGET Qt6::Core)

