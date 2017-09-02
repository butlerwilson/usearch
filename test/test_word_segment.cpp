#include <string>
#include <vector>
#include <iostream>

#include "read_documents.h"
#include "word_segment.h"

int main()
{
    Documents *document = new Documents("/Users/youngcy/Works/cpplang/usearch/data/documents");
    WordSegment segment = WordSegment();

    while (document->has_next()) {
         std::pair<std::string, std::string> *item = 
             document->next_document();

         if (item == NULL) {
             std::cout << "read file failed. continue" << std::endl;
         } else {
             std::string content = item->second;
             std::vector<std::string> words = segment.words_segment(content);

            for (std::vector<std::string>::iterator it = words.begin();
                it != words.end(); ++it) {
                std::cout << *it << std::endl;    
            }
            break;
         }
     }

     return 0;
}
