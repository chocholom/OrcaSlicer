#include "AMSMaterialsSetting.hpp"

namespace Slic3r { namespace GUI {

wxDEFINE_EVENT(EVT_SELECTED_COLOR, wxCommandEvent);

// ColorPicker

ColorPicker::ColorPicker(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
    : wxWindow(parent, id, pos, size), ctype(0)
{}

ColorPicker::~ColorPicker() {}
void ColorPicker::msw_rescale() {}
void ColorPicker::set_color(wxColour) {}
void ColorPicker::set_colors(std::vector<wxColour>) {}
void ColorPicker::paintEvent(wxPaintEvent&) {}
void ColorPicker::render(wxDC&) {}
void ColorPicker::doRender(wxDC&) {}

// ColorPickerPopup

ColorPickerPopup::ColorPickerPopup(wxWindow* parent)
    : PopupWindow(parent, wxBORDER_NONE),
      m_ts_stbitmap_custom(nullptr), m_custom_cp(nullptr),
      m_clrData(nullptr), m_def_color_box(nullptr), m_ams_fg_sizer(nullptr)
{}

void ColorPickerPopup::on_custom_clr_picker(wxMouseEvent&) {}
void ColorPickerPopup::set_ams_colours(std::vector<wxColour>) {}
void ColorPickerPopup::set_def_colour(wxColour) {}
void ColorPickerPopup::paintEvent(wxPaintEvent&) {}
void ColorPickerPopup::Popup() {}
void ColorPickerPopup::OnDismiss() {}
bool ColorPickerPopup::ProcessLeftDown(wxMouseEvent& event) { return PopupWindow::ProcessLeftDown(event); }

// AMSMaterialsSetting

AMSMaterialsSetting::AMSMaterialsSetting(wxWindow *parent, wxWindowID id)
    : DPIDialog(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE),
      m_color_picker_popup(this),
      m_clr_picker(nullptr), m_clr_name(nullptr),
      m_is_third(false), m_filament_selection(0)
{}

AMSMaterialsSetting::~AMSMaterialsSetting() {}
void AMSMaterialsSetting::create() {}
void AMSMaterialsSetting::paintEvent(wxPaintEvent&) {}
void AMSMaterialsSetting::input_min_finish() {}
void AMSMaterialsSetting::input_max_finish() {}
void AMSMaterialsSetting::update() {}
bool AMSMaterialsSetting::Show(bool show) { return DPIDialog::Show(show); }
void AMSMaterialsSetting::Popup(wxString, wxString, wxString, wxString, wxString, wxString) {}
void AMSMaterialsSetting::post_select_event(int) {}
void AMSMaterialsSetting::set_color(wxColour) {}
void AMSMaterialsSetting::set_empty_color(wxColour) {}
void AMSMaterialsSetting::set_colors(std::vector<wxColour>) {}
void AMSMaterialsSetting::set_ctype(int) {}
void AMSMaterialsSetting::on_picker_color(wxCommandEvent&) {}
void AMSMaterialsSetting::create_panel_normal(wxWindow*) {}
void AMSMaterialsSetting::create_panel_kn(wxWindow*) {}
void AMSMaterialsSetting::on_dpi_changed(const wxRect&) {}
void AMSMaterialsSetting::on_select_filament(wxCommandEvent&) {}
void AMSMaterialsSetting::on_select_cali_result(wxCommandEvent&) {}
void AMSMaterialsSetting::on_select_ok(wxCommandEvent&) {}
void AMSMaterialsSetting::on_select_reset(wxCommandEvent&) {}
void AMSMaterialsSetting::on_select_close(wxCommandEvent&) {}
void AMSMaterialsSetting::on_clr_picker(wxMouseEvent&) {}
bool AMSMaterialsSetting::is_virtual_tray() { return false; }
void AMSMaterialsSetting::update_widgets() {}
void AMSMaterialsSetting::update_filament_editing(bool) {}

}} // namespace Slic3r::GUI
