/*
 * LCD Image Converter. Converts images and fonts for embedded applications.
 * Copyright (C) 2013 riuson
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

#ifndef REORDERINGPREVIEWMODEL_H
#define REORDERINGPREVIEWMODEL_H

#include <QAbstractItemModel>

#include <QVariant>
#include "conversion_options.h"

namespace Settings
{
namespace Presets
{
class Preset;
}
}

namespace AppUI
{
namespace Setup
{
namespace Parts
{
namespace Reordering
{

class ReorderingPreviewModel : public QAbstractItemModel
{
  Q_OBJECT
public:
  enum RowType {
    Source,
    Operation,
    Result
  };

  explicit ReorderingPreviewModel(Settings::Presets::Preset *preset, QObject *parent = 0);
  virtual ~ReorderingPreviewModel() {}

  int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
  int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
  QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
  bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
  QModelIndex index(int row, int column, const QModelIndex &parent) const Q_DECL_OVERRIDE;
  QModelIndex parent(const QModelIndex &child) const Q_DECL_OVERRIDE;
  Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
  RowType rowType(int row) const;

private:
  Settings::Presets::Preset *mPreset;

  enum ColorType {
    Empty,
    //for used bits
    Gray
  };

  void getBitType(int bitIndex, Parsing::Conversion::Options::ConversionType *convType, ColorType *colorType, int *partIndex) const;
  void resultToSourceBit(int bitIndex, QVariant *name, QVariant *color) const;
  void sourceBitProperties(int bitIndex, QVariant *name, QVariant *color) const;
  int maxBitIndex() const;

signals:

public slots:
  void callReset();
};

} // namespace Reordering
} // namespace Parts
} // namespace Setup
} // namespace AppUI

#endif // REORDERINGPREVIEWMODEL_H
