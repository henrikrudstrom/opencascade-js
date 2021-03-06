#include <TestModule/Ax1.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Ax1::constructor;
Nan::Persistent<v8::Object> TestModule::Ax1::prototype;

TestModule::Ax1::Ax1() {}
TestModule::Ax1::Ax1(gp_Ax1* wrapObj) : wrappedObject(*wrapObj) {}
TestModule::Ax1::Ax1(gp_Ax1 wrapObj) : wrappedObject(wrapObj) {}

v8::Local<v8::Object> TestModule::Ax1::BuildWrapper(void* res) {
    Nan::EscapableHandleScope scope;
    v8::TryCatch errorHandler;

    v8::Local<v8::Function> func = Nan::GetFunction(Nan::New(constructor)).ToLocalChecked();
    v8::Local<v8::Value> args[1];
    args[0] = Nan::New<v8::External>(res);
    v8::MaybeLocal<v8::Object> maybeVal = Nan::NewInstance(func, 1, args);

    return scope.Escape(maybeVal.ToLocalChecked());
}

NAN_METHOD(TestModule::Ax1::__cptr__) {
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    int addr = reinterpret_cast<std::uintptr_t>(&wrapped->wrappedObject);
    info.GetReturnValue().Set(Nan::New<v8::Int32>(addr));
}

