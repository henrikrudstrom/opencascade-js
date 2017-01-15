#include <TestModule/Pnt.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Pnt::constructor;
Nan::Persistent<v8::Object> TestModule::Pnt::prototype;

TestModule::Pnt::Pnt() {}
TestModule::Pnt::Pnt(gp_Pnt* wrapObj) : wrappedObject(*wrapObj) {}
TestModule::Pnt::Pnt(gp_Pnt wrapObj) : wrappedObject(wrapObj) {}

v8::Local<v8::Object> TestModule::Pnt::BuildWrapper(void* res) {
    Nan::EscapableHandleScope scope;
    v8::TryCatch errorHandler;

    v8::Local<v8::Function> func = Nan::GetFunction(Nan::New(constructor)).ToLocalChecked();
    v8::Local<v8::Value> args[1];
    args[0] = Nan::New<v8::External>(res);
    v8::MaybeLocal<v8::Object> maybeVal = Nan::NewInstance(func, 1, args);

    return scope.Escape(maybeVal.ToLocalChecked());
}

NAN_METHOD(TestModule::Pnt::__cptr__) {
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    int addr = reinterpret_cast<std::uintptr_t>(&wrapped->wrappedObject);
    info.GetReturnValue().Set(Nan::New<v8::Int32>(addr));
}

