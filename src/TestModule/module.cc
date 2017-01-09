#include <nan.h>
#include <TestModule/Ax1.h>
#include <TestModule/Dir.h>
#include <TestModule/Geometry.h>
#include <TestModule/Pnt.h>
#include <TestModule/Vec.h>
#include <TestModule/Curve.h>
#include <TestModule/Point.h>
#include <TestModule/CartesianPoint.h>
#include <TestModule/Line.h>

NAN_MODULE_INIT(InitAll) {
    TestModule::Ax1::Init(target);
    TestModule::Dir::Init(target);
    TestModule::Geometry::Init(target);
    TestModule::Pnt::Init(target);
    TestModule::Vec::Init(target);
    TestModule::Curve::Init(target);
    TestModule::Point::Init(target);
    TestModule::CartesianPoint::Init(target);
    TestModule::Line::Init(target);
}

NODE_MODULE(NanObject, InitAll)