add_library(App
    App.cpp
)

target_include_directories(App PRIVATE
    ${PROJECT_SOURCE_DIR}/Source
)