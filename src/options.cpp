#include "options.h"
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
Options::Options(int argc_outer,char** argv_outer):
	argc(argc_outer),
	argv(argv_outer)
{
	expected_options="edfo:";
}

void Options::parse_options()
{
	int c;
	while((c=getopt(argc,argv,expected_options.c_str())) != -1)
		switch (c) {
		case 'e':
			encode = 1;
			break;
		case 'd':
			decode = 1;
			break;
		case 'f':
			input_file = optarg;
			break;
		case 'o':
			output_file = optarg;
			break;
		case '?':
			if(c=='f' || c=='o')
				fprintf (stderr, "Option -%c requires an argument.\n", c);
			else if (isprint (c))
				fprintf (stderr, "Unknown option `-%c'.\n", c);
			else
				fprintf (stderr, "Unknown option character `\\x%x'.\n", c);
			break;
		default:
			break;
		}
}


