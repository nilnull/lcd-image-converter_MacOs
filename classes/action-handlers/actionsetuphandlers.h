/*
 * LCD Image Converter. Converts images and fonts for embedded applications.
 * Copyright (C) 2012 riuson
 * mailto: riuson@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef ACTIONSETUPHANDLERS_H
#define ACTIONSETUPHANDLERS_H

#include <QObject>

#include "actionhandlersbase.h"

namespace AppUI
{
namespace MenuHandlers
{

class ActionSetupHandlers : public ActionHandlersBase
{
  Q_OBJECT
public:
  explicit ActionSetupHandlers(QObject *parent = 0);
  virtual ~ActionSetupHandlers() {}

signals:

public slots:
  void conversion_triggered();
  void external_editor_triggered();
};

} // namespace MenuHandlers
} // namespace AppUI

#endif // ACTIONSETUPHANDLERS_H
