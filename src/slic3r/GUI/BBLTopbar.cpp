#include "BBLTopbar.hpp"

// CenteredTitle

CenteredTitle::CenteredTitle(wxWindow* parent)
    : wxControl(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER)
{}

void CenteredTitle::SetTitle(const wxString& title) { m_title = title; }
wxSize CenteredTitle::DoGetBestSize() const { return wxSize(0, 0); }

#ifdef __WIN32__
WXLRESULT CenteredTitle::MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam)
{
    return wxControl::MSWWindowProc(nMsg, wParam, lParam);
}
#endif

// BBLTopbar

BBLTopbar::BBLTopbar(wxWindow* pwin, wxFrame* parent)
    : wxAuiToolBar(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE),
      m_frame(parent), m_file_menu_item(nullptr), m_dropdown_menu_item(nullptr),
      m_file_menu(nullptr), m_account_item(nullptr), m_model_store_item(nullptr),
      m_undo_item(nullptr), m_redo_item(nullptr), m_calib_item(nullptr),
      maximize_btn(nullptr), m_toolbar_h(0),
      m_skip_popup_file_menu(false), m_skip_popup_dropdown_menu(false),
      m_skip_popup_calib_menu(false)
{}

BBLTopbar::BBLTopbar(wxFrame* parent)
    : wxAuiToolBar(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE),
      m_frame(parent), m_file_menu_item(nullptr), m_dropdown_menu_item(nullptr),
      m_file_menu(nullptr), m_account_item(nullptr), m_model_store_item(nullptr),
      m_undo_item(nullptr), m_redo_item(nullptr), m_calib_item(nullptr),
      maximize_btn(nullptr), m_toolbar_h(0),
      m_skip_popup_file_menu(false), m_skip_popup_dropdown_menu(false),
      m_skip_popup_calib_menu(false)
{}

void BBLTopbar::Init(wxFrame *parent) {}
BBLTopbar::~BBLTopbar() {}
void BBLTopbar::UpdateToolbarWidth(int) {}
void BBLTopbar::Rescale() {}
void BBLTopbar::OnIconize(wxAuiToolBarEvent&) {}
void BBLTopbar::OnFullScreen(wxAuiToolBarEvent&) {}
void BBLTopbar::OnCloseFrame(wxAuiToolBarEvent&) {}
void BBLTopbar::OnFileToolItem(wxAuiToolBarEvent&) {}
void BBLTopbar::OnDropdownToolItem(wxAuiToolBarEvent&) {}
void BBLTopbar::OnCalibToolItem(wxAuiToolBarEvent&) {}
void BBLTopbar::OnMouseLeftDClock(wxMouseEvent&) {}
void BBLTopbar::OnMouseLeftDown(wxMouseEvent&) {}
void BBLTopbar::OnMouseLeftUp(wxMouseEvent&) {}
void BBLTopbar::OnMouseMotion(wxMouseEvent&) {}
void BBLTopbar::OnMouseCaptureLost(wxMouseCaptureLostEvent&) {}
void BBLTopbar::OnMenuClose(wxMenuEvent&) {}
void BBLTopbar::OnOpenProject(wxAuiToolBarEvent&) {}
void BBLTopbar::OnSaveProject(wxAuiToolBarEvent&) {}
void BBLTopbar::OnUndo(wxAuiToolBarEvent&) {}
void BBLTopbar::OnRedo(wxAuiToolBarEvent&) {}
void BBLTopbar::OnModelStoreClicked(wxAuiToolBarEvent&) {}
void BBLTopbar::OnPublishClicked(wxAuiToolBarEvent&) {}

wxAuiToolBarItem* BBLTopbar::FindToolByCurrentPosition() { return nullptr; }

void BBLTopbar::SetFileMenu(wxMenu*) {}
void BBLTopbar::AddDropDownSubMenu(wxMenu*, const wxString&) {}
void BBLTopbar::AddDropDownMenuItem(wxMenuItem*) {}
wxMenu* BBLTopbar::GetTopMenu() { return &m_top_menu; }
wxMenu* BBLTopbar::GetCalibMenu() { return &m_calib_menu; }
void BBLTopbar::SetTitle(wxString) {}
void BBLTopbar::SetMaximizedSize() {}
void BBLTopbar::SetWindowSize() {}
void BBLTopbar::EnableUndoRedoItems() {}
void BBLTopbar::DisableUndoRedoItems() {}
void BBLTopbar::SaveNormalRect() {}
void BBLTopbar::ShowCalibrationButton(bool) {}

#ifdef __WIN32__
WXLRESULT BBLTopbar::MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam)
{
    return wxAuiToolBar::MSWWindowProc(nMsg, wParam, lParam);
}
#endif
