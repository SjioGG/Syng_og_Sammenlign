#include <iostream>
#include <pybind11/embed.h>

namespace py = pybind11;

// Function to initialize the Python interpreter
void init_python() {
    py::initialize_interpreter();
}

// Function to finalize the Python interpreter
void finalize_python() {
    py::finalize_interpreter();
}

// Function to set the highscore using the Python class
void set_highscore(py::object& game, int score) {
    game.attr("set_highscore")(score);
}

// Function to get the highscore using the Python class
int get_highscore(py::object& game) {
    return game.attr("get_highscore")().cast<int>();
}

PYBIND11_MODULE(control_unit, m) {
    m.def("init_python", &init_python);
    m.def("finalize_python", &finalize_python);
    m.def("set_highscore", &set_highscore);
    m.def("get_highscore", &get_highscore);
}
