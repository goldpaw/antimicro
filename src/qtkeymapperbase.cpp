/* antimicro Gamepad to KB+M event mapper
 * Copyright (C) 2015 Travis Nickles <nickles.travis@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "qtkeymapperbase.h"

#include "messagehandler.h"

#include <QDebug>


const int QtKeyMapperBase::customQtKeyPrefix;
const int QtKeyMapperBase::customKeyPrefix;
const int QtKeyMapperBase::nativeKeyPrefix;

QtKeyMapperBase::QtKeyMapperBase(QObject *parent) :
    QObject(parent)
{
    qInstallMessageHandler(MessageHandler::myMessageOutput);
}

int QtKeyMapperBase::returnQtKey(int key, int scancode)
{
    qInstallMessageHandler(MessageHandler::myMessageOutput);

    Q_UNUSED(scancode);

    return virtKeyToQtKeyHash.value(key);
}

int QtKeyMapperBase::returnVirtualKey(int qkey)
{
    qInstallMessageHandler(MessageHandler::myMessageOutput);

    return qtKeyToVirtKeyHash.value(qkey);
}

bool QtKeyMapperBase::isModifier(int qkey)
{
    qInstallMessageHandler(MessageHandler::myMessageOutput);

    bool modifier = false;
    int qtKeyValue = qkey & 0x0FFFFFFF;

    switch(qtKeyValue)
    {
        case Qt::Key_Shift:
        {
            modifier = true;
            break;
        }
        case Qt::Key_Control:
        {
            modifier = true;
            break;
        }
        case Qt::Key_Alt:
        {
            modifier = true;
            break;
        }
        case Qt::Key_Meta:
        {
            modifier = true;
            break;
        }
    }

    return modifier;
}

QtKeyMapperBase::charKeyInformation QtKeyMapperBase::getCharKeyInformation(QChar value)
{
    qInstallMessageHandler(MessageHandler::myMessageOutput);

    charKeyInformation temp;
    temp.virtualkey = 0;
    temp.modifiers = Qt::NoModifier;

    if (virtkeyToCharKeyInfo.contains(value.unicode()))
        temp = virtkeyToCharKeyInfo.value(value.unicode());

    return temp;
}

/**
 * @brief Obtain identifier string for key mapper.
 * @return Identifier string.
 */
QString QtKeyMapperBase::getIdentifier()
{
    qInstallMessageHandler(MessageHandler::myMessageOutput);

    return identifier;
}
