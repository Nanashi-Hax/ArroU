add_library(Platform
    TestLogger.cpp
    TestNetwork.cpp
)

target_include_directories(Platform PRIVATE
    ${PROJECT_SOURCE_DIR}/Source
)