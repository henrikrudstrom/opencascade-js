#include <TestModule/Line.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Line::constructor;
Nan::Persistent<v8::Object> TestModule::Line::prototype;

TestModule::Line::Line() {}
TestModule::Line::Line(Geom_Line* wrapObj) : Curve(wrapObj) {}
TestModule::Line::Line(opencascade::handle<Geom_Line> wrapObj) : Curve(wrapObj) {}

v8::Local<v8::Object> TestModule::Line::BuildWrapper(void* res) {
    auto obj = new Line(*static_cast<opencascade::handle<Geom_Line>*>(res));
    v8::Local<v8::Object> val =
        Nan::New(constructor)->GetFunction()->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
    obj->Wrap(val);
    return val;
}

bool TestModule::Line::firstCall = true;
bool TestModule::Line::LineOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argA1)) {
        return false;
    }

    auto wrapper = new TestModule::Line(new Geom_Line(argA1));
    wrapper->Wrap(info.This());
    return true;
}
bool TestModule::Line::LineOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }

    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }
    gp_Dir argV;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[1], argV)) {
        return false;
    }

    auto wrapper = new TestModule::Line(new Geom_Line(argP, argV));
    wrapper->Wrap(info.This());
    return true;
}

NAN_METHOD(TestModule::Line::New) {
    if (!info.IsConstructCall()) {
        std::vector<v8::Local<v8::Value> > args(info.Length());
        for (std::size_t i = 0; i < args.size(); ++i) args[i] = info[i];
        auto inst = Nan::NewInstance(info.Callee(), args.size(), args.data());
        if (!inst.IsEmpty()) info.GetReturnValue().Set(inst.ToLocalChecked());
        return;
    }
    if (firstCall) {
        auto wrapper = new Line();
        wrapper->Wrap(info.This());
        firstCall = false;
        return;
    }
    if (TestModule::Line::LineOverload0(info)) {
        return;
    }
    if (TestModule::Line::LineOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Line::SetPositionOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info.Data(), argA1)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Line>(info.Holder());
    auto obj = opencascade::handle<Geom_Line>::DownCast(wrapped->wrappedObject);
    obj->SetPosition(argA1);

    return true;
}

NAN_SETTER(TestModule::Line::SetPosition) {
    if (TestModule::Line::SetPositionOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}

NAN_MODULE_INIT(TestModule::Line::Init) {
    auto qualifiedName = Nan::New("TestModule::Line").ToLocalChecked();
    auto className = Nan::New("Line").ToLocalChecked();
    auto ctor = Nan::New<v8::FunctionTemplate>(New);
    auto ctorInst = ctor->InstanceTemplate();  // target for member functions
    ctor->SetClassName(qualifiedName);
    ctorInst->SetInternalFieldCount(1);  // for ObjectWrap, it should set 1
    ctor->Inherit(Nan::New(TestModule::Curve::constructor));

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("Geom_Line", &BuildWrapper);
}