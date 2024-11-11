#ifndef PID_HPP
#define PID_HPP

template <typename T> constexpr T sgn(T value) { return value < 0 ? -1 : 1; }

class TBPid {
    public:
        
        TBPid(float kP, float kI, float kD, float windupRange = 0, bool signFlipReset = false);

        
        float update(float error);

        
        void reset();

    protected:
        // gains
        const float kP;
        const float kI;
        const float kD;

        // optimizations
        const float windupRange;
        const bool signFlipReset;

        float integral = 0;
        float prevError = 0;
};

#endif