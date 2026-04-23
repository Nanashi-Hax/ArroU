#include "Interface/INetwork.hpp"
#include "Interface/ILogger.hpp"

#include "Platform/Test/TestNetwork.hpp"
#include "Platform/Test/TestLogger.hpp"

#include "App/Test/App.hpp"

int main()
{
    INetwork* network = new TestNetwork();
    ILogger* logger = new TestLogger();
    App app(network, logger);
    return app.run();
}