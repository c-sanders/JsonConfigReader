#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// #include <boost/json/string_view.hpp>
// Type(s) : string_view
#include <boost/json.hpp>
#include <boost/json/object.hpp>
// Type(s) : object
// #include <boost/json/value_to.hpp>
// Function(s) : value_to

// #include <iomanip>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::stringstream;

// namespace json = boost::json;


namespace
configReader
{
    // Options relating to the category : General

    struct
    OptionsGeneral
    {
        // Options 1 - 10

        bool     help;
        bool     version;
        bool     update;
        bool     no_update; 
        string   update_to;

        bool     ignore_errors;
        bool     no_abort_on_error;
        bool     abort_on_error;
        bool     dump_user_agent;
        bool     list_extractors;
        
        // Options 11 - 20

        bool     extractor_descriptions;
        string   use_extractors;
        string   default_search;
        bool     ignore_config;
        bool     no_config_locations;

        string   config_locations;
        bool     flat_playlist;
        bool     no_flat_playlist;
        bool     live_from_start;
        bool     no_live_from_start;

        // Options 21 - 37

        string   wait_for_video;
        bool     no_wait_for_video;
        bool     mark_watched;
        bool     no_mark_watched;
        string   color;

        string   compat_options;
        string   alias;
    };


    // Options relating to the category : Network
    
    struct
    OptionsNetwork
    {
        string   proxy;
        string   socket_timeout;
        string   source_address;
        bool     force_ipv4;
        bool     force_ipv6;
        bool     enable_file_urls;
    };


    // Options relating to the category : Geo-restriction
    
    struct
    OptionsGeoRestriction
    {
        string   geo_verification_proxy;
        string   xff;
    };


    // Options relating to the category : Geo-restriction

    struct
    OptionsVideoSelection
    {
        // Options 1 - 10

        string   playlist_items;
        string   min_filesize;
        string   max_filesize;
        string   date;
        string   date_before;
        string   date_after;
        string   match_filters;
        bool     no_match_filters;
        string   break_match_filters;
        bool     no_break_match_filters;

        // Options 11 - 20

        bool     no_playlist;
        bool     yes_playlist;
        string   age_limit;
        bool     download_archive;
        bool     no_download_archive;
        string   max_downloads;
        bool     break_on_existing;
        bool     break_per_input;
        bool     no_break_per_input;
        string   skip_playlist_after_errors;
    };

    struct
    OptionsDownload
    {

    };

    struct
    OptionsFilesystem
    {

    };

    struct
    OptionsThumbnail
    {

    };

    struct
    OptionsInternetShortcut
    {

    };

    struct
    OptionsVerbosityAndSimulation
    {

    };

    struct
    OptionsWorkarounds
    {

    };

    struct
    OptionsVideoFormat
    {

    };

    struct
    OptionsSubtitle
    {

    };

    struct
    OptionsAuthentication
    {

    };

    // Options relating to the category : Post-processing
    //
    // THIS STRUCT IS NOT COMPLETED!!!

    struct
    OptionsPostProcessing
    {
        // Options : 1 - 10

        string   extract_audio;
        string   audio_format;
        string   audio_quality;
        string   remux_video;
        string   recode_video;
        string   postprocessor_args;
        bool     keep_video;
        bool     no_keep_video;
        bool     post_overwrites;
        bool     no_post;

        // Options : 11 - 20
    };

    struct
    OptionsSponsorBlock
    {

    };

    struct
    OptionsExtractor
    {

    };


    template<class T>
    void
    extract
    (
     boost::json::object const & obj,
     T                         & t,
     boost::json::string_view    key
    )
    {
        t = value_to<T>(obj.at(key));
    }


    OptionsGeneral
    tag_invoke
    (
     boost::json::value_to_tag< OptionsGeneral >,
     boost::json::value const & jv
    )
    {
        OptionsGeneral   options;


        return options;
    }

}  // End of namespace : configReader


boost::json::value
parseFile
(
    char
    const * filename
);


int
processJsonModel
(
    boost::json::value   jv
);


int
main
(
 int    argc,
 char * argv[]
)
{
	const
	string   nameFunction = "main",
		     nF           = nameFunction + " : ";


	cout << nF << "Enter" << endl;

    parseFile(argv[1]);

	cout << nF << "Exit" << endl;
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

    jv = p.release();

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
    int   status        = -1;

    int   counter_inner = 0,
          counter_outer = 0;


    // Maybe make the following code recursive.

    switch (jv.kind())
    {
        case boost::json::kind::object :
        {
            auto
            const & obj = jv.get_object();


            cout << "json::kind::object" << endl;

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
                    cout << /* * indent << */ boost::json::serialize(it->key()) << " : ";
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
