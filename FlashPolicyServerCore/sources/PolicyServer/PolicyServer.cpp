#include <QtCore/QSettings>
#include <Kolyunya/FPS/ThreadPool>
#include <Kolyunya/FPS/SocketServer>
#include <Kolyunya/FPS/PolicyFactory>
#include <Kolyunya/FPS/PolicyServer>

using namespace Kolyunya::FPS;

PolicyServer::PolicyServer ( int& argc , char** argv ) :
    QCoreApplication(argc,argv),
    socketServer(nullptr)
{
    this->initializeSettings();
    this->initializeThreadPool();
    this->initializePolicyFactory();
    this->initializeSocketServer();
}

void PolicyServer::initializeSettings ( void )
{
    QString settinsFile = "FlashPolicyServer.ini";
    QSettings::Format settingsFormat = QSettings::IniFormat;
    this->settings = new QSettings(settinsFile,settingsFormat,this);
}

void PolicyServer::initializeThreadPool ( void )
{
    this->threadPool = new ThreadPool(this);
    this->threadPool->setSettings(this->settings);
    this->threadPool->initialize();
}

void PolicyServer::initializePolicyFactory ( void )
{
    this->policyFactory = new PolicyFactory(this);
    this->policyFactory->setSettings(this->settings);
    this->policyFactory->initialize();
}

void PolicyServer::initializeSocketServer ( void )
{
    this->socketServer = new SocketServer(this);
    this->socketServer->setSettings(this->settings);
    this->socketServer->setThreadPool(this->threadPool);
    this->socketServer->setPolicyFactory(this->policyFactory);
    this->socketServer->initialize();
    this->socketServer->launch();
}
