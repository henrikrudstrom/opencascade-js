// Class Line
#ifndef LINE_H
#define LINE_H

#include <common/DynamicCastMap.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <nan.h>

#include <Geom_Line.hxx>

#include <TestModule/Ax1.h>
#include <TestModule/Curve.h>
#include <TestModule/Dir.h>
#include <TestModule/Pnt.h>
#include <GC_MakeLine.hxx>

namespace TestModule {
class Line : public TestModule::Curve {
   public:
    static NAN_MODULE_INIT(Init);
    static Nan::Persistent<v8::Object> prototype;
    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static v8::Local<v8::Object> BuildWrapper(void* res);

    Line();
    Line(Geom_Line* wrapObj);
    Line(opencascade::handle<Geom_Line> wrapObj);

   protected:
   private:
    static NAN_METHOD(__cptr__);
    static bool makeLineOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool makeLineOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool makeLineOverload4(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(makeLine);
    static bool firstCall;

    static bool NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool NewOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(New);
    static bool positionOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info);
    static NAN_GETTER(position);
    static bool setPositionOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(setPosition);
};
}

template <>
struct wrapper_for_type<Geom_Line> {
    typedef TestModule::Line type;
};
template <>
struct wrapped_type<TestModule::Line> {
    typedef Geom_Line type;
    constexpr static const char* name = "Line";
};

#endif  // LINE_H