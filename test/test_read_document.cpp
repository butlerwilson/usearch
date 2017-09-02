#include <string>
#include <iostream>

#include "read_documents.h"

int main()
{
    Documents *document = new Documents("/Users/youngcy/Works/cpplang/usearch/data/documents");

    while (document->has_next()) {
         std::pair<std::string, std::string> *item = 
             document->next_document();

         if (item == NULL) {
             std::cout << "read file failed. continue" << std::endl;
         } else {
             std::string content = item->second;

         }
     }

     return 0;
}
