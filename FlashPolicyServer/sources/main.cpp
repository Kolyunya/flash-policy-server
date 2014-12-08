#include <Kolyunya/FPS/PolicyServer>

using namespace Kolyunya::FPS;

int main ( int argc , char** argv )
{
    PolicyServer policyServer(argc,argv);
    return policyServer.exec();
}
