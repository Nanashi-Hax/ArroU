add_library(Platform
    TestLogger.cpp
    TestStream.cpp
    TestPCService.cpp
)

target_include_directories(Platform PRIVATE
    ${PROJECT_SOURCE_DIR}/Source
)