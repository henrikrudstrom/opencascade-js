#include <TestModule/Ax1.h>
#include <TestModule/Ax2.h>
#include <TestModule/CartesianPoint.h>
#include <TestModule/Curve.h>
#include <TestModule/Dir.h>
#include <TestModule/Geometry.h>
#include <TestModule/Line.h>
#include <TestModule/Pnt.h>
#include <TestModule/Point.h>
#include <TestModule/Vec.h>
#include <common/Array1.h>
#include <common/Array1.h>
#include <nan.h>

NAN_MODULE_INIT(InitAll) {
    Array1<TestModule::Pnt>::Init(target);
    Array1<double>::Init(target);
    TestModule::Ax1::Init(target);
    TestModule::Ax2::Init(target);
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