#include <TestModule/Line.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Line::constructor;
Nan::Persistent<v8::Object> TestModule::Line::prototype;

TestModule::Line::Line() {}
TestModule::Line::Line(Geom_Line* wrapObj) : Curve(wrapObj) {}
TestModule::Line::Line(opencascade::handle<Geom_Line> wrapObj) : Curve(wrapObj) {}

v8::Local<v8::Object> TestModule::Line::BuildWrapper(void* res) {
    Nan::EscapableHandleScope scope;
    v8::TryCatch errorHandler;

    v8::Local<v8::Function> func = Nan::GetFunction(Nan::New(constructor)).ToLocalChecked();
    v8::Local<v8::Value> args[1];
    args[0] = Nan::New<v8::External>(res);
    v8::MaybeLocal<v8::Object> maybeVal = Nan::NewInstance(func, 1, args);

    return scope.Escape(maybeVal.ToLocalChecked());
}

NAN_METHOD(TestModule::Line::__cptr__) {
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Line>(info.Holder());
    int addr = reinterpret_cast<std::uintptr_t>(&wrapped->wrappedObject);
    info.GetReturnValue().Set(Nan::New<v8::Int32>(addr));
}

bool TestModule::Line::makeLineOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argA1)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        GC_MakeLine builder(argA1);
        info.GetReturnValue().Set(TestModule::Line::BuildWrapper((void*)&builder.Value()));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Line::makeLineOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }
    gp_Dir argV;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[1], argV)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        GC_MakeLine builder(argP, argV);
        info.GetReturnValue().Set(TestModule::Line::BuildWrapper((void*)&builder.Value()));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Line::makeLineOverload4(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Pnt argP1;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP1)) {
        return false;
    }
    gp_Pnt argP2;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[1], argP2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        GC_MakeLine builder(argP1, argP2);
        info.GetReturnValue().Set(TestModule::Line::BuildWrapper((void*)&builder.Value()));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Line::makeLine) {
    if (TestModule::Line::makeLineOverload0(info)) {
        return;
    }
    if (TestModule::Line::makeLineOverload2(info)) {
        return;
    }
    if (TestModule::Line::makeLineOverload4(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Line::firstCall = true;
bool TestModule::Line::NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argA1)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::Line(new Geom_Line(argA1));
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Line::NewOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }
    gp_Dir argV;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[1], argV)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::Line(new Geom_Line(argP, argV));
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
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
    if (info.Length() == 1 && info[0]->IsExternal()) {
        auto ext = info[0].As<v8::External>()->Value();
        auto wrapper = new Line(*static_cast<opencascade::handle<Geom_Line>*>(ext));
        wrapper->Wrap(info.This());
        return;
    }

    if (TestModule::Line::NewOverload0(info)) {
        return;
    }
    if (TestModule::Line::NewOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Line::positionOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Line>(info.Holder());
    auto obj = opencascade::handle<Geom_Line>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj->Position();
        info.GetReturnValue().Set(TestModule::Ax1::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_GETTER(TestModule::Line::position) {
    if (TestModule::Line::positionOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Line::setPositionOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info.Data(), argA1)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Line>(info.Holder());
    auto obj = opencascade::handle<Geom_Line>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj->SetPosition(argA1);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_SETTER(TestModule::Line::setPosition) {
    if (TestModule::Line::setPositionOverload0(info)) {
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

    Nan::SetPrototypeMethod(ctor, "__cptr__", __cptr__);
    Nan::SetMethod(ctor, "makeLine", makeLine);
    Nan::SetAccessor(ctorInst, Nan::New("position").ToLocalChecked(), position, setPosition);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("Geom_Line", &BuildWrapper);
}