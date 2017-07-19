#include "Dir_or_File.hpp"

Dir_or_File::Dir_or_File(std::string name)
{
	// constructor stuff goes here
	// make sure that is_file is set according to the '/' rules -> make a check here!
	is_file = name.back() != '/';
}


std::vector<std::string> Dir_or_File::split_after_slash(std::string full_path)
{
	// take care of '/'
	// check what comes after a slash and decide what to do according to what you find
	// so iterate through your string and find slashes
	// and then decide what to do...

	std::vector<std::string> ret;
	// iteration goes here
	int position_after_last_slash = 0;
 	for(int i=0; i < full_path.length(); i++)
	{
		if (full_path[i] == '/')
		{
			if (i == 0)
			{
				ret.push_back("/");
			}
			else
			{
				std::string substring = full_path.substr(position_after_last_slash, i);
				ret.push_back(substring);
			}
			position_after_last_slash = i + 1;
		}
	}
	return ret;
}


void Dir_or_File::insert(std::vector<std::string> names)
{
	// now comes the insertion of new entries
	// again make sure to distinguihs between files and directories

}

