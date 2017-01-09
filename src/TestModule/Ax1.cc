#include <TestModule/Ax1.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Ax1::constructor;
Nan::Persistent<v8::Object> TestModule::Ax1::prototype;

TestModule::Ax1::Ax1() {}
TestModule::Ax1::Ax1(gp_Ax1* wrapObj) : wrappedObject(*wrapObj) {}
TestModule::Ax1::Ax1(gp_Ax1 wrapObj) : wrappedObject(wrapObj) {}

v8::Local<v8::Object> TestModule::Ax1::BuildWrapper(void* res) {
    auto obj = new Ax1(*static_cast<gp_Ax1*>(res));
    v8::Local<v8::Object> val =
        Nan::New(constructor)->GetFunction()->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
    obj->Wrap(val);
    return val;
}

bool TestModule::Ax1::firstCall = true;
bool TestModule::Ax1::Ax1Overload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }

    auto wrapper = new TestModule::Ax1(new gp_Ax1());
    wrapper->Wrap(info.This());
    return true;
}
bool TestModule::Ax1::Ax1Overload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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

    auto wrapper = new TestModule::Ax1(new gp_Ax1(argP, argV));
    wrapper->Wrap(info.This());
    return true;
}

NAN_METHOD(TestModule::Ax1::New) {
    if (!info.IsConstructCall()) {
        std::vector<v8::Local<v8::Value> > args(info.Length());
        for (std::size_t i = 0; i < args.size(); ++i) args[i] = info[i];
        auto inst = Nan::NewInstance(info.Callee(), args.size(), args.data());
        if (!inst.IsEmpty()) info.GetReturnValue().Set(inst.ToLocalChecked());
        return;
    }
    if (firstCall) {
        auto wrapper = new Ax1();
        wrapper->Wrap(info.This());
        firstCall = false;
        return;
    }
    if (TestModule::Ax1::Ax1Overload0(info)) {
        return;
    }
    if (TestModule::Ax1::Ax1Overload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::SetDirectionOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    gp_Dir argV;
    if (!Util::ConvertWrappedValue<gp_Dir>(info.Data(), argV)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetDirection(argV);

    return true;
}

NAN_SETTER(TestModule::Ax1::SetDirection) {
    if (TestModule::Ax1::SetDirectionOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::SetLocationOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info.Data(), argP)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetLocation(argP);

    return true;
}

NAN_SETTER(TestModule::Ax1::SetLocation) {
    if (TestModule::Ax1::SetLocationOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}

NAN_MODULE_INIT(TestModule::Ax1::Init) {
    auto qualifiedName = Nan::New("TestModule::Ax1").ToLocalChecked();
    auto className = Nan::New("Ax1").ToLocalChecked();
    auto ctor = Nan::New<v8::FunctionTemplate>(New);
    auto ctorInst = ctor->InstanceTemplate();  // target for member functions
    ctor->SetClassName(qualifiedName);
    ctorInst->SetInternalFieldCount(1);  // for ObjectWrap, it should set 1

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("gp_Ax1", &BuildWrapper);
}