#include "AmsWidgets.hpp"

namespace Slic3r { namespace GUI {

TrayListModel::TrayListModel() {}

void TrayListModel::GetValueByRow(wxVariant& variant, unsigned int row, unsigned int col) const {}

bool TrayListModel::GetAttrByRow(unsigned int row, unsigned int col, wxDataViewItemAttr& attr) const { return false; }

bool TrayListModel::SetValueByRow(const wxVariant& variant, unsigned int row, unsigned int col) { return false; }

void TrayListModel::update(MachineObject*) {}
void TrayListModel::clear_data() {}

}} // namespace Slic3r::GUI
