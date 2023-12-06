#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "SongScoreCombined.hpp"

namespace py = pybind11;

// Trampoline class for Parse
class PyParse : public Parse {
public:
    using Parse::Parse; // Inherit constructors

    void parseString(const std::string &input) override {
        PYBIND11_OVERRIDE_PURE(
            void,    /* Return type */
            Parse,   /* Parent class */
            parseString, /* Name of function in C++ (must match Python name) */
            input    /* Argument(s) */
        );
    }

    std::string getData(int id) override {
        PYBIND11_OVERRIDE_PURE(
            std::string, /* Return type */
            Parse,       /* Parent class */
            getData,     /* Name of function in C++ (must match Python name) */
            id           /* Argument(s) */
        );
    }
};

PYBIND11_MODULE(py_dbserver, m) {
    py::class_<Parse, PyParse>(m, "Parse")
        .def(py::init<>())
        .def("parse_string", &Parse::parseString)
        .def("get_data", &Parse::getData);

    py::class_<Song, Parse>(m, "Song")
        .def(py::init<int>())
        .def("get_id", &Song::getId)
        .def("get_artist", &Song::getArtist)
        .def("get_title", &Song::getTitle)
        .def("get_duration", &Song::getDuration)
        .def("get_key", &Song::getKey)
        .def("get_instrumental_file", &Song::getInstrumentalFile)
        .def("get_cmp_melody_file", &Song::getCmpMelodyFile)
        .def("get_lyrics_file", &Song::getLyricsFile)
        .def("get_data", &Song::getData)
        .def("parse_string", &Song::parseString);

    py::class_<Score, Parse>(m, "Score")
        .def(py::init<int>(), py::arg("song_id") = -1)
        .def("get_id", &Score::getId)
        .def("get_song_id", &Score::getSongId)
        .def("get_score_value", &Score::getScoreValue)
        .def("get_user", &Score::getUser)
        .def("get_date", &Score::getDate)
        .def("get_data", &Score::getData)
        .def("parse_string", &Score::parseString)
        .def("add_score", &Score::addScore);

    py::class_<ScoreList, Parse>(m, "ScoreList")
        .def(py::init<>())
        .def("parse_string", &ScoreList::parseString)
        .def("get_data", &ScoreList::getData)
        .def("get_scores", &ScoreList::getScores);
}
