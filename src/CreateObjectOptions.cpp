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


void
createObjectOptionsGeoRestriction
(
)
{
    /*
    jv_new = {
              {"geo_verification_proxy", options.geo_verification_proxy},
              {"xff",                    options.xff}
             };
     */
}


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


// Function : processObjectOptionsGeoRestriction
// =============================================
// Alias    : copyJsonObjectToStructObject_GeoRestriction
// 
// 
// Process a JSON object which contains the values related to the
// Geo-Restriction settings.
// 
// This function processes the JSON object by copying the values from it
// into an object which is an instance of a customised struct.
//
// Return value :
// --------------
// 
// A customised struct object which contains the values from the JSON object.
// 
// Parameters :
// ------------
// 
// obj : A JSON object which contains the Geo-Restriction settings. These should
//       be in the form of a key-value pair, an example of which is listed
//       below;
//
//         "OptionsGeoRestriction" :
//         {
//          "geo_verification_proxy" : "http:///www.proxy.com:800",
//          "xff" : "Poop"
//         }
//

struct
jsonConfigReader::optionsGeoRestriction::OptionsStruct
processOptionsGeoRestriction
(
 const
 boost::json::value  & value
)
{
    const
    string   nameFunction = "processObjectOptionsGeoRestriction",
             nF           = nameFunction + " : ";

    cout << nF << "Enter" << endl;

    jsonConfigReader::optionsGeoRestriction::OptionsStruct
    options
    (
     boost::json::value_to<jsonConfigReader::optionsGeoRestriction::OptionsStruct>
     (
      value
     )
    );

    cout << "Object is of type : OptionsGeoRestriction" << endl;
    cout << "!!! objValue = " << boost::json::serialize(value) << endl;


    return options;
}

void
processOptionsVideoSelection
(
)
{
}


struct
jsonConfigReader::optionsPostProcessing::OptionsStruct
processOptionsPostProcessing
(
 const
 boost::json::value & obj
)
{
    const
    string   nameFunction = "jsonConfigReader::processObjectOptions::processOptionsPostProcessing",
             nF           = nameFunction + " : ";

    auto
    const  & objValue = obj.at("OptionsPostProcessing");

    /*
    struct
    jsonConfigReader::optionsPostProcessing::OptionsStruct   rarr;
     */


    cout << nF << "Enter" << endl;

    // Create a new object of type struct OptionsPostProcessing

    /*
    jsonConfigReader::options::OptionsGeoRestriction
    options
    (
     boost::json::value_to<jsonConfigReader::options::OptionsGeoRestriction>
     (
      objValue
     )
    );
     */

    // The compiler doesn't like the following instruction.

    jsonConfigReader::optionsPostProcessing::OptionsStruct
    options
    (
     boost::json::value_to<jsonConfigReader::optionsPostProcessing::OptionsStruct>
     (
      objValue
     )
    );

    cout << nF << "Object is of type : OptionsPostProcessing" << endl;
    cout << "!!! objValue = " << boost::json::serialize(objValue) << endl;


    cout << nF << "Exit" << endl;

    return options;
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
