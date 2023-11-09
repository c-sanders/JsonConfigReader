#include <OptionsPostProcessing.hpp>


template<class T>
void
jsonConfigReader::optionsPostProcessing::extract
(
 boost::json::object const & obj,
 T                         & t,
 boost::json::string_view    key
)
{
    const
    string   nameFunction = "jsonConfigReader::optionsPostProcessing::extract",
             nF           = nameFunction + " : ";


    cout << nF << "Enter" << endl;
    cout << nF << "obj = " << obj << endl;
    cout << nF << "obj.at(key) = " << obj.at(key) << endl;
    cout << nF << "Key = " << key << endl;
    cout << nF << obj.at(key) << endl;

    t = boost::json::value_to<T>(obj.at(key));

    cout << nF << "Exit" << endl;
}


jsonConfigReader::optionsPostProcessing::OptionsStruct
jsonConfigReader::optionsPostProcessing::tag_invoke
(
 boost::json::value_to_tag< jsonConfigReader::optionsPostProcessing::OptionsStruct >,
 boost::json::value const& jv
) 
{
    const
    string                     nameFunction = "jsonConfigReader::optionsPostProcessing::tag_invoke",
                               nF = nameFunction + " : ";

    OptionsStruct              options;

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


/*
class
OptionsPostProcessing_class
{
    public :

        OptionsGeoRestriction_class();

        ~OptionsGeoRestriction_class();

    public :

        jsonConfigReader::options::OptionsGeoRestriction
        tag_invoke
        (
         boost::json::value_to_tag< jsonConfigReader::options::OptionsGeoRestriction >,
         boost::json::value const & jv 
        );

    private :

        template<class T>
        void
        extract
        (
         boost::json::object const & obj,
         T                         & t,
         boost::json::string_view    key
        );


    private :

        string   geo_verification_proxy;

        string   xff;
};
 */
