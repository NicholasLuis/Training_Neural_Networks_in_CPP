#include "log.h"


logger::logger(const std::string inputFileName)
{
	this->mutex = NULL;
	this->fileName = inputFileName;
	this->usingMutex = false;

	// Opening the file for writing
	outfile.open(fileName, std::ios::binary);
	if (!outfile.is_open()) {
		std::cerr << "Failed to open file for writing: " << fileName << std::endl;
		return;
	}
}

logger::logger(const std::string inputFileName, std::mutex* inputMutex)
{
	this->fileName = inputFileName;
	this->mutex = inputMutex;
	this->usingMutex = true;
	//this->printerObj = prntObj;

	// Opening the file for writing
	outfile.open(fileName, std::ios::app);
	if (!outfile.is_open()) {
		std::cerr << "Failed to open file for writing: " << fileName << std::endl;
		return;
	}
}

logger::~logger() // Destructor
{
	outfile.close();
	delete this->mutex; // avoiding memory leaks
}

void logger::log(const std::vector<std::vector<double>> toLog)
{
	// Update the nnShape variable
	// Loop through the outer vector (layers)
		// Loop through the innter vector (Number of neurons)


/* Example Code from a different program: 
	uint32_t length = message.size();
	outfile.write(reinterpret_cast<const char*>(&length), sizeof(length));
	outfile.write(toLog.data(), toLog.size());
*/
}

std::vector<std::vector<double>> getWeights()
{
	
}