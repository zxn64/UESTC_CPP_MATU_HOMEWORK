#include "CNumberFactory.h"

class CNumber : public CNumberFactory {
private:
    int val_;
public:
    void Add(int number) {
        val_ += number;
    }

    void Sub(int number) {
        val_ -= number;
    }

    int GetValue() {
        return val_;
    }

    void SetValue(int number) {
        val_ = number;
    }
};

CNumberFactory *CNumberFactory::Create() {
    return new CNumber;
}