#include "Main.h"

#define newButton(id, str, point) new wxButton(this, id, str, point);

wxBEGIN_EVENT_TABLE(Main, wxFrame)
	EVT_BUTTON(10001, create_db)
	EVT_BUTTON(10002, open_db)
	EVT_BUTTON(10003, delete_db)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Window", wxDefaultPosition, wxSize(300, 300))
{
	button = newButton(10001, "Create new database", wxPoint(10, 10))
	button = newButton(10002, "Open existing database", wxPoint(10, 50))
	button = newButton(10003, "Delete database", wxPoint(10, 90))
}

Main::~Main() {}

void Main::create_db(wxCommandEvent& evt)
{
	wxTextEntryDialog* t = new wxTextEntryDialog(this, "Enter database name");
	t->ShowModal();
	if (!wxFile::Exists("Databases/" + t->GetValue()))
	{
		sqlite3* db;
		sqlite3_open("Databases/" + t->GetValue(), &db);
		sqlite3_close(db);
	}
}

void Main::open_db(wxCommandEvent& evt)
{
	file = new wxFileDialog(this, "Open a database", "Databases");
	file->ShowModal();
	if (file->GetPath() != "")
	{
		Db* Database = new Db(file->GetPath());
		Database->ShowModal();
	}
}

void Main::delete_db(wxCommandEvent& evt)
{
	file = new wxFileDialog(this, "Delete a database", "Databases");
	file->ShowModal();
	if (file->GetPath() != "") wxRemoveFile(file->GetPath());
}
