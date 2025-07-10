//
// Created by JBispo on 05/04/2025.
//
#include "ScrimParser.hpp"

#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Logger.hpp"
#include "Command/Invert.hpp"
#include "Command/ToGrayScale.hpp"
#include "Command/Replace.hpp"
#include "Command/Fill.hpp"
#include "Command/H_Mirror.hpp"
#include "Command/V_Mirror.hpp"
#include "Command/Add.hpp"
#include "Command/Move.hpp"
#include "Command/Slide.hpp"
#include "Command/Rotate_left.hpp"
#include "Command/Rotate_right.hpp"
#include "Command/Scaleup.hpp"
#include "Command/Crop.hpp"
#include "Command/Resize.hpp"
#include "Command/Chain.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;

namespace prog {
    ScrimParser::ScrimParser() {
    };

    ScrimParser::~ScrimParser() {
    };


    Scrim *ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }


                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new image pipeline
        return new Scrim(commands);
    }


    Scrim *ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    Command *ScrimParser::parse_command(string command_name, istream &input) {
        if (command_name == "blank") {
            // Read information for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Read information for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        // TODO: implement cases for the new commands
        if (command_name == "invert") {
            return new Invert();
        }

        if (command_name == "to_gray_scale") {
            return new ToGrayScale();
        }

        if (command_name == "replace") {
            Color color, newColor;
            input >> color >> newColor;
            return new Replace(color, newColor);
        }

        if (command_name == "fill") {
            int x, y, w, h;
            Color color;
            input >> x >> y >> w >> h >> color;
            return new Fill(x, y, w, h, color);
        }

        if (command_name == "h_mirror") {
            return new H_Mirror();
        }

        if (command_name == "v_mirror") {
            return new V_Mirror();
        }

        if (command_name == "add") {
            std::string filename;
            int r, g, b, x, y;
            input >> filename >> r >> g >> b >> x >> y;
            return new Add(filename, r, g, b, x, y);
        }

        if (command_name == "move") {
            int x, y;
            input >> x >> y;
            return new Move(x, y);
        }

        if (command_name == "slide") {
            int x, y;
            input >> x >> y;
            return new Slide(x, y);
        }

        if (command_name == "rotate_left"){
            return new Rotate_left();
        }

        if (command_name == "rotate_right"){
            return new Rotate_right();
        }

        if (command_name == "scaleup"){
            int x, y;
            input >> x >> y;
            return new Scaleup(x, y);
        }

        if (command_name == "crop"){
            int x, y, w, h;
            input >> x >> y >> w >> h;
            return new Crop(x, y, w, h);
        }

        if (command_name == "resize"){
            int x, y, w, h;
            input >> x >> y >> w >> h;
            return new Resize(x, y, w, h);
        }

        if (command_name == "chain") {
            std::vector<std::string> files;
            std::string file;
            while (input >> file && file != "end") {
                files.push_back(file);
            }
            return new Chain(files);
        }

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
