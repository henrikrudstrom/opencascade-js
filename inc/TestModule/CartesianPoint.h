// Class CartesianPoint
#ifndef CARTESIANPOINT_H
#define CARTESIANPOINT_H

#include <common/DynamicCastMap.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <nan.h>

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
    static NAN_METHOD(__cptr__);
    static bool firstCall;

    static bool NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool NewOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(New);
    static bool xOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(x);
    static bool yOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(y);
    static bool zOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(z);
    static bool setXOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setX);
    static bool setYOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setY);
    static bool setZOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setZ);
};
}

template <>
struct wrapper_for_type<Geom_CartesianPoint> {
    typedef TestModule::CartesianPoint type;
};
template <>
struct wrapped_type<TestModule::CartesianPoint> {
    typedef Geom_CartesianPoint type;
    constexpr static const char* name = "CartesianPoint";
};

#endif  // CARTESIANPOINT_H