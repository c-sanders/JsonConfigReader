#include <iostream>
#include <string>

#include <Utilities.hpp>


using std::string;
using std::cout;
using std::endl;

// namespace json = boost::json;

// using jsonConfigReader::jsonToObject::tag_invoke;


/*
 *  main  (Main.cpp)
 *    |
 *    |- jsonConfigReader::utilities::parseFile                                           (Utilities.cpp)
 *    |
 *    |- jsonConfigReader::utilities::processJsonModel                                    (Utilities.cpp)
 *         |
 *         |- jsonConfigReader::processObjectOptions::processOptionsXXX                   (CreateObjectOptions.cpp)
 *              |
 *              |- jsonConfigReader::optionsXXX::tag_invoke                               (OptionsXXX.cpp)
 */

int
main
(
 int    argc,
 char * argv[]
)
{
	const
	string               nameFunction = "main",
		                 nF           = nameFunction + " : ";

    stringstream         jsonCode;

    const
    char               * jsonCode_p;

    boost::json::value   jsonModel;


	cout << nF << "Enter" << endl;

    /*
    configReader::OptionsGeoRestriction   options{"http://www.proxy.com:800", "Poop"};

    cout << nF << "options = " << boost::json::serialize( boost::json::value_from( options ) ) << endl;

    jsonCode << boost::json::serialize(boost::json::value_from(options));

    jsonCode_p = jsonCode.str().c_str();

    cout << "jsonCode = " << jsonCode_p << endl;
     */

    cout << nF << "About to invoke function : parseFile" << endl;

    jsonModel = jsonConfigReader::utilities::parseFile(argv[1]);

    cout << nF << "Have invoked function : parseFile" << endl;
    
    cout << nF << endl;
    cout << nF << endl;
    cout << nF << endl;
    cout << nF << endl;
    cout << nF << endl;

    // The following function is currently invoked from the function parseFile.

    cout << nF << "About to invoke function : processJsonModel" << endl;

    jsonConfigReader::utilities::processJsonModel(jsonModel);

    cout << nF << "Have invoked function : processJsonModel" << endl;

	cout << nF << "Exit" << endl;
}
