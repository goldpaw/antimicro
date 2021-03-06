#include "gamecontrollerdpadxml.h"
#include "messagehandler.h"

#include "gamecontroller/gamecontrollerdpad.h"

#include <QXmlStreamReader>
#include <QDebug>


GameControllerDPadXml::GameControllerDPadXml(GameControllerDPad* gameContrDpad, QObject* parent) : JoyDPadXml<VDPad>(gameContrDpad, parent)
{
    dpadXml = new JoyDPadXml<GameControllerDPad>(gameContrDpad, this);
}

void GameControllerDPadXml::readJoystickConfig(QXmlStreamReader *xml)
{
    qInstallMessageHandler(MessageHandler::myMessageOutput);

    if (xml->isStartElement() && (xml->name() == GlobalVariables::VDPad::xmlName))
    {
        xml->readNextStartElement();

        while (!xml->atEnd() && (!xml->isEndElement() && (xml->name() != GlobalVariables::VDPad::xmlName)))
        {
            bool found = dpadXml->readMainConfig(xml);

            if (!found)
            {
                xml->skipCurrentElement();
            }

            xml->readNextStartElement();
        }
    }
}
