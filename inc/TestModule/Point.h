// Class Point
#ifndef POINT_H
#define POINT_H

#include <nan.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <common/DynamicCastMap.h>

#include <Geom_Point.hxx>

#include <TestModule/Geometry.h>

namespace TestModule {
class Point : public TestModule::Geometry {
   public:
    static NAN_MODULE_INIT(Init);
    static Nan::Persistent<v8::Object> prototype;
    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static v8::Local<v8::Object> BuildWrapper(void* res);

    Point();
    Point(Geom_Point* wrapObj);
    Point(opencascade::handle<Geom_Point> wrapObj);

   protected:
   private:
    static bool firstCall;

    static NAN_METHOD(New);
    static bool DistanceOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(Distance);
};
}

template <>
struct wrapper_for_type<Geom_Point> {
    typedef TestModule::Point type;
};
template <>
struct wrapped_type<TestModule::Point> {
    typedef Geom_Point type;
};

#endif  // POINT_H