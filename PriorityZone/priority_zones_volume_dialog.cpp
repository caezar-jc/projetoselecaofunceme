#include "stdafx.h"
#include "priority_zones_volume_dialog.h"

///////////////////////////////////////////////////////////////////////////

PriorityZonesVolumeDialog::PriorityZonesVolumeDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxStaticBoxSizer* layout;
	layout = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Volume em faixas de liberação")), wxVERTICAL);

	volumesGrid = new wxGrid(layout->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	// Grid
	volumesGrid->CreateGrid(0, 0);
	volumesGrid->EnableEditing(false);
	volumesGrid->EnableGridLines(true);
	volumesGrid->EnableDragGridSize(false);
	volumesGrid->SetMargins(0, 0);

	// Columns
	volumesGrid->EnableDragColMove(false);
	volumesGrid->EnableDragColSize(true);
	volumesGrid->SetColLabelSize(30);
	volumesGrid->SetColLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

	// Rows
	volumesGrid->EnableDragRowSize(true);
	volumesGrid->SetRowLabelSize(80);
	volumesGrid->SetRowLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

	// Label Appearance

	// Cell Defaults
	volumesGrid->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_TOP);
	layout->Add(volumesGrid, 0, wxALL, 5);


	this->SetSizer(layout);
	this->Layout();
	layout->Fit(this);

	this->Centre(wxBOTH);
}

PriorityZonesVolumeDialog::~PriorityZonesVolumeDialog()
{
}

void PriorityZonesVolumeDialog::setVolumeGridValues(VectorOfPriorityZones values)
{
	while (volumesGrid->GetNumberRows() > 0)
		volumesGrid->DeleteRows();
	while (volumesGrid->GetNumberCols() > 0)
		volumesGrid->DeleteCols();

	volumesGrid->AppendRows(values.size());
	volumesGrid->AppendCols(2);
	volumesGrid->SetColLabelValue(0, "Volume Disponível (hm³)");
	volumesGrid->SetColLabelValue(1, "Prioridade");

	volumesGrid->SetSize(24, 30*values.size());

	// Columns
	volumesGrid->EnableDragColMove(false);
	volumesGrid->EnableDragColSize(true);
	volumesGrid->SetColLabelSize(30);
	volumesGrid->SetColLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

	// Rows
	volumesGrid->EnableDragRowSize(true);
	volumesGrid->SetRowLabelSize(80);
	volumesGrid->SetRowLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

	volumesGrid->AutoSize();
	volumesGrid->AutoSizeColumns();
	volumesGrid->AutoSizeRows();

	int line = 0;
	for (auto& i : values) {
		volumesGrid->SetCellValue(line, 0, wxString::Format(wxT("%f"), i.getAvailableVolume()));
		volumesGrid->SetCellValue(line, 1, wxString::Format(wxT("%i"), i.getPriority()));
		line++;
	}

}
