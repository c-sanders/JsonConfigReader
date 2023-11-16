#include <Utilities.hpp>


namespace jsonConfigReader
{

namespace utilities
{

int
displayOptions
(
 int    optionsCategory,
 void * optionsStruct_p
)
{
    const
    string   nameFunction = "displayOptions",
             nF           = nameFunction + " : ";


    cout << nF << "Enter" << endl;

    switch (optionsCategory)
    {
        case 1 :
        {
            // General options

            break;
        }
        case 2 :
        {
            // Network options

            const
            struct
            jsonConfigReader::optionsNetwork::OptionsStruct * optionsStruct_local_p = NULL;


            optionsStruct_local_p = static_cast<const struct jsonConfigReader::optionsNetwork::OptionsStruct*>(optionsStruct_p);

            cout << nF << "Options category = 2 : Network" << endl;

            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            // cout << nF << "options.xff                    = " << optionsStruct_local_p->xff << endl;
            // cout << nF << "options.geo_verification_proxy = " << optionsStruct_local_p->geo_verification_proxy << endl;
            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            break;
        }
        case 3 :
        {
            // Geo-restriction options

            const
            struct
            jsonConfigReader::optionsGeoRestriction::OptionsStruct * optionsStruct_local_p = NULL;


            optionsStruct_local_p = static_cast<const struct jsonConfigReader::optionsGeoRestriction::OptionsStruct*>(optionsStruct_p);

            cout << nF << "Options category = 3 : Geo-restriction" << endl;

            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << nF << "options.xff                    = " << optionsStruct_local_p->xff << endl;
            cout << nF << "options.geo_verification_proxy = " << optionsStruct_local_p->geo_verification_proxy << endl;
            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            break;
        }
        case 4 :
        {
            // Video selection options

            break;
        }
        case 5 :
        {
            // Download options

            break;
        }
        case 6 :
        {
            // Filesystem options

            break;
        }
        case 7 :
        {
            // Thumbnail options

            break;
        }
        case 8 :
        {
            // Internet Shortcut options

            break;
        }
        case 9 :
        {
            // Verbosity and Simulation options

            break;
        }
        case 10 :
        {
            // Workarounds options

            break;
        }
        case 11 :
        {
            // Video format options

            break;
        }
        case 12 :
        {
            // Subtitle options

            break;
        }
        case 13 :
        {
            // Authentication options

            break;
        }
        case 14 :
        {
            // Post-processing options

            break;
        }
        case 15 :
        {
            // SponsorBlock options

            break;
        }
        case 16 :
        {
            // Extractor options

            break;
        }
        default :
        {
            cout << nF << "Unknown options category specified." << endl;
        }
    }

    cout << nF << "Exit" << endl;

    return 0;
}

/*
boost::json::value
parse_file
(
 char
 const * 
 filename
)
{
    file   f(filename, "r");

    json::stream_parser p;
    
    json::error_code ec;
    
    
    do
    {
        char buf[4096];
        auto const nread = f.read(buf, sizeof(buf));
        p.write(buf, nread, ec);
    } while (!f.eof());
    if (ec)
        return nullptr;
    p.finish(ec);
    if (ec)
        return nullptr;
    return p.release();
}
 */


boost::json::value
parseFile
(
 char
 const * filename
)
{
    int                          status = -1;

    const
    string                       nameFunction = "parseFile",
                                 nF           = nameFunction + " : ";

    ifstream                     inputFile(filename);

    stringstream                 inputBuffer;

    string                       textLine,
                                 inputFile_buffer;

    boost::json::stream_parser   p;

    boost::json::value           jv;

    boost::json::error_code      ec;


    cout << nF << "Enter" << endl;

    // Read the next line from the file into the string named textLine.

    while
    (
     getline(inputFile, textLine)
    )
    {
        // Copy the contents of the string into the buffer.

        inputBuffer << textLine << endl;

        cout << "String length = " << textLine.length() << endl;
        cout << "----------" << endl;
        cout << textLine << endl;
        cout << "----------" << endl;
    }

    inputFile.close();

    inputFile_buffer = inputBuffer.str();

    cout << "==========" << endl;
    cout << inputFile_buffer;
    cout << "==========" << endl;

    p.write(inputFile_buffer.c_str(), inputFile_buffer.length(), ec);

    if (ec)
    {
        status = -2;

        goto return_failure_routine;
    }

    p.finish(ec);
    
    if (ec)
    {
        status = -3;

        goto return_failure_routine;
    }

    // jv = p.release();

    // cout << nF << "About to invoke the function : processJsonModel" << endl;

    // processJsonModel(jv);

    goto return_routine;


    return_failure_routine :
    {
        if (ec)
        {
            cout << nF << "About to exit this function with a Parser Error code = " << ec << endl;
            cout << nF << "Error status = " << status << endl;

            // return nullptr;
        }
        else
        {
            cout << nF << "About to exit this function with a generic failure. Error status = " << status << endl;
        }

        cout << nF << "Exit (with failure)" << endl;

        return status;
    }

    return_routine :
    {
        cout << nF << "Exit (with success)" << endl;

        return p.release();
    }

}  // End of function : parseFile


int
processJsonNode
(
 boost::json::value   jsonNode
)
{
    string               nameFunction  = "processJsonNode",
                         nF            = nameFunction + " : ";

    int                  returnCode    = -1;

    int                  counter_inner = 0,
                         counter_outer = 0;

    boost::json::value   jv_new;


    cout << nF << "Enter" << endl;

    switch (jsonNode.kind())
    {
        case boost::json::kind::object :
        {
            processJsonObject(jsonNode);
            break;
        }
        case boost::json::kind::array :
        {
            cout << "json::kind::array" << endl;
            break;
        }
        case boost::json::kind::string :
        {
            cout << "json::kind::string" << endl;
            break;
        }
        case boost::json::kind::uint64 :
        {
            cout << "json::kind::uint64" << endl;
            break;
        }
        case boost::json::kind::int64 :
        {
            cout << "json::kind::int64" << endl;
            break;
        }
        case boost::json::kind::double_ :
        {
            cout << "json::kind::double_" << endl;
            break;
        }
        case boost::json::kind::bool_ :
        {
            cout << "json::kind::bool_" << endl;
            break;
        }
        case boost::json::kind::null :
        {
            cout << "json::kind::null" << endl;
            break;
        }
        default :
        {
            cout << nF << "Unknown JSON datatype" << endl;
        }
    }

    returnCode = 0;

    goto return_routine;


return_failure_routine :


return_routine :

    return returnCode;

}  // End of function : processJsonNode


int
processJsonObject
(
 boost::json::value   jsonNode
)
{
    int                                   returnCode = -1;

    const
    string                                nameFunction = "processJsonObject",
                                          nF = nameFunction + " : ";

    // auto
    // const                               & obj = jsonNode.get_object();

    const
    boost::json::object                 & obj = jsonNode.get_object();

    string                                indent = "    ";

    boost::json::object::const_iterator   iter;

    // auto     iter = obj.begin

    int                                   counter = 0;


    cout << nF << "Enter" << endl;

    cout << nF << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << nF << "Type of JSON element : json::kind::object" << endl;
    cout << nF << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << nF << boost::json::serialize(obj) << endl;
    cout << nF << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << nF << "Number of elements in object = " << obj.size() << endl;
    cout << nF << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

    // Iterate over all the values that comprise the current JSON object.
    
    for
    (
     iter  = obj.begin();
     iter != obj.end();
     ++iter
    )
    {
        auto
        const & obj_optionsGeoRestriction = obj.at("OptionsGeoRestriction");

        boost::json::value   obj_local;

        obj_local = iter->value();


        cout << nF << "Element       = " << boost::json::serialize(obj_optionsGeoRestriction) << endl;
        cout << nF << "Element value = " << boost::json::serialize(iter->value()) << endl;

        cout << nF << "Counter = " << ++counter << endl;
        cout << nF << "Element name  = " << iter->key() << endl;
        cout << nF << "Element value = " << boost::json::serialize(iter->value()) << endl;
        cout << nF << "----------------------------------------" << endl;

        // Bear in mind that the current JSON object may be comprised of
        // multiple elements, such as is shown in the following example
        // which contains two top-level elements, OptionsNetwork and
        // OptionsGeoRestriction.
        //
        // {
        //   "OptionsNetwork" :
        //   {
        //     "proxy"          : "http:///www.proxy.com:800",
        //     "socket_timeout" : "200"
        //   },
        //   "OptionsGeoRestriction" :
        //   {
        //     "geo_verification_proxy" : "http:///www.proxy.com:800",
        //     "xff" : "Poop"
        //   }
        // }

        // How many elements in the current object?

        // How can the type of the JSON object be determined?

        // Option set : 1

        if (iter->key() == "OptionsGeneral")
        {
            cout << nF << "Object contains a key : OptionsGeneral" << endl;

            // jsonConfigReader::processObjectOptions::processOptionsGeneral();

            continue;
        }

        // Option set : 2

        if (iter->key() == "OptionsNetwork")
        {
            cout << nF << "Object contains a key : OptionsNetwork" << endl;

            // jsonConfigReader::options::OptionsNetwork   options;

            // jsonConfigReader::processObjectOptions::processOptionsNetwork();

            continue;
        }

        // Option set : 3

        if (iter->key() == "OptionsGeoRestriction")
        {
            jsonConfigReader::optionsGeoRestriction::OptionsStruct   options;


            options = processValue_optionsGeoRestriction(iter->value());

            displayOptions
            (
             3,
             & options
            );

            continue;
        }

        // Option set : 4

        if (iter->key() == "OptionsVideoSelection")
        {
            cout << nF << "Object contains a key : OptionsVideoSelection" << endl;

            // jsonConfigReader::processObjectOptions::processOptionsVideoSelection();

            continue;
        }

        // Option set : 5

        if (iter->key() == "OptionsDownload")
        {
            cout << nF << "Object contains a key : OptionsDownload" << endl;

            continue;
        }

        // Option set : 6

        if (iter->key() == "OptionsFilesystem")
        {
            cout << nF << "Object contains a key : OptionsFilesystem" << endl;

            continue;
        }

        // Option set : 7

        if (iter->key() == "OptionsThumbnail")
        {
            cout << nF << "Object contains a key : OptionsThumbnail" << endl;

            continue;
        }

        // Option set : 8

        if (iter->key() == "OptionsInternetShortcut")
        {
            cout << nF << "Object contains a key : OptionsInternetShortcut" << endl;

            continue;
        }

        // Option set : 9

        if (iter->key() == "OptionsVerbosityAndSimulation")
        {
            continue;
        }

        // Option set : 10

        if (iter->key() == "OptionsWorkarounds")
        {
            continue;
        }

        // Option set : 11

        if (iter->key() == "OptionsVideoFormat")
        {
            continue;
        }

        // Option set : 12

        if (iter->key() == "OptionsSubtitle")
        {
            continue;
        }

        // Option set : 13

        if (iter->key() == "OptionsAuthentication")
        {
            continue;
        }

        // Option set : 14

        if (iter->key() == "OptionsPostProcessing")
        {
            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << nF << "Object contains a key : OptionsPostProcessing" << endl;
            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            jsonConfigReader::optionsPostProcessing::OptionsStruct   options;


            /*
            options = jsonConfigReader::processObjectOptions::processOptionsPostProcessing
                      (
                       obj
                      );
             */

            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            continue;
        }

        // Option set : 15

        if (iter->key() == "OptionsSponsorBlock")
        {
            continue;
        }

        // Option set : 16

        if (iter->key() == "OptionsExtractor")
        {
            continue;
        }

        // We know we are dealing with a JSON object type. Despite this,
        // the JSON object type that we are dealing with, is unknown. It
        // could very well be a compound JSON object type.

        processJsonNode(obj_local);

    }  // End of for loop that iterates over each value in the current
       // JSON object.

    cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << nF << "Have exited the for loop" << endl;
    cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    /*
    counter_outer++;

    cout << "Counter outer = " << counter_outer << endl;

    if (!obj.empty())
    {
        auto it = obj.begin();


        // Variable it is of type boost::json::key_value_pair

        counter_inner++;

        cout << "Counter inner = " << counter_inner << endl;

        cout << "json::kind::object" << endl;

        for (;;)
        {
            cout << "For loop contents :" << endl;
            cout << "-------------------" << endl;

            cout << indent << boost::json::serialize(it->key()) << " : ";
            cout << boost::json::serialize(it->value()) << endl;

            ++it;

            if (it == obj.end())
            {
                break;
            }
        }
    }

     */

    returnCode = 0;

    goto return_routine;


return_failure_routine :


return_routine :

    cout << nF << "Exit" << endl;

    return returnCode;
}


jsonConfigReader::optionsGeoRestriction::OptionsStruct
processValue_optionsGeoRestriction
(
 const
 boost::json::value   jsonNode
)
{
    const
    string   nameFunction     = "processValue_optionsGeoRestriction",
             nF               = nameFunction + " : ";

    int      returnCode       = -1;

    const
    boost::json::object & obj = jsonNode.as_object();

    jsonConfigReader::optionsGeoRestriction::OptionsStruct   options;

    stringstream                value;


    cout << nF << "Enter" << endl;

    cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << nF << "JSON value is of type : OptionsGeoRestriction" << endl;
    cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    // Create a new object called options.
    // 
    // This object will be of type struct optionsGeoRestriction::OptionsStruct
    // 
    // The process of doing this will invoke the function tag_invoke, which will
    // in turn invoke the function extract.
    //
    //   - jsonConfigReader::optionsOptionsGeoRestriction::tag_invoke
    // 
    //       - jsonConfigReader::optionsGeoRestriction::extract
    //
    // From what I can gather, the tag_invoke function should reside in the same
    // namespace that the struct is defined in.
    // 
    // How does the tag_invoke function know which extract function to use? The
    // version of it which resides within the same namespace? 
    // 
    // -------------------------------------------------------------------------
    // What if we had the following?
    //
    //   class
    //   optionsOptionsGeoRestriction
    //   {
    //     private :
    // 
    //       // Elements from the struct  
    // 
    //     public :
    //   
    //       tag_invoke();  // Or should this be a free floating function?
    // 
    //       extract();
    //   };

    // - Create an object.
    // - Populate it with values from the JSON node.

    // Convert the variable jsonNode into a JSON object.

    // Maybe write these into stringstreams first.

    value.clear();
    value << obj.at("geo_verification_proxy");
    options.geo_verification_proxy = value.str();

    value.clear();
    value << obj.at("xff");
    options.xff = value.str();

    cout << nF << "++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << nF << "obj = " << boost::json::serialize(obj) << endl;
    cout << nF << "++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << nF << "geo_verification_proxy = " << options.geo_verification_proxy << endl;
    cout << nF << "xff                    = " << options.xff << endl;
    cout << nF << "++++++++++++++++++++++++++++++++++++++++" << endl;

    /*
    jsonConfigReader::optionsGeoRestriction::OptionsStruct
    options
    (
     boost::json::value_to<jsonConfigReader::optionsGeoRestriction::OptionsStruct>
     (
      jsonNode
     )
    );
     */

    returnCode = 0;

    goto return_routine;


return_failure_routine :


return_routine :

    cout << nF << "Exit" << endl;

    return options;
}


}  // End of namespace : utilities

}  // End of namespace : jsonConfigReader
