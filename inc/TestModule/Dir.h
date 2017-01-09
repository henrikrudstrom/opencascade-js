// Class Dir
#ifndef DIR_H
#define DIR_H

#include <nan.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <common/DynamicCastMap.h>

#include <gp_Dir.hxx>

#include <TestModule/Vec.h>

namespace TestModule {
class Dir : public Nan::ObjectWrap {
   public:
    static NAN_MODULE_INIT(Init);
    static Nan::Persistent<v8::Object> prototype;
    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static v8::Local<v8::Object> BuildWrapper(void* res);
    gp_Dir wrappedObject;
    Dir();
    Dir(gp_Dir* wrapObj);
    Dir(gp_Dir wrapObj);

   protected:
   private:
    static bool firstCall;

    static bool DirOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool DirOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool DirOverload3(const Nan::FunctionCallbackInfo<v8::Value>& info);
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
struct wrapper_for_type<gp_Dir> {
    typedef TestModule::Dir type;
};
template <>
struct wrapped_type<TestModule::Dir> {
    typedef gp_Dir type;
};

#endif  // DIR_H