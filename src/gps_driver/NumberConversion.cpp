#include <cstdlib>

#include "../../headers/gps_driver/nmeaparse/NumberConversion.h"

using namespace std;

namespace nmea {
    // Note: both parseDouble and parseInt return 0 with "" input.

    double parseDouble(std::string s){
        char* p;
        double d = ::strtod(s.c_str(), &p);

        // Save locale setting
        const std::string oldLocale=std::setlocale(LC_NUMERIC,nullptr);
        // Force '.' as the radix point. If you comment this out,
        // you'll get output similar to the OP's GUI mode sample
        std::setlocale(LC_NUMERIC,"C");

        if (*p != 0){
            std::stringstream ss;
            ss << "NumberConversionError: parseDouble() error in argument \"" << s << "\", '"
                << *p << "' is not a number.";
            throw NumberConversionError(ss.str());
        }

        // Restore locale setting
        std::setlocale(LC_NUMERIC,oldLocale.c_str());

        return d;
    }

    int64_t parseInt(std::string s, int radix){
        char* p;
        int64_t d = ::strtoll(s.c_str(), &p, radix);

        if (*p != 0) {
            std::stringstream ss;
            ss << "NumberConversionError: parseInt() error in argument \"" << s << "\", '"
                << *p << "' is not a number.";
            throw NumberConversionError(ss.str());
        }

        return d;
    }
}