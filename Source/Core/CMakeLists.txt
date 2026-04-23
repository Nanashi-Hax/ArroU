add_library(Core
    Logger.cpp
    Stream.cpp
    RPCPC.cpp
    RPCWiiU.cpp
)

target_include_directories(Core PRIVATE
    ${PROJECT_SOURCE_DIR}/Source
)