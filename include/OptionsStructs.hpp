#ifndef OPTION_STRUCTS_HPP
#define OPTION_STRUCTS_HPP


#include <string>


using std::string;


namespace
configReader
{
    // Option set : 1
    // 
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


    // Option set : 2
    // 
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


    // Option set : 3
    // 
    // Options relating to the category : Geo-restriction
    
    struct
    OptionsGeoRestriction
    {
        string   geo_verification_proxy;
        string   xff;
    };


    // Option set : 4
    // 
    // Options relating to the category : Video selection

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

    // Option set : 5

    struct
    OptionsDownload
    {

    };

    // Option set : 6

    struct
    OptionsFilesystem
    {

    };

    // Option set : 7

    struct
    OptionsThumbnail
    {

    };

    // Option set : 8

    struct
    OptionsInternetShortcut
    {

    };

    // Option set : 9

    struct
    OptionsVerbosityAndSimulation
    {

    };

    // Option set : 10

    struct
    OptionsWorkarounds
    {

    };

    // Option set : 11

    struct
    OptionsVideoFormat
    {

    };

    // Option set : 12

    struct
    OptionsSubtitle
    {

    };

    // Option set : 13

    struct
    OptionsAuthentication
    {

    };

    // Option set : 14
    // 
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

    // Option set : 15

    struct
    OptionsSponsorBlock
    {

    };

    // Option set : 16

    struct
    OptionsExtractor
    {

    };

}  // End of namespace : configReader


#endif
