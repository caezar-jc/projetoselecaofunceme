#include "stdafx.h"

#include "reservoir_frame.h"

///////////////////////////////////////////////////////////////////////////

ReservoirFrame::ReservoirFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

	wxBoxSizer* frameLayout;
	frameLayout = new wxBoxSizer(wxVERTICAL);

	m_staticline8 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	frameLayout->Add(m_staticline8, 0, wxEXPAND | wxTOP | wxBOTTOM, 0);

	tabPanel = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	reservoirPanel = new wxPanel(tabPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	reservoirPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	wxBoxSizer* reservoirLayout;
	reservoirLayout = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* valuesGroupLayout;
	valuesGroupLayout = new wxStaticBoxSizer(new wxStaticBox(reservoirPanel, wxID_ANY, wxT("Carcterísticas")), wxVERTICAL);

	wxBoxSizer* reservoirSubLayout1;
	reservoirSubLayout1 = new wxBoxSizer(wxHORIZONTAL);

	initialVol_Lb = new wxStaticText(valuesGroupLayout->GetStaticBox(), wxID_ANY, wxT("Inicial (hm³)"), wxDefaultPosition, wxDefaultSize, 0);
	initialVol_Lb->Wrap(-1);
	reservoirSubLayout1->Add(initialVol_Lb, 0, wxALL, 5);


	reservoirSubLayout1->Add(0, 0, 1, wxEXPAND, 5);

	initialVol_Tb = new wxTextCtrl(valuesGroupLayout->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	reservoirSubLayout1->Add(initialVol_Tb, 0, wxALL, 5);


	valuesGroupLayout->Add(reservoirSubLayout1, 1, wxEXPAND, 5);

	wxBoxSizer* reservoirSubLayout2;
	reservoirSubLayout2 = new wxBoxSizer(wxHORIZONTAL);

	minimumVol_Lb = new wxStaticText(valuesGroupLayout->GetStaticBox(), wxID_ANY, wxT("Mínimo (hm³)"), wxDefaultPosition, wxDefaultSize, 0);
	minimumVol_Lb->Wrap(-1);
	reservoirSubLayout2->Add(minimumVol_Lb, 0, wxALL, 5);


	reservoirSubLayout2->Add(0, 0, 1, wxEXPAND, 5);

	minimumVol_Tb = new wxTextCtrl(valuesGroupLayout->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	reservoirSubLayout2->Add(minimumVol_Tb, 0, wxALL, 5);


	valuesGroupLayout->Add(reservoirSubLayout2, 1, wxEXPAND, 5);

	wxBoxSizer* reservoirSubLayout3;
	reservoirSubLayout3 = new wxBoxSizer(wxHORIZONTAL);

	maximumVol_Lb = new wxStaticText(valuesGroupLayout->GetStaticBox(), wxID_ANY, wxT("Máximo (hm³)"), wxDefaultPosition, wxDefaultSize, 0);
	maximumVol_Lb->Wrap(-1);
	reservoirSubLayout3->Add(maximumVol_Lb, 0, wxALL, 5);


	reservoirSubLayout3->Add(0, 0, 1, wxEXPAND, 5);

	maximumVol_Tb = new wxTextCtrl(valuesGroupLayout->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	reservoirSubLayout3->Add(maximumVol_Tb, 0, wxALL, 5);


	valuesGroupLayout->Add(reservoirSubLayout3, 1, wxEXPAND, 5);


	reservoirLayout->Add(valuesGroupLayout, 1, wxEXPAND, 5);

	wxBoxSizer* viewZonesLayout;
	viewZonesLayout = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* groupLayout;
	groupLayout = new wxStaticBoxSizer(new wxStaticBox(reservoirPanel, wxID_ANY, wxT("Vizualizar volume em faixas de liberação")), wxVERTICAL);

	priorityZoneVol_Bt = new wxBitmapButton(groupLayout->GetStaticBox(), wxID_ANY, wxBitmap(wxT("view.bmp"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);
	groupLayout->Add(priorityZoneVol_Bt, 0, wxALL, 5);


	viewZonesLayout->Add(groupLayout, 1, wxEXPAND, 5);


	reservoirLayout->Add(viewZonesLayout, 1, wxEXPAND, 5);


	reservoirPanel->SetSizer(reservoirLayout);
	reservoirPanel->Layout();
	reservoirLayout->Fit(reservoirPanel);
	tabPanel->AddPage(reservoirPanel, wxT("Reservatório"), false);
	priorityZonesPanel = new wxPanel(tabPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	priorityZonesPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	wxBoxSizer* priorityZonesLayout;
	priorityZonesLayout = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer* subLayout = new wxStaticBoxSizer(new wxStaticBox(priorityZonesPanel, wxID_ANY, wxT("Zonas de Liberação")), wxVERTICAL);

	gridOptions = new wxToolBar(subLayout->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL);
	gridOptions->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	addLine = gridOptions->AddTool(wxID_ANY, wxT("Adicionar linha"), wxBitmap(wxT("add.bmp"), wxBITMAP_TYPE_ANY), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);

	deleteLine = gridOptions->AddTool(wxID_ANY, wxT("Remover ultima linha"), wxBitmap(wxT("delete.bmp"), wxBITMAP_TYPE_ANY), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);

	gridOptions->Realize();

	subLayout->Add(gridOptions, 0, wxEXPAND, 5);

	wxBoxSizer* gridLayout;
	gridLayout = new wxBoxSizer(wxHORIZONTAL);

	m_scrolledWindow1 = new wxScrolledWindow(subLayout->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	m_scrolledWindow1->SetScrollRate(5, 5);
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer(wxVERTICAL);

	reservoirGrid = new wxGrid(m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxSize(360, 500), 0);

	// Grid
	reservoirGrid->CreateGrid(0, 0);
	reservoirGrid->EnableEditing(true);
	reservoirGrid->EnableGridLines(true);
	reservoirGrid->EnableDragGridSize(false);
	reservoirGrid->SetMargins(20, 0);
	reservoirGrid->ShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_NEVER);

	// Add Columns
	reservoirGrid->AppendCols(3);
	reservoirGrid->SetColLabelValue(0, "Limite Inferior (hm³)");
	reservoirGrid->SetColLabelValue(1, "Limite Superior (hm³)");
	reservoirGrid->SetColLabelValue(2, "Prioridade");
	reservoirGrid->AutoSize();

	// Columns
	reservoirGrid->EnableDragColMove(false);
	reservoirGrid->EnableDragColSize(true);
	reservoirGrid->SetColLabelSize(30);
	reservoirGrid->SetColLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

	// Rows
	reservoirGrid->EnableDragRowSize(true);
	reservoirGrid->SetRowLabelSize(80);
	reservoirGrid->SetRowLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

	// Label Appearance

	// Cell Defaults
	reservoirGrid->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_TOP);
	bSizer12->Add(reservoirGrid, 0, wxALL, 5);


	m_scrolledWindow1->SetSizer(bSizer12);
	m_scrolledWindow1->Layout();
	bSizer12->Fit(m_scrolledWindow1);
	gridLayout->Add(m_scrolledWindow1, 1, wxEXPAND | wxALL, 5);

	subLayout->Add(gridLayout, 1, wxEXPAND, 5);


	priorityZonesLayout->Add(subLayout, 1, wxEXPAND, 5);


	priorityZonesPanel->SetSizer(priorityZonesLayout);
	priorityZonesPanel->Layout();
	priorityZonesLayout->Fit(priorityZonesPanel);
	tabPanel->AddPage(priorityZonesPanel, wxT("Zonas de Liberação"), false);

	frameLayout->Add(tabPanel, 1, wxEXPAND, 5);


	this->SetSizer(frameLayout);
	this->Layout();
	options = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
	options->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	newFile = options->AddTool(wxID_ANY, wxT("Novo Arquivo"), wxBitmap(wxT("saveas.bmp"), wxBITMAP_TYPE_ANY), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);

	open = options->AddTool(wxID_ANY, wxT("Abrir"), wxBitmap(wxT("open.bmp"), wxBITMAP_TYPE_ANY), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);

	save = options->AddTool(wxID_ANY, wxT("Salvar"), wxBitmap(wxT("save.bmp"), wxBITMAP_TYPE_ANY), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);

	erase = options->AddTool(wxID_ANY, wxT("apagar"), wxBitmap(wxT("delete.bmp"), wxBITMAP_TYPE_ANY), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL);

	options->Realize();


	this->Centre(wxBOTH);

	// Connect Events
	tabPanel->Connect(wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, wxNotebookEventHandler(ReservoirFrame::onTabChanging), NULL, this);
	initialVol_Tb->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(ReservoirFrame::onInitialValueEdit), NULL, this);
	minimumVol_Tb->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(ReservoirFrame::onMinimumValueEdit), NULL, this);
	maximumVol_Tb->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(ReservoirFrame::onMaximumValueEdit), NULL, this);
	priorityZoneVol_Bt->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReservoirFrame::onViewPriorityZonesVolPressed), NULL, this);
	reservoirGrid->Connect(wxEVT_GRID_CELL_CHANGED, wxGridEventHandler(ReservoirFrame::onGridCellChange), NULL, this);
	this->Connect(addLine->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onAddLinePressed));
	this->Connect(deleteLine->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onDeleteLinePressed));
	this->Connect(newFile->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onNewFilePressed));
	this->Connect(open->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onOpenFilePressed));
	this->Connect(save->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onSavePressed));
	this->Connect(erase->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onErasePressed));

}

