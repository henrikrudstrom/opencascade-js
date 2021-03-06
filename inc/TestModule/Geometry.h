// Class Geometry
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <common/DynamicCastMap.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <nan.h>

#include <Geom_Geometry.hxx>

#include <TestModule/Ax1.h>
#include <TestModule/Ax2.h>
#include <TestModule/Pnt.h>

namespace TestModule {
class Geometry : public Nan::ObjectWrap {
   public:
    static NAN_MODULE_INIT(Init);
    static Nan::Persistent<v8::Object> prototype;
    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static v8::Local<v8::Object> BuildWrapper(void* res);
    opencascade::handle<Geom_Geometry> wrappedObject;
    Geometry();
    Geometry(Geom_Geometry* wrapObj);
    Geometry(opencascade::handle<Geom_Geometry> wrapObj);

   protected:
   private:
    static NAN_METHOD(__cptr__);
    static bool firstCall;

    static NAN_METHOD(New);
    static bool mirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool mirroredOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(mirrored);
};
}

template <>
struct wrapper_for_type<Geom_Geometry> {
    typedef TestModule::Geometry type;
};
template <>
struct wrapped_type<TestModule::Geometry> {
    typedef Geom_Geometry type;
    constexpr static const char* name = "Geometry";
};

#endif  // GEOMETRY_H