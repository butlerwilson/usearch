#ifndef _READ_DOCUMENTS_HPP_
#define _READ_DOCUMENTS_HPP_ 

#include <string>
#include <vector>

class Documents {
public:
    Documents(std::string document_dir = "./data/document") : _document_dir(document) { }
    size_t size() {
        return _files.size();
    }

private:
    std::string _document_dir;
    std::vector<std::string> _files;
    
    std::vector<std::string> initFiles();
};

#endif
