#include "options.h"
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
Options::Options(int argcOuter,char** argvOuter):
	argc(argcOuter),
	argv(argvOuter)
{
	expectedOptions="edi:o:t:";
	encode=0;
	decode=0;
	parseOptions();
	checkExpectations();
}

int Options::isEncode()
{
	return encode;
}

int Options::isDecode()
{
	return decode;
}

std::string Options::getInputFile()
{
	return inputFile;
}

std::string Options::getOutputFile()
{
	return outputFile;
}

std::string Options::getInputText()
{
	return inputText;
}

void Options::parseOptions()
{
	int c;
	while((c=getopt(argc,argv,expectedOptions.c_str())) != -1)
		switch (c) {
		case 'e':
			encode = 1;
			break;
		case 'd':
			decode = 1;
			break;
		case 'i':
			inputFile = optarg;
			break;
		case 'o':
			outputFile = optarg;
			break;
		case 't':
			inputText = optarg;
			break;
		case '?':
			if(optopt == 'i' || optopt == 'o' || optopt == 't') {
				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				abort();
			}
			else if (isprint (c)) {
				fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				abort();
			}
			else {
				fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
				abort();
			}
			break;
		default:
			break;
		}
	printf("encode = %i, decode = %i, input_file = %s, output_file = %s,"
				 " input_text = %s\n",encode,decode,inputFile.c_str(),
				 outputFile.c_str(),inputText.c_str());
}

void Options::checkExpectations()
{
	if(encode){
		if(inputFile.empty()) {
			fprintf (stderr, "Encode option specified,"
											 " but no input file specified.\n");
			abort();
		}
		else if (outputFile.empty()){
			fprintf (stderr, "Encode option specified,"
											 " but no output file specified.\n");
			abort();
		}
		else if (inputText.empty())
			fprintf (stderr, "Encode option specified,"
											 " but no input text specified.\n");
	}
	else if (decode)
		if (inputFile.empty())
			fprintf (stderr, "Decode option specified,"
											 " but no input file specified.\n");
}
