#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <memory>
#include <string>

class FileManager {
    public:
        FileManager(FILE** f, std::string filename, std::string mode) {
            filePtr = std::shared_ptr<FILE>(fopen(filename.c_str(), mode.c_str()), fclose);
            *f = filePtr.get();
        }

    private:
        std::shared_ptr<FILE> filePtr;

        FileManager(const FileManager&);
        FileManager& operator=(const FileManager&); //
};
