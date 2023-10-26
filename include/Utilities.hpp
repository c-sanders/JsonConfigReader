#ifndef UTILITIES_HPP
#define UTILITIES_HPP


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// #include <boost/json/string_view.hpp>
// Type(s) : string_view
#include <boost/json.hpp>
#include <boost/json/object.hpp>
// Type(s) : object
// #include <boost/json/value_to.hpp>
// Function(s) : value_to

#include <OptionsStructs.hpp>
#include <CreateObjectOptions.hpp>
#include <JsonToObject.hpp>


using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::stringstream;


namespace jsonConfigReader
{

namespace utilities
{

	// Don't use the following function.
	
	boost::json::value
	parse_file
	(
	 char
	 const * 
	 filename
	);


	boost::json::value
	parseFile
	(
	 char
	 const * filename
	);


	int
	processJsonModel
	(
	 boost::json::value   jv
	);

}  // End of namespace : utilities

}  // End of namespace : jsonConfigReader


#endif