ReservoirFrame::~ReservoirFrame()
{
	// Disconnect Events
	tabPanel->Disconnect(wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, wxNotebookEventHandler(ReservoirFrame::onTabChanging), NULL, this);
	initialVol_Tb->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(ReservoirFrame::onInitialValueEdit), NULL, this);
	minimumVol_Tb->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(ReservoirFrame::onMinimumValueEdit), NULL, this);
	maximumVol_Tb->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(ReservoirFrame::onMaximumValueEdit), NULL, this);
	priorityZoneVol_Bt->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ReservoirFrame::onViewPriorityZonesVolPressed), NULL, this);
	reservoirGrid->Disconnect(wxEVT_GRID_CELL_CHANGED, wxGridEventHandler(ReservoirFrame::onGridCellChange), NULL, this);
	this->Disconnect(addLine->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onAddLinePressed));
	this->Disconnect(deleteLine->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onDeleteLinePressed));
	this->Disconnect(newFile->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onNewFilePressed));
	this->Disconnect(open->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onOpenFilePressed));
	this->Disconnect(save->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onSavePressed));
	this->Disconnect(erase->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(ReservoirFrame::onErasePressed));

}


inline void ReservoirFrame::ClearGrid() {
	while (reservoirGrid->GetNumberRows() > 0)
		reservoirGrid->DeleteRows();
}

