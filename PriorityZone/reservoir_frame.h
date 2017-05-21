#ifndef __FRAMES_RESERVOIR_H__
#define __FRAMES_RESERVOIR_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/statline.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/toolbar.h>
#include <wx/grid.h>
#include <wx/notebook.h>
#include <wx/frame.h>
#include <wx/msgdlg.h>
#include <wx/scrolwin.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/log.h> 

#include "priority_zones_volume_dialog.h"

#include "reservoir.h"


///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Reservoir
///////////////////////////////////////////////////////////////////////////////
class ReservoirFrame : public wxFrame
{
private:

protected:
	wxStaticLine* m_staticline8;
	wxNotebook* tabPanel;
	wxPanel* reservoirPanel;
	wxStaticText* initialVol_Lb;
	wxTextCtrl* initialVol_Tb;
	wxStaticText* minimumVol_Lb;
	wxTextCtrl* minimumVol_Tb;
	wxStaticText* maximumVol_Lb;
	wxTextCtrl* maximumVol_Tb;
	wxBitmapButton* priorityZoneVol_Bt;
	wxPanel* priorityZonesPanel;
	wxToolBar* gridOptions;
	wxToolBarToolBase* addLine;
	wxToolBarToolBase* deleteLine;
	wxGrid* reservoirGrid;
	wxToolBar* options;
	wxToolBarToolBase* newFile;
	wxToolBarToolBase* open;
	wxToolBarToolBase* save;
	wxToolBarToolBase* erase;
	wxScrolledWindow* m_scrolledWindow1;

	void ClearGrid();

	void ClearTextBoxes();

	void UpdateTextBoxes();

	void UpdateGrid();

	// Event handlers
	virtual void onTabChanging(wxNotebookEvent& event);
	virtual void onInitialValueEdit(wxCommandEvent& event);
	virtual void onMinimumValueEdit(wxCommandEvent& event);
	virtual void onMaximumValueEdit(wxCommandEvent& event);
	virtual void onViewPriorityZonesVolPressed(wxCommandEvent& event);
	virtual void onAddLinePressed(wxCommandEvent& event);
	virtual void onDeleteLinePressed(wxCommandEvent& event);
	virtual void onNewFilePressed(wxCommandEvent& event);
	virtual void onOpenFilePressed(wxCommandEvent& event);
	virtual void onSavePressed(wxCommandEvent& event);
	virtual void onErasePressed(wxCommandEvent& event);
	virtual void onGridCellChange(wxGridEvent& event);

public:
	ReservoirFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Reservatório"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	~ReservoirFrame();

};


#endif //__FRAMES_RESERVOIR_H__
