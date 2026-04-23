#include "Interface/IStream.hpp"
#include "Interface/ILogger.hpp"

#include "Platform/Test/TestStream.hpp"
#include "Platform/Test/TestLogger.hpp"
#include "Platform/Test/TestPCService.hpp"

#include "App/Test/App.hpp"

int main()
{
    IStream* stream = new TestStream();
    ILogger* logger = new TestLogger();
    IPCService* pc = new TestPCService();
    App app(stream, logger, pc);
    return app.run();
}