bool TestModule::Pnt::firstCall = true;
bool TestModule::Pnt::NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::Pnt(new gp_Pnt());
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Pnt::NewOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argXp;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argXp)) {
        return false;
    }
    Standard_Real argYp;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argYp)) {
        return false;
    }
    Standard_Real argZp;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[2], argZp)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::Pnt(new gp_Pnt(argXp, argYp, argZp));
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Pnt::New) {
    if (!info.IsConstructCall()) {
        std::vector<v8::Local<v8::Value> > args(info.Length());
        for (std::size_t i = 0; i < args.size(); ++i) args[i] = info[i];
        auto inst = Nan::NewInstance(info.Callee(), args.size(), args.data());
        if (!inst.IsEmpty()) info.GetReturnValue().Set(inst.ToLocalChecked());
        return;
    }
    if (firstCall) {
        auto wrapper = new Pnt();
        wrapper->Wrap(info.This());
        firstCall = false;
        return;
    }
    if (info.Length() == 1 && info[0]->IsExternal()) {
        auto ext = info[0].As<v8::External>()->Value();
        auto wrapper = new Pnt(*static_cast<gp_Pnt*>(ext));
        wrapper->Wrap(info.This());
        return;
    }

    if (TestModule::Pnt::NewOverload0(info)) {
        return;
    }
    if (TestModule::Pnt::NewOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::xOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
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

NAN_GETTER(TestModule::Pnt::x) {
    if (TestModule::Pnt::xOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::yOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
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

NAN_GETTER(TestModule::Pnt::y) {
    if (TestModule::Pnt::yOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::zOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
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

NAN_GETTER(TestModule::Pnt::z) {
    if (TestModule::Pnt::zOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::baryCenterOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }
    Nan::TryCatch errorHandler;
    Standard_Real argAlpha;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[0], argAlpha)) {
        return false;
    }
    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[1], argP)) {
        return false;
    }
    Standard_Real argBeta;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[2], argBeta)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.BaryCenter(argAlpha, argP, argBeta);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Pnt::baryCenter) {
    if (TestModule::Pnt::baryCenterOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::distanceOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Pnt argOther;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argOther)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Distance(argOther);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Pnt::distance) {
    if (TestModule::Pnt::distanceOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::isEqualOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Pnt argOther;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argOther)) {
        return false;
    }
    Standard_Real argLinearTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argLinearTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.IsEqual(argOther, argLinearTolerance);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Pnt::isEqual) {
    if (TestModule::Pnt::isEqualOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::mirrorOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Mirror(argP);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Pnt::mirrorOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
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
bool TestModule::Pnt::mirrorOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
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

NAN_METHOD(TestModule::Pnt::mirror) {
    if (TestModule::Pnt::mirrorOverload0(info)) {
        return;
    }
    if (TestModule::Pnt::mirrorOverload1(info)) {
        return;
    }
    if (TestModule::Pnt::mirrorOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::mirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argP);
        info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Pnt::mirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argA1);
        info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Pnt::mirroredOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argA2);
        info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Pnt::mirrored) {
    if (TestModule::Pnt::mirroredOverload0(info)) {
        return;
    }
    if (TestModule::Pnt::mirroredOverload1(info)) {
        return;
    }
    if (TestModule::Pnt::mirroredOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::rotateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
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

NAN_METHOD(TestModule::Pnt::rotate) {
    if (TestModule::Pnt::rotateOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::rotatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Rotated(argA1, argAng);
        info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Pnt::rotated) {
    if (TestModule::Pnt::rotatedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::scaleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }
    Standard_Real argS;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argS)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Scale(argP, argS);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Pnt::scale) {
    if (TestModule::Pnt::scaleOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::scaledOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }
    Standard_Real argS;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argS)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Scaled(argP, argS);
        info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Pnt::scaled) {
    if (TestModule::Pnt::scaledOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::squareDistanceOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Pnt argOther;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argOther)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.SquareDistance(argOther);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Pnt::squareDistance) {
    if (TestModule::Pnt::squareDistanceOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::translateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Translate(argV);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Pnt::translateOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.Translate(argP1, argP2);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Pnt::translate) {
    if (TestModule::Pnt::translateOverload0(info)) {
        return;
    }
    if (TestModule::Pnt::translateOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::translatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Translated(argV);
        info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Pnt::translatedOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Translated(argP1, argP2);
        info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Pnt::translated) {
    if (TestModule::Pnt::translatedOverload0(info)) {
        return;
    }
    if (TestModule::Pnt::translatedOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::setXOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argX;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argX)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
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

NAN_SETTER(TestModule::Pnt::setX) {
    if (TestModule::Pnt::setXOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::setYOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argY;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argY)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
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

NAN_SETTER(TestModule::Pnt::setY) {
    if (TestModule::Pnt::setYOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::setZOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    Standard_Real argZ;
    if (!Util::ConvertWrappedValue<Standard_Real>(info.Data(), argZ)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
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

NAN_SETTER(TestModule::Pnt::setZ) {
    if (TestModule::Pnt::setZOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}

NAN_MODULE_INIT(TestModule::Pnt::Init) {
    auto qualifiedName = Nan::New("TestModule::Pnt").ToLocalChecked();
    auto className = Nan::New("Pnt").ToLocalChecked();
    auto ctor = Nan::New<v8::FunctionTemplate>(New);
    auto ctorInst = ctor->InstanceTemplate();  // target for member functions
    ctor->SetClassName(qualifiedName);
    ctorInst->SetInternalFieldCount(1);  // for ObjectWrap, it should set 1

    Nan::SetPrototypeMethod(ctor, "__cptr__", __cptr__);
    Nan::SetAccessor(ctorInst, Nan::New("x").ToLocalChecked(), x, setX);
    Nan::SetAccessor(ctorInst, Nan::New("y").ToLocalChecked(), y, setY);
    Nan::SetAccessor(ctorInst, Nan::New("z").ToLocalChecked(), z, setZ);
    Nan::SetPrototypeMethod(ctor, "baryCenter", baryCenter);
    Nan::SetPrototypeMethod(ctor, "distance", distance);
    Nan::SetPrototypeMethod(ctor, "isEqual", isEqual);
    Nan::SetPrototypeMethod(ctor, "mirror", mirror);
    Nan::SetPrototypeMethod(ctor, "mirrored", mirrored);
    Nan::SetPrototypeMethod(ctor, "rotate", rotate);
    Nan::SetPrototypeMethod(ctor, "rotated", rotated);
    Nan::SetPrototypeMethod(ctor, "scale", scale);
    Nan::SetPrototypeMethod(ctor, "scaled", scaled);
    Nan::SetPrototypeMethod(ctor, "squareDistance", squareDistance);
    Nan::SetPrototypeMethod(ctor, "translate", translate);
    Nan::SetPrototypeMethod(ctor, "translated", translated);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("gp_Pnt", &BuildWrapper);
}