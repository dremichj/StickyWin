#pragma once
#include <wx/wx.h>
#include <wx/webview.h>
#include "NoteFrame.h"


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	void RemoveNoteFrame(NoteFrame* frame);

private:
	void CreateControls();

	void OnAddButtonClicked(wxCommandEvent& event);
	void OnClearButtonClicked(wxCommandEvent& event);
	void clearNotes();
	void OnWinClose(wxCloseEvent& event);
	
	wxPanel* panel;
	wxStaticText* headlineText;
	wxButton* addButton;
	wxButton* clearButton;
	wxTextCtrl* text;

	std::vector<NoteFrame*> noteFrames;

	
};

