#ifndef JSONTOOBJECT_HPP
#define JSONTOOBJECT_HPP


// #include <boost/json.hpp>
// #include <boost/json/object.hpp>
// Type(s) : object

#include <OptionsStructs.hpp>


namespace
jsonConfigReader
{

namespace
jsonToObject
{
    /*
     * It appears as though I have moved the declarations for these functions
     * into the file OptionsStructs.hpp.   
     */

    /*
    template<class T>
    void
    extract
    (
     boost::json::object const & obj,
     T                         & t,
     boost::json::string_view    key
    );
     */


    // The following free function is used to convert from JSON code to an object.
    //
    // Who invokes this function?
    //
    // It is invoked from the function processJsonModel, when the object named options is instantiated. 

    /*
    jsonConfigReader::options::OptionsGeoRestriction
    tag_invoke
    (
     boost::json::value_to_tag< jsonConfigReader::options::OptionsGeoRestriction >,
     boost::json::value const & jv 
    );
     */

}  // End of namespace : jsonToObject

}  // End of namespace : jsonConfigReader


#endif
