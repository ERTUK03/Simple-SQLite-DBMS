#pragma once

#include <wx/dialog.h>
#include <sqlite3.h>
#include <wx/wx.h>
#include <sstream>

#define error() if (exit != SQLITE_OK)	str = sqlite3_errmsg(database);

class Db : public wxDialog
{
public:
	Db(wxString path);
	~Db();

private:
	void getText(wxCommandEvent& evt);

	wxButton* button = nullptr;
	sqlite3* database = nullptr;
	wxTextCtrl* text = nullptr;
	wxDialog* dialog = nullptr;
	wxStaticText* info = nullptr;
	char* msg = nullptr;
	int exit = 0;

	DECLARE_EVENT_TABLE();
};

