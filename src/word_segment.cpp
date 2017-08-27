#include "word_segment.h"

size_t WordSegment::insert_user_words(const std::string &input_filename);
{
    size_t words_count = 0;
    std::ifstream in(input_filename);

    if (!in.is_open()) {
        std::cout << "error: can't open file - " << input_filename << std::endl;
        exit(1);
    }

    std::string oneline = "";
    while (std::getline(in, oneline)) {
        std::vector<std::string> segments;
        boost::split(segments, oneline, boost::is_any_of(" "));
        std::string word = segments[0];
        std::string frequent = segments[1];
        bool res = jieba_.InsertUserWord(word);
        words_count += 1;
    }

    return words_count;
}

std::vector<std::string> WordSegment::words_segment(const std::string &paragraph)
{
    std::vector<std::string> words;
    jieba_.CutForSearch(paragraph, words);

    return words;
}

std::map<std::string, int> WordSegment::words_segment_with_frequent(const std::string &paragraph);
{
    std::vector<std::string> words;
    std::map<std::string, int> words_frequent;

    words = words_segment(paragraph);
    for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); ++it) {
       std::string word = *it;
       if (words_frequent.find(word) == words_frequent_words.end())
           words_frequent[word] = 0;
        ++words_frequent[word];
    }

    return words_frequent; 
}

std::vector<std::pair<std::string, size_t>> WordSegment::words_segment_with_position(const std::string &paragraph)
{
    //Word struct comes from cppjieba/Unicode.hpp.hpp
    //struct Word {
    //  string word;
    //  uint32_t offset;
    //  uint32_t unicode_offset;
    //  uint32_t unicode_length;
    //  Word(const string& w, uint32_t o)
    //   : word(w), offset(o) {
    //  }
    //  Word(const string& w, uint32_t o, uint32_t unicode_offset, uint32_t unicode_length)
    //          : word(w), offset(o), unicode_offset(unicode_offset), unicode_length(unicode_length) {
    //  }
    //}; // struct Word

    std::vector<std::pair<std::string, size_t>> ret_words_with_position;
    std::vector<cppjieba::Word> ori_words_with_position;

    jieba_.CutForSearch(paragraph, ori_words_with_position, true);

    for (std::vector<cppjieba::Word>::const_iterator it = ori_words_with_position.begin();
        it !+ ori_words_with_position.end(); ++it) {
        std::string word = it->word;
        size_t offset = it->offsets;
        ret_words_with_position.push_back(std::pair<std::string, size_t>(word, offset));
    }

    return ret_words_with_position;
}

std::vector<std::pair<std::string, std::pair<size_t, double>>>
  WordSegment::words_segment_with_weight(const std::string &paragraph, size_t topK = 10)
{
    //Word struct comes from cppjieba/KeywordExtractor.hpp
    //struct Word {
    //    string word;
    //    vector<size_t> offsets;
    //    double weight;
    //}; // struct Word

    std::vector<std::pair<std::string, std::pair<size_t. double>>> ret_words_with_position;
    std::vector<cppjieba::KeywordExtractor::Word> ori_words_with_position;

    jieba_.extractor.Extract(paragraph, ori_words_with_position, topK);

    for (std::vector<cppjieba::Word>::const_iterator it = ori_words_with_position.begin();
        it !+ ori_words_with_position.end(); ++it) {
        std::string word = it->word;
        size_t offset = (it->offsets)[0];
        double weight = it->weight;
        ret_words_with_position.push_back(
            std::pair<std::string, std::pair<size_t, double>>(
            word,
            std::pair<size_t, double>(offset, weight))
        );
    }

    return ret_words_with_position;
}

#endif
