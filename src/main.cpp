#include <iostream>
#include <stdexcept>
#include "app.h"

int main(int argc, char** argv){
	App::Init();
	App app;
	try{
		app.run();
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	

	return EXIT_SUCCESS;
}
