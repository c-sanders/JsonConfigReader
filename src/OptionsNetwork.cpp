#include <OptionsNetwork.hpp>


template<class T>
void
jsonConfigReader::optionsNetwork::extract
(
 boost::json::object const & obj,
 T                         & t,
 boost::json::string_view    key
)
{
    const
    string   nameFunction = "jsonConfigReader::optionsNetwork::extract",
             nF           = nameFunction + " : ";


    cout << nF << "Enter" << endl;
    cout << nF << "obj = " << obj << endl;
    cout << nF << "obj.at(key) = " << obj.at(key) << endl;
    cout << nF << "Key = " << key << endl;
    cout << nF << obj.at(key) << endl;

    t = boost::json::value_to<T>(obj.at(key));

    cout << nF << "Exit" << endl;
}


jsonConfigReader::optionsNetwork::OptionsStruct
jsonConfigReader::optionsNetwork::tag_invoke
(
 boost::json::value_to_tag< jsonConfigReader::optionsNetwork::OptionsStruct >,
 boost::json::value const& jv
) 
{
    const
    string                     nameFunction = "jsonConfigReader::optionsNetwork::tag_invoke",
                               nF = nameFunction + " : ";

    OptionsStruct              options;

    boost::json::object const& obj = jv.as_object();


    cout << nF << "Enter" << endl;

    cout << nF << "obj = " << obj << endl;

    cout << nF << "About to invoke function : extract" << endl;

    /*
    struct
    OptionsStruct
    {
        string   proxy;
        string   socket_timeout;
        string   source_address;
        bool     force_ipv4;
        bool     force_ipv6;
        bool     enable_file_urls;
    };
     */

    extract
    (
        obj,            // Source object to extract value from. 
        options.proxy,  // Field in destination object to write value into. 
        "proxy"         // Name of field in source object.
    );

    extract
    (
        obj,                     // Source object to extract value from. 
        options.socket_timeout,  // Field in destination object to write value into. 
        "socket_timeout"         // Name of field in source object.
    );

    cout << "options.proxy          = " << options.proxy << endl;
    cout << "options.socket_timeout = " << options.socket_timeout << endl;

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
