#include <iostream>
#include <string>

#include <Utilities.hpp>


using std::string;
using std::cout;
using std::endl;

// namespace json = boost::json;

// using jsonConfigReader::jsonToObject::tag_invoke;


int
main
(
 int    argc,
 char * argv[]
)
{
	const
	string         nameFunction = "main",
		           nF           = nameFunction + " : ";

    stringstream   jsonCode;

    const
    char         * jsonCode_p;   


	cout << nF << "Enter" << endl;

    /*
    configReader::OptionsGeoRestriction   options{"http://www.proxy.com:800", "Poop"};

    cout << nF << "options = " << boost::json::serialize( boost::json::value_from( options ) ) << endl;

    jsonCode << boost::json::serialize(boost::json::value_from(options));

    jsonCode_p = jsonCode.str().c_str();

    cout << "jsonCode = " << jsonCode_p << endl;
     */

    jsonConfigReader::utilities::parseFile(argv[1]);

	cout << nF << "Exit" << endl;
}
