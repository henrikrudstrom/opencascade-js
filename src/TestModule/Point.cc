#include <TestModule/Point.h>

Nan::Persistent<v8::FunctionTemplate> TestModule::Point::constructor;
Nan::Persistent<v8::Object> TestModule::Point::prototype;

TestModule::Point::Point() {}
TestModule::Point::Point(Geom_Point* wrapObj) : Geometry(wrapObj) {}
TestModule::Point::Point(opencascade::handle<Geom_Point> wrapObj) : Geometry(wrapObj) {}

v8::Local<v8::Object> TestModule::Point::BuildWrapper(void* res) {
    auto obj = new Point(*static_cast<opencascade::handle<Geom_Point>*>(res));
    v8::Local<v8::Object> val =
        Nan::New(constructor)->GetFunction()->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
    obj->Wrap(val);
    return val;
}

bool TestModule::Point::firstCall = true;

NAN_METHOD(TestModule::Point::New) {}
bool TestModule::Point::DistanceOverload0(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1) {
        return false;
    }

    opencascade::handle<Geom_Point> argOther;
    if (!Util::ConvertWrappedTransientValue<Geom_Point>(info[0], argOther)) {
        return false;
    }

    auto wrapped = Nan::ObjectWrap::Unwrap<TestModule::Point>(info.Holder());
    auto obj = opencascade::handle<Geom_Point>::DownCast(wrapped->wrappedObject);
    auto res = obj->Distance(argOther);
    info.GetReturnValue().Set(Nan::New(res));
    return true;
}

NAN_METHOD(TestModule::Point::Distance) {
    if (TestModule::Point::DistanceOverload0(info)) {
        return;
    }
    Nan::ThrowError("Argument exception.");
}

NAN_MODULE_INIT(TestModule::Point::Init) {
    auto qualifiedName = Nan::New("TestModule::Point").ToLocalChecked();
    auto className = Nan::New("Point").ToLocalChecked();
    auto ctor = Nan::New<v8::FunctionTemplate>(New);
    auto ctorInst = ctor->InstanceTemplate();  // target for member functions
    ctor->SetClassName(qualifiedName);
    ctorInst->SetInternalFieldCount(1);  // for ObjectWrap, it should set 1
    ctor->Inherit(Nan::New(TestModule::Geometry::constructor));

    Nan::SetPrototypeMethod(ctor, "distance", Distance);

    Nan::Set(target, className, Nan::GetFunction(ctor).ToLocalChecked());
    v8::Local<v8::Object> obj =
        Nan::To<v8::Object>(ctor->GetFunction()->NewInstance()->GetPrototype()).ToLocalChecked();
    prototype.Reset(obj);
    constructor.Reset(ctor);

    DynamicCastMap::Register("Geom_Point", &BuildWrapper);
}