inline void ReservoirFrame::ClearTextBoxes() {
	initialVol_Tb->SetValue("");
	minimumVol_Tb->SetValue("");
	maximumVol_Tb->SetValue("");
}

inline void ReservoirFrame::UpdateTextBoxes() {
	initialVol_Tb->SetValue(wxString::Format(wxT("%f"), Reservoir::getInstance()->currentVolume));
	minimumVol_Tb->SetValue(wxString::Format(wxT("%f"), Reservoir::getInstance()->minimumVolume));
	maximumVol_Tb->SetValue(wxString::Format(wxT("%f"), Reservoir::getInstance()->maximumVolume));
}

inline void ReservoirFrame::UpdateGrid() {

	while (reservoirGrid->GetNumberRows() > 0)
		reservoirGrid->DeleteRows();

	int line = 0;
	for (auto& i : Reservoir::getInstance()->pZonesMaxVolume) {
		reservoirGrid->AppendRows();
		reservoirGrid->SetCellValue(line, 0, wxString::Format(wxT("%f"), Reservoir::getInstance()->getZoneMinVolume(line)));
		reservoirGrid->SetCellValue(line, 1, wxString::Format(wxT("%f"), i));
		reservoirGrid->SetCellValue(line, 2, wxString::Format(wxT("%i"), line + 1));
		line++;

	}
	reservoirGrid->AutoSize();
}

// Event handlers

inline void ReservoirFrame::onTabChanging(wxNotebookEvent & event) {
	ClearGrid();
	UpdateGrid();
}

inline void ReservoirFrame::onInitialValueEdit(wxCommandEvent & event) {
	initialVol_Tb->GetValue().ToDouble(&Reservoir::getInstance()->currentVolume);
}

