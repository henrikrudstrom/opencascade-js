#include <TestModule/Point.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Point::constructor;
Nan::Persistent<v8::Object> TestModule::Point::prototype;

TestModule::Point::Point() {}
TestModule::Point::Point(Geom_Point* wrapObj) : Geometry(wrapObj) {}
TestModule::Point::Point(opencascade::handle<Geom_Point> wrapObj) : Geometry(wrapObj) {}

v8::Local<v8::Object> TestModule::Point::BuildWrapper(void* res) {
    Nan::EscapableHandleScope scope;
    v8::TryCatch errorHandler;

    v8::Local<v8::Function> func = Nan::GetFunction(Nan::New(constructor)).ToLocalChecked();
    v8::Local<v8::Value> args[1];
    args[0] = Nan::New<v8::External>(res);
    v8::MaybeLocal<v8::Object> maybeVal = Nan::NewInstance(func, 1, args);

    return scope.Escape(maybeVal.ToLocalChecked());
}

NAN_METHOD(TestModule::Point::__cptr__) {
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Point>(info.Holder());
    int addr = reinterpret_cast<std::uintptr_t>(&wrapped->wrappedObject);
    info.GetReturnValue().Set(Nan::New<v8::Int32>(addr));
}

bool TestModule::Point::firstCall = true;

NAN_METHOD(TestModule::Point::New) {}
bool TestModule::Point::distanceOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    opencascade::handle<Geom_Point> argOther;
    if (!Util::ConvertWrappedTransientValue<Geom_Point>(info[0], argOther)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Point>(info.Holder());
    auto obj = opencascade::handle<Geom_Point>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj->Distance(argOther);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Point::distance) {
    if (TestModule::Point::distanceOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}

NAN_MODULE_INIT(TestModule::Point::Init) {
    auto qualifiedName = Nan::New("TestModule::Point").ToLocalChecked();
    auto className = Nan::New("Point").ToLocalChecked();
    auto ctor = Nan::New<v8::FunctionTemplate>(New);
    auto ctorInst = ctor->InstanceTemplate();  // target for member functions
    ctor->SetClassName(qualifiedName);
    ctorInst->SetInternalFieldCount(1);  // for ObjectWrap, it should set 1
    ctor->Inherit(Nan::New(TestModule::Geometry::constructor));

    Nan::SetPrototypeMethod(ctor, "__cptr__", __cptr__);
    Nan::SetPrototypeMethod(ctor, "distance", distance);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("Geom_Point", &BuildWrapper);
}