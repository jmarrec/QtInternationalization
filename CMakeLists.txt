cmake_minimum_required(VERSION 3.15)

project(QtInternationalization LANGUAGES CXX)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the followig variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools Test REQUIRED)
message(STATUS "Found Qt${QT_VERSION_MAJOR}")
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools Test REQUIRED)

set(TS_FILES
  translations/QtInternationalization_fr.ts
  translations/QtInternationalization_es.ts
)

set(PROJECT_SOURCES
  # main.cpp is included directly in executable, so that the test one doesn't find two mains
  mainwindow.cpp
  mainwindow.hpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

    qt_add_executable(QtInternationalization
        main.cpp

        ${PROJECT_SOURCES}
        ${QM_FILES}
    )
else()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

    message(STATUS "QM_FILES=${QM_FILES}")
    if(ANDROID)
        add_library(QtInternationalization SHARED
            main.cpp

            ${PROJECT_SOURCES}
        )
    else()
        add_executable(QtInternationalization
            main.cpp

            ${PROJECT_SOURCES}
            ${QM_FILES}
        )
    endif()


endif()

target_link_libraries(QtInternationalization PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

enable_testing(true)
add_executable(Internationalization_Test tests/Internationalization_Test.cpp ${PROJECT_SOURCES})
add_test(NAME Internationalization_Test COMMAND Internationalization_Test)

target_link_libraries(Internationalization_Test PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Widgets)
