//
// Created by s on 05.01.2022.
//

#ifndef MEMBERSTEMPLATES_TEMPLATES_H
#define MEMBERSTEMPLATES_TEMPLATES_H

struct Data {
   template <typename T> T read() const { return 5; };
};

template <typename T>
class DataReader {
    const T& source_;
public:
    DataReader(const T& data) : source_(data) {};

    template<class R> R read();
};




#endif //MEMBERSTEMPLATES_TEMPLATES_H
