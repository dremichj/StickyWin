#pragma once
#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>


class MainFrame;

class NoteFrame : public wxFrame
{
public:
	NoteFrame(MainFrame* parentFrame,const wxString& title);
	
private:
	MainFrame* mainFrame;


	wxPanel* notePanel;
	wxRichTextCtrl* noteText;
	wxButton* stickButton;
	wxPanel* stickPanel;
	
	bool sticky { false };

	NoteFrame(const NoteFrame&) = delete;
	NoteFrame& operator = (const NoteFrame&) = delete;

	void onStickButtonClicked(wxCommandEvent& event);
	void OnWinClose(wxCloseEvent& event);
};