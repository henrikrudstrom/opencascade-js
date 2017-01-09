#include <TestModule/Curve.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Curve::constructor;
Nan::Persistent<v8::Object> TestModule::Curve::prototype;

TestModule::Curve::Curve() {}
TestModule::Curve::Curve(Geom_Curve *wrapObj) : Geometry(wrapObj) {}
TestModule::Curve::Curve(opencascade::handle<Geom_Curve> wrapObj) : Geometry(wrapObj) {}

v8::Local<v8::Object> TestModule::Curve::BuildWrapper(void *res) {
    auto obj = new Curve(*static_cast<opencascade::handle<Geom_Curve> *>(res));
    v8::Local<v8::Object> val =
        Nan::New(constructor)->GetFunction()->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
    obj->Wrap(val);
    return val;
}

bool TestModule::Curve::firstCall = true;

NAN_METHOD(TestModule::Curve::New) {}
bool TestModule::Curve::D0Overload0(const Nan::FunctionCallbackInfo<v8::Value> &info) {
    if (info.Length() != 1) {
        return false;
    }

    Standard_Real argU;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argU)) {
        return false;
    }
    gp_Pnt argP;

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Curve>(info.Holder());
    auto obj = opencascade::handle<Geom_Curve>::DownCast(wrapped->wrappedObject);
    obj->D0(argU, argP);
    info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void *)&argP));
    return true;
}

NAN_METHOD(TestModule::Curve::D0) {
    if (TestModule::Curve::D0Overload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Curve::D1Overload0(const Nan::FunctionCallbackInfo<v8::Value> &info) {
    if (info.Length() != 1) {
        return false;
    }

    Standard_Real argU;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argU)) {
        return false;
    }
    gp_Pnt argP;

    gp_Vec argV1;

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Curve>(info.Holder());
    auto obj = opencascade::handle<Geom_Curve>::DownCast(wrapped->wrappedObject);
    obj->D1(argU, argP, argV1);
    auto returnValue = Nan::New<v8::Object>();
    returnValue->Set(Nan::GetCurrentContext(), Nan::New("P").ToLocalChecked(),
                     TestModule::Pnt::BuildWrapper((void *)&argP));
    returnValue->Set(Nan::GetCurrentContext(), Nan::New("V1").ToLocalChecked(),
                     TestModule::Vec::BuildWrapper((void *)&argV1));
    info.GetReturnValue().Set(returnValue);
    return true;
}

NAN_METHOD(TestModule::Curve::D1) {
    if (TestModule::Curve::D1Overload0(info)) {
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

    Nan::SetPrototypeMethod(ctor, "d0", D0);
    Nan::SetPrototypeMethod(ctor, "d1", D1);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("Geom_Curve", &BuildWrapper);
}