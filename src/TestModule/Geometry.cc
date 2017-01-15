#include <TestModule/Geometry.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Geometry::constructor;
Nan::Persistent<v8::Object> TestModule::Geometry::prototype;

TestModule::Geometry::Geometry() {}
TestModule::Geometry::Geometry(Geom_Geometry* wrapObj) : wrappedObject(wrapObj) {}
TestModule::Geometry::Geometry(opencascade::handle<Geom_Geometry> wrapObj) : wrappedObject(wrapObj) {}

v8::Local<v8::Object> TestModule::Geometry::BuildWrapper(void* res) {
    Nan::EscapableHandleScope scope;
    v8::TryCatch errorHandler;

    v8::Local<v8::Function> func = Nan::GetFunction(Nan::New(constructor)).ToLocalChecked();
    v8::Local<v8::Value> args[1];
    args[0] = Nan::New<v8::External>(res);
    v8::MaybeLocal<v8::Object> maybeVal = Nan::NewInstance(func, 1, args);

    return scope.Escape(maybeVal.ToLocalChecked());
}

NAN_METHOD(TestModule::Geometry::__cptr__) {
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Geometry>(info.Holder());
    int addr = reinterpret_cast<std::uintptr_t>(&wrapped->wrappedObject);
    info.GetReturnValue().Set(Nan::New<v8::Int32>(addr));
}

bool TestModule::Geometry::firstCall = true;

NAN_METHOD(TestModule::Geometry::New) {}
bool TestModule::Geometry::mirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Geometry>(info.Holder());
    auto obj = opencascade::handle<Geom_Geometry>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj->Mirrored(argP);
        info.GetReturnValue().Set(DynamicCastMap::Create(res->DynamicType()->Name(), (void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Geometry::mirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Geometry>(info.Holder());
    auto obj = opencascade::handle<Geom_Geometry>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj->Mirrored(argA1);
        info.GetReturnValue().Set(DynamicCastMap::Create(res->DynamicType()->Name(), (void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Geometry::mirroredOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Ax2 argA2;
    if (!Util::ConvertWrappedValue<gp_Ax2>(info[0], argA2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Geometry>(info.Holder());
    auto obj = opencascade::handle<Geom_Geometry>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj->Mirrored(argA2);
        info.GetReturnValue().Set(DynamicCastMap::Create(res->DynamicType()->Name(), (void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Geometry::mirrored) {
    if (TestModule::Geometry::mirroredOverload0(info)) {
        return;
    }
    if (TestModule::Geometry::mirroredOverload1(info)) {
        return;
    }
    if (TestModule::Geometry::mirroredOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}

NAN_MODULE_INIT(TestModule::Geometry::Init) {
    auto qualifiedName = Nan::New("TestModule::Geometry").ToLocalChecked();
    auto className = Nan::New("Geometry").ToLocalChecked();
    auto ctor = Nan::New<v8::FunctionTemplate>(New);
    auto ctorInst = ctor->InstanceTemplate();  // target for member functions
    ctor->SetClassName(qualifiedName);
    ctorInst->SetInternalFieldCount(1);  // for ObjectWrap, it should set 1

    Nan::SetPrototypeMethod(ctor, "__cptr__", __cptr__);
    Nan::SetPrototypeMethod(ctor, "mirrored", mirrored);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("Geom_Geometry", &BuildWrapper);
}