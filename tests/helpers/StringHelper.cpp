#include "helpers/StringHelper.h"

#include <gtest/gtest.h>

#include <cstdint>
#include <vector>

// namespace ent = MAP_GEN_LIB_NAMESPACE::Entities;
namespace hlp = MAP_GEN_LIB_NAMESPACE::Helpers;

TEST(StringHelper, SingleFound) {
    std::string haystack = "the quick brown fox jumps over the lazy dog";
    std::string needle = "fox";

    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(haystack, needle), 1) << "One substring found";
}

TEST(StringHelper, NoneFound) {
    std::string haystack =
        "Julius hurried, strolling through the bustling crowds. Brutus hurried behind him trying to keep up. The "
        "people who comprised the crowd were the multitude of beings occupying the bustling city of Rome. From street "
        "vendors to the rich, from city scum to the well off, those who begged to those who were posed sentinels. Just "
        "when he stepped on the first step to the council, his tunic got jerked by some old one. The old person "
        "possessed some mystic wisdom reflected in his wrinkled eyes. Everyone knew him. The seer. He could see beyond "
        "the things life would yet unfold, & unfog the clouded future of people. Julius turned to the old seer. \"The "
        "Ides come for you, look out.\" the seer spoke forth \"They spell doom, they divulge demise! The wretched cold "
        "wings of Pluto’s workers pursue you! The ides loom with misery & misfortune!\" his shrill screech shook the "
        "whole setting. Numerous eyes turned to Julius. The seer’s words echoed in every person, sending chills "
        "throughout. Julius brushed him loosening his iron grip off his tunic. \"The ides loom over my soul? Let them "
        "be. With my own boldness & my friend by my side, no force in Rome or beyond reckons to so much even touch me. "
        "These delusions of divinings I heed to not. My trust is but for the life echoing through my veins & in Brutus "
        "here, ever beside me. \"Giving one sneering look to the senile fool he thought the seer to be, he moved on, "
        "Brutus on his heels. Life returned to its monotonity in the street. Most people, like they ever do, followed "
        "suit, insulting the seer. But some kept silence. For they knew of divinings. They knew the will of their gods "
        "would never rest unfulfilled. The seer’s lips curled into some curved crescent for he knew the terrible force "
        "the future is. He knew of the events to occur on the ides of the month. When trust would be broken. When "
        "blood would blossom from the very tunic of Julius he jerked this morning. The ides would come.";
    std::string needle = "a";

    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(haystack, needle), 0) << "No substrings found";
}

TEST(StringHelper, ManyFound) {
    std::string haystack = "ababab abab";
    std::string needle = "ab";

    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(haystack, needle), 5) << "Five substrings found";
}

TEST(StringHelper, AllFound) {
    std::string haystack = "pppppppppppppppppppppppppppppppp";
    std::string needle = "p";

    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(haystack, needle), haystack.size())
        << haystack.size() << " substrings found";
}

TEST(StringHelper, EmptyNeedle) {
    std::string haystack = "some string";
    std::string needle = "";

    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(haystack, needle), 0) << "No substrings found";
}

TEST(StringHelper, EmptyHaystack) {
    std::string haystack = "";
    std::string needle = "some string";

    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(haystack, needle), 0) << "No substrings found";
}

TEST(StringHelper, PregeneratedTable) {
    std::string haystack = "the quick brown fox jumps over the lazy dog";
    std::string needle = "the";
    std::vector<int_fast64_t> KMPTable = hlp::StringHelper::buildKMPTable(needle);

    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(haystack, needle, KMPTable), 2) << "2 substrings found";
    ASSERT_EQ(hlp::StringHelper::countSubstring<uint8_t>(haystack, needle, KMPTable), 2) << "still 2 substrings found";
}
