#include "Interface/INetwork.hpp"

int main()
{
    INetwork* network = new TestNetwork();
    App app(network);
    return app.run();
}