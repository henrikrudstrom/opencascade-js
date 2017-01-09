#include <TestModule/Vec.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Vec::constructor;
Nan::Persistent<v8::Object> TestModule::Vec::prototype;

TestModule::Vec::Vec() {}
TestModule::Vec::Vec(gp_Vec* wrapObj) : wrappedObject(*wrapObj) {}
TestModule::Vec::Vec(gp_Vec wrapObj) : wrappedObject(wrapObj) {}

v8::Local<v8::Object> TestModule::Vec::BuildWrapper(void* res) {
    auto obj = new Vec(*static_cast<gp_Vec*>(res));
    v8::Local<v8::Object> val =
        Nan::New(constructor)->GetFunction()->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
    obj->Wrap(val);
    return val;
}

bool TestModule::Vec::firstCall = true;
bool TestModule::Vec::VecOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }

    auto wrapper = new TestModule::Vec(new gp_Vec());
    wrapper->Wrap(info.This());
    return true;
}
bool TestModule::Vec::VecOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Dir argV;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argV)) {
        return false;
    }

    auto wrapper = new TestModule::Vec(new gp_Vec(argV));
    wrapper->Wrap(info.This());
    return true;
}
bool TestModule::Vec::VecOverload3(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }

    Standard_Real argXv;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argXv)) {
        return false;
    }
    Standard_Real argYv;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argYv)) {
        return false;
    }
    Standard_Real argZv;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[2], argZv)) {
        return false;
    }

    auto wrapper = new TestModule::Vec(new gp_Vec(argXv, argYv, argZv));
    wrapper->Wrap(info.This());
    return true;
}
bool TestModule::Vec::VecOverload4(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }

    gp_Pnt argP1;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP1)) {
        return false;
    }
    gp_Pnt argP2;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[1], argP2)) {
        return false;
    }

    auto wrapper = new TestModule::Vec(new gp_Vec(argP1, argP2));
    wrapper->Wrap(info.This());
    return true;
}

NAN_METHOD(TestModule::Vec::New) {
    if (!info.IsConstructCall()) {
        std::vector<v8::Local<v8::Value> > args(info.Length());
        for (std::size_t i = 0; i < args.size(); ++i) args[i] = info[i];
        auto inst = Nan::NewInstance(info.Callee(), args.size(), args.data());
        if (!inst.IsEmpty()) info.GetReturnValue().Set(inst.ToLocalChecked());
        return;
    }
    if (firstCall) {
        auto wrapper = new Vec();
        wrapper->Wrap(info.This());
        firstCall = false;
        return;
    }
    if (TestModule::Vec::VecOverload0(info)) {
        return;
    }
    if (TestModule::Vec::VecOverload1(info)) {
        return;
    }
    if (TestModule::Vec::VecOverload3(info)) {
        return;
    }
    if (TestModule::Vec::VecOverload4(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::XOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.X();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::Vec::X) {
    if (TestModule::Vec::XOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::YOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Y();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::Vec::Y) {
    if (TestModule::Vec::YOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::ZOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Z();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::Vec::Z) {
    if (TestModule::Vec::ZOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::SetXOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Real argX;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argX)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetX(argX);

    return true;
}

NAN_SETTER(TestModule::Vec::SetX) {
    if (TestModule::Vec::SetXOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::SetYOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Real argY;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argY)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetY(argY);

    return true;
}

NAN_SETTER(TestModule::Vec::SetY) {
    if (TestModule::Vec::SetYOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::SetZOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Real argZ;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argZ)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetZ(argZ);

    return true;
}

NAN_SETTER(TestModule::Vec::SetZ) {
    if (TestModule::Vec::SetZOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}

NAN_MODULE_INIT(TestModule::Vec::Init) {
    auto qualifiedName = Nan::New("TestModule::Vec").ToLocalChecked();
    auto className = Nan::New("Vec").ToLocalChecked();
    auto ctor = Nan::New<v8::FunctionTemplate>(New);
    auto ctorInst = ctor->InstanceTemplate();  // target for member functions
    ctor->SetClassName(qualifiedName);
    ctorInst->SetInternalFieldCount(1);  // for ObjectWrap, it should set 1

    Nan::SetAccessor(ctorInst, Nan::New("x").ToLocalChecked(), X, SetX);
    Nan::SetAccessor(ctorInst, Nan::New("y").ToLocalChecked(), Y, SetY);
    Nan::SetAccessor(ctorInst, Nan::New("z").ToLocalChecked(), Z, SetZ);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("gp_Vec", &BuildWrapper);
}