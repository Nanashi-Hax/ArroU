#include "Interface/IStream.hpp"
#include "Interface/ILogger.hpp"

#include "Platform/Test/TestStream.hpp"
#include "Platform/Test/TestLogger.hpp"

#include "App/Test/App.hpp"

int main()
{
    IStream* stream = new TestStream();
    ILogger* logger = new TestLogger();
    App app(stream, logger);
    return app.run();
}