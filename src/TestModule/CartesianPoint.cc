#include <TestModule/CartesianPoint.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::CartesianPoint::constructor;
Nan::Persistent<v8::Object> TestModule::CartesianPoint::prototype;

TestModule::CartesianPoint::CartesianPoint() {}
TestModule::CartesianPoint::CartesianPoint(Geom_CartesianPoint* wrapObj) : Point(wrapObj) {}
TestModule::CartesianPoint::CartesianPoint(opencascade::handle<Geom_CartesianPoint> wrapObj)
    : Point(wrapObj) {}

v8::Local<v8::Object> TestModule::CartesianPoint::BuildWrapper(void* res) {
    Nan::EscapableHandleScope scope;
    v8::TryCatch errorHandler;

    v8::Local<v8::Function> func = Nan::GetFunction(Nan::New(constructor)).ToLocalChecked();
    v8::Local<v8::Value> args[1];
    args[0] = Nan::New<v8::External>(res);
    v8::MaybeLocal<v8::Object> maybeVal = Nan::NewInstance(func, 1, args);

    return scope.Escape(maybeVal.ToLocalChecked());
}

NAN_METHOD(TestModule::CartesianPoint::__cptr__) {
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    int addr = reinterpret_cast<std::uintptr_t>(&wrapped->wrappedObject);
    info.GetReturnValue().Set(Nan::New<v8::Int32>(addr));
}

bool TestModule::CartesianPoint::firstCall = true;
bool TestModule::CartesianPoint::NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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

    try {
        auto wrapper = new TestModule::CartesianPoint(new Geom_CartesianPoint(argP));
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::CartesianPoint::NewOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argX;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argX)) {
        return false;
    }
    Standard_Real argY;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argY)) {
        return false;
    }
    Standard_Real argZ;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[2], argZ)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::CartesianPoint(new Geom_CartesianPoint(argX, argY, argZ));
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::CartesianPoint::New) {
    if (!info.IsConstructCall()) {
        std::vector<v8::Local<v8::Value> > args(info.Length());
        for (std::size_t i = 0; i < args.size(); ++i) args[i] = info[i];
        auto inst = Nan::NewInstance(info.Callee(), args.size(), args.data());
        if (!inst.IsEmpty()) info.GetReturnValue().Set(inst.ToLocalChecked());
        return;
    }
    if (firstCall) {
        auto wrapper = new CartesianPoint();
        wrapper->Wrap(info.This());
        firstCall = false;
        return;
    }
    if (info.Length() == 1 && info[0]->IsExternal()) {
        auto ext = info[0].As<v8::External>()->Value();
        auto wrapper = new CartesianPoint(*static_cast<opencascade::handle<Geom_CartesianPoint>*>(ext));
        wrapper->Wrap(info.This());
        return;
    }

    if (TestModule::CartesianPoint::NewOverload0(info)) {
        return;
    }
    if (TestModule::CartesianPoint::NewOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::xOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj->X();
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_GETTER(TestModule::CartesianPoint::x) {
    if (TestModule::CartesianPoint::xOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::yOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj->Y();
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_GETTER(TestModule::CartesianPoint::y) {
    if (TestModule::CartesianPoint::yOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::zOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj->Z();
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_GETTER(TestModule::CartesianPoint::z) {
    if (TestModule::CartesianPoint::zOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::setXOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argX;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argX)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj->SetX(argX);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_SETTER(TestModule::CartesianPoint::setX) {
    if (TestModule::CartesianPoint::setXOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::setYOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argY;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argY)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj->SetY(argY);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_SETTER(TestModule::CartesianPoint::setY) {
    if (TestModule::CartesianPoint::setYOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::setZOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argZ;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argZ)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj->SetZ(argZ);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_SETTER(TestModule::CartesianPoint::setZ) {
    if (TestModule::CartesianPoint::setZOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}

NAN_MODULE_INIT(TestModule::CartesianPoint::Init) {
    auto qualifiedName = Nan::New("TestModule::CartesianPoint").ToLocalChecked();
    auto className = Nan::New("CartesianPoint").ToLocalChecked();
    auto ctor = Nan::New<v8::FunctionTemplate>(New);
    auto ctorInst = ctor->InstanceTemplate();  // target for member functions
    ctor->SetClassName(qualifiedName);
    ctorInst->SetInternalFieldCount(1);  // for ObjectWrap, it should set 1
    ctor->Inherit(Nan::New(TestModule::Point::constructor));

    Nan::SetPrototypeMethod(ctor, "__cptr__", __cptr__);
    Nan::SetAccessor(ctorInst, Nan::New("x").ToLocalChecked(), x, setX);
    Nan::SetAccessor(ctorInst, Nan::New("y").ToLocalChecked(), y, setY);
    Nan::SetAccessor(ctorInst, Nan::New("z").ToLocalChecked(), z, setZ);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("Geom_CartesianPoint", &BuildWrapper);
}