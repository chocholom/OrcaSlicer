#include "BBLStatusBar.hpp"

#include <wx/timer.h>
#include <wx/gauge.h>
#include <wx/button.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

namespace Slic3r {

BBLStatusBar::BBLStatusBar(wxWindow *parent, int id)
    : m_self(nullptr), m_prog(nullptr), m_cancelbutton(nullptr),
      m_status_text(nullptr), m_object_info(nullptr), m_slice_info(nullptr),
      m_slice_info_sizer(nullptr), m_object_info_sizer(nullptr), m_sizer(nullptr)
{}

int BBLStatusBar::get_progress() const { return 0; }
void BBLStatusBar::set_progress(int) {}
int BBLStatusBar::get_range() const { return 100; }
void BBLStatusBar::set_range(int) {}
void BBLStatusBar::clear_percent() {}
void BBLStatusBar::show_error_info(wxString, int, wxString, wxString) {}
void BBLStatusBar::show_progress(bool) {}
void BBLStatusBar::start_busy(int) {}
void BBLStatusBar::stop_busy() {}
void BBLStatusBar::set_cancel_callback(CancelFn) {}
wxPanel* BBLStatusBar::get_panel() { return m_self; }
void BBLStatusBar::set_status_text(const wxString&) {}
void BBLStatusBar::set_status_text(const std::string&) {}
void BBLStatusBar::set_status_text(const char*) {}
wxString BBLStatusBar::get_status_text() const { return wxString(); }
void BBLStatusBar::set_font(const wxFont&) {}
void BBLStatusBar::set_object_info(const wxString&) {}
void BBLStatusBar::set_slice_info(const wxString&) {}
void BBLStatusBar::show_slice_info(bool) {}
bool BBLStatusBar::is_slice_info_shown() { return false; }
void BBLStatusBar::show_cancel_button() {}
void BBLStatusBar::hide_cancel_button() {}

} // namespace Slic3r
