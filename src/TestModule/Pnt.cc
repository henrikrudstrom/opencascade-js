#include <TestModule/Pnt.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Pnt::constructor;
Nan::Persistent<v8::Object> TestModule::Pnt::prototype;

TestModule::Pnt::Pnt() {}
TestModule::Pnt::Pnt(gp_Pnt* wrapObj) : wrappedObject(*wrapObj) {}
TestModule::Pnt::Pnt(gp_Pnt wrapObj) : wrappedObject(wrapObj) {}

v8::Local<v8::Object> TestModule::Pnt::BuildWrapper(void* res) {
    auto obj = new Pnt(*static_cast<gp_Pnt*>(res));
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

bool TestModule::Pnt::firstCall = true;
bool TestModule::Pnt::PntOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 0) {
        return false;
    }

    auto wrapper = new TestModule::Pnt(new gp_Pnt());
    wrapper->Wrap(info.This());
    return true;
}
bool TestModule::Pnt::PntOverload2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }

    Standard_Integer argXp;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[0], argXp)) {
        return false;
    }
    Standard_Integer argYp;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[1], argYp)) {
        return false;
    }
    Standard_Integer argZp;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[2], argZp)) {
        return false;
    }

    auto wrapper = new TestModule::Pnt(new gp_Pnt(argXp, argYp, argZp));
    wrapper->Wrap(info.This());
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
    if (TestModule::Pnt::PntOverload0(info)) {
        return;
    }
    if (TestModule::Pnt::PntOverload2(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::XOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.X();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::Pnt::X) {
    if (TestModule::Pnt::XOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::YOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Y();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::Pnt::Y) {
    if (TestModule::Pnt::YOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::ZOverload0(const Nan::PropertyCallbackInfo<v8::Value>& info) {

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Z();
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_GETTER(TestModule::Pnt::Z) {
    if (TestModule::Pnt::ZOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::BaryCenterOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }

    Standard_Integer argAlpha;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[0], argAlpha)) {
        return false;
    }
    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[1], argP)) {
        return false;
    }
    Standard_Integer argBeta;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[2], argBeta)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.BaryCenter(argAlpha, argP, argBeta);

    return true;
}

NAN_METHOD(TestModule::Pnt::BaryCenter) {
    if (TestModule::Pnt::BaryCenterOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::DistanceOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Pnt argOther;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argOther)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Distance(argOther);
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_METHOD(TestModule::Pnt::Distance) {
    if (TestModule::Pnt::DistanceOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::IsEqualOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }

    gp_Pnt argOther;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argOther)) {
        return false;
    }
    Standard_Integer argLinearTolerance;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[1], argLinearTolerance)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.IsEqual(argOther, argLinearTolerance);
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_METHOD(TestModule::Pnt::IsEqual) {
    if (TestModule::Pnt::IsEqualOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::MirrorOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.Mirror(argP);

    return true;
}
bool TestModule::Pnt::MirrorOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argA1)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.Mirror(argA1);

    return true;
}

NAN_METHOD(TestModule::Pnt::Mirror) {
    if (TestModule::Pnt::MirrorOverload0(info)) {
        return;
    }
    if (TestModule::Pnt::MirrorOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::MirroredOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Mirrored(argP);
    info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    return true;
}
bool TestModule::Pnt::MirroredOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argA1)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Mirrored(argA1);
    info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    return true;
}

NAN_METHOD(TestModule::Pnt::Mirrored) {
    if (TestModule::Pnt::MirroredOverload0(info)) {
        return;
    }
    if (TestModule::Pnt::MirroredOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::RotateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }

    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argA1)) {
        return false;
    }
    Standard_Integer argAng;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[1], argAng)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.Rotate(argA1, argAng);

    return true;
}

NAN_METHOD(TestModule::Pnt::Rotate) {
    if (TestModule::Pnt::RotateOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::RotatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }

    gp_Ax1 argA1;
    if (!Util::ConvertWrappedValue<gp_Ax1>(info[0], argA1)) {
        return false;
    }
    Standard_Integer argAng;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[1], argAng)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Rotated(argA1, argAng);
    info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    return true;
}

NAN_METHOD(TestModule::Pnt::Rotated) {
    if (TestModule::Pnt::RotatedOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::ScaleOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }

    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }
    Standard_Integer argS;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[1], argS)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.Scale(argP, argS);

    return true;
}

NAN_METHOD(TestModule::Pnt::Scale) {
    if (TestModule::Pnt::ScaleOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::ScaledOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }

    gp_Pnt argP;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argP)) {
        return false;
    }
    Standard_Integer argS;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[1], argS)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Scaled(argP, argS);
    info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    return true;
}

