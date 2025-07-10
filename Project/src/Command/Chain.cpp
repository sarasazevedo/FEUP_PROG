#include "Command/Chain.hpp"
#include "Image.hpp"
#include "Scrim.hpp"
#include "ScrimParser.hpp"
#include "Logger.hpp"
#include <sstream>
#include <vector>
#include <algorithm>

namespace prog {
    Chain::Chain(const std::vector<std::string>& scrimFiles) : Command("Chain"), scrimFiles(scrimFiles) { }  // Constructor

    Chain::~Chain() { }  // Destructor

    // Getter para os arquivos de scrim
    const std::vector<std::string>& Chain::getScrimFiles() const {
        return scrimFiles;
    }

    // Função para aplicar todos os arquivos de scrim
    Image *Chain::apply(Image *img) {
        std::vector<std::string> visitedFiles;
        for (const std::string& filename : scrimFiles) {
            img = executeScrimFile(filename, img, visitedFiles);
        }

        return img;
    }

    // Função auxiliar para executar um arquivo de scrim
    Image* Chain::executeScrimFile(const std::string& filename, Image* img, std::vector<std::string>& visitedFiles) {
        // Evitar recursão infinita
        if (std::find(visitedFiles.begin(), visitedFiles.end(), filename) != visitedFiles.end()) {
            return img;
        }

        // Adiciona à lista de visitados
        visitedFiles.push_back(filename);

        ScrimParser parser;
        Scrim* scrim = parser.parseScrim(filename);

        // Processa os comandos
        for (Command* command : scrim->getCommands()) {
            std::string commandName = command->name();
            // Ignora o save, o blank e o open
            if (commandName != "Save" && commandName != "Blank" && commandName != "Open") {
                if (commandName == "Chain") {
                    Chain* chainCmd = (Chain*) command;
                    const std::vector<std::string>& chainFiles = chainCmd->getScrimFiles();
                    for (const std::string& chainFile : chainFiles) {
                        img = executeScrimFile(chainFile, img, visitedFiles);
                    }
                } else {
                    img = command->apply(img);
                }
            }
        }

        // Remove da lista de visitados
        visitedFiles.pop_back();
        delete scrim;
        return img;
    }
}