inline void ReservoirFrame::onMinimumValueEdit(wxCommandEvent & event) {
	minimumVol_Tb->GetValue().ToDouble(&Reservoir::getInstance()->minimumVolume);
}

inline void ReservoirFrame::onMaximumValueEdit(wxCommandEvent & event) {
	maximumVol_Tb->GetValue().ToDouble(&Reservoir::getInstance()->maximumVolume);
}

inline void ReservoirFrame::onViewPriorityZonesVolPressed(wxCommandEvent & event) {
	Reservoir::getInstance()->getVolumeInPriorityZones();
	PriorityZonesVolumeDialog dialog(this);
	dialog.SetSize(340, 240);
	dialog.setVolumeGridValues(Reservoir::getInstance()->getVolumeInPriorityZones());
	dialog.ShowModal();
}

inline void ReservoirFrame::onAddLinePressed(wxCommandEvent & event) {
	if (!Reservoir::getInstance()->addDefaultPriorityZone()) {
		wxMessageBox("O valor da nova linha é inconsistente.");
	}
	UpdateGrid();
}

inline void ReservoirFrame::onDeleteLinePressed(wxCommandEvent & event) {
	if (reservoirGrid->GetNumberRows() > 0) {
		reservoirGrid->DeleteRows(reservoirGrid->GetNumberRows() - 1);
		Reservoir::getInstance()->deletePriorityZone();
	}
}

inline void ReservoirFrame::onNewFilePressed(wxCommandEvent & event) {
	wxFileDialog
		saveFileDialog(this, _("Save zp file"), "", "",
			"zp files (*.zp)|*.zp", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
		return;    

	wxFileOutputStream output_stream(saveFileDialog.GetPath());
	if (!output_stream.IsOk())
	{
		wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
		return;
	}

	Reservoir::getInstance()->saveReservoir(saveFileDialog.GetDirectory().ToStdString(),
		saveFileDialog.GetFilename().ToStdString());
}

inline void ReservoirFrame::onOpenFilePressed(wxCommandEvent & event) {
	wxFileDialog
		openFileDialog(this, _("Open zp file"), "", "",
			"zp files (*.zp)|*.zp", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (openFileDialog.ShowModal() == wxID_CANCEL)
		return;    

	wxFileInputStream input_stream(openFileDialog.GetPath());
	if (!input_stream.IsOk())
	{
		wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
		return;
	}
	Reservoir::getInstance()->loadReservoir(openFileDialog.GetDirectory().ToStdString(),
		openFileDialog.GetFilename().ToStdString());
	UpdateTextBoxes();
	UpdateGrid();
}

inline void ReservoirFrame::onSavePressed(wxCommandEvent & event) {
	Reservoir::getInstance()->saveReservoir(Reservoir::getInstance()->currentPath,
		Reservoir::getInstance()->currentFileName);
}

inline void ReservoirFrame::onErasePressed(wxCommandEvent & event) {
	Reservoir::CleanInstance();
	ClearTextBoxes();
	ClearGrid();
}

inline void ReservoirFrame::onGridCellChange(wxGridEvent & event) {
	if (event.GetCol() == 1) {
		double value;
		double bkp = Reservoir::getInstance()->pZonesMaxVolume[event.GetRow()];
		reservoirGrid->GetCellValue(event.GetRow(), event.GetCol()).ToDouble(&value);
		if (!Reservoir::getInstance()->EditZoneMaximumVolume(event.GetRow(), value)) {
			wxMessageBox("O valor entrado é inconsistente.");
			reservoirGrid->SetCellValue(event.GetRow(), event.GetCol(),
				wxString::Format(wxT("%f"), bkp));
		}
	}
	else if (event.GetCol() == 0) {
		reservoirGrid->SetCellValue(event.GetRow(), event.GetCol(),
			wxString::Format(wxT("%f"), Reservoir::getInstance()->getZoneMinVolume(event.GetRow())));
	}
	else if (event.GetCol() == 2) {
		reservoirGrid->SetCellValue(event.GetRow(), event.GetCol(),
			wxString::Format(wxT("%i"), event.GetRow()));
	}
}

