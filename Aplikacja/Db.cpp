#include "Db.h"

Db::Db(wxString path) : wxDialog(nullptr, wxID_ANY, "Database manager")
{
	sqlite3_open(path, &database);
	text = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(350, 125), wxTE_MULTILINE);
	button = new wxButton(this, 20001, "Confirm", wxPoint(10, 150));
}

Db::~Db()
{
	sqlite3_close(database);
}

void Db::getText(wxCommandEvent& evt)
{
	dialog = new wxDialog(this, wxID_ANY, "Output");
	wxString str = "";
	sqlite3_stmt* stmt;
	exit = sqlite3_prepare(database, text->GetValue(), -1, &stmt, NULL);
	error()
		else
		{
		while ((exit = sqlite3_step(stmt)) == SQLITE_ROW)
		{
			for (int i = 0; sqlite3_column_text(stmt, i) != NULL; i++)
			{
				str += wxString(sqlite3_column_text(stmt, i));
				str += wxString(' ');
			}
			str += "\n";
		}
		error()
			else if (str == "")	str = "Operation successful";
			sqlite3_reset(stmt);
			sqlite3_finalize(stmt);
		}
		info = new wxStaticText(dialog, wxID_ANY, str);
		dialog->ShowModal();
		text->Clear();
}

wxBEGIN_EVENT_TABLE(Db, wxDialog)
	EVT_BUTTON(20001, getText)
wxEND_EVENT_TABLE()