#include <TestModule/Dir.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Dir::constructor;
Nan::Persistent<v8::Object> TestModule::Dir::prototype;

TestModule::Dir::Dir() {}
TestModule::Dir::Dir(gp_Dir* wrapObj) : wrappedObject(*wrapObj) {}
TestModule::Dir::Dir(gp_Dir wrapObj) : wrappedObject(wrapObj) {}

v8::Local<v8::Object> TestModule::Dir::BuildWrapper(void* res) {
    Nan::EscapableHandleScope scope;
    v8::TryCatch errorHandler;

    v8::Local<v8::Function> func = Nan::GetFunction(Nan::New(constructor)).ToLocalChecked();
    v8::Local<v8::Value> args[1];
    args[0] = Nan::New<v8::External>(res);
    v8::MaybeLocal<v8::Object> maybeVal = Nan::NewInstance(func, 1, args);

    return scope.Escape(maybeVal.ToLocalChecked());
}

NAN_METHOD(TestModule::Dir::__cptr__) {
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    int addr = reinterpret_cast<std::uintptr_t>(&wrapped->wrappedObject);
    info.GetReturnValue().Set(Nan::New<v8::Int32>(addr));
}

bool TestModule::Dir::firstCall = true;
bool TestModule::Dir::NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::Dir(new gp_Dir());
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Dir::NewOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argV;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argV)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::Dir(new gp_Dir(argV));
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Dir::NewOverload3(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }
    Nan::TryCatch errorHandler;
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
    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::Dir(new gp_Dir(argXv, argYv, argZv));
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
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
    if (info.Length() == 1 && info[0]->IsExternal()) {
        auto ext = info[0].As<v8::External>()->Value();
        auto wrapper = new Dir(*static_cast<gp_Dir*>(ext));
        wrapper->Wrap(info.This());
        return;
    }

    if (TestModule::Dir::NewOverload0(info)) {
        return;
    }
    if (TestModule::Dir::NewOverload1(info)) {
        return;
    }
    if (TestModule::Dir::NewOverload3(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::xOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.X();
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_GETTER(TestModule::Dir::x) {
    if (TestModule::Dir::xOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::yOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Y();
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_GETTER(TestModule::Dir::y) {
    if (TestModule::Dir::yOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::zOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Z();
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_GETTER(TestModule::Dir::z) {
    if (TestModule::Dir::zOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::angleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argOther;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argOther)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Angle(argOther);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::angle) {
    if (TestModule::Dir::angleOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::angleWithRefOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argOther;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argOther)) {
        return false;
    }
    gp_Dir argVRef;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[1], argVRef)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.AngleWithRef(argOther, argVRef);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::angleWithRef) {
    if (TestModule::Dir::angleWithRefOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::crossOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argRight;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argRight)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Cross(argRight);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::cross) {
    if (TestModule::Dir::crossOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::crossCrossOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argV1;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argV1)) {
        return false;
    }
    gp_Dir argV2;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[1], argV2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.CrossCross(argV1, argV2);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::crossCross) {
    if (TestModule::Dir::crossCrossOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::crossCrossedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argV1;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argV1)) {
        return false;
    }
    gp_Dir argV2;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[1], argV2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.CrossCrossed(argV1, argV2);
        info.GetReturnValue().Set(TestModule::Dir::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::crossCrossed) {
    if (TestModule::Dir::crossCrossedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::crossedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argRight;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argRight)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Crossed(argRight);
        info.GetReturnValue().Set(TestModule::Dir::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::crossed) {
    if (TestModule::Dir::crossedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::dotOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argOther;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argOther)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Dot(argOther);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::dot) {
    if (TestModule::Dir::dotOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::dotCrossOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argV1;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argV1)) {
        return false;
    }
    gp_Dir argV2;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[1], argV2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.DotCross(argV1, argV2);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::dotCross) {
    if (TestModule::Dir::dotCrossOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::isEqualOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argOther;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argOther)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAngularTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.IsEqual(argOther, argAngularTolerance);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::isEqual) {
    if (TestModule::Dir::isEqualOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::isNormalOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argOther;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argOther)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAngularTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.IsNormal(argOther, argAngularTolerance);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::isNormal) {
    if (TestModule::Dir::isNormalOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::isOppositeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argOther;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argOther)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAngularTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.IsOpposite(argOther, argAngularTolerance);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::isOpposite) {
    if (TestModule::Dir::isOppositeOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::isParallelOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argOther;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argOther)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAngularTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.IsParallel(argOther, argAngularTolerance);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::isParallel) {
    if (TestModule::Dir::isParallelOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::mirrorOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argV;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argV)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Mirror(argV);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Dir::mirrorOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Mirror(argA1);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Dir::mirrorOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Mirror(argA2);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::mirror) {
    if (TestModule::Dir::mirrorOverload0(info)) {
        return;
    }
    if (TestModule::Dir::mirrorOverload1(info)) {
        return;
    }
    if (TestModule::Dir::mirrorOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::mirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Dir argV;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[0], argV)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argV);
        info.GetReturnValue().Set(TestModule::Dir::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Dir::mirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argA1);
        info.GetReturnValue().Set(TestModule::Dir::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Dir::mirroredOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argA2);
        info.GetReturnValue().Set(TestModule::Dir::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::mirrored) {
    if (TestModule::Dir::mirroredOverload0(info)) {
        return;
    }
    if (TestModule::Dir::mirroredOverload1(info)) {
        return;
    }
    if (TestModule::Dir::mirroredOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::reverseOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Reverse();
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::reverse) {
    if (TestModule::Dir::reverseOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::reversedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Reversed();
        info.GetReturnValue().Set(TestModule::Dir::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::reversed) {
    if (TestModule::Dir::reversedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::rotateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argA1)) {
        return false;
    }
    Standard_Real argAng;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAng)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Rotate(argA1, argAng);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::rotate) {
    if (TestModule::Dir::rotateOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::rotatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argA1)) {
        return false;
    }
    Standard_Real argAng;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAng)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Rotated(argA1, argAng);
        info.GetReturnValue().Set(TestModule::Dir::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Dir::rotated) {
    if (TestModule::Dir::rotatedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::setXOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argX;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argX)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.SetX(argX);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_SETTER(TestModule::Dir::setX) {
    if (TestModule::Dir::setXOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::setYOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argY;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argY)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.SetY(argY);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_SETTER(TestModule::Dir::setY) {
    if (TestModule::Dir::setYOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Dir::setZOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argZ;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argZ)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Dir>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.SetZ(argZ);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_SETTER(TestModule::Dir::setZ) {
    if (TestModule::Dir::setZOverload0(info)) {
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

    Nan::SetPrototypeMethod(ctor, "__cptr__", __cptr__);
    Nan::SetAccessor(ctorInst, Nan::New("x").ToLocalChecked(), x, setX);
    Nan::SetAccessor(ctorInst, Nan::New("y").ToLocalChecked(), y, setY);
    Nan::SetAccessor(ctorInst, Nan::New("z").ToLocalChecked(), z, setZ);
    Nan::SetPrototypeMethod(ctor, "angle", angle);
    Nan::SetPrototypeMethod(ctor, "angleWithRef", angleWithRef);
    Nan::SetPrototypeMethod(ctor, "cross", cross);
    Nan::SetPrototypeMethod(ctor, "crossCross", crossCross);
    Nan::SetPrototypeMethod(ctor, "crossCrossed", crossCrossed);
    Nan::SetPrototypeMethod(ctor, "crossed", crossed);
    Nan::SetPrototypeMethod(ctor, "dot", dot);
    Nan::SetPrototypeMethod(ctor, "dotCross", dotCross);
    Nan::SetPrototypeMethod(ctor, "isEqual", isEqual);
    Nan::SetPrototypeMethod(ctor, "isNormal", isNormal);
    Nan::SetPrototypeMethod(ctor, "isOpposite", isOpposite);
    Nan::SetPrototypeMethod(ctor, "isParallel", isParallel);
    Nan::SetPrototypeMethod(ctor, "mirror", mirror);
    Nan::SetPrototypeMethod(ctor, "mirrored", mirrored);
    Nan::SetPrototypeMethod(ctor, "reverse", reverse);
    Nan::SetPrototypeMethod(ctor, "reversed", reversed);
    Nan::SetPrototypeMethod(ctor, "rotate", rotate);
    Nan::SetPrototypeMethod(ctor, "rotated", rotated);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("gp_Dir", &BuildWrapper);
}