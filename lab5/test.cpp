#include <igloo/igloo.h>
#include <geometry.h>

using namespace igloo;

Context(PointInRectTestSuite){
    // Your specs below

    Spec(CheckPointOutside){
        float x = 100;
        float y = 100;
        float rx = 1;
        float ry = 3;
        float rw = 2;
        float rh = 2;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsFalse());
    }
    Spec(CheckPointOutside1){
        float x = -1;
        float y = 1;
        float rx = 1;
        float ry = 3;
        float rw = 2;
        float rh = 2;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsFalse());
    }
    Spec(CheckPointOutside2){
        float x = -2;
        float y = -2;
        float rx = 1;
        float ry = 3;
        float rw = 2;
        float rh = 2;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsFalse());
    }
    Spec(CheckPointOutside3){
        float x = 400;
        float y = -1;
        float rx = 1;
        float ry = 3;
        float rw = 2;
        float rh = 2;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsFalse());
    }
    Spec(CheckPointOutside4){
        float x = 500;
        float y = 500;
        float rx = 1;
        float ry = 3;
        float rw = 2;
        float rh = 2;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsFalse());
    }
    Spec(CheckPointOutside5){
        float x = 600;
        float y = 600;
        float rx = 1;
        float ry = 3;
        float rw = 2;
        float rh = 2;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsFalse());
    }
    Spec(CheckPointInside){
        float x = 4;
        float y = 4;
        float rx = 2;
        float ry = 7;
        float rw = 5;
        float rh = 5;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsTrue());

    }
    Spec(CheckPointInside2){
        float x = 6;
        float y = 6;
        float rx = 2;
        float ry = 10;
        float rw = 10;
        float rh = 10;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsTrue());

    }
    Spec(CheckPointInside3){
        float x = 5;
        float y = 5;
        float rx = 2;
        float ry = 6;
        float rw = 5;
        float rh = 5;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsTrue());

    }
    Spec(CheckPointInside4){
        float x = 4;
        float y = 4;
        float rx = 2;
        float ry = 5;
        float rw = 5;
        float rh = 5;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsTrue());

    }
    Spec(CheckPointInside5){
        float x = 7;
        float y = 7;
        float rx = 1;
        float ry = 10;
        float rw = 15;
        float rh = 15;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsTrue());

    }
    Spec(CheckPointInside6){
        float x = 100;
        float y = 100;
        float rx = 2;
        float ry = 400;
        float rw = 300;
        float rh = 300;
        Assert::That(pointInRect(x, y, rx, ry, rw, rh), IsTrue());

    }

    // Your specs above
};

int main(int argc, const char** argv){
    return TestRunner::RunAllTests(argc, argv);
}
