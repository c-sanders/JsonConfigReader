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
createObjectOptionsGeneral
(
);


void
createObjectOptionsNetwork
(
);


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


void
createObjectOptionsVideoSelection
(
);


void
createObjectOptionsDownload
(
);


void
createObjectOptionsFormat
(
);


void
createObjectOptionsSubtitle
(
);


void
createObjectOptionsAuthentication
(
);


void
createObjectOptionsPostProcessing
(
);


void
createObjectOptionsSponsorBlock
(
);


void
createObjectOptionsExtractor
(
);

}  // End of namespace : createObjectOptions


namespace
processObjectOptions
{
    void
    processOptionsGeneral
    (
    );

    void
    processOptionsNetwork
    (
    );

    void
    processObjectOptionsGeoRestriction
    (
     const
     boost::json::object & obj
    );

    void
    processOptionsVideoSelection
    (
    );

    void
    processOptionsPostProcessing
    (
    );

    void
    processObjectOptionsSponsorBlock
    (
    );

    void
    processObjectOptionsExtractor
    (
    );

}  // End of namespace : processObjectOptions

}  // End of namespace : jsonConfigReader


#endif