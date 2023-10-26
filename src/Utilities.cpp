#include <Utilities.hpp>


namespace jsonConfigReader
{

namespace utilities
{

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

    jv = p.release();

    cout << nF << "About to invoke the function : processJsonModel" << endl;

    processJsonModel(jv);

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

        cout << nF << "Exit" << endl;

        return status;
    }

    return_routine :
    {
        cout << nF << "Exit" << endl;

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

            // Test if the object contains a key called OptionsGeoRestriction 

            cout << "About to check if the object contains a key : OptionsGeoRestriction" << endl;

            // Option set : 1

            if (obj.contains("OptionsGeneral"))
            {
                jsonConfigReader::processObjectOptions::processOptionsGeneral();
            }
            else

            // Option set : 2
                
            if (obj.contains("OptionsNetwork"))
            {
                jsonConfigReader::processObjectOptions::processOptionsNetwork();
            }
            else

            // Option set : 3

            if (obj.contains("OptionsGeoRestriction"))
            {
                // Object obj will be in the form of a key-value pair, which
                // should have the following format;
                //
                //   "OptionsGeoRestriction" :
                //   {
                //     "geo_verification_proxy" : "http:///www.proxy.com:800",
                //     "xff" : "Poop"
                //   }

                cout << "Object is of type : OptionsGeoRestriction" << endl;

                // Get the value of this key-value pair.

                auto
                const & obj_value = obj.at("OptionsGeoRestriction");

                cout << "!!! obj_value = " << boost::json::serialize(obj_value) << endl;

                // Create an object from the segment of JSON code which is contained
                // within the variable jv.

                jsonConfigReader::options::OptionsGeoRestriction   options
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

                cout << "options.geo_verification_proxy = " << options.geo_verification_proxy << endl;
                cout << "options.xff                    = " << options.xff << endl;
            }
            else

            // Option set : 4

            if (obj.contains("OptionsVideoSelection"))
            {
                jsonConfigReader::processObjectOptions::processOptionsVideoSelection();
            }
            else

            // Option set : 5

            if (obj.contains("OptionsDownload"))
            {

            }
            else

            // Option set : 6

            if (obj.contains("OptionsFilesystem"))
            {
            }
            else

            // Option set : 7

            if (obj.contains("OptionsThumbnail"))
            {
            }
            else

            // Option set : 8

            if (obj.contains("OptionsInternetShortcut"))
            {
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