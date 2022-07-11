#include "App.h"

bool App::OnInit()
{
	m_frame1 = new Main();
	m_frame1->Show();
	return true;
}

wxIMPLEMENT_APP(App);