// Class Vec
#ifndef VEC_H
#define VEC_H

#include <nan.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <common/DynamicCastMap.h>

#include <gp_Vec.hxx>

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
    static bool firstCall;

    static bool VecOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool VecOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool VecOverload3(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool VecOverload4(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(New);
    static bool XOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(X);
    static bool YOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(Y);
    static bool ZOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(Z);
    static bool SetXOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(SetX);
    static bool SetYOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(SetY);
    static bool SetZOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(SetZ);
};
}

template <>
struct wrapper_for_type<gp_Vec> {
    typedef TestModule::Vec type;
};
template <>
struct wrapped_type<TestModule::Vec> {
    typedef gp_Vec type;
};

#endif  // VEC_H