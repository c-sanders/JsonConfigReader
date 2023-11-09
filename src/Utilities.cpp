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
processJsonModel
(
 boost::json::value   jv
)
{
    string               nameFunction  = "processJsonModel",
                         nF            = nameFunction + " : ";

    int                  status        = -1;

    int                  counter_inner = 0,
                         counter_outer = 0;

    boost::json::value   jv_new;


    cout << nF << "Enter" << endl;

    // Maybe make the following code recursive.

    switch (jv.kind())
    {
        case boost::json::kind::object :
        {
            auto
            const  & obj = jv.get_object();

            string   indent = "    ";


            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
            cout << "json::kind::object" << endl;
            cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
            cout << boost::json::serialize(obj) << endl;
            cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

            // How can the type of the JSON object be determined?

            // Option set : 1

            if (obj.contains("OptionsGeneral"))
            {
                cout << nF << "Object contains a key : OptionsGeneral" << endl;

                // jsonConfigReader::processObjectOptions::processOptionsGeneral();
            }
            else

            // Option set : 2
                
            if (obj.contains("OptionsNetwork"))
            {
                cout << nF << "Object contains a key : OptionsNetwork" << endl;

                // jsonConfigReader::options::OptionsNetwork   options;

                // jsonConfigReader::processObjectOptions::processOptionsNetwork();
            }
            else

            // Option set : 3

            if (obj.contains("OptionsGeoRestriction"))
            {
                cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << nF << "Object contains a key : OptionsGeoRestriction" << endl;
                cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

                // jsonConfigReader::processObjectOptions::processOptionsGeoRestriction(obj);

                // Create an empty struct object of type OptionsGeoRestriction.
                // This will be used to hold the values which have been read in
                // from the JSON file.

                jsonConfigReader::optionsGeoRestriction::OptionsStruct   options;

                // jsonConfigReader::options::OptionsUnion   optionsUnion;


                options = jsonConfigReader::processObjectOptions::processOptionsGeoRestriction
                          (
                           obj
                          );

                displayOptions
                (
                 3,
                 & options
                );
            }
            else

            // Option set : 4

            if (obj.contains("OptionsVideoSelection"))
            {
                cout << nF << "Object contains a key : OptionsVideoSelection" << endl;

                // jsonConfigReader::processObjectOptions::processOptionsVideoSelection();
            }
            else

            // Option set : 5

            if (obj.contains("OptionsDownload"))
            {
                cout << nF << "Object contains a key : OptionsDownload" << endl;
            }
            else

            // Option set : 6

            if (obj.contains("OptionsFilesystem"))
            {
                cout << nF << "Object contains a key : OptionsFilesystem" << endl;
            }
            else

            // Option set : 7

            if (obj.contains("OptionsThumbnail"))
            {
                cout << nF << "Object contains a key : OptionsThumbnail" << endl;
            }
            else

            // Option set : 8

            if (obj.contains("OptionsInternetShortcut"))
            {
                cout << nF << "Object contains a key : OptionsInternetShortcut" << endl;
            }
            else

            // Option set : 9

            if (obj.contains("OptionsVerbosityAndSimulation"))
            {
            }
            else

            // Option set : 10

            if (obj.contains("OptionsWorkarounds"))
            {
            }
            else

            // 11

            if (obj.contains("OptionsVideoFormat"))
            {
            }
            else

            // 12

            if (obj.contains("OptionsSubtitle"))
            {
            }
            else

            // 13

            if (obj.contains("OptionsAuthentication"))
            {
            }
            else

            // 14

            if (obj.contains("OptionsPostProcessing"))
            {
                cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << nF << "Object contains a key : OptionsPostProcessing" << endl;
                cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

                jsonConfigReader::optionsPostProcessing::OptionsStruct   options;


                options = jsonConfigReader::processObjectOptions::processOptionsPostProcessing
                          (
                           obj
                          );

                cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << nF << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            }
            else

            // 15

            if (obj.contains("OptionsSponsorBlock"))
            {
            }
            else

            // 16

            if (obj.contains("OptionsExtractor"))
            {
            }
            else
            {
                // Unknown JSON object type.
            }
   
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
    }

    return status;

}  // End of function : processJsonModel

}  // End of namespace : utilities

}  // End of namespace : jsonConfigReader
