#ifndef SERIAL_H
#define SERIAL_H

#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#define SERIAL_ACCESS friend class boost::serialization::access

namespace serial {
    template <typename T>
    T load(const char *filename) {
        std::ifstream ifs(filename);
        boost::archive::text_iarchive iarc(ifs);
        T object;
        iarc >> object;

        return object;
    }

    template <typename T>
    void dump(T &object, const char *filename) {
        std::ofstream ofs(filename);
        boost::archive::text_oarchive oarc(ofs);

        oarc << object;
    }
}

#endif // SERIAL_H
