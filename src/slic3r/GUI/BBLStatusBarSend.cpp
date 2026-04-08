#include "BBLStatusBarSend.hpp"

#include <wx/timer.h>
#include <wx/gauge.h>
#include <wx/button.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

namespace Slic3r {

wxDEFINE_EVENT(EVT_SHOW_ERROR_INFO_SEND, wxCommandEvent);
wxDEFINE_EVENT(EVT_SHOW_ERROR_FAIL_SEND, wxCommandEvent);

BBLStatusBarSend::BBLStatusBarSend(wxWindow *parent, int id)
    : m_self(nullptr), m_prog(nullptr), m_link_show_error(nullptr),
      m_sizer_status_text(nullptr), m_static_bitmap_show_error(nullptr),
      m_cancelbutton(nullptr), m_status_text(nullptr), m_stext_percent(nullptr),
      m_sizer(nullptr), m_sizer_eline(nullptr),
      block_left(nullptr), block_right(nullptr)
{}

int BBLStatusBarSend::get_progress() const { return 0; }
void BBLStatusBarSend::set_prog_block() {}
void BBLStatusBarSend::set_progress(int) {}
int BBLStatusBarSend::get_range() const { return 100; }
void BBLStatusBarSend::set_range(int) {}
void BBLStatusBarSend::clear_percent() {}
void BBLStatusBarSend::show_error_info(wxString, int, wxString, wxString) {}
void BBLStatusBarSend::show_progress(bool) {}
void BBLStatusBarSend::start_busy(int) {}
void BBLStatusBarSend::stop_busy() {}
void BBLStatusBarSend::set_cancel_callback_fina(CancelFn) {}
void BBLStatusBarSend::set_cancel_callback(CancelFn) {}
wxPanel* BBLStatusBarSend::get_panel() { return m_self; }
bool BBLStatusBarSend::is_english_text(wxString) { return false; }
bool BBLStatusBarSend::format_text(wxStaticText*, int, const wxString&, wxString&) { return false; }
void BBLStatusBarSend::set_status_text(const wxString&) {}
void BBLStatusBarSend::set_percent_text(const wxString&) {}
void BBLStatusBarSend::msw_rescale() {}
void BBLStatusBarSend::set_status_text(const std::string&) {}
void BBLStatusBarSend::set_status_text(const char*) {}
wxString BBLStatusBarSend::get_status_text() const { return wxString(); }
void BBLStatusBarSend::set_font(const wxFont&) {}
void BBLStatusBarSend::set_object_info(const wxString&) {}
void BBLStatusBarSend::set_slice_info(const wxString&) {}
void BBLStatusBarSend::show_slice_info(bool) {}
bool BBLStatusBarSend::is_slice_info_shown() { return false; }
bool BBLStatusBarSend::update_status(wxString&, bool&, int, bool) { return false; }
void BBLStatusBarSend::reset() {}
void BBLStatusBarSend::show_cancel_button() {}
void BBLStatusBarSend::hide_cancel_button() {}
void BBLStatusBarSend::change_button_label(wxString) {}
void BBLStatusBarSend::disable_cancel_button() {}
void BBLStatusBarSend::enable_cancel_button() {}
void BBLStatusBarSend::cancel() {}

} // namespace Slic3r
