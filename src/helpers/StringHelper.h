#ifndef MAP_GEN_LIB_HELPERS_STRING_H
#define MAP_GEN_LIB_HELPERS_STRING_H

#include <concepts>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace MAP_GEN_LIB_NAMESPACE::Helpers {

class StringHelper {
   public:
    template <std::integral T>
    inline static T countSubstring(const std::string& haystack, const std::string& needle) {
        if (needle.empty() || haystack.empty()) return 0;
        std::vector<int_fast64_t> table = buildKMPTable(needle);
        return StringHelper::countSubstring<T>(haystack, needle, table);
    }

    template <std::integral T>
    inline static T countSubstring(const std::string& haystack, const std::string& needle,
                                   const std::vector<int_fast64_t>& KMPTable) {
        if (needle.empty() || haystack.empty()) return 0;
        T count = 0;
        int_fast64_t posInHaystack = 0;
        int_fast64_t posInNeedle = 0;
        size_t haystackSize = haystack.size();
        size_t needleSize = needle.size();

        while (posInHaystack < haystackSize) {
            if (needle[posInNeedle] == haystack[posInHaystack]) {
                ++posInHaystack;
                ++posInNeedle;
                if (posInNeedle == needleSize) {
                    ++count;
                    posInNeedle = KMPTable[posInNeedle];
                }
            } else {
                posInNeedle = KMPTable[posInNeedle];
                if (posInNeedle < 0) {
                    ++posInHaystack;
                    ++posInNeedle;
                }
            }
        }
        return count;
    }

    inline static std::vector<int_fast64_t> buildKMPTable(const std::string& needle) {
        size_t needleSize = needle.size();
        std::vector<int_fast64_t> result(needleSize + 1);
        result[0] = -1;
        int_fast64_t checkedPosition = 1;
        int_fast64_t candidatePosition = 0;

        while (checkedPosition < needleSize) {
            if (needle[checkedPosition] == needle[candidatePosition]) {
                result[checkedPosition] = result[candidatePosition];
            } else {
                result[checkedPosition] = candidatePosition;
                while (candidatePosition >= 0 && needle[checkedPosition] != needle[candidatePosition]) {
                    candidatePosition = result[candidatePosition];
                }
            }
            ++checkedPosition;
            ++candidatePosition;
        }
        result[checkedPosition] = candidatePosition;
        return result;
    }
};

}  // namespace MAP_GEN_LIB_NAMESPACE::Helpers
#endif  // MAP_GEN_LIB_HELPERS_STRING_H
