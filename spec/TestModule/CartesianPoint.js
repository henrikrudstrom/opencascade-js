const chai = require('chai');
const expect = chai.expect;

var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('CartesianPoint', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.CartesianPoint(680.5, 681.5, 682.5)
  });

  it('New(double, double, double)', () => {
    var result = new TestModule.CartesianPoint(683.5, 684.5, 685.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::CartesianPoint');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New(Pnt)', () => {
    var result = new TestModule.CartesianPoint(new TestModule.Pnt(686.5, 687.5, 688.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::CartesianPoint');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('x', () => {
    var result = subject.x;
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('y', () => {
    var result = subject.y;
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('z', () => {
    var result = subject.z;
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('distance(Point)', () => {
    var result = subject.distance('abstract');
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('mirrored(Pnt)', () => {
    var result = subject.mirrored(new TestModule.Pnt(689.5, 690.5, 691.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::CartesianPoint');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax1)', () => {
    var result = subject.mirrored(new TestModule.Ax1(new TestModule.Pnt(692.5, 693.5, 694.5), new TestModule.Dir(695.5, 696.5, 697.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::CartesianPoint');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax2)', () => {
    var result = subject.mirrored(new TestModule.Ax2(new TestModule.Pnt(698.5, 699.5, 700.5), new TestModule.Dir(701.5, 702.5, 703.5), new TestModule.Dir(704.5, 705.5, 706.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::CartesianPoint');
    expect(result.__cptr__()).to.be.above(0);
  });
});