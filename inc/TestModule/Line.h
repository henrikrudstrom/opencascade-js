// Class Line
#ifndef LINE_H
#define LINE_H

#include <nan.h>
#include <common/Util.h>
#include <common/WrapperClassTraits.h>
#include <common/DynamicCastMap.h>

#include <Geom_Line.hxx>

#include <TestModule/Ax1.h>
#include <TestModule/Pnt.h>
#include <TestModule/Dir.h>
#include <TestModule/Curve.h>

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
    static bool firstCall;

    static bool LineOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static bool LineOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static NAN_METHOD(New);
    static bool SetPositionOverload0(const Nan::PropertyCallbackInfo<void>& info);
    static NAN_SETTER(SetPosition);
};
}

template <>
struct wrapper_for_type<Geom_Line> {
    typedef TestModule::Line type;
};
template <>
struct wrapped_type<TestModule::Line> {
    typedef Geom_Line type;
};

#endif  // LINE_H