// Class Curve
#ifndef CURVE_H
#define CURVE_H

#include <common/DynamicCastMap.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <nan.h>

#include <Geom_Curve.hxx>

#include <TestModule/Geometry.h>
#include <TestModule/Pnt.h>
#include <TestModule/Vec.h>

namespace TestModule {
class Curve : public TestModule::Geometry {
   public:
    static NAN_MODULE_INIT(Init);
    static Nan::Persistent<v8::Object> prototype;
    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static v8::Local<v8::Object> BuildWrapper(void* res);

    Curve();
    Curve(Geom_Curve* wrapObj);
    Curve(opencascade::handle<Geom_Curve> wrapObj);

   protected:
   private:
    static NAN_METHOD(__cptr__);
    static bool firstCall;

    static NAN_METHOD(New);
    static bool d0Overload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(d0);
    static bool d1Overload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(d1);
};
}

template <>
struct wrapper_for_type<Geom_Curve> {
    typedef TestModule::Curve type;
};
template <>
struct wrapped_type<TestModule::Curve> {
    typedef Geom_Curve type;
    constexpr static const char* name = "Curve";
};

#endif  // CURVE_H