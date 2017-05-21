#ifndef __FRAMES_PRIORITYZONESVOLUMEDIALOG_H__
#define __FRAMES_PRIORITYZONESVOLUMEDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/dialog.h>

#include "Priority.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class PriorityZonesVolumeDialog
///////////////////////////////////////////////////////////////////////////////
class PriorityZonesVolumeDialog : public wxDialog
{
private:

protected:
	wxGrid* volumesGrid;

public:

	PriorityZonesVolumeDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);
	~PriorityZonesVolumeDialog();

	void setVolumeGridValues(VectorOfPriorityZones values);

};

#endif //__FRAMES_PRIORITYZONESVOLUMEDIALOG_H__
