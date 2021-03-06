// Class Pnt
#ifndef PNT_H
#define PNT_H

#include <common/DynamicCastMap.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <nan.h>

#include <gp_Pnt.hxx>

#include <TestModule/Ax1.h>
#include <TestModule/Ax2.h>
#include <TestModule/Vec.h>

namespace TestModule {
class Pnt : public Nan::ObjectWrap {
   public:
    static NAN_MODULE_INIT(Init);
    static Nan::Persistent<v8::Object> prototype;
    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static v8::Local<v8::Object> BuildWrapper(void* res);
    gp_Pnt wrappedObject;
    Pnt();
    Pnt(gp_Pnt* wrapObj);
    Pnt(gp_Pnt wrapObj);

   protected:
   private:
    static NAN_METHOD(__cptr__);
    static bool firstCall;

    static bool NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool NewOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(New);
    static bool xOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(x);
    static bool yOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(y);
    static bool zOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(z);
    static bool baryCenterOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(baryCenter);
    static bool distanceOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(distance);
    static bool isEqualOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(isEqual);
    static bool mirrorOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirrorOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirrorOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(mirror);
    static bool mirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirroredOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(mirrored);
    static bool rotateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(rotate);
    static bool rotatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(rotated);
    static bool scaleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(scale);
    static bool scaledOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(scaled);
    static bool squareDistanceOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(squareDistance);
    static bool translateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool translateOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(translate);
    static bool translatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool translatedOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(translated);
    static bool setXOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setX);
    static bool setYOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setY);
    static bool setZOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setZ);
};
}

template <>
struct wrapper_for_type<gp_Pnt> {
    typedef TestModule::Pnt type;
};
template <>
struct wrapped_type<TestModule::Pnt> {
    typedef gp_Pnt type;
    constexpr static const char* name = "Pnt";
};

#endif  // PNT_H