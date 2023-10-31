#include <CreateObjectOptions.hpp>


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
    )
    {
    }

    void
    processOptionsNetwork
    (
    )
    {
    }

void
processObjectOptionsGeoRestriction
(
 const
 boost::json::object & obj
)
{
    const
    string   nameFunction = "processObjectOptionsGeoRestriction",
             nF           = nameFunction + " : ";

    // Get the value of this key-value pair.

    auto
    const  & obj_value    = obj.at("OptionsGeoRestriction");

    // jsonConfigReader::options::OptionsGeoRestriction   options;


    cout << nF << "Enter" << endl;

    // Object obj will be in the form of a key-value pair, which
    // should have the following format;
    //
    //   "OptionsGeoRestriction" :
    //   {
    //     "geo_verification_proxy" : "http:///www.proxy.com:800",
    //     "xff" : "Poop"
    //   }

    cout << "Object is of type : OptionsGeoRestriction" << endl;

    cout << "!!! obj_value = " << boost::json::serialize(obj_value) << endl;

    // Create an object from the segment of JSON code which is contained
    // within the variable jv.

    // We are currently in namespace jsonConfigReader::utilities
    //
    // We are attempting to create a struct from namespace jsonConfigReader::options
    //
    // The function which will create this struct resides in namespace
    // jsonConfigReader::jsonToObject

    // Create a new object of type struct OptionsGeoRestriction

    jsonConfigReader::options::OptionsGeoRestriction
    options
    (
     boost::json::value_to<jsonConfigReader::options::OptionsGeoRestriction>
     (
      obj_value
     )
    );

    /*
    jv_new = {
              {"geo_verification_proxy", options.geo_verification_proxy},
              {"xff",                    options.xff}
             };
     */

    cout << nF << "options.geo_verification_proxy = " << options.geo_verification_proxy << endl;
    cout << nF << "options.xff                    = " << options.xff << endl;

    cout << nF << "Exit" << endl;
}


    void
    processOptionsVideoSelection
    (
    )
    {
    }

    void
    processOptionsPostProcessing
    (
    )
    {
    }

    void
    processObjectOptionsSponsorBlock
    (
    )
    {
    }

    void
    processObjectOptionsExtractor
    (
    )
    {
    }

}  // End of namespace : processObjectOptions

}  // End of namespace : jsonConfigReader
