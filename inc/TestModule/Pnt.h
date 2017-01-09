// Class Pnt
#ifndef PNT_H
#define PNT_H

#include <nan.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <common/DynamicCastMap.h>

#include <gp_Pnt.hxx>

#include <TestModule/Ax1.h>
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
    static bool firstCall;

    static bool PntOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool PntOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(New);
    static bool XOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(X);
    static bool YOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(Y);
    static bool ZOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(Z);
    static bool BaryCenterOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(BaryCenter);
    static bool DistanceOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(Distance);
    static bool IsEqualOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(IsEqual);
    static bool MirrorOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool MirrorOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(Mirror);
    static bool MirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool MirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(Mirrored);
    static bool RotateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(Rotate);
    static bool RotatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(Rotated);
    static bool ScaleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(Scale);
    static bool ScaledOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(Scaled);
    static bool SetCoordOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool SetCoordOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(SetCoord);
    static bool SquareDistanceOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(SquareDistance);
    static bool TranslateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool TranslateOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(Translate);
    static bool TranslatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool TranslatedOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(Translated);
    static bool SetXOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(SetX);
    static bool SetYOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(SetY);
    static bool SetZOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(SetZ);
};
}

template <>
struct wrapper_for_type<gp_Pnt> {
    typedef TestModule::Pnt type;
};
template <>
struct wrapped_type<TestModule::Pnt> {
    typedef gp_Pnt type;
};

#endif  // PNT_H