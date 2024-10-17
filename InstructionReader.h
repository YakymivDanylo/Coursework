//
// Created by danyl on 17.10.2024.
//

#ifndef COURSEWORK_INSTRUCTIONREADER_H
#define COURSEWORK_INSTRUCTIONREADER_H
#include <iostream>
#include <fstream>
#include "FileReader.h"
using namespace std;
class InstructionReader: public FileReader{
public:
    string readData(const string& filename) const override{
        ifstream file(filename);
        string instructions;
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                instructions += line + "\n";
            }
            file.close();
        } else {
            instructions = "Помилка: Не вдалося відкрити файл інструкцій: " + filename;
        }

        return instructions;
    }
};
#endif //COURSEWORK_INSTRUCTIONREADER_H