bool TestModule::Ax1::firstCall = true;
bool TestModule::Ax1::NewOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::Ax1(new gp_Ax1());
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Ax1::NewOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }
    gp_Dir argV;
    if (!Util::ConvertWrappedValue<gp_Dir>(info[1], argV)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }

    try {
        auto wrapper = new TestModule::Ax1(new gp_Ax1(argP, argV));
        wrapper->Wrap(info.This());
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
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
    if (info.Length() == 1 && info[0]->IsExternal()) {
        auto ext = info[0].As<v8::External>()->Value();
        auto wrapper = new Ax1(*static_cast<gp_Ax1*>(ext));
        wrapper->Wrap(info.This());
        return;
    }

    if (TestModule::Ax1::NewOverload0(info)) {
        return;
    }
    if (TestModule::Ax1::NewOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::directionOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Direction();
        info.GetReturnValue().Set(TestModule::Dir::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_GETTER(TestModule::Ax1::direction) {
    if (TestModule::Ax1::directionOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::locationOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Location();
        info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_GETTER(TestModule::Ax1::location) {
    if (TestModule::Ax1::locationOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::angleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Ax1 argOther;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argOther)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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

NAN_METHOD(TestModule::Ax1::angle) {
    if (TestModule::Ax1::angleOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::isCoaxialOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Ax1 argOther;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argOther)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAngularTolerance)) {
        return false;
    }
    Standard_Real argLinearTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[2], argLinearTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.IsCoaxial(argOther, argAngularTolerance, argLinearTolerance);
        info.GetReturnValue().Set(Nan::New(res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Ax1::isCoaxial) {
    if (TestModule::Ax1::isCoaxialOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::isNormalOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Ax1 argOther;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argOther)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAngularTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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

NAN_METHOD(TestModule::Ax1::isNormal) {
    if (TestModule::Ax1::isNormalOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::isOppositeOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Ax1 argOther;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argOther)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAngularTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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

NAN_METHOD(TestModule::Ax1::isOpposite) {
    if (TestModule::Ax1::isOppositeOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::isParallelOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }
    Nan::TryCatch errorHandler;
    gp_Ax1 argOther;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argOther)) {
        return false;
    }
    Standard_Real argAngularTolerance;
    if (!Util::ConvertWrappedValue<Standard_Real>(info[1], argAngularTolerance)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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

NAN_METHOD(TestModule::Ax1::isParallel) {
    if (TestModule::Ax1::isParallelOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::mirrorOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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
bool TestModule::Ax1::mirrorOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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
bool TestModule::Ax1::mirrorOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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

NAN_METHOD(TestModule::Ax1::mirror) {
    if (TestModule::Ax1::mirrorOverload0(info)) {
        return;
    }
    if (TestModule::Ax1::mirrorOverload1(info)) {
        return;
    }
    if (TestModule::Ax1::mirrorOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::mirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argP);
        info.GetReturnValue().Set(TestModule::Ax1::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Ax1::mirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argA1);
        info.GetReturnValue().Set(TestModule::Ax1::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Ax1::mirroredOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Mirrored(argA2);
        info.GetReturnValue().Set(TestModule::Ax1::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Ax1::mirrored) {
    if (TestModule::Ax1::mirroredOverload0(info)) {
        return;
    }
    if (TestModule::Ax1::mirroredOverload1(info)) {
        return;
    }
    if (TestModule::Ax1::mirroredOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::reverseOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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

NAN_METHOD(TestModule::Ax1::reverse) {
    if (TestModule::Ax1::reverseOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::reversedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }
    Nan::TryCatch errorHandler;

    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Reversed();
        info.GetReturnValue().Set(TestModule::Ax1::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Ax1::reversed) {
    if (TestModule::Ax1::reversedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::rotateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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

NAN_METHOD(TestModule::Ax1::rotate) {
    if (TestModule::Ax1::rotateOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::rotatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Rotated(argA1, argAng);
        info.GetReturnValue().Set(TestModule::Ax1::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Ax1::rotated) {
    if (TestModule::Ax1::rotatedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::scaleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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

NAN_METHOD(TestModule::Ax1::scale) {
    if (TestModule::Ax1::scaleOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::scaledOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Scaled(argP, argS);
        info.GetReturnValue().Set(TestModule::Ax1::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Ax1::scaled) {
    if (TestModule::Ax1::scaledOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::translateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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
bool TestModule::Ax1::translateOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
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

NAN_METHOD(TestModule::Ax1::translate) {
    if (TestModule::Ax1::translateOverload0(info)) {
        return;
    }
    if (TestModule::Ax1::translateOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::translatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Translated(argV);
        info.GetReturnValue().Set(TestModule::Ax1::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}
bool TestModule::Ax1::translatedOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        auto res = obj.Translated(argP1, argP2);
        info.GetReturnValue().Set(TestModule::Ax1::BuildWrapper((void*)&res));
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_METHOD(TestModule::Ax1::translated) {
    if (TestModule::Ax1::translatedOverload0(info)) {
        return;
    }
    if (TestModule::Ax1::translatedOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::setDirectionOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    gp_Dir argV;
    if (!Util::ConvertWrappedValue<gp_Dir>(info.Data(), argV)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.SetDirection(argV);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_SETTER(TestModule::Ax1::setDirection) {
    if (TestModule::Ax1::setDirectionOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Ax1::setLocationOverload0(const Nan::PropertyCallbackInfo<void>& info) {
    Nan::TryCatch errorHandler;
    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info.Data(), argP)) {
        return false;
    }
    if (errorHandler.HasCaught()) {
        return false;
    }
    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Ax1>(info.Holder());
    auto obj = wrapped->wrappedObject;
    if (errorHandler.HasCaught()) {
        return false;
    }
    try {
        obj.SetLocation(argP);
        Nan::HandleScope scope;
        auto returnValue = Nan::New<v8::Object>();

        info.GetReturnValue().Set(returnValue);
    } catch (...) {
        Nan::ThrowError(Nan::New("Error occured in native call.").ToLocalChecked());
        return true;
    }
    return true;
}

NAN_SETTER(TestModule::Ax1::setLocation) {
    if (TestModule::Ax1::setLocationOverload0(info)) {
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

    Nan::SetPrototypeMethod(ctor, "__cptr__", __cptr__);
    Nan::SetAccessor(ctorInst, Nan::New("direction").ToLocalChecked(), direction, setDirection);
    Nan::SetAccessor(ctorInst, Nan::New("location").ToLocalChecked(), location, setLocation);
    Nan::SetPrototypeMethod(ctor, "angle", angle);
    Nan::SetPrototypeMethod(ctor, "isCoaxial", isCoaxial);
    Nan::SetPrototypeMethod(ctor, "isNormal", isNormal);
    Nan::SetPrototypeMethod(ctor, "isOpposite", isOpposite);
    Nan::SetPrototypeMethod(ctor, "isParallel", isParallel);
    Nan::SetPrototypeMethod(ctor, "mirror", mirror);
    Nan::SetPrototypeMethod(ctor, "mirrored", mirrored);
    Nan::SetPrototypeMethod(ctor, "reverse", reverse);
    Nan::SetPrototypeMethod(ctor, "reversed", reversed);
    Nan::SetPrototypeMethod(ctor, "rotate", rotate);
    Nan::SetPrototypeMethod(ctor, "rotated", rotated);
    Nan::SetPrototypeMethod(ctor, "scale", scale);
    Nan::SetPrototypeMethod(ctor, "scaled", scaled);
    Nan::SetPrototypeMethod(ctor, "translate", translate);
    Nan::SetPrototypeMethod(ctor, "translated", translated);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("gp_Ax1", &BuildWrapper);
}