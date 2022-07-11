#pragma once

#include "Main.h"

class App : public wxApp
{
public:
	App(){}
	~App(){}

private:
	Main* m_frame1 = nullptr;
	bool OnInit();
};

