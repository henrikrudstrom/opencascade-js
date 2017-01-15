// Class Vec
#ifndef VEC_H
#define VEC_H

#include <common/DynamicCastMap.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <nan.h>

#include <gp_Vec.hxx>

#include <TestModule/Ax1.h>
#include <TestModule/Ax2.h>
#include <TestModule/Dir.h>
#include <TestModule/Pnt.h>

namespace TestModule {
class Vec : public Nan::ObjectWrap {
   public:
    static NAN_MODULE_INIT(Init);
    static Nan::Persistent<v8::Object> prototype;
    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static v8::Local<v8::Object> BuildWrapper(void* res);
    gp_Vec wrappedObject;
    Vec();
    Vec(gp_Vec* wrapObj);
    Vec(gp_Vec wrapObj);

   protected:
   private:
    static NAN_METHOD(__cptr__);
    static bool firstCall;

    static bool NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool NewOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool NewOverload3(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool NewOverload4(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(New);
    static bool xOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(x);
    static bool yOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(y);
    static bool zOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(z);
    static bool addOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(add);
    static bool addedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(added);
    static bool angleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(angle);
    static bool angleWithRefOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(angleWithRef);
    static bool crossOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(cross);
    static bool crossCrossOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(crossCross);
    static bool crossCrossedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(crossCrossed);
    static bool crossMagnitudeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(crossMagnitude);
    static bool crossSquareMagnitudeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(crossSquareMagnitude);
    static bool crossedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(crossed);
    static bool divideOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(divide);
    static bool dividedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(divided);
    static bool dotOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(dot);
    static bool dotCrossOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(dotCross);
    static bool isEqualOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(isEqual);
    static bool isNormalOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(isNormal);
    static bool isOppositeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(isOpposite);
    static bool isParallelOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(isParallel);
    static bool magnitudeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(magnitude);
    static bool mirrorOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirrorOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirrorOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(mirror);
    static bool mirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirroredOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(mirrored);
    static bool multipliedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(multiplied);
    static bool multiplyOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(multiply);
    static bool normalizeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(normalize);
    static bool normalizedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(normalized);
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
    static bool setLinearFormOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool setLinearFormOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool setLinearFormOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool setLinearFormOverload3(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool setLinearFormOverload4(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool setLinearFormOverload5(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(setLinearForm);
    static bool squareMagnitudeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(squareMagnitude);
    static bool subtractOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(subtract);
    static bool subtractedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(subtracted);
    static bool setXOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setX);
    static bool setYOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setY);
    static bool setZOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setZ);
};
}

template <>
struct wrapper_for_type<gp_Vec> {
    typedef TestModule::Vec type;
};
template <>
struct wrapped_type<TestModule::Vec> {
    typedef gp_Vec type;
    constexpr static const char* name = "Vec";
};

#endif  // VEC_H