#include <TestModule/Vec.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Vec::constructor;
Nan::Persistent<v8::Object> TestModule::Vec::prototype;

TestModule::Vec::Vec() {}
TestModule::Vec::Vec(gp_Vec* wrapObj) : wrappedObject(*wrapObj) {}
TestModule::Vec::Vec(gp_Vec wrapObj) : wrappedObject(wrapObj) {}

v8::Local<v8::Object> TestModule::Vec::BuildWrapper(void* res) {
    Nan::EscapableHandleScope scope;
    v8::TryCatch errorHandler;

    v8::Local<v8::Function> func = Nan::GetFunction(Nan::New(constructor)).ToLocalChecked();
    v8::Local<v8::Value> args[1];
    args[0] = Nan::New<v8::External>(res);
    v8::MaybeLocal<v8::Object> maybeVal = Nan::NewInstance(func, 1, args);

    return scope.Escape(maybeVal.ToLocalChecked());
}

NAN_METHOD(TestModule::Vec::__cptr__) {
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    int addr = reinterpret_cast<std::uintptr_t>(&wrapped->wrappedObject);
    info.GetReturnValue().Set(Nan::New<v8::Int32>(addr));
}

bool TestModule::Vec::firstCall = true;
bool TestModule::Vec::NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::Vec(new gp_Vec());
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Vec::NewOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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

    try {
        auto wrapper = new TestModule::Vec(new gp_Vec(argV));
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Vec::NewOverload3(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
        auto wrapper = new TestModule::Vec(new gp_Vec(argXv, argYv, argZv));
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Vec::NewOverload4(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Pnt argP1;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP1)) {
        return false;
    }
    gp_Pnt argP2;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[1], argP2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::Vec(new gp_Vec(argP1, argP2));
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
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
    if (info.Length() == 1 && info[0]->IsExternal()) {
        auto ext = info[0].As<v8::External>()->Value();
        auto wrapper = new Vec(*static_cast<gp_Vec*>(ext));
        wrapper->Wrap(info.This());
        return;
    }

    if (TestModule::Vec::NewOverload0(info)) {
        return;
    }
    if (TestModule::Vec::NewOverload1(info)) {
        return;
    }
    if (TestModule::Vec::NewOverload3(info)) {
        return;
    }
    if (TestModule::Vec::NewOverload4(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::xOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_GETTER(TestModule::Vec::x) {
    if (TestModule::Vec::xOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::yOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_GETTER(TestModule::Vec::y) {
    if (TestModule::Vec::yOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::zOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_GETTER(TestModule::Vec::z) {
    if (TestModule::Vec::zOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::addOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argOther;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argOther)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Add(argOther);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::add) {
    if (TestModule::Vec::addOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::addedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argOther;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argOther)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Added(argOther);
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::added) {
    if (TestModule::Vec::addedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::angleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argOther;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argOther)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::angle) {
    if (TestModule::Vec::angleOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::angleWithRefOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argOther;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argOther)) {
        return false;
    }
    gp_Vec argVRef;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[1], argVRef)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::angleWithRef) {
    if (TestModule::Vec::angleWithRefOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::crossOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argRight;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argRight)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::cross) {
    if (TestModule::Vec::crossOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::crossCrossOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argV1;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argV1)) {
        return false;
    }
    gp_Vec argV2;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[1], argV2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::crossCross) {
    if (TestModule::Vec::crossCrossOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::crossCrossedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argV1;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argV1)) {
        return false;
    }
    gp_Vec argV2;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[1], argV2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.CrossCrossed(argV1, argV2);
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::crossCrossed) {
    if (TestModule::Vec::crossCrossedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::crossMagnitudeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argRight;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argRight)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.CrossMagnitude(argRight);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::crossMagnitude) {
    if (TestModule::Vec::crossMagnitudeOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::crossSquareMagnitudeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argRight;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argRight)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.CrossSquareMagnitude(argRight);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::crossSquareMagnitude) {
    if (TestModule::Vec::crossSquareMagnitudeOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::crossedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argRight;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argRight)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Crossed(argRight);
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::crossed) {
    if (TestModule::Vec::crossedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::divideOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argScalar;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argScalar)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Divide(argScalar);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::divide) {
    if (TestModule::Vec::divideOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::dividedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argScalar;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argScalar)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Divided(argScalar);
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::divided) {
    if (TestModule::Vec::dividedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::dotOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argOther;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argOther)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::dot) {
    if (TestModule::Vec::dotOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::dotCrossOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argV1;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argV1)) {
        return false;
    }
    gp_Vec argV2;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[1], argV2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::dotCross) {
    if (TestModule::Vec::dotCrossOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::isEqualOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argOther;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argOther)) {
        return false;
    }
    Standard_Real argLinearTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argLinearTolerance)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[2], argAngularTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.IsEqual(argOther, argLinearTolerance, argAngularTolerance);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::isEqual) {
    if (TestModule::Vec::isEqualOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::isNormalOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argOther;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argOther)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAngularTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::isNormal) {
    if (TestModule::Vec::isNormalOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::isOppositeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argOther;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argOther)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAngularTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::isOpposite) {
    if (TestModule::Vec::isOppositeOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::isParallelOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argOther;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argOther)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAngularTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::isParallel) {
    if (TestModule::Vec::isParallelOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::magnitudeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Magnitude();
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::magnitude) {
    if (TestModule::Vec::magnitudeOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::mirrorOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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
bool TestModule::Vec::mirrorOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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
bool TestModule::Vec::mirrorOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::mirror) {
    if (TestModule::Vec::mirrorOverload0(info)) {
        return;
    }
    if (TestModule::Vec::mirrorOverload1(info)) {
        return;
    }
    if (TestModule::Vec::mirrorOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::mirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argV);
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Vec::mirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argA1);
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Vec::mirroredOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argA2);
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::mirrored) {
    if (TestModule::Vec::mirroredOverload0(info)) {
        return;
    }
    if (TestModule::Vec::mirroredOverload1(info)) {
        return;
    }
    if (TestModule::Vec::mirroredOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::multipliedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argScalar;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argScalar)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Multiplied(argScalar);
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::multiplied) {
    if (TestModule::Vec::multipliedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::multiplyOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argScalar;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argScalar)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Multiply(argScalar);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::multiply) {
    if (TestModule::Vec::multiplyOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::normalizeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Normalize();
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::normalize) {
    if (TestModule::Vec::normalizeOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::normalizedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Normalized();
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::normalized) {
    if (TestModule::Vec::normalizedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::reverseOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::reverse) {
    if (TestModule::Vec::reverseOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::reversedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Reversed();
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::reversed) {
    if (TestModule::Vec::reversedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::rotateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_METHOD(TestModule::Vec::rotate) {
    if (TestModule::Vec::rotateOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::rotatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Rotated(argA1, argAng);
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::rotated) {
    if (TestModule::Vec::rotatedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::scaleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argS;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argS)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Scale(argS);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::scale) {
    if (TestModule::Vec::scaleOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::scaledOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argS;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argS)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Scaled(argS);
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::scaled) {
    if (TestModule::Vec::scaledOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::setLinearFormOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 7) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argA1;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argA1)) {
        return false;
    }
    gp_Vec argV1;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[1], argV1)) {
        return false;
    }
    Standard_Real argA2;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[2], argA2)) {
        return false;
    }
    gp_Vec argV2;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[3], argV2)) {
        return false;
    }
    Standard_Real argA3;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[4], argA3)) {
        return false;
    }
    gp_Vec argV3;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[5], argV3)) {
        return false;
    }
    gp_Vec argV4;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[6], argV4)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.SetLinearForm(argA1, argV1, argA2, argV2, argA3, argV3, argV4);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Vec::setLinearFormOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 6) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argA1;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argA1)) {
        return false;
    }
    gp_Vec argV1;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[1], argV1)) {
        return false;
    }
    Standard_Real argA2;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[2], argA2)) {
        return false;
    }
    gp_Vec argV2;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[3], argV2)) {
        return false;
    }
    Standard_Real argA3;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[4], argA3)) {
        return false;
    }
    gp_Vec argV3;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[5], argV3)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.SetLinearForm(argA1, argV1, argA2, argV2, argA3, argV3);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Vec::setLinearFormOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 5) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argA1;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argA1)) {
        return false;
    }
    gp_Vec argV1;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[1], argV1)) {
        return false;
    }
    Standard_Real argA2;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[2], argA2)) {
        return false;
    }
    gp_Vec argV2;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[3], argV2)) {
        return false;
    }
    gp_Vec argV3;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[4], argV3)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.SetLinearForm(argA1, argV1, argA2, argV2, argV3);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Vec::setLinearFormOverload3(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 4) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argA1;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argA1)) {
        return false;
    }
    gp_Vec argV1;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[1], argV1)) {
        return false;
    }
    Standard_Real argA2;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[2], argA2)) {
        return false;
    }
    gp_Vec argV2;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[3], argV2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.SetLinearForm(argA1, argV1, argA2, argV2);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Vec::setLinearFormOverload4(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argA1;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argA1)) {
        return false;
    }
    gp_Vec argV1;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[1], argV1)) {
        return false;
    }
    gp_Vec argV2;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[2], argV2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.SetLinearForm(argA1, argV1, argV2);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Vec::setLinearFormOverload5(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argV1;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argV1)) {
        return false;
    }
    gp_Vec argV2;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[1], argV2)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.SetLinearForm(argV1, argV2);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::setLinearForm) {
    if (TestModule::Vec::setLinearFormOverload0(info)) {
        return;
    }
    if (TestModule::Vec::setLinearFormOverload1(info)) {
        return;
    }
    if (TestModule::Vec::setLinearFormOverload2(info)) {
        return;
    }
    if (TestModule::Vec::setLinearFormOverload3(info)) {
        return;
    }
    if (TestModule::Vec::setLinearFormOverload4(info)) {
        return;
    }
    if (TestModule::Vec::setLinearFormOverload5(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::squareMagnitudeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.SquareMagnitude();
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::squareMagnitude) {
    if (TestModule::Vec::squareMagnitudeOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::subtractOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argRight;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argRight)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Subtract(argRight);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::subtract) {
    if (TestModule::Vec::subtractOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::subtractedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Vec argRight;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argRight)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Subtracted(argRight);
        info.GetReturnValue().Set(TestModule::Vec::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Vec::subtracted) {
    if (TestModule::Vec::subtractedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::setXOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argX;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argX)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_SETTER(TestModule::Vec::setX) {
    if (TestModule::Vec::setXOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::setYOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argY;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argY)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_SETTER(TestModule::Vec::setY) {
    if (TestModule::Vec::setYOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Vec::setZOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argZ;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argZ)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Vec>(info.Holder());
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

NAN_SETTER(TestModule::Vec::setZ) {
    if (TestModule::Vec::setZOverload0(info)) {
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

    Nan::SetPrototypeMethod(ctor, "__cptr__", __cptr__);
    Nan::SetAccessor(ctorInst, Nan::New("x").ToLocalChecked(), x, setX);
    Nan::SetAccessor(ctorInst, Nan::New("y").ToLocalChecked(), y, setY);
    Nan::SetAccessor(ctorInst, Nan::New("z").ToLocalChecked(), z, setZ);
    Nan::SetPrototypeMethod(ctor, "add", add);
    Nan::SetPrototypeMethod(ctor, "added", added);
    Nan::SetPrototypeMethod(ctor, "angle", angle);
    Nan::SetPrototypeMethod(ctor, "angleWithRef", angleWithRef);
    Nan::SetPrototypeMethod(ctor, "cross", cross);
    Nan::SetPrototypeMethod(ctor, "crossCross", crossCross);
    Nan::SetPrototypeMethod(ctor, "crossCrossed", crossCrossed);
    Nan::SetPrototypeMethod(ctor, "crossMagnitude", crossMagnitude);
    Nan::SetPrototypeMethod(ctor, "crossSquareMagnitude", crossSquareMagnitude);
    Nan::SetPrototypeMethod(ctor, "crossed", crossed);
    Nan::SetPrototypeMethod(ctor, "divide", divide);
    Nan::SetPrototypeMethod(ctor, "divided", divided);
    Nan::SetPrototypeMethod(ctor, "dot", dot);
    Nan::SetPrototypeMethod(ctor, "dotCross", dotCross);
    Nan::SetPrototypeMethod(ctor, "isEqual", isEqual);
    Nan::SetPrototypeMethod(ctor, "isNormal", isNormal);
    Nan::SetPrototypeMethod(ctor, "isOpposite", isOpposite);
    Nan::SetPrototypeMethod(ctor, "isParallel", isParallel);
    Nan::SetPrototypeMethod(ctor, "magnitude", magnitude);
    Nan::SetPrototypeMethod(ctor, "mirror", mirror);
    Nan::SetPrototypeMethod(ctor, "mirrored", mirrored);
    Nan::SetPrototypeMethod(ctor, "multiplied", multiplied);
    Nan::SetPrototypeMethod(ctor, "multiply", multiply);
    Nan::SetPrototypeMethod(ctor, "normalize", normalize);
    Nan::SetPrototypeMethod(ctor, "normalized", normalized);
    Nan::SetPrototypeMethod(ctor, "reverse", reverse);
    Nan::SetPrototypeMethod(ctor, "reversed", reversed);
    Nan::SetPrototypeMethod(ctor, "rotate", rotate);
    Nan::SetPrototypeMethod(ctor, "rotated", rotated);
    Nan::SetPrototypeMethod(ctor, "scale", scale);
    Nan::SetPrototypeMethod(ctor, "scaled", scaled);
    Nan::SetPrototypeMethod(ctor, "setLinearForm", setLinearForm);
    Nan::SetPrototypeMethod(ctor, "squareMagnitude", squareMagnitude);
    Nan::SetPrototypeMethod(ctor, "subtract", subtract);
    Nan::SetPrototypeMethod(ctor, "subtracted", subtracted);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("gp_Vec", &BuildWrapper);
}