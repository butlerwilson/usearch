#ifndef _WORD_SEGMENT_H_
#define _WORD_SEGMENT_H_

#include <regex>
#include <fstream>
#include <string>
#include <map>
#include <regex>

#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include "cppjieba/Jieba.hpp"
#include "util.h"


class WordSegment {
public:
    WordSegment() {
        jieba_ = std::make_shared<cppjieba::Jieba>(
                    default_dict_file_,
                    hmm_dict_file_,
                    user_defined_dict_file_,
                    idf_dict_file_,
                    user_stop_words_file);
    }
    ~WordSegment() {}

    void set_default_dict_file(const std::string &default_dict_file) {
        default_dict_file_ = default_dict_file;
    }

    void set_hmm_dict_file(const std::string &hmm_dict_file) {
        hmm_dict_file_ = hmm_path;
    }

    void set_idf_dict_file(const std::string &idf_dict_file) {
        idf_dict_file_ = idf_dict_file;
    }

    void set_user_defined_dict_file(const std::string &user_defined_dict_file) {
        user_defined_dict_file = user_defined_dict_file;
    }

    void set_user_stop_words_file(const std::string &user_stop_words_file) {
        user_stop_words_file_ = user_stop_words_file;
    }

    size_t insert_user_words(const std::string &input_filename);

    std::vector<std::string> words_segment(const std::string &paragraph);
    std::map<std::string, int> words_segment_with_frequent(const std::string &paragraph);
    std::vector<std::pair<std::string, size_t>> words_segment_with_position(const std::string &paragraph);
    std::vector<std::pair<std::string, size_t>> words_segment_with_weight(const std::string &paragraph, size_t topK = 10);
private:
    //const char* DICT_PATH = "data/dict/cppjieba/jieba.dict.utf8";
    const char* default_dict_file_ = "data/dict/cppjieba/big.dict.utf8";
    const char* hmm_dict_file_ = "data/dict/cppjieba/hmm_model.utf8";
    const char* idf_dict_file_ = "data/dict/cppjieba/idf.utf8";
    
    const char* user_defined_dict_file_ = "data/dict/review/user.dict.utf8";
    const char* user_stop_words_file_ = "data/dict/review/stop_words.utf8";

    std::shared_ptr<cppjieba::Jieba> jieba_;
};


#endif
