#pragma once

#include "window.h"
#include "scene.h"

#include <string>

class App{
	private:
		std::string APP_NAME = "TODO App";
		int width = 1920;
		int height = 1080;

		Window window{APP_NAME, width, height};

		Scene m_MainScene{Size(1920, 1080)};
	public:

		App();

		static void Init();

		void run();

		void build();
};
