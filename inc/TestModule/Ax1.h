// Class Ax1
#ifndef AX1_H
#define AX1_H

#include <nan.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <common/DynamicCastMap.h>

#include <gp_Ax1.hxx>

#include <TestModule/Pnt.h>
#include <TestModule/Dir.h>

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
    static bool firstCall;

    static bool Ax1Overload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool Ax1Overload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(New);
    static bool SetDirectionOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(SetDirection);
    static bool SetLocationOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(SetLocation);
};
}

template <>
struct wrapper_for_type<gp_Ax1> {
    typedef TestModule::Ax1 type;
};
template <>
struct wrapped_type<TestModule::Ax1> {
    typedef gp_Ax1 type;
};

#endif  // AX1_H