NAN_METHOD(TestModule::Pnt::Scaled) {
    if (TestModule::Pnt::ScaledOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::SetCoordOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 2) {
        return false;
    }

    Standard_Integer argIndex;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[0], argIndex)) {
        return false;
    }
    Standard_Integer argXi;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[1], argXi)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetCoord(argIndex, argXi);

    return true;
}
bool TestModule::Pnt::SetCoordOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 3) {
        return false;
    }

    Standard_Integer argXp;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[0], argXp)) {
        return false;
    }
    Standard_Integer argYp;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[1], argYp)) {
        return false;
    }
    Standard_Integer argZp;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info[2], argZp)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetCoord(argXp, argYp, argZp);

    return true;
}

NAN_METHOD(TestModule::Pnt::SetCoord) {
    if (TestModule::Pnt::SetCoordOverload0(info)) {
        return;
    }
    if (TestModule::Pnt::SetCoordOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::SquareDistanceOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Pnt argOther;
    if (!Util::ConvertWrappedValue<gp_Pnt>(info[0], argOther)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.SquareDistance(argOther);
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_METHOD(TestModule::Pnt::SquareDistance) {
    if (TestModule::Pnt::SquareDistanceOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::TranslateOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Vec argV;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argV)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.Translate(argV);

    return true;
}
bool TestModule::Pnt::TranslateOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.Translate(argP1, argP2);

    return true;
}

NAN_METHOD(TestModule::Pnt::Translate) {
    if (TestModule::Pnt::TranslateOverload0(info)) {
        return;
    }
    if (TestModule::Pnt::TranslateOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::TranslatedOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    gp_Vec argV;
    if (!Util::ConvertWrappedValue<gp_Vec>(info[0], argV)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Translated(argV);
    info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    return true;
}
bool TestModule::Pnt::TranslatedOverload1(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    auto res = obj.Translated(argP1, argP2);
    info.GetReturnValue().Set(TestModule::Pnt::BuildWrapper((void*)&res));
    return true;
}

NAN_METHOD(TestModule::Pnt::Translated) {
    if (TestModule::Pnt::TranslatedOverload0(info)) {
        return;
    }
    if (TestModule::Pnt::TranslatedOverload1(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::SetXOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Integer argX;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info.Data(), argX)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetX(argX);

    return true;
}

NAN_SETTER(TestModule::Pnt::SetX) {
    if (TestModule::Pnt::SetXOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::SetYOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Integer argY;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info.Data(), argY)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetY(argY);

    return true;
}

NAN_SETTER(TestModule::Pnt::SetY) {
    if (TestModule::Pnt::SetYOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}
bool TestModule::Pnt::SetZOverload0(const Nan::PropertyCallbackInfo<void>& info) {

    Standard_Integer argZ;
    if (!Util::ConvertWrappedValue<Standard_Integer>(info.Data(), argZ)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Pnt>(info.Holder());
    auto obj = wrapped->wrappedObject;
    obj.SetZ(argZ);

    return true;
}

NAN_SETTER(TestModule::Pnt::SetZ) {
    if (TestModule::Pnt::SetZOverload0(info)) {
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

    Nan::SetAccessor(ctorInst, Nan::New("x").ToLocalChecked(), X, SetX);
    Nan::SetAccessor(ctorInst, Nan::New("y").ToLocalChecked(), Y, SetY);
    Nan::SetAccessor(ctorInst, Nan::New("z").ToLocalChecked(), Z, SetZ);
    Nan::SetPrototypeMethod(ctor, "baryCenter", BaryCenter);
    Nan::SetPrototypeMethod(ctor, "distance", Distance);
    Nan::SetPrototypeMethod(ctor, "isEqual", IsEqual);
    Nan::SetPrototypeMethod(ctor, "mirror", Mirror);
    Nan::SetPrototypeMethod(ctor, "mirrored", Mirrored);
    Nan::SetPrototypeMethod(ctor, "rotate", Rotate);
    Nan::SetPrototypeMethod(ctor, "rotated", Rotated);
    Nan::SetPrototypeMethod(ctor, "scale", Scale);
    Nan::SetPrototypeMethod(ctor, "scaled", Scaled);
    Nan::SetPrototypeMethod(ctor, "setCoord", SetCoord);
    Nan::SetPrototypeMethod(ctor, "squareDistance", SquareDistance);
    Nan::SetPrototypeMethod(ctor, "translate", Translate);
    Nan::SetPrototypeMethod(ctor, "translated", Translated);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("gp_Pnt", &BuildWrapper);
}