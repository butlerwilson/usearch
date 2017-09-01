#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <dirent.h>

#include "read_documents.h"

size_t Documents::init_files()
{
    struct dirent *filename = NULL;
    DIR *dir = NULL;
    dir = opendir(_document_dir.c_str());
    if (dir) {
        while ((filename = readdir(dir)) != NULL)  {
            if (strcmp(filename->d_name, ".") == 0 ||
                strcmp(filename->d_name, "..") == 0)
                continue;
            _files.push_back(_document_dir + "/" + filename->d_name);
        }
    }

    return _files.size();
}

std::string Documents::read_document(std::string filename)
{
    std::string content = "";
    std::ifstream in(filename, std::ios::in);

    if (in.is_open()) {
        std::string line = "";
        while (std::getline(in, line)) {
            content += "\n" + line;
        }
    }

    return content;
}

std::pair<std::string, std::string> *Documents::next_document()
{
    std::string content = "";
    std::string filename = _files[_current_pos];

    //maybe queue is more suitable
    --_current_pos;         //update the _current_pos
    _files.pop_back();

    content = read_document(filename);
    if (content.length() == 0) {
        return NULL;    
    } else {
        return new std::pair<std::string, std::string>  (filename, content);
    }
}
