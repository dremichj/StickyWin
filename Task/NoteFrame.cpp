#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>
#include <vector>
#include <string>
#include <wx/filename.h>
#include "NoteFrame.h"



NoteFrame::NoteFrame(MainFrame* parentFrame,const wxString& title)
	: wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)), mainFrame(parentFrame)
{
	sticky;

	notePanel = new wxPanel(this, wxID_ANY);


	noteText = new wxRichTextCtrl(notePanel, wxID_ANY, "Enter your note",
		wxDefaultPosition, wxDefaultSize, wxTC_MULTILINE | wxTE_LEFT);

	stickButton = new wxButton(notePanel, wxID_ANY, "P", wxDefaultPosition, wxSize(25,25));

	stickButton->Bind(wxEVT_BUTTON, &NoteFrame::onStickButtonClicked,this);

	stickPanel = new wxPanel(notePanel, wxID_ANY, wxDefaultPosition,wxSize(-1,25));




	wxBoxSizer* horSizer = new wxBoxSizer(wxHORIZONTAL);

	horSizer->Add(stickPanel, 1, wxEXPAND | wxALL, 2);
	horSizer->Add(stickButton, 0, wxEXPAND | wxALL, 2);



	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	sizer->Add(horSizer, 0, wxEXPAND | wxALL, 5);

	sizer->Add(noteText, 1, wxEXPAND | wxALL, 5);

	notePanel->SetSizer(sizer);

	Bind(wxEVT_CLOSE_WINDOW, &NoteFrame::OnWinClose, this);
}

void NoteFrame::onStickButtonClicked(wxCommandEvent& event)
{
	if (sticky) {
		sticky = false;
		this->SetWindowStyle(GetWindowStyleFlag()& ~wxSTAY_ON_TOP);
	}
	else {
		sticky = true;
		this->SetWindowStyle(GetWindowStyleFlag()| wxSTAY_ON_TOP);
	}
}

void NoteFrame::OnWinClose(wxCloseEvent& event)
{
	if (mainFrame) {
		mainFrame->RemoveNoteFrame(this);
	}
	Destroy();
}
