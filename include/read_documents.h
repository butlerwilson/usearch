#ifndef _READ_DOCUMENTS_H_
#define _READ_DOCUMENTS_H_ 

#include <string>
#include <vector>
#include <fstream>

class Documents {
public:
    Documents(std::string document_dir = "./data/document") : _document_dir(document) { }
    size_t size() {
        return _files.size();
    }

    std::string read_document(std::string filename);
    std::pair<std::string, std::string> next();

private:
    std::string _document_dir;
    std::vector<std::string> _files;
    
    size_t initFiles();
};

#endif
