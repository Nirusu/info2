#include "Dir_or_File.hpp"

Dir_or_File::Dir_or_File(std::string name)
{
	this->name = name;
	this->is_file = name.back() != '/';
}


std::vector<std::string> Dir_or_File::split_after_slash(std::string full_path)
{
	std::vector<std::string> ret;

	/* because dealing with the substring function seems to be a hassle (see past commits), do a "dumb approach":
	 * add every char (including /) of we string to a second, temporary one until we hit a slash
	 * if we hit one, push it back in the vector and clear the temporary string
	 * repeat this until we reach the end of the string.
	 */

	std::string current_path;
	for (char i : full_path)
	{
		current_path += i;
		if (i == '/')
		{
			ret.emplace_back(current_path);
			current_path = "";
		}
	}

	/* if the end of the path is a file, there's no slash at the end,
	 * so we insert the rest of the temporary string
	 * (if it's not empty, which would be the case if the path ends with a dir)
	 * in the vector and call it a day
	 */

	if (!current_path.empty())
	{
		ret.emplace_back(current_path);
	}
	return ret;
}


void Dir_or_File::insert(std::vector<std::string> names)
{
	if (names.empty()) // since we recursively call this function again, we have to abort if we have nothing to insert
		return;

	// pick the current directory or file to work with, than move the rest of the path up for our next iterator

	std::string current_name = names[0]; // save the dir or file we want to work with as current_name
	names.erase(names.begin()); // remove the just-before saved entry from "names" so we can use "names" for the recursive calls

	// go through "entries" to search for equal (case 1) or bigger entries (case 2)
	for (int i=0; i<entries.size(); i++)
	{
		// case 1: If we find the same dir or file, recursively call the insert function again with the reduced path
		if (current_name == entries[i]->name)
		{
			entries[i]->insert(names);
			return;
		}
		// case 2: If we find an entry with a "higher" letter, we insert before this one and recursively call the insert again on the newly inserted object for the rest of "names"
		if (current_name < entries[i]->name)
		{
			entries.insert(entries.begin()+ i, new Dir_or_File(current_name)); // workaround: entries.begin() + i because we need to provide an iterator instead of just an index
			entries[i]->insert(names);
			return;
		}
	}
	// case 3: if we find no equal or "bigger" entry, than we need to insert at the end of "entries"
	entries.emplace_back(new Dir_or_File(current_name));
	entries[entries.size() - 1]->insert(names);
}