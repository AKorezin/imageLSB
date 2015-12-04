#include "options.h"
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
Options::Options(int argc_outer,char** argv_outer):
	argc(argc_outer),
	argv(argv_outer)
{
	expectedOptions="edi:o:t:";
	encode=0;
	decode=0;
	parseOptions();
	checkExpectations();
}

int Options::isEncode()
{

}

int Options::isDecode()
{

}

std::string Options::getInputFile()
{

}

std::string Options::getOutputFile()
{

}

std::string Options::getInputText()
{

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
			if(optopt == 'i' || optopt == 'o' || optopt == 't')
				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
			else if (isprint (c))
				fprintf (stderr, "Unknown option `-%c'.\n", optopt);
			else
				fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
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
		if(inputFile.empty())
			fprintf (stderr, "Encode option specified,"
											 " but no input file specified.\n");
		else if (outputFile.empty())
			fprintf (stderr, "Encode option specified,"
											 " but no output file specified.\n");
		else if (inputText.empty())
			fprintf (stderr, "Encode option specified,"
											 " but no input text specified.\n");
	}
	else if (decode)
		if (inputFile.empty())
					fprintf (stderr, "Decode option specified,"
													 " but no input file specified.\n");
}
