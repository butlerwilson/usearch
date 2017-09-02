#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "word_segment.h"

std::string default_dict_file = "../data/cppjieba/jieba.dict.utf8";       //small dict
//std::string  default_dict_file = "../data/cppjieba/big.dict.utf8";        //big dict
std::string  hmm_dict_file = "../data/cppjieba/hmm_model.utf8";
std::string  idf_dict_file = "../data/cppjieba/idf.utf8";
std::string  user_defined_dict_file = "../data/cppjieba/user.dict.utf8";
std::string  user_stop_words_file = "../data/cppjieba/stop_words.utf8";


int main()
{
    WordSegment segment = WordSegment(default_dict_file,
                hmm_dict_file,
                idf_dict_file,
                user_defined_dict_file,
                user_stop_words_file);

    std::string content = "分词测试，this is segment test， 这里这里分词";
    std::vector<std::string> words = segment.words_segment(content);

    for (std::vector<std::string>::iterator it = words.begin();
        it != words.end(); ++it) {
        std::cout << *it << std::endl;    
    }

    std::map<std::string, int> words_frequent = segment.words_segment_with_frequent(content);
    for (std::map<std::string, int>::iterator it = words_frequent.begin();
        it != words_frequent.end(); ++it) {
        std::cout << "word: " << it->first << " frequent: " << it->second << std::endl;    
    }

    std::map<std::string, size_t> words_position = 
            segment.words_segment_with_position(content);

    for (std::map<std::string, size_t>::iterator it = words_position.begin();
        it != words_position.end(); ++it) {
        std::cout << "word: " << it->first << " frequent: " << it->second << std::endl;    
    }

     return 0;
}
