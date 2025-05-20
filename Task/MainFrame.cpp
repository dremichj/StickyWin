#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/webview.h>
#include <vector>
#include <string>
#include <wx/filename.h>




MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr,wxID_ANY,title)
{
	CreateControls();
	//this->SetWindowStyle(GetWindowStyleFlag() | wxSTAY_ON_TOP);
}


void MainFrame::CreateControls()
{

	// font stuff
	wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));

	// base panel stuff
	panel = new wxPanel(this);
	panel->SetFont(mainFont);
	
	// Text control test
	//text = new wxTextCtrl(panel,wxID_ANY, "Hey there", wxPoint(100,150), wxSize(-1,-1));

	// Headline text
	headlineText = new wxStaticText(panel, wxID_ANY, "StickyWin", wxPoint(0, 22), wxSize(400, -1),
		wxALIGN_CENTER_HORIZONTAL);
	headlineText->SetFont(headlineFont);

	// Buttons
	addButton = new wxButton(panel, wxID_ANY, "Add", wxPoint(600, 80), wxSize(100, 35));
	clearButton = new wxButton(panel, wxID_ANY, "Clear", wxPoint(100, 225), wxSize(100, 35));
	
	// Binding button to add
	addButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClicked, this);
	clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearButtonClicked, this);

	Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnWinClose, this);
}

void MainFrame::OnAddButtonClicked(wxCommandEvent& event)
{
	// Creates and adds a new 
	NoteFrame* noteFrame = new NoteFrame(this,"New Note");
	noteFrame->Show();
	noteFrames.push_back(noteFrame);
}

void MainFrame::OnClearButtonClicked(wxCommandEvent& event)
{
	clearNotes();
}

void MainFrame::clearNotes() {
	for (NoteFrame* frame : noteFrames) {
		if (frame) {
			frame->Destroy();
		}
	}
	noteFrames.clear();
}

void MainFrame::OnWinClose(wxCloseEvent& event)
{
	clearNotes();
	event.Skip();
}

void MainFrame::RemoveNoteFrame(NoteFrame* frame) 
{
	noteFrames.erase(std::remove(noteFrames.begin(), noteFrames.end(), frame), noteFrames.end());
}