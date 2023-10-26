#include <ObjectToJson.hpp>


namespace
jsonConfigReader
{
namespace
objectToJson
{
    // The following free function should be used to create JSON code which 
    // will represent an object.
    //
    // value_from_tag :
    // jv             : Variable which the resulting JSON value should be
    //                  written into.
    // options        : The object which the values should be read from.

    void
    tag_invoke
    (
     boost::json::value_from_tag,
     boost::json::value          & jv,
     OptionsGeoRestriction const & options
    )
    {
        // How can we tell which type of object has been passed to this
        // function?
        
        // Option set : 1

        if (obj.contains("OptionsGeneral"))
        {
            createObjectOptionsGeneral
            (
             boost::json::value_from_tag,
             boost::json::value & jv,
             OptionsGeoRestriction const & options
            );
        }
    }


}  // End of namespace : objectToJson

}