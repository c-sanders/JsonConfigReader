#ifndef CREATEOBJECTOPTIONS_HPP
#define CREATEOBJECTOPTIONS_HPP


#include <string>
#include <iostream>

#include <boost/json.hpp>
#include <boost/json/object.hpp>
// Type(s) : object

#include <OptionsStructs.hpp>

using std::string;
using std::cout;
using std::endl;


namespace jsonConfigReader
{

namespace createObjectOptions
{
    void
    createObjectOptionsGeoRestriction
    (
    );

    /*
    {
        jv = {
              {"geo_verification_proxy", options.geo_verification_proxy},
              {"xff",                    options.xff}
             };
    }
     */

}  // End of namespace : createObjectOptions


namespace
processObjectOptions
{
    struct
    jsonConfigReader::optionsGeoRestriction::OptionsStruct
    processOptionsGeoRestriction
    (
     const
     boost::json::value & obj
    );


    struct
    jsonConfigReader::optionsPostProcessing::OptionsStruct
    processOptionsPostProcessing
    (
     const
     boost::json::object & obj
    );

}  // End of namespace : processObjectOptions

}  // End of namespace : jsonConfigReader


#endif