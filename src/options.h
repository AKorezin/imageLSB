#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

class Options
{
private:
	int argc;
	char **argv;
	int encode,decode;
	std::string input_file,output_file;
	void parse_options();
	std::string expected_options;
public:
	Options(int, char**);
};

#endif // OPTIONS_H
