
find_package(Qt6 QUIET COMPONENTS Core)


if(NOT Qt6_FOUND AND NOT TARGET Qt6::Core)

set(QT_BUILD_TESTS OFF)
set(QT_BUILD_EXAMPLES OFF)
set(QT_FEATURE_sql OFF)
include(FetchContent)
FetchContent_Declare(
        qtbase
        GIT_REPOSITORY git://code.qt.io/qt/qtbase.git
        GIT_TAG dev 
        )
FetchContent_MakeAvailable(qtbase)

endif(NOT Qt6_FOUND AND NOT TARGET Qt6::Core)

