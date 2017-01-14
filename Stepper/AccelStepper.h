
#ifndef AccelStepper_h
#define AccelStepper_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
 #include "stdlib.h"
 #include "wiring.h"
#endif


// These defs cause trouble on some versions of Arduino
#undef round


class AccelStepper
{
public:

    AccelStepper(uint8_t pins = 4, uint8_t pin1 = 2, uint8_t pin2 = 3, uint8_t pin3 = 4, uint8_t pin4 = 5);

    AccelStepper(void (*forward)(), void (*backward)());
    
    void    moveTo(long absolute); 

    void    move(long relative);

    boolean run();

    boolean runSpeed();
 
    void    setMaxSpeed(float speed);

    void    setAcceleration(float acceleration);
    
    void    setSpeed(float speed);

    float   speed();

    long    distanceToGo();

    long    targetPosition();

    long    currentPosition();  

    void    setCurrentPosition(long position);  
    
    void    runToPosition();

    boolean runSpeedToPosition();

    void    runToNewPosition(long position);

    void    disableOutputs();

    void    enableOutputs();

protected:

    void           computeNewSpeed();

    virtual void   step(uint8_t step);

    virtual void   step0(void);

    virtual void   step1(uint8_t step);

    virtual void   step2(uint8_t step);

    virtual void   step4(uint8_t step);

    virtual float  desiredSpeed();
    
private:

    uint8_t        _pins;          // 2 or 4

    uint8_t        _pin1, _pin2, _pin3, _pin4;

    long           _currentPos;    // Steps

    long           _targetPos;     // Steps

    float          _speed;         // Steps per second
 

    float          _acceleration;

    unsigned long  _stepInterval;

    unsigned long  _lastStepTime;

    void (*_forward)();

    void (*_backward)();
};

#endif 
