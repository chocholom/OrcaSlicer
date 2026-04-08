#include "BBLStatusBarBind.hpp"

#include <wx/timer.h>
#include <wx/gauge.h>
#include <wx/button.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

namespace Slic3r {

BBLStatusBarBind::BBLStatusBarBind(wxWindow *parent, int id)
    : m_self(nullptr), m_prog(nullptr), m_cancelbutton(nullptr),
      m_status_text(nullptr), m_stext_percent(nullptr),
      m_sizer(nullptr), m_sizer_eline(nullptr)
{}

int BBLStatusBarBind::get_progress() const { return 0; }
void BBLStatusBarBind::set_prog_block() {}
void BBLStatusBarBind::set_progress(int) {}
int BBLStatusBarBind::get_range() const { return 100; }
void BBLStatusBarBind::set_range(int) {}
void BBLStatusBarBind::clear_percent() {}
void BBLStatusBarBind::show_error_info(wxString, int, wxString, wxString) {}
void BBLStatusBarBind::show_progress(bool) {}
void BBLStatusBarBind::start_busy(int) {}
void BBLStatusBarBind::stop_busy() {}
void BBLStatusBarBind::set_cancel_callback_fina(CancelFn) {}
void BBLStatusBarBind::set_cancel_callback(CancelFn) {}
wxPanel* BBLStatusBarBind::get_panel() { return m_self; }
void BBLStatusBarBind::set_status_text(const wxString&) {}
void BBLStatusBarBind::set_percent_text(const wxString&) {}
void BBLStatusBarBind::msw_rescale() {}
void BBLStatusBarBind::set_status_text(const std::string&) {}
void BBLStatusBarBind::set_status_text(const char*) {}
wxString BBLStatusBarBind::get_status_text() const { return wxString(); }
void BBLStatusBarBind::set_font(const wxFont&) {}
void BBLStatusBarBind::set_object_info(const wxString&) {}
void BBLStatusBarBind::set_slice_info(const wxString&) {}
void BBLStatusBarBind::show_slice_info(bool) {}
bool BBLStatusBarBind::is_slice_info_shown() { return false; }
bool BBLStatusBarBind::update_status(wxString&, bool&, int, bool) { return false; }
void BBLStatusBarBind::reset() {}
void BBLStatusBarBind::show_cancel_button() {}
void BBLStatusBarBind::hide_cancel_button() {}

} // namespace Slic3r
