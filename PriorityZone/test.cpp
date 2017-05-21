#include "stdafx.h"

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <iostream>
#include "Priority.h"

#include "reservoir_frame.h"


class PriorityZonesGUI: public wxApp {

public:
	virtual bool OnInit();
};

class PriorityZonesFrame : public wxFrame {
public:
	PriorityZonesFrame();
};

enum
{
	ID_Hello = 1
};

wxIMPLEMENT_APP(PriorityZonesGUI);

bool PriorityZonesGUI::OnInit() {
	ReservoirFrame *frame = new ReservoirFrame(NULL);
	frame->Show(true);
	return true;
}

PriorityZonesFrame::PriorityZonesFrame(): wxFrame(NULL, wxID_ANY, "Hello World") {
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");

	Bind(wxEVT_MENU, [=](wxCommandEvent&) { Close(true); }, wxID_EXIT);
	Bind(wxEVT_MENU, [=](wxCommandEvent&) 
	{ wxMessageBox("This is a wxWidgets' Hello world sample",
		"About Hello World", wxOK | wxICON_INFORMATION); }, wxID_ABOUT);
	Bind(wxEVT_MENU, [=](wxCommandEvent&) 
	{ wxLogMessage("Hello world from wxWidgets!"); }, ID_Hello);
}


/*
int main(int args, char* argv[]) {

	
	PriorityUtils pUtils;
	VectorOfPriorityZones p = pUtils.zonesAvailableSupply({3,1,2}, {8000.0f, 1000.0f, 2500.0f}, 500.0f, 8000.0f, 2650.0f);

	for (auto& i : p) {
		std::cout << i.getPriority() << ", " << i.getAvailableVolume() << std::endl;
	}
	system("pause");
}*/