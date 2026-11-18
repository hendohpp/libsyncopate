#ifndef SYNCOPATE_MODELS_PLAYLIST_HPP_
#define SYNCOPATE_MODELS_PLAYLIST_HPP_

#include "syncopate/models/track.hpp"

#include <string>
#include <vector>

namespace syncopate::models {

struct Playlist {
    std::string name_;
    std::string desc_;
    std::string imgUrl_;
    std::vector<syncopate::models::Track> trackList_;
};

} // namespace syncopate::models

#endif // SYNCOPATE_MODELS_PLAYLIST_HPP_