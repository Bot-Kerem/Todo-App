#pragma once

#include <string>

class App{
	private:	
		std::string APP_NAME = "TODO App";

	public:

		App();

		static void init();

		void run();
}
