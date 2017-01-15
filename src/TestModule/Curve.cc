#include <TestModule/Curve.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Curve::constructor;
Nan::Persistent<v8::Object> TestModule::Curve::prototype;

TestModule::Curve::Curve() {}
TestModule::Curve::Curve(Geom_Curve *wrapObj) : Geometry(wrapObj) {}
TestModule::Curve::Curve(opencascade::handle<Geom_Curve> wrapObj) : Geometry(wrapObj) {}

v8::Local<v8::Object> TestModule::Curve::BuildWrapper(void *res) {
    Nan::EscapableHandleScope scope;
    v8::TryCatch errorHandler;

    v8::Local<v8::Function> func = Nan::GetFunction(Nan::New(constructor)).ToLocalChecked();
    v8::Local<v8::Value> args[1];
    args[0] = Nan::New<v8::External>(res);
    v8::MaybeLocal<v8::Object> maybeVal = Nan::NewInstance(func, 1, args);

    return scope.Escape(maybeVal.ToLocalChecked());
}

NAN_METHOD(TestModule::Curve::__cptr__) {
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Curve>(info.Holder());
    int addr = reinterpret_cast<std::uintptr_t>(&wrapped->wrappedObject);
    info.GetReturnValue().Set(Nan::New<v8::Int32>(addr));
}

bool TestModule::Curve::firstCall = true;

NAN_METHOD(TestModule::Curve::New) {}
bool TestModule::Curve::d0Overload0(const Nan::FunctionCallbackInfo<v8::Value> &info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argU;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argU)) {
        return false;
    }
    gp_Pnt argP;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Curve>(info.Holder());
    auto obj = opencascade::handle<Geom_Curve>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj->D0(argU, argP);
        info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void *)&argP));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Curve::d0) {
    if (TestModule::Curve::d0Overload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Curve::d1Overload0(const Nan::FunctionCallbackInfo<v8::Value> &info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argU;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argU)) {
        return false;
    }
    gp_Pnt argP;

    gp_Vec argV1;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Curve>(info.Holder());
    auto obj = opencascade::handle<Geom_Curve>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj->D1(argU, argP, argV1);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();
        returnValue->Set(Nan::GetCurrentContext(), Nan::New("P").ToLocalChecked(),
                         TestModule::Pnt::BuildWrapper((void *)&argP));
        returnValue->Set(Nan::GetCurrentContext(), Nan::New("V1").ToLocalChecked(),
                         TestModule::Vec::BuildWrapper((void *)&argV1));
        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Curve::d1) {
    if (TestModule::Curve::d1Overload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}

NAN_MODULE_INIT(TestModule::Curve::Init) {
    auto qualifiedName = Nan::New("TestModule::Curve").ToLocalChecked();
    auto className = Nan::New("Curve").ToLocalChecked();
    auto ctor = Nan::New<v8::FunctionTemplate>(New);
    auto ctorInst = ctor->InstanceTemplate();  // target for member functions
    ctor->SetClassName(qualifiedName);
    ctorInst->SetInternalFieldCount(1);  // for ObjectWrap, it should set 1
    ctor->Inherit(Nan::New(TestModule::Geometry::constructor));

    Nan::SetPrototypeMethod(ctor, "__cptr__", __cptr__);
    Nan::SetPrototypeMethod(ctor, "d0", d0);
    Nan::SetPrototypeMethod(ctor, "d1", d1);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("Geom_Curve", &BuildWrapper);
}