#include "AmsMappingPopup.hpp"
#include "I18N.hpp"

namespace Slic3r { namespace GUI {

wxDEFINE_EVENT(EVT_SET_FINISH_MAPPING, wxCommandEvent);

// MaterialItem

MaterialItem::MaterialItem(wxWindow *parent, wxColour mcolour, wxString mname)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize),
      m_main_panel(nullptr), m_material_coloul(mcolour), m_material_name(mname)
{}

MaterialItem::~MaterialItem() {}
void MaterialItem::msw_rescale() {}
void MaterialItem::allow_paint_dropdown(bool) {}
void MaterialItem::set_ams_info(wxColour, wxString, int, std::vector<wxColour>, bool) {}
void MaterialItem::reset_ams_info() {}
void MaterialItem::disable() {}
void MaterialItem::enable() {}
void MaterialItem::on_normal() {}
void MaterialItem::on_selected() {}
void MaterialItem::on_warning() {}
void MaterialItem::paintEvent(wxPaintEvent&) {}
void MaterialItem::render(wxDC&) {}
void MaterialItem::match(bool) {}
void MaterialItem::doRender(wxDC&) {}
void MaterialItem::reset_valid_info() {}

// MaterialSyncItem

MaterialSyncItem::MaterialSyncItem(wxWindow *parent, wxColour mcolour, wxString mname)
    : MaterialItem(parent, mcolour, mname)
{}

MaterialSyncItem::~MaterialSyncItem() {}
int MaterialSyncItem::get_real_offset() { return 0; }
void MaterialSyncItem::render(wxDC&) {}
void MaterialSyncItem::doRender(wxDC&) {}
void MaterialSyncItem::set_material_index_str(std::string str) { m_material_index = str; }

// MappingItem

MappingItem::MappingItem(wxWindow *parent)
    : wxPanel(parent, wxID_ANY)
{}

MappingItem::~MappingItem() {}
void MappingItem::update_data(TrayData) {}
void MappingItem::send_event(int) {}
void MappingItem::set_data(const wxString&, wxColour, wxString, bool, TrayData, bool) {}
void MappingItem::set_checked(bool checked) { m_checked = checked; }
void MappingItem::msw_rescale() {}
void MappingItem::paintEvent(wxPaintEvent&) {}
void MappingItem::render(wxDC&) {}
void MappingItem::doRender(wxDC&) {}
int MappingItem::get_remain_area_height() const { return 0; }

// MappingContainer

MappingContainer::MappingContainer(wxWindow* parent, const wxString& ams_type, int slots_num)
    : wxPanel(parent, wxID_ANY), m_slots_num(slots_num), m_ams_type(ams_type)
{}

MappingContainer::~MappingContainer() {}
void MappingContainer::msw_rescale() {}
void MappingContainer::paintEvent(wxPaintEvent&) {}
void MappingContainer::render(wxDC&) {}
void MappingContainer::doRender(wxDC&) {}

// AmsMapingPopup

AmsMapingPopup::AmsMapingPopup(wxWindow *parent, bool use_in_sync_dialog)
    : PopupWindow(parent, wxBORDER_NONE),
      m_use_in_sync_dialog(use_in_sync_dialog), m_current_filament_id(0)
{}

void AmsMapingPopup::set_sizer_title(wxBoxSizer*, wxString) {}
wxBoxSizer* AmsMapingPopup::create_split_sizer(wxWindow*, wxString) { return nullptr; }
void AmsMapingPopup::update_materials_list(std::vector<std::string>) {}
void AmsMapingPopup::set_tag_texture(std::string) {}
void AmsMapingPopup::update(MachineObject*, const std::vector<FilamentInfo>&) {}
void AmsMapingPopup::update_title(MachineObject*) {}
void AmsMapingPopup::update_items_check_state(const std::vector<FilamentInfo>&) {}
void AmsMapingPopup::update_ams_data_multi_machines() {}
void AmsMapingPopup::add_ams_mapping(std::vector<TrayData>, bool, wxWindow*, wxBoxSizer*) {}
void AmsMapingPopup::add_ext_ams_mapping(TrayData, MappingItem*) {}
bool AmsMapingPopup::is_match_material(std::string) const { return false; }
void AmsMapingPopup::on_left_down(wxMouseEvent&) {}
void AmsMapingPopup::OnDismiss() {}
bool AmsMapingPopup::ProcessLeftDown(wxMouseEvent& event) { return PopupWindow::ProcessLeftDown(event); }
void AmsMapingPopup::paintEvent(wxPaintEvent&) {}
std::vector<TrayData> AmsMapingPopup::parse_ams_mapping(const std::map<std::string, DevAms*, NumericStrCompare>&) { return {}; }
void AmsMapingPopup::reset_ams_info() {}
void AmsMapingPopup::set_reset_callback(ResetCallback) {}
void AmsMapingPopup::show_reset_button() {}
void AmsMapingPopup::set_only_show_ext_spool(bool) {}
void AmsMapingPopup::msw_rescale() {}

// AmsMapingTipPopup

AmsMapingTipPopup::AmsMapingTipPopup(wxWindow *parent)
    : PopupWindow(parent, wxBORDER_NONE),
      m_panel_enable_ams(nullptr), m_title_enable_ams(nullptr), m_tip_enable_ams(nullptr),
      m_split_lines(nullptr), m_panel_disable_ams(nullptr),
      m_title_disable_ams(nullptr), m_tip_disable_ams(nullptr)
{}

void AmsMapingTipPopup::paintEvent(wxPaintEvent&) {}
void AmsMapingTipPopup::OnDismiss() {}
bool AmsMapingTipPopup::ProcessLeftDown(wxMouseEvent& event) { return PopupWindow::ProcessLeftDown(event); }

// AmsHumidityLevelList

AmsHumidityLevelList::AmsHumidityLevelList(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{}

void AmsHumidityLevelList::msw_rescale() {}
void AmsHumidityLevelList::paintEvent(wxPaintEvent&) {}
void AmsHumidityLevelList::render(wxDC&) {}
void AmsHumidityLevelList::doRender(wxDC&) {}

// AmsHumidityTipPopup

AmsHumidityTipPopup::AmsHumidityTipPopup(wxWindow* parent)
    : PopupWindow(parent, wxBORDER_NONE),
      curr_humidity_img(nullptr), m_img(nullptr),
      m_staticText(nullptr), m_staticText_note(nullptr)
{}

void AmsHumidityTipPopup::set_humidity_level(int level) { current_humidity_level = level; }
void AmsHumidityTipPopup::msw_rescale() {}
void AmsHumidityTipPopup::paintEvent(wxPaintEvent&) {}
void AmsHumidityTipPopup::render(wxDC&) {}
void AmsHumidityTipPopup::doRender(wxDC&) {}

// AmsTutorialPopup

AmsTutorialPopup::AmsTutorialPopup(wxWindow* parent)
    : PopupWindow(parent, wxBORDER_NONE),
      text_title(nullptr), img_top(nullptr), arrows_top(nullptr), tip_top(nullptr),
      arrows_bottom(nullptr), tip_bottom(nullptr), img_middle(nullptr),
      tip_middle(nullptr), img_botton(nullptr)
{}

void AmsTutorialPopup::paintEvent(wxPaintEvent&) {}
void AmsTutorialPopup::OnDismiss() {}
bool AmsTutorialPopup::ProcessLeftDown(wxMouseEvent& event) { return PopupWindow::ProcessLeftDown(event); }

// AmsIntroducePopup

AmsIntroducePopup::AmsIntroducePopup(wxWindow* parent)
    : PopupWindow(parent, wxBORDER_NONE),
      m_staticText_top(nullptr), m_staticText_bottom(nullptr),
      m_img_enable_ams(nullptr), m_img_disable_ams(nullptr)
{}

void AmsIntroducePopup::set_mode(bool) {}
void AmsIntroducePopup::paintEvent(wxPaintEvent&) {}
void AmsIntroducePopup::OnDismiss() {}
bool AmsIntroducePopup::ProcessLeftDown(wxMouseEvent& event) { return PopupWindow::ProcessLeftDown(event); }

// AmsRMGroup

AmsRMGroup::AmsRMGroup(wxWindow* parent, std::map<std::string, wxColour> group_info, wxString mname, wxString group_index)
    : wxWindow(parent, wxID_ANY), m_group_info(group_info), m_material_name(mname), m_group_index(group_index)
{}

void AmsRMGroup::paintEvent(wxPaintEvent&) {}
void AmsRMGroup::render(wxDC&) {}
void AmsRMGroup::doRender(wxDC&) {}
void AmsRMGroup::on_mouse_move(wxMouseEvent&) {}
double AmsRMGroup::GetAngle(wxPoint, wxPoint) { return 0.0; }
wxPoint AmsRMGroup::CalculateEndpoint(const wxPoint& startPoint, int, int) { return startPoint; }

// AmsReplaceMaterialDialog

AmsReplaceMaterialDialog::AmsReplaceMaterialDialog(wxWindow* parent)
    : DPIDialog(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{}

void AmsReplaceMaterialDialog::update_machine_obj(MachineObject*) {}
void AmsReplaceMaterialDialog::paintEvent(wxPaintEvent&) {}
void AmsReplaceMaterialDialog::on_dpi_changed(const wxRect&) {}
void AmsReplaceMaterialDialog::create() {}
AmsRMGroup* AmsReplaceMaterialDialog::create_backup_group(wxString, std::map<std::string, wxColour>, wxString) { return nullptr; }
void AmsReplaceMaterialDialog::update_to_nozzle(int) {}

}} // namespace Slic3r::GUI
