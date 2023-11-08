#include <JsonToObject.hpp>


namespace
jsonConfigReader
{

namespace
jsonToObject
{
    // 

    template<class T>
    void
    extract
    (
     boost::json::object const & obj,
     T                         & t,
     boost::json::string_view    key
    )
    {
        const
        string   nameFunction = "configReader::extract",
                 nF           = nameFunction + " : ";


        cout << nF << "Enter" << endl;
        cout << nF << "obj = " << obj << endl;
        cout << nF << "obj.at(key) = " << obj.at(key) << endl;
        cout << nF << "Key = " << key << endl;
        cout << nF << obj.at(key) << endl;

        t = boost::json::value_to<T>(obj.at(key));

        cout << nF << "Exit" << endl;
    }


    // The following free function is used to convert from JSON code to an
    // object.
    // 
    // Note that it resides in the namespace jsonConfigReader::jsonToObject
    //
    // This is in contrast to the invoking client function
    // jsonConfigReader::utilities::processJsonModel, which resides in a
    // different namespace. The offending command in the client function is the
    // one which attempts to instantiate a struct of type
    // jsonConfigReader::options::OptionsGeoRestriction. 
    // 
    // Furthermore, the struct which is to be created resides in the
    // jsonConfigReader::options namespace.
    // 
    // Note the discrepancy across three namespaces here. I think this is what
    // is causing the problems at compile time.

    /*
    jsonConfigReader::jsonToObject::OptionsGeoRestriction
    tag_invoke
    (
     boost::json::value_to_tag< OptionsGeoRestriction >,
     boost::json::value const & jv 
    )
    {
        const
        string                     nameFunction = "configReader::tag_invoke",
                                   nF = nameFunction + " : ";

        OptionsGeoRestriction      options;

        boost::json::object const& obj = jv.as_object();


        cout << nF << "Enter" << endl;

        cout << nF << "obj = " << obj << endl;

        cout << nF << "About to invoke function : extract" << endl;

        extract
        (
         obj,                             // Source object to extract value from. 
         options.geo_verification_proxy,  // Field in destination object to write value into. 
         "geo_verification_proxy"         // Name of field in source object.
        );

        extract
        (
         obj,          // Source object to extract value from. 
         options.xff,  // Field in destination object to write value into. 
         "xff"         // Name of field in source object.
        );

        cout << "options.geo_verification_proxy = " << options.geo_verification_proxy << endl;
        cout << "options.xff                    = " << options.xff << endl;

        cout << nF << "Exit" << endl;

        return options;
    }
     */


    jsonConfigReader::jsonToObject::OptionsPostProcessing
    tag_invoke
    (
     boost::json::value_to_tag< OptionsPostProcessing >,
     boost::json::value const & jv 
    )
    {
        const
        string                     nameFunction = "configReader::tag_invoke",
                                   nF = nameFunction + " : ";

        OptionsPostProcessing      options;

        boost::json::object const& obj = jv.as_object();


        cout << nF << "Enter" << endl;

        cout << nF << "obj = " << obj << endl;

        cout << nF << "About to invoke function : extract" << endl;

        /*
        extract
        (
         obj,                             // Source object to extract value from. 
         options.geo_verification_proxy,  // Field in destination object to write value into. 
         "geo_verification_proxy"         // Name of field in source object.
        );

        extract
        (
         obj,          // Source object to extract value from. 
         options.xff,  // Field in destination object to write value into. 
         "xff"         // Name of field in source object.
        );

        cout << "options.geo_verification_proxy = " << options.geo_verification_proxy << endl;
        cout << "options.xff                    = " << options.xff << endl;
         */

        cout << nF << "Exit" << endl;

        return options;
    }

}

}  // End of namespace : jsonToObject


namespace
objectToJson
{
    // The following free function is used to create the JSON code which will 
    // represent the object.

    void
    tag_invoke
    (
     boost::json::value_from_tag,
     boost::json::value         & jv,
     OptionsGeoRestriction const& options
    )
    {
        jv = {
              {"geo_verification_proxy", options.geo_verification_proxy},
              {"xff",                    options.xff}
             };
    }


    void
    tag_invoke
    (
     boost::json::value_from_tag,
     boost::json::value         & jv,
     OptionsPostProcessing const& options
    )
    {
        /*
        jv = {
              {"geo_verification_proxy", options.geo_verification_proxy},
              {"xff",                    options.xff}
             };
         */
    }

}  // End of namespace : objectToJson
