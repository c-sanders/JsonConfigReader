#ifndef OPTIONSPOSTPROCESSING_HPP
#define OPTIONSPOSTPROCESSING_HPP


#include <iostream>
#include <string>

#include <boost/json.hpp>
// #include <boost/json/object.hpp>
// Type(s) : object

using std::cout;
using std::endl;

// #include <JsonToObject.hpp>


using std::string;

// using jsonConfigReader::jsonToObject::tag_invoke;


namespace
jsonConfigReader
{

namespace
optionsPostProcessing
{    
    struct
    OptionsStruct
    {
     string   geo_verification_proxy;
     string   xff;
    };


    // Note that the following function is templated and thus generic.
    //
    // Should it live in this namespace or another namespace?

    template<class T>
    void
    extract
    (
     boost::json::object const & obj,
     T                         & t,
     boost::json::string_view    key
    );


    // Is the following free function used to;
    // 
    //   - create an instance of the type OptionsGeoRestriction,
    // 
    //   - convert from JSON code to an object.
    // 
    // When an instance of the type OptionsGeoRestriction needs to be created,
    // the compiler should use this version of the tag_invoke function. 
    //
    // Who invokes this function?
    //
    // It is invoked from the function processJsonModel, when the object named options is instantiated. 

    jsonConfigReader::optionsPostProcessing::OptionsStruct
    tag_invoke
    (
     boost::json::value_to_tag< jsonConfigReader::optionsPostProcessing::OptionsStruct >,
     boost::json::value const & jv 
    );

}  // End of namespace : optionsPostProcessing

}  // End of namespace : configReader


#endif
