add_executable(ArroU main.cpp)

target_include_directories(ArroU PRIVATE
    ${PROJECT_SOURCE_DIR}/Source
)

target_link_libraries(ArroU PRIVATE
    App Core Platform
)