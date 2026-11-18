#ifndef SYNCOPATE_MODELS_TRACK_HPP_
#define SYNCOPATE_MODELS_TRACK_HPP_

#include <string>

namespace syncopate::models {

struct Track {
    // core track data
    std::string name_;
    std::string artist_;
    std::string album_;

    // international standard recording code (unique id per recording, not per song)
    std::string isrc_;

    // platform specific identifiers
    std::string spotId_;
    bool existsOnSpot_{false};

    std::string applId_;
    bool existsOnAppl_{false};
};

} // namespace syncopate::models

#endif // SYNCOPATE_MODELS_TRACK_HPP_