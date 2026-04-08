#include "AMSItem.hpp"
#include "../DeviceCore/DevFilaSystem.h"

namespace Slic3r { namespace GUI {

    wxDEFINE_EVENT(EVT_AMS_EXTRUSION_CALI, wxCommandEvent);
    wxDEFINE_EVENT(EVT_AMS_LOAD, SimpleEvent);
    wxDEFINE_EVENT(EVT_AMS_UNLOAD, SimpleEvent);
    wxDEFINE_EVENT(EVT_AMS_SETTINGS, SimpleEvent);
    wxDEFINE_EVENT(EVT_AMS_FILAMENT_BACKUP, SimpleEvent);
    wxDEFINE_EVENT(EVT_AMS_REFRESH_RFID, wxCommandEvent);
    wxDEFINE_EVENT(EVT_AMS_ON_SELECTED, wxCommandEvent);
    wxDEFINE_EVENT(EVT_AMS_ON_FILAMENT_EDIT, wxCommandEvent);
    wxDEFINE_EVENT(EVT_VAMS_ON_FILAMENT_EDIT, wxCommandEvent);
    wxDEFINE_EVENT(EVT_AMS_CLIBRATION_AGAIN, wxCommandEvent);
    wxDEFINE_EVENT(EVT_AMS_CLIBRATION_CANCEL, wxCommandEvent);
    wxDEFINE_EVENT(EVT_AMS_GUIDE_WIKI, wxCommandEvent);
    wxDEFINE_EVENT(EVT_AMS_RETRY, wxCommandEvent);
    wxDEFINE_EVENT(EVT_AMS_SHOW_HUMIDITY_TIPS, wxCommandEvent);
    wxDEFINE_EVENT(EVT_AMS_UNSELETED_VAMS, wxCommandEvent);
    wxDEFINE_EVENT(EVT_AMS_UNSELETED_AMS, wxCommandEvent);
    wxDEFINE_EVENT(EVT_AMS_SWITCH, SimpleEvent);

// AMSinfo struct methods

bool AMSinfo::parse_ams_info(MachineObject*, DevAms*, bool, bool) { return false; }
void AMSinfo::parse_ext_info(MachineObject*, DevAmsTray) {}
Caninfo AMSinfo::get_caninfo(const std::string&, bool& found) const { found = false; return Caninfo(); }
int AMSinfo::get_humidity_display_idx() const { return 0; }

// AMSExtText

AMSExtText::AMSExtText(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
    : wxWindow(parent, id, pos, size)
{}

AMSExtText::~AMSExtText() {}
void AMSExtText::msw_rescale() {}
void AMSExtText::paintEvent(wxPaintEvent&) {}
void AMSExtText::render(wxDC&) {}
void AMSExtText::doRender(wxDC&) {}

// AMSrefresh

AMSrefresh::AMSrefresh() : m_playing_timer(nullptr) {}

AMSrefresh::AMSrefresh(wxWindow *parent, std::string ams_id, wxString can_id, Caninfo info, const wxPoint &pos, const wxSize &size)
    : wxWindow(parent, wxID_ANY, pos, size), m_playing_timer(nullptr), m_ams_id(ams_id), m_info(info)
{}

AMSrefresh::AMSrefresh(wxWindow *parent, std::string ams_id, int can_id, Caninfo info, const wxPoint &pos, const wxSize &size)
    : wxWindow(parent, wxID_ANY, pos, size), m_playing_timer(nullptr), m_ams_id(ams_id), m_info(info)
{}

AMSrefresh::~AMSrefresh() {}
void AMSrefresh::Update(std::string, Caninfo) {}
void AMSrefresh::PlayLoading() {}
void AMSrefresh::StopLoading() {}
void AMSrefresh::msw_rescale() {}
void AMSrefresh::create(wxWindow*, wxWindowID, const wxPoint&, const wxSize&) {}
void AMSrefresh::on_timer(wxTimerEvent&) {}
void AMSrefresh::OnEnterWindow(wxMouseEvent&) {}
void AMSrefresh::OnLeaveWindow(wxMouseEvent&) {}
void AMSrefresh::OnClick(wxMouseEvent&) {}
void AMSrefresh::post_event(wxCommandEvent&&) {}
void AMSrefresh::paintEvent(wxPaintEvent&) {}
void AMSrefresh::DoSetSize(int, int, int, int, int) {}

// AMSextruderImage

AMSextruderImage::AMSextruderImage(wxWindow *parent, wxWindowID id, string file_name, const wxSize& size, const wxPoint &pos)
    : wxWindow(parent, id, pos, size), m_file_name(file_name)
{}

AMSextruderImage::~AMSextruderImage() {}
void AMSextruderImage::OnAmsLoading(bool, wxColour) {}
void AMSextruderImage::TurnOff() {}
void AMSextruderImage::msw_rescale() {}
void AMSextruderImage::paintEvent(wxPaintEvent&) {}
void AMSextruderImage::render(wxDC&) {}
void AMSextruderImage::doRender(wxDC&) {}

// AMSExtImage

AMSExtImage::AMSExtImage(wxWindow *parent, AMSPanelPos ext_pos, int total_ext_num, bool over_ext, wxWindowID id, const wxPoint &pos)
    : wxWindow(parent, id, pos, wxDefaultSize), m_ext_pos(ext_pos), m_ext_num(total_ext_num)
{}

AMSExtImage::~AMSExtImage() {}
void AMSExtImage::msw_rescale() {}
void AMSExtImage::setShowAmsExt(bool) {}
void AMSExtImage::setTotalExtNum(const std::string&, const std::string&, int) {}
void AMSExtImage::paintEvent(wxPaintEvent&) {}
void AMSExtImage::render(wxDC&) {}
void AMSExtImage::doRender(wxDC&) {}
const wxBitmap& AMSExtImage::get_bmp(const std::string&, bool, AMSPanelPos) { static wxBitmap bmp; return bmp; }

// AMSextruder

AMSextruder::AMSextruder(wxWindow *parent, wxWindowID id, int nozzle_num, const wxPoint &pos, const wxSize &size)
    : wxWindow(parent, id, pos, size), m_nozzle_num(nozzle_num)
{}

AMSextruder::~AMSextruder() {}
void AMSextruder::TurnOn(wxColour) {}
void AMSextruder::TurnOff() {}
void AMSextruder::OnVamsLoading(bool, wxColour) {}
void AMSextruder::OnAmsLoading(bool, int, wxColour) {}
void AMSextruder::msw_rescale() {}
bool AMSextruder::updateNozzleNum(int, const std::string&) { return false; }
void AMSextruder::create(wxWindow*, wxWindowID, const wxPoint&, const wxSize&, int) {}

// AMSLib

AMSLib::AMSLib(wxWindow *parent, std::string ams_idx, Caninfo info, AMSModelOriginType ext_type)
    : wxWindow(parent, wxID_ANY), m_info(info), m_ams_id(ams_idx), m_ext_type(ext_type)
{}

AMSLib::~AMSLib() {}
void AMSLib::create(wxWindow*, wxWindowID, const wxPoint&, const wxSize&) {}
wxColour AMSLib::GetLibColour() { return *wxWHITE; }
void AMSLib::Update(Caninfo, std::string, bool) {}
void AMSLib::OnSelected() {}
void AMSLib::UnSelected() {}
void AMSLib::post_event(wxCommandEvent&&) {}
bool AMSLib::Enable(bool enable) { return wxWindow::Enable(enable); }
void AMSLib::msw_rescale() {}
void AMSLib::on_pass_road(bool) {}
void AMSLib::on_enter_window(wxMouseEvent&) {}
void AMSLib::on_leave_window(wxMouseEvent&) {}
void AMSLib::on_left_down(wxMouseEvent&) {}
void AMSLib::paintEvent(wxPaintEvent&) {}
void AMSLib::render(wxDC&) {}
void AMSLib::render_lite_text(wxDC&) {}
void AMSLib::render_generic_text(wxDC&) {}
void AMSLib::doRender(wxDC&) {}
void AMSLib::render_lite_lib(wxDC&) {}
void AMSLib::render_generic_lib(wxDC&) {}

// AMSRoad

AMSRoad::AMSRoad() {}

AMSRoad::AMSRoad(wxWindow *parent, wxWindowID id, Caninfo info, int canindex, int maxcan, const wxPoint &pos, const wxSize &size)
    : wxWindow(parent, id, pos, size), m_info(info), m_canindex(canindex)
{}

void AMSRoad::create(wxWindow*, wxWindowID, const wxPoint&, const wxSize&) {}
void AMSRoad::Update(AMSinfo, Caninfo, int, int) {}
void AMSRoad::OnVamsLoading(bool, wxColour) {}
void AMSRoad::SetPassRoadColour(wxColour) {}
void AMSRoad::SetMode(AMSRoadMode) {}
void AMSRoad::OnPassRoad(std::vector<AMSPassRoadMode>) {}
void AMSRoad::UpdatePassRoad(int, AMSPassRoadType, AMSPassRoadSTEP) {}
void AMSRoad::paintEvent(wxPaintEvent&) {}
void AMSRoad::render(wxDC&) {}
void AMSRoad::doRender(wxDC&) {}

// AMSRoadUpPart

AMSRoadUpPart::AMSRoadUpPart() {}

AMSRoadUpPart::AMSRoadUpPart(wxWindow* parent, wxWindowID id, AMSinfo info, AMSModel mode, const wxPoint& pos, const wxSize& size)
    : wxWindow(parent, id, pos, size), m_amsinfo(info), m_ams_model(mode)
{}

void AMSRoadUpPart::create(wxWindow*, wxWindowID, const wxPoint&, const wxSize&) {}
void AMSRoadUpPart::Update(AMSinfo) {}
void AMSRoadUpPart::OnVamsLoading(bool, wxColour) {}
void AMSRoadUpPart::SetPassRoadColour(wxColour) {}
void AMSRoadUpPart::SetMode(AMSRoadShowMode) {}
void AMSRoadUpPart::OnPassRoad(std::vector<AMSPassRoadMode>) {}
void AMSRoadUpPart::UpdatePassRoad(std::string, std::string, AMSPassRoadType, AMSPassRoadSTEP) {}
void AMSRoadUpPart::paintEvent(wxPaintEvent&) {}
void AMSRoadUpPart::render(wxDC&) {}
void AMSRoadUpPart::doRender(wxDC&) {}
void AMSRoadUpPart::msw_rescale() {}

// AMSRoadDownPart

AMSRoadDownPart::AMSRoadDownPart() {}

AMSRoadDownPart::AMSRoadDownPart(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
    : wxWindow(parent, id, pos, size)
{}

void AMSRoadDownPart::create(wxWindow*, wxWindowID, const wxPoint&, const wxSize&) {}
void AMSRoadDownPart::UpdateLeft(int, AMSRoadShowMode) {}
void AMSRoadDownPart::UpdateRight(int, AMSRoadShowMode) {}
void AMSRoadDownPart::OnVamsLoading(bool, wxColour) {}
void AMSRoadDownPart::SetPassRoadColour(bool, wxColour) {}
void AMSRoadDownPart::SetShowMode(AMSRoadShowMode, AMSRoadShowMode) {}
void AMSRoadDownPart::UpdatePassRoad(AMSPanelPos, int, AMSPassRoadSTEP) {}
void AMSRoadDownPart::paintEvent(wxPaintEvent&) {}
void AMSRoadDownPart::render(wxDC&) {}
void AMSRoadDownPart::doRender(wxDC&) {}
void AMSRoadDownPart::msw_rescale() {}

// AMSPreview

AMSPreview::AMSPreview() {}

AMSPreview::AMSPreview(wxWindow *parent, wxWindowID id, AMSinfo amsinfo, AMSModel itemType, const wxPoint& pos, const wxSize& size)
    : wxWindow(parent, id, pos, size), m_amsinfo(amsinfo), m_ams_item_type(itemType)
{}

void AMSPreview::Open() { m_open = true; }
void AMSPreview::Close() { m_open = false; }
void AMSPreview::Update(AMSinfo amsinfo) { m_amsinfo = amsinfo; }
void AMSPreview::create(wxWindow*, wxWindowID, const wxPoint&, const wxSize&) {}
void AMSPreview::OnEnterWindow(wxMouseEvent&) {}
void AMSPreview::OnLeaveWindow(wxMouseEvent&) {}
void AMSPreview::OnSelected() {}
void AMSPreview::UnSelected() {}
bool AMSPreview::Enable(bool enable) { return wxWindow::Enable(enable); }
void AMSPreview::msw_rescale() {}
bool AMSPreview::IsSelected() const { return m_selected; }
void AMSPreview::paintEvent(wxPaintEvent&) {}
void AMSPreview::render(wxDC&) {}
void AMSPreview::doRender(wxDC&) {}

// AMSHumidity

AMSHumidity::AMSHumidity() {}

AMSHumidity::AMSHumidity(wxWindow* parent, wxWindowID id, AMSinfo info, const wxPoint& pos, const wxSize& size)
    : wxWindow(parent, id, pos, size), m_amsinfo(info)
{}

void AMSHumidity::create(wxWindow*, wxWindowID, const wxPoint&, const wxSize&) {}
void AMSHumidity::Update(AMSinfo) {}
void AMSHumidity::paintEvent(wxPaintEvent&) {}
void AMSHumidity::render(wxDC&) {}
void AMSHumidity::doRender(wxDC&) {}
void AMSHumidity::msw_rescale() {}
void AMSHumidity::update_size() {}

// AmsItem

AmsItem::AmsItem(wxWindow *parent, AMSinfo info, AMSModel model, AMSPanelPos pos)
    : wxWindow(parent, wxID_ANY), m_info(info), m_ams_model(model), m_panel_pos(pos)
{}

AmsItem::~AmsItem() {}
void AmsItem::Update(AMSinfo) {}
void AmsItem::create(wxWindow*) {}
void AmsItem::AddCan(Caninfo, int, int, wxBoxSizer*) {}
void AmsItem::AddLiteCan(Caninfo, int, wxGridSizer*) {}
void AmsItem::SetDefSelectCan() {}
void AmsItem::SelectCan(std::string) {}
void AmsItem::PlayRridLoading(wxString) {}
void AmsItem::StopRridLoading(wxString) {}
void AmsItem::msw_rescale() {}
void AmsItem::show_sn_value(bool) {}
void AmsItem::SetAmsStepExtra(wxString, AMSPassRoadType, AMSPassRoadSTEP) {}
void AmsItem::SetAmsStep(std::string, std::string, AMSPassRoadType, AMSPassRoadSTEP) {}
void AmsItem::SetAmsStep(std::string) {}
void AmsItem::paintEvent(wxPaintEvent&) {}
void AmsItem::render(wxDC&) {}
void AmsItem::doRender(wxDC&) {}
void AmsItem::RenderLiteRoad(wxDC&, wxSize) {}
wxColour AmsItem::GetTagColr(wxString) { return *wxWHITE; }
std::string AmsItem::GetCurrentCan() { return std::string(); }

}} // namespace Slic3r::GUI
