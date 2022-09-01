#pragma once

#include "window.h"

#include <string>

class App{
	private:	
		std::string APP_NAME = "TODO App";
		int width = 800;
		int height = 600;
		Window window{APP_NAME, width, height};

	public:

		App();

		static void Init();

		void run();
};
