add_library(Core
    Logger.cpp
)

target_include_directories(Core PRIVATE
    ${PROJECT_SOURCE_DIR}/Source
)