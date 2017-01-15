// Class Ax2
#ifndef AX2_H
#define AX2_H

#include <common/DynamicCastMap.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <nan.h>

#include <gp_Ax2.hxx>

#include <TestModule/Ax1.h>
#include <TestModule/Dir.h>
#include <TestModule/Pnt.h>
#include <TestModule/Vec.h>

namespace TestModule {
class Ax2 : public Nan::ObjectWrap {
   public:
    static NAN_MODULE_INIT(Init);
    static Nan::Persistent<v8::Object> prototype;
    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static v8::Local<v8::Object> BuildWrapper(void* res);
    gp_Ax2 wrappedObject;
    Ax2();
    Ax2(gp_Ax2* wrapObj);
    Ax2(gp_Ax2 wrapObj);

   protected:
   private:
    static NAN_METHOD(__cptr__);
    static bool firstCall;

    static bool NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool NewOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool NewOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(New);
    static bool directionOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(direction);
    static bool locationOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(location);
    static bool angleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(angle);
    static bool axisOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(axis);
    static bool isCoplanarOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool isCoplanarOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(isCoplanar);
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
    static bool setAxisOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(setAxis);
    static bool setXDirectionOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(setXDirection);
    static bool setYDirectionOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(setYDirection);
    static bool translateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool translateOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(translate);
    static bool translatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool translatedOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(translated);
    static bool xDirectionOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(xDirection);
    static bool yDirectionOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(yDirection);
    static bool setDirectionOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setDirection);
    static bool setLocationOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setLocation);
};
}

template <>
struct wrapper_for_type<gp_Ax2> {
    typedef TestModule::Ax2 type;
};
template <>
struct wrapped_type<TestModule::Ax2> {
    typedef gp_Ax2 type;
    constexpr static const char* name = "Ax2";
};

#endif  // AX2_H