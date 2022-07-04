#include <igloo/igloo.h>
#include <map_utils.h>

using namespace igloo;

Context(TestNearestNeighbor){
    Spec(MercedDavis){
        int map[4][4] = {
            {  0, 110, 130, 136},
            {110,   0,  64,  75},
            {130,  64,   0,  17},
            {136,  75,  17,   0}
        };

        Assert::That(nearestNeighbor(0, map), Equals(1));
    }

    Spec(DavisBerkeley){
        int map[4][4] = {
            {  0, 110, 130, 136},
            {110,   0,  64,  75},
            {130,  64,   0,  17},
            {136,  75,  17,   0}
        };

        Assert::That(nearestNeighbor(1, map), Equals(2));
    }

    Spec(BerkeleySF){
        int map[4][4] = {
            {  0, 110, 130, 136},
            {110,   0,  64,  75},
            {130,  64,   0,  17},
            {136,  75,  17,   0}
        };

        Assert::That(nearestNeighbor(2, map), Equals(3));
    }

    Spec(SFBerkeley){
        int map[4][4] = {
            {  0, 110, 130, 136},
            {110,   0,  64,  75},
            {130,  64,   0,  17},
            {136,  75,  17,   0}
        };

        Assert::That(nearestNeighbor(3, map), Equals(2));
    }
};

Context(TestNearestUnseenNeighbor){
    Spec(BerkeleySF){
        int map[4][4] = {
            {  0, 110, 130, 136},
            {110,   0,  64,  75},
            {130,  64,   0,  17},
            {136,  75,  17,   0}
        };

        std::vector<int> seen;

        Assert::That(nearestUnseenNeighbor(2, map, seen), Equals(3));
    }

    Spec(BerkeleyDavis){
        int map[4][4] = {
            {  0, 110, 130, 136},
            {110,   0,  64,  75},
            {130,  64,   0,  17},
            {136,  75,  17,   0}
        };

        std::vector<int> seen = {3};

        Assert::That(nearestUnseenNeighbor(2, map, seen), Equals(1));
    }
};

Context(TestItinerary){
    Spec(StartFromMerced){
        std::string campuses[4] = {"UC Merced", "UC Davis", "UC Berkeley", "UC San Francisco"};

        int distances[4][4] = {
            {  0, 110, 130, 136},
            {110,   0,  64,  75},
            {130,  64,   0,  17},
            {136,  75,  17,   0}
        };

        std::vector<std::string> actual = planTrip(0, distances, campuses, 4);
        std::vector<std::string> expected = {"UC Merced", "UC Davis", "UC Berkeley", "UC San Francisco", "UC Merced"};

        Assert::That(actual, Equals(expected));
    }

    Spec(StartFromDavis){
        std::string campuses[4] = {"UC Merced", "UC Davis", "UC Berkeley", "UC San Francisco"};

        int distances[4][4] = {
            {  0, 110, 130, 136},
            {110,   0,  64,  75},
            {130,  64,   0,  17},
            {136,  75,  17,   0}
        };

        std::vector<std::string> actual = planTrip(1, distances, campuses, 4);
        std::vector<std::string> expected = {"UC Davis", "UC Berkeley", "UC San Francisco", "UC Merced", "UC Davis"};

        Assert::That(actual, Equals(expected));
    }

    Spec(StartFromDavisModified){
        std::string campuses[4] = {"UC Merced", "UC Davis", "UC Berkeley", "UC San Francisco"};

        int distances[4][4] = {
            {  0, 110, 130, 136},
            {110,   0,  64,  75},
            {130,  64,   0, 170},
            {136,  75, 170,   0}
        };

        std::vector<std::string> actual = planTrip(1, distances, campuses, 4);
        std::vector<std::string> expected = {"UC Davis", "UC Berkeley", "UC Merced", "UC San Francisco", "UC Davis"};

        Assert::That(actual, Equals(expected));
    }
};

int main(){
    return TestRunner::RunAllTests();
}
