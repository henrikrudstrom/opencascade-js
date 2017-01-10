#include <TestModule/CartesianPoint.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::CartesianPoint::constructor;
Nan::Persistent<v8::Object> TestModule::CartesianPoint::prototype;

TestModule::CartesianPoint::CartesianPoint() {}
TestModule::CartesianPoint::CartesianPoint(Geom_CartesianPoint* wrapObj) : Point(wrapObj) {}
TestModule::CartesianPoint::CartesianPoint(opencascade::handle<Geom_CartesianPoint> wrapObj)
    : Point(wrapObj) {}

v8::Local<v8::Object> TestModule::CartesianPoint::BuildWrapper(void* res) {
    auto obj = new CartesianPoint(*static_cast<opencascade::handle<Geom_CartesianPoint>*>(res));
    v8::TryCatch onError;
    v8::MaybeLocal<v8::Object> maybeVal =
        Nan::New(constructor)->GetFunction()->NewInstance(Nan::GetCurrentContext());
    if (onError.HasCaught()) {
        v8::Local<v8::Object> empty;
        return empty;
    }
    v8::Local<v8::Object> val = maybeVal.ToLocalChecked();
    obj->Wrap(val);
    return val;
}

bool TestModule::CartesianPoint::firstCall = true;
bool TestModule::CartesianPoint::CartesianPointOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }

    auto wrapper = new TestModule::CartesianPoint(new Geom_CartesianPoint(argP));
    wrapper->Wrap(info.This());
    return true;
}
bool TestModule::CartesianPoint::CartesianPointOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }

    Standard_Integer argX;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[0], argX)) {
        return false;
    }
    Standard_Integer argY;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[1], argY)) {
        return false;
    }
    Standard_Integer argZ;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[2], argZ)) {
        return false;
    }

    auto wrapper = new TestModule::CartesianPoint(new Geom_CartesianPoint(argX, argY, argZ));
    wrapper->Wrap(info.This());
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
    if (TestModule::CartesianPoint::CartesianPointOverload0(info)) {
        return;
    }
    if (TestModule::CartesianPoint::CartesianPointOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::XOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    auto res = obj->X();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::CartesianPoint::X) {
    if (TestModule::CartesianPoint::XOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::YOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    auto res = obj->Y();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::CartesianPoint::Y) {
    if (TestModule::CartesianPoint::YOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::ZOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    auto res = obj->Z();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::CartesianPoint::Z) {
    if (TestModule::CartesianPoint::ZOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::SetXOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Integer argX;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info.Data(), argX)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    obj->SetX(argX);

    return true;
}

NAN_SETTER(TestModule::CartesianPoint::SetX) {
    if (TestModule::CartesianPoint::SetXOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::SetYOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Integer argY;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info.Data(), argY)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    obj->SetY(argY);

    return true;
}

NAN_SETTER(TestModule::CartesianPoint::SetY) {
    if (TestModule::CartesianPoint::SetYOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::CartesianPoint::SetZOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Integer argZ;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info.Data(), argZ)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::CartesianPoint>(info.Holder());
    auto obj = opencascade::handle<Geom_CartesianPoint>::DownCast(wrapped->wrappedObject);
    obj->SetZ(argZ);

    return true;
}

NAN_SETTER(TestModule::CartesianPoint::SetZ) {
    if (TestModule::CartesianPoint::SetZOverload0(info)) {
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

    Nan::SetAccessor(ctorInst, Nan::New("x").ToLocalChecked(), X, SetX);
    Nan::SetAccessor(ctorInst, Nan::New("y").ToLocalChecked(), Y, SetY);
    Nan::SetAccessor(ctorInst, Nan::New("z").ToLocalChecked(), Z, SetZ);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("Geom_CartesianPoint", &BuildWrapper);
}