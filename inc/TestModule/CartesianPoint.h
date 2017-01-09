// Class CartesianPoint
#ifndef CARTESIANPOINT_H
#define CARTESIANPOINT_H

#include <nan.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <common/DynamicCastMap.h>

#include <Geom_CartesianPoint.hxx>

#include <TestModule/Pnt.h>
#include <TestModule/Point.h>

namespace TestModule {
class CartesianPoint : public TestModule::Point {
   public:
    static NAN_MODULE_INIT(Init);
    static Nan::Persistent<v8::Object> prototype;
    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static v8::Local<v8::Object> BuildWrapper(void* res);

    CartesianPoint();
    CartesianPoint(Geom_CartesianPoint* wrapObj);
    CartesianPoint(opencascade::handle<Geom_CartesianPoint> wrapObj);

   protected:
   private:
    static bool firstCall;

    static bool CartesianPointOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool CartesianPointOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
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
struct wrapper_for_type<Geom_CartesianPoint> {
    typedef TestModule::CartesianPoint type;
};
template <>
struct wrapped_type<TestModule::CartesianPoint> {
    typedef Geom_CartesianPoint type;
};

#endif  // CARTESIANPOINT_H