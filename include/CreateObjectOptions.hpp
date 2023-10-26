#ifndef CREATEOBJECTOPTIONS_HPP
#define CREATEOBJECTOPTIONS_HPP


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
);

/*
{
    jv = {
      {"geo_verification_proxy", options.geo_verification_proxy},
      {"xff",                    options.xff}
    };
}
 */


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
    );

    void
    processOptionsNetwork
    (
    );

    void
    processOptionsVideoSelection
    (
    );

    void
    processOptionsPostProcessing
    (
    );

    void
    processObjectOptionsSponsorBlock
    (
    );

    void
    processObjectOptionsExtractor
    (
    );

}  // End of namespace : processObjectOptions

}  // End of namespace : jsonConfigReader


#endif