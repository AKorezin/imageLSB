#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

class Options
{
private:
	int argc;
	char **argv;
	int encode,decode;
	std::string inputFile,outputFile,inputText;
	std::string expectedOptions;

	void parseOptions();
	void checkExpectations();

public:
	Options(int, char**);
	int isEncode();
	int isDecode();
	std::string getInputFile();
	std::string getOutputFile();
	std::string getInputText();
};

#endif // OPTIONS_H
