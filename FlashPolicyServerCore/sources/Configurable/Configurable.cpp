#include <QtCore/QSettings>
#include <Kolyunya/FPS/Configurable>

using namespace Kolyunya::FPS;

void Configurable::setSettings ( QSettings* settings )
{
    this->settings = settings;
}

QString Configurable::getParameterKey ( const QString& parameterName )
{
    QString settingsName = this->getSettingsName();
    QString parameterKey = settingsName + "/" + parameterName;
    return parameterKey;
}

QVariant Configurable::getParameter ( const QString& parameterName )
{
    QString parameterKey = this->getParameterKey(parameterName);
    QVariant parameter = this->settings->value(parameterKey);
    return parameter;
}
