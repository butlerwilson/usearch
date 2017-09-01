#ifndef _READ_DOCUMENTS_H_
#define _READ_DOCUMENTS_H_ 

#include <string>
#include <vector>
#include <fstream>

/*
 Usage: new a Document Object
   while (document.has_next()) {
       document.next_document()
   }
*/


class Documents {
public:
    Documents(std::string document_dir)
        : _document_dir(document_dir), _current_pos(0) {
            _current_pos = init_files() - 1;    
        }

    bool has_next() {
        return _files.size() > 0 ? true : false;
    }

    std::string read_document(std::string filename);
    std::pair<std::string, std::string> *next_document();

private:
    std::string _document_dir;          //document directory
    std::vector<std::string> _files;    //document file name
    int _current_pos;                   //position of next file name
    
    size_t init_files();
};

#endif
