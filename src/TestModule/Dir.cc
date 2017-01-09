#include <TestModule/Dir.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Dir::constructor;
Nan::Persistent<v8::Object> TestModule::Dir::prototype;

TestModule::Dir::Dir() {}
TestModule::Dir::Dir(gp_Dir* wrapObj) : wrappedObject(*wrapObj) {}
TestModule::Dir::Dir(gp_Dir wrapObj) : wrappedObject(wrapObj) {}

v8::Local<v8::Object> TestModule::Dir::BuildWrapper(void* res) {
    auto obj = new Dir(*static_cast<gp_Dir*>(res));
    v8::Local<v8::Object> val =
        Nan::New(constructor)->GetFunction()->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
    obj->Wrap(val);
    return val;
}

bool TestModule::Dir::firstCall = true;
bool TestModule::Dir::DirOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }

    auto wrapper = new TestModule::Dir(new gp_Dir());
    wrapper->Wrap(info.This());
    return true;
}
bool TestModule::Dir::DirOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Vec argV;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argV)) {
        return false;
    }

    auto wrapper = new TestModule::Dir(new gp_Dir(argV));
    wrapper->Wrap(info.This());
    return true;
}
bool TestModule::Dir::DirOverload3(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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

    auto wrapper = new TestModule::Dir(new gp_Dir(argXv, argYv, argZv));
    wrapper->Wrap(info.This());
    return true;
}

NAN_METHOD(TestModule::Dir::New) {
    if (!info.IsConstructCall()) {
        std::vector<v8::Local<v8::Value> > args(info.Length());
        for (std::size_t i = 0; i < args.size(); ++i) args[i] = info[i];
        auto inst = Nan::NewInstance(info.Callee(), args.size(), args.data());
        if (!inst.IsEmpty()) info.GetReturnValue().Set(inst.ToLocalChecked());
        return;
    }
    if (firstCall) {
        auto wrapper = new Dir();
        wrapper->Wrap(info.This());
        firstCall = false;
        return;
    }
    if (TestModule::Dir::DirOverload0(info)) {
        return;
    }
    if (TestModule::Dir::DirOverload1(info)) {
        return;
    }
    if (TestModule::Dir::DirOverload3(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::XOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.X();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::Dir::X) {
    if (TestModule::Dir::XOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::YOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Y();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::Dir::Y) {
    if (TestModule::Dir::YOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::ZOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Z();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::Dir::Z) {
    if (TestModule::Dir::ZOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::SetXOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Real argX;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argX)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetX(argX);

    return true;
}

NAN_SETTER(TestModule::Dir::SetX) {
    if (TestModule::Dir::SetXOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::SetYOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Real argY;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argY)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetY(argY);

    return true;
}

NAN_SETTER(TestModule::Dir::SetY) {
    if (TestModule::Dir::SetYOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::SetZOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Real argZ;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argZ)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetZ(argZ);

    return true;
}

NAN_SETTER(TestModule::Dir::SetZ) {
    if (TestModule::Dir::SetZOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}

NAN_MODULE_INIT(TestModule::Dir::Init) {
    auto qualifiedName = Nan::New("TestModule::Dir").ToLocalChecked();
    auto className = Nan::New("Dir").ToLocalChecked();
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

    DynamicCastMap::Register("gp_Dir", &BuildWrapper);
}