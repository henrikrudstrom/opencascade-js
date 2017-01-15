// Class Ax1
#ifndef AX1_H
#define AX1_H

#include <common/DynamicCastMap.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <nan.h>

#include <gp_Ax1.hxx>

#include <TestModule/Ax2.h>
#include <TestModule/Dir.h>
#include <TestModule/Pnt.h>
#include <TestModule/Vec.h>

namespace TestModule {
class Ax1 : public Nan::ObjectWrap {
   public:
    static NAN_MODULE_INIT(Init);
    static Nan::Persistent<v8::Object> prototype;
    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static v8::Local<v8::Object> BuildWrapper(void* res);
    gp_Ax1 wrappedObject;
    Ax1();
    Ax1(gp_Ax1* wrapObj);
    Ax1(gp_Ax1 wrapObj);

   protected:
   private:
    static NAN_METHOD(__cptr__);
    static bool firstCall;

    static bool NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool NewOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(New);
    static bool directionOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(direction);
    static bool locationOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(location);
    static bool angleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(angle);
    static bool isCoaxialOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(isCoaxial);
    static bool isNormalOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(isNormal);
    static bool isOppositeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(isOpposite);
    static bool isParallelOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(isParallel);
    static bool mirrorOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirrorOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirrorOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(mirror);
    static bool mirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirroredOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(mirrored);
    static bool reverseOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(reverse);
    static bool reversedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(reversed);
    static bool rotateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(rotate);
    static bool rotatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(rotated);
    static bool scaleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(scale);
    static bool scaledOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(scaled);
    static bool translateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool translateOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(translate);
    static bool translatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool translatedOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(translated);
    static bool setDirectionOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setDirection);
    static bool setLocationOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setLocation);
};
}

template <>
struct wrapper_for_type<gp_Ax1> {
    typedef TestModule::Ax1 type;
};
template <>
struct wrapped_type<TestModule::Ax1> {
    typedef gp_Ax1 type;
    constexpr static const char* name = "Ax1";
};

#endif  // AX1_H