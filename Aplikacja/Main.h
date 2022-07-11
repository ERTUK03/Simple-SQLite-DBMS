#pragma once

#include <wx/dir.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/textdlg.h>
#include "Db.h"

class Main : public wxFrame
{
public:
	Main();
	~Main();

private:
	void create_db(wxCommandEvent& evt);
	void open_db(wxCommandEvent& evt);
	void delete_db(wxCommandEvent& evt);

	wxButton* button = nullptr;
	wxFileDialog* file = nullptr;

	DECLARE_EVENT_TABLE();
};

