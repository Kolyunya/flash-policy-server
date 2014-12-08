#include <QtCore/QCoreApplication>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <Kolyunya/FPS/PolicyFactory>

using namespace Kolyunya::FPS;

PolicyFactory::PolicyFactory ( QObject* parent ) :
    QObject(parent)
{

}

PolicyFactory::~PolicyFactory ( void ) noexcept(true)
{

}

QByteArray PolicyFactory::getPolicy ( void ) const
{
    return this->policy;
}

void PolicyFactory::initialize ( void )
{
    this->getAllowedHosts();
    this->getPolicyBlank();
    this->preparePolicy();
}

QString PolicyFactory::getSettingsName ( void ) const
{
    QString settingsName = "Policy";
    return settingsName;
}

void PolicyFactory::getAllowedHosts ( void )
{
    this->allowedHosts = this->getParameter("AllowedHosts").toString();
    this->allowedPorts = this->getParameter("AllowedPorts").toString();
}

void PolicyFactory::getPolicyBlank ( void )
{
    QFile file("FlashPolicyServer.xml");
    bool fileOpened = file.open(QFile::ReadOnly|QFile::Text);
    if ( ! fileOpened )
    {
        QCoreApplication::exit(-1);
    }
    QTextStream stream(&file);
    QString text = stream.readAll();
    this->policyBlank = text;
}

void PolicyFactory::preparePolicy ( void )
{
    this->policyBlank = this->policyBlank.arg(this->allowedHosts);
    this->policyBlank = this->policyBlank.arg(this->allowedPorts);
    this->policy = this->policyBlank.toUtf8();
}
