#include <TestModule/Geometry.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Geometry::constructor;
Nan::Persistent<v8::Object> TestModule::Geometry::prototype;

TestModule::Geometry::Geometry() {}
TestModule::Geometry::Geometry(Geom_Geometry *wrapObj) : wrappedObject(wrapObj) {}
TestModule::Geometry::Geometry(opencascade::handle<Geom_Geometry> wrapObj) : wrappedObject(wrapObj) {}

v8::Local<v8::Object> TestModule::Geometry::BuildWrapper(void *res) {
    auto obj = new Geometry(*static_cast<opencascade::handle<Geom_Geometry> *>(res));
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

bool TestModule::Geometry::firstCall = true;

NAN_METHOD(TestModule::Geometry::New) {}
bool TestModule::Geometry::MirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value> &info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Geometry>(info.Holder());
    auto obj = opencascade::handle<Geom_Geometry>::DownCast(wrapped->wrappedObject);
    auto res = obj->Mirrored(argP);
    info.GetReturnValue().Set(TestModule::Geometry::BuildWrapper((void *)&res));
    return true;
}
bool TestModule::Geometry::MirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value> &info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argA1)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Geometry>(info.Holder());
    auto obj = opencascade::handle<Geom_Geometry>::DownCast(wrapped->wrappedObject);
    auto res = obj->Mirrored(argA1);
    info.GetReturnValue().Set(TestModule::Geometry::BuildWrapper((void *)&res));
    return true;
}

NAN_METHOD(TestModule::Geometry::Mirrored) {
    if (TestModule::Geometry::MirroredOverload0(info)) {
        return;
    }
    if (TestModule::Geometry::MirroredOverload1(info)) {
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

    Nan::SetPrototypeMethod(ctor, "mirrored", Mirrored);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("Geom_Geometry", &BuildWrapper);
}