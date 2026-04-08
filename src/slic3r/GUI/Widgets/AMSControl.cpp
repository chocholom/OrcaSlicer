#include "AMSControl.hpp"

namespace Slic3r { namespace GUI {

// AMSControl

AMSControl::AMSControl(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
    : wxSimplebook(parent, id, pos, size),
      m_ams_introduce_popup(parent),
      m_Humidity_tip_popup(parent),
      m_percent_humidity_dry_popup(nullptr)
{}

AMSControl::~AMSControl() {}

void AMSControl::on_retry() {}
std::string AMSControl::GetCurentAms() { return std::string(); }
std::string AMSControl::GetCurentShowAms(AMSPanelPos) { return std::string(); }
std::string AMSControl::GetCurrentCan(std::string) { return std::string(); }
bool AMSControl::IsAmsInRightPanel(std::string) { return false; }
wxColour AMSControl::GetCanColour(std::string, std::string) { return *wxWHITE; }
void AMSControl::createAms(wxSimplebook*, int&, AMSinfo, AMSPanelPos) {}
void AMSControl::createAmsPanel(wxSimplebook*, int&, std::vector<AMSinfo>, const std::string&, const std::string&, AMSPanelPos, int) {}
AMSRoadShowMode AMSControl::findFirstMode(AMSPanelPos) { return AMSRoadShowMode::AMS_ROAD_MODE_NONE; }

void AMSControl::AmsSelectedSwitch(wxCommandEvent&) {}
void AMSControl::EnableLoadFilamentBtn(bool, const std::string&, const std::string&, const wxString&) {}
void AMSControl::EnableUnLoadFilamentBtn(bool, const std::string&, const std::string&, const wxString&) {}
void AMSControl::EnterNoneAMSMode() {}
void AMSControl::EnterGenericAMSMode() {}
void AMSControl::EnterExtraAMSMode() {}
void AMSControl::PlayRridLoading(wxString, wxString) {}
void AMSControl::StopRridLoading(wxString, wxString) {}
void AMSControl::ShowFilamentTip(bool) {}
void AMSControl::UpdatePassRoad(string, AMSPassRoadType, AMSPassRoadSTEP) {}
void AMSControl::CreateAms() {}
void AMSControl::CreateAmsDoubleNozzle(const std::string&, const std::string&) {}
void AMSControl::CreateAmsSingleNozzle(const std::string&, const std::string&) {}
void AMSControl::ClearAms() {}
void AMSControl::UpdateAms(const std::string&, const std::string&, std::vector<AMSinfo>, std::vector<AMSinfo>, DevExtderSystem, std::string, bool, bool) {}
std::vector<AMSinfo> AMSControl::GenerateSimulateData() { return {}; }
void AMSControl::AddAms(AMSinfo, AMSPanelPos) {}
void AMSControl::AddAmsPreview(AMSinfo, AMSModel) {}
void AMSControl::AddAms(std::vector<AMSinfo>, const std::string&, const std::string&, AMSPanelPos) {}
void AMSControl::AddAmsPreview(std::vector<AMSinfo>, AMSPanelPos) {}
void AMSControl::SetExtruder(bool, int, std::string, std::string) {}
void AMSControl::SetAmsStep(std::string, std::string, AMSPassRoadType, AMSPassRoadSTEP) {}
void AMSControl::SwitchAms(std::string) {}
void AMSControl::msw_rescale() {}
void AMSControl::on_filament_load(wxCommandEvent&) {}
void AMSControl::on_filament_unload(wxCommandEvent&) {}
void AMSControl::auto_refill(wxCommandEvent&) {}
void AMSControl::on_ams_setting_click(wxMouseEvent&) {}
void AMSControl::on_extrusion_cali(wxCommandEvent&) {}
void AMSControl::on_ams_setting_click(wxCommandEvent&) {}
void AMSControl::on_clibration_again_click(wxMouseEvent&) {}
void AMSControl::on_clibration_cancel_click(wxMouseEvent&) {}
void AMSControl::Reset() {}
void AMSControl::show_noams_mode() {}
void AMSControl::show_auto_refill(bool) {}
void AMSControl::enable_ams_setting(bool) {}
void AMSControl::show_vams_kn_value(bool) {}
void AMSControl::post_event(wxEvent&&) {}
bool AMSControl::Enable(bool enable) { return wxSimplebook::Enable(enable); }
void AMSControl::parse_object(MachineObject*) {}
std::string AMSControl::get_filament_id(const std::string&, const std::string&) { return std::string(); }

}} // namespace Slic3r::GUI
