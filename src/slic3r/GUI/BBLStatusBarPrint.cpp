#include "BBLStatusBarPrint.hpp"

#include <wx/timer.h>
#include <wx/gauge.h>
#include <wx/button.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

namespace Slic3r {

wxDEFINE_EVENT(EVT_SHOW_ERROR_INFO, wxCommandEvent);

BBLStatusBarPrint::BBLStatusBarPrint(wxWindow *parent, int id)
    : m_self(nullptr), m_prog(nullptr), m_link_show_error(nullptr),
      m_sizer_status_text(nullptr), m_static_bitmap_show_error(nullptr),
      m_cancelbutton(nullptr), m_status_text(nullptr), top_panel(nullptr),
      m_stext_percent(nullptr), m_sizer(nullptr), m_sizer_eline(nullptr),
      block_left(nullptr), block_right(nullptr)
{}

int BBLStatusBarPrint::get_progress() const { return 0; }
void BBLStatusBarPrint::set_prog_block() {}
void BBLStatusBarPrint::set_progress(int) {}
int BBLStatusBarPrint::get_range() const { return 100; }
void BBLStatusBarPrint::set_range(int) {}
void BBLStatusBarPrint::clear_percent() {}
void BBLStatusBarPrint::show_error_info(wxString, int, wxString, wxString) {}
void BBLStatusBarPrint::show_progress(bool) {}
void BBLStatusBarPrint::start_busy(int) {}
void BBLStatusBarPrint::stop_busy() {}
void BBLStatusBarPrint::set_cancel_callback_fina(CancelFn) {}
void BBLStatusBarPrint::set_cancel_callback(CancelFn) {}
wxPanel* BBLStatusBarPrint::get_panel() { return m_self; }
bool BBLStatusBarPrint::is_english_text(wxString) { return false; }
bool BBLStatusBarPrint::format_text(wxStaticText*, int, const wxString&, wxString&) { return false; }
void BBLStatusBarPrint::set_status_text(const wxString&) {}
void BBLStatusBarPrint::set_percent_text(const wxString&) {}
void BBLStatusBarPrint::msw_rescale() {}
void BBLStatusBarPrint::set_status_text(const std::string&) {}
void BBLStatusBarPrint::set_status_text(const char*) {}
wxString BBLStatusBarPrint::get_status_text() const { return wxString(); }
void BBLStatusBarPrint::set_font(const wxFont&) {}
void BBLStatusBarPrint::set_object_info(const wxString&) {}
void BBLStatusBarPrint::set_slice_info(const wxString&) {}
void BBLStatusBarPrint::show_slice_info(bool) {}
bool BBLStatusBarPrint::is_slice_info_shown() { return false; }
bool BBLStatusBarPrint::update_status(wxString&, bool&, int, bool) { return false; }
void BBLStatusBarPrint::reset() {}
void BBLStatusBarPrint::show_cancel_button() {}
void BBLStatusBarPrint::hide_cancel_button() {}
void BBLStatusBarPrint::change_button_label(wxString) {}
void BBLStatusBarPrint::disable_cancel_button() {}
void BBLStatusBarPrint::enable_cancel_button() {}

} // namespace Slic3r
