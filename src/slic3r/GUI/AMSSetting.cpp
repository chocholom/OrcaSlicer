#include "AMSSetting.hpp"

namespace Slic3r { namespace GUI {

// AMSSetting

AMSSetting::AMSSetting(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style)
    : DPIDialog(parent, id, wxEmptyString, pos, size, style)
{}

AMSSetting::~AMSSetting() {}
void AMSSetting::UpdateByObj(MachineObject*) {}
void AMSSetting::create() {}
void AMSSetting::update_ams_img(MachineObject*) {}
void AMSSetting::update_starting_read_mode(bool) {}
void AMSSetting::update_remain_mode(bool) {}
void AMSSetting::update_switch_filament(bool) {}
void AMSSetting::update_insert_material_read_mode(MachineObject*) {}
void AMSSetting::update_insert_material_read_mode(bool, std::string) {}
void AMSSetting::update_air_printing_detection(MachineObject*) {}
void AMSSetting::update_firmware_switching_status() {}
void AMSSetting::on_insert_material_read(wxCommandEvent&) {}
void AMSSetting::on_starting_read(wxCommandEvent&) {}
void AMSSetting::on_remain(wxCommandEvent&) {}
void AMSSetting::on_switch_filament(wxCommandEvent&) {}
void AMSSetting::on_air_print_detect(wxCommandEvent&) {}
void AMSSetting::on_dpi_changed(const wxRect&) {}

// AMSSettingTypePanel

AMSSettingTypePanel::AMSSettingTypePanel(wxWindow* parent, AMSSetting* setting_dlg)
    : wxPanel(parent, wxID_ANY), m_setting_dlg(setting_dlg),
      m_type_combobox(nullptr), m_switching_tips(nullptr), m_switching_icon(nullptr)
{}

AMSSettingTypePanel::~AMSSettingTypePanel() {}
void AMSSettingTypePanel::Update(const MachineObject*) {}
void AMSSettingTypePanel::CreateGui() {}
void AMSSettingTypePanel::OnAmsTypeChanged(wxCommandEvent&) {}

}} // namespace Slic3r::GUI
