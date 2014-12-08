#include <QtCore/QSettings>
#include <Kolyunya/FPS/Configurable>

using namespace Kolyunya::FPS;

void Configurable::setSettings ( QSettings* settings )
{
    this->settings = settings;
}

QVariant Configurable::getParameter ( const QString& parameterName )
{
    QVariant parameter = this->settings->value(parameterName);
    return parameter;
}
