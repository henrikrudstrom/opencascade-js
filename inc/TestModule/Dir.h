// Class Dir
#ifndef DIR_H
#define DIR_H

#include <common/DynamicCastMap.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <nan.h>

#include <gp_Dir.hxx>

#include <TestModule/Ax1.h>
#include <TestModule/Ax2.h>
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
    static NAN_METHOD(__cptr__);
    static bool firstCall;

    static bool NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool NewOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool NewOverload3(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(New);
    static bool xOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(x);
    static bool yOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(y);
    static bool zOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(z);
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
    static bool crossedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(crossed);
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
    static bool setXOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setX);
    static bool setYOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setY);
    static bool setZOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setZ);
};
}

template <>
struct wrapper_for_type<gp_Dir> {
    typedef TestModule::Dir type;
};
template <>
struct wrapped_type<TestModule::Dir> {
    typedef gp_Dir type;
    constexpr static const char* name = "Dir";
};

#endif  // DIR_H