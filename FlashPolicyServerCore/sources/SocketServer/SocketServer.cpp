#include <QtCore/QCoreApplication>
#include <QtCore/QThreadPool>
#include <Kolyunya/FPS/SocketServer>
#include <Kolyunya/FPS/PolicyFactory>
#include <Kolyunya/FPS/ClientRoutine>

#ifdef QT_DEBUG
    #include <QtCore/QDebug>
#endif

using namespace Kolyunya::FPS;

SocketServer::SocketServer ( QObject* parent ) :
    QTcpServer(parent)
{

}

SocketServer::~SocketServer ( void ) noexcept(true)
{

}

void SocketServer::setThreadPool ( QThreadPool* threadPool )
{
    this->threadPool = threadPool;
}

void SocketServer::setPolicyFactory ( PolicyFactory* policyFactory )
{
    this->policyFactory = policyFactory;
}

void SocketServer::initialize ( void )
{
    this->hostName = this->getParameter("HostName").toString();
    this->port = this->getParameter("Port").toUInt();
}

void SocketServer::launch ( void )
{

    // Start listening for new connections
    bool isListening = this->listen(this->hostName,this->port);

    // Print debug message
    #ifdef QT_DEBUG
        const char* status = isListening ? "started successfully." : "failed to start.";
        qDebug() << "Flash policy server" << status;
    #endif

    // If listening failed
    if ( ! isListening )
    {

        // Terminate the application
        QCoreApplication::exit(-1);

    }

}

QString SocketServer::getSettingsName ( void ) const
{
    QString settingsName = "Server";
    return settingsName;
}

void SocketServer::incomingConnection ( qintptr socketDescriptor )
{
    QByteArray policy = this->policyFactory->getPolicy();
    ClientRoutine* clientRoutine = new ClientRoutine();
    clientRoutine->setSocketDescriptor(socketDescriptor);
    clientRoutine->setPolicy(policy);
    this->threadPool->start(clientRoutine);
}
