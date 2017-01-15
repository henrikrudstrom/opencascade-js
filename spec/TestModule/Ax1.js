const chai = require('chai');
const expect = chai.expect;

var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Ax1', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.Ax1(new TestModule.Pnt(8.5, 9.5, 10.5), new TestModule.Dir(11.5, 12.5, 13.5))
  });

  it('New(Pnt, Dir)', () => {
    var result = new TestModule.Ax1(new TestModule.Pnt(14.5, 15.5, 16.5), new TestModule.Dir(17.5, 18.5, 19.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New()', () => {
    var result = new TestModule.Ax1();
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('direction', () => {
    var result = subject.direction;
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('location', () => {
    var result = subject.location;
    expect(result).to.be.typeOrConstructorOf('TestModule::Pnt');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('angle(Ax1)', () => {
    var result = subject.angle(new TestModule.Ax1(new TestModule.Pnt(20.5, 21.5, 22.5), new TestModule.Dir(23.5, 24.5, 25.5)));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('isCoaxial(Ax1, double, double)', () => {
    var result = subject.isCoaxial(new TestModule.Ax1(new TestModule.Pnt(26.5, 27.5, 28.5), new TestModule.Dir(29.5, 30.5, 31.5)), 32.5, 33.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('isNormal(Ax1, double)', () => {
    var result = subject.isNormal(new TestModule.Ax1(new TestModule.Pnt(34.5, 35.5, 36.5), new TestModule.Dir(37.5, 38.5, 39.5)), 40.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('isOpposite(Ax1, double)', () => {
    var result = subject.isOpposite(new TestModule.Ax1(new TestModule.Pnt(41.5, 42.5, 43.5), new TestModule.Dir(44.5, 45.5, 46.5)), 47.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('isParallel(Ax1, double)', () => {
    var result = subject.isParallel(new TestModule.Ax1(new TestModule.Pnt(48.5, 49.5, 50.5), new TestModule.Dir(51.5, 52.5, 53.5)), 54.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('mirror(Pnt)', () => {
    var result = subject.mirror(new TestModule.Pnt(55.5, 56.5, 57.5));

  });

  it('mirror(Ax1)', () => {
    var result = subject.mirror(new TestModule.Ax1(new TestModule.Pnt(58.5, 59.5, 60.5), new TestModule.Dir(61.5, 62.5, 63.5)));

  });

  it('mirror(Ax2)', () => {
    var result = subject.mirror(new TestModule.Ax2(new TestModule.Pnt(64.5, 65.5, 66.5), new TestModule.Dir(67.5, 68.5, 69.5), new TestModule.Dir(70.5, 71.5, 72.5)));

  });

  it('mirrored(Pnt)', () => {
    var result = subject.mirrored(new TestModule.Pnt(73.5, 74.5, 75.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax1)', () => {
    var result = subject.mirrored(new TestModule.Ax1(new TestModule.Pnt(76.5, 77.5, 78.5), new TestModule.Dir(79.5, 80.5, 81.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax2)', () => {
    var result = subject.mirrored(new TestModule.Ax2(new TestModule.Pnt(82.5, 83.5, 84.5), new TestModule.Dir(85.5, 86.5, 87.5), new TestModule.Dir(88.5, 89.5, 90.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('reverse()', () => {
    var result = subject.reverse();

  });

  it('reversed()', () => {
    var result = subject.reversed();
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('rotate(Ax1, double)', () => {
    var result = subject.rotate(new TestModule.Ax1(new TestModule.Pnt(91.5, 92.5, 93.5), new TestModule.Dir(94.5, 95.5, 96.5)), 97.5);

  });

  it('rotated(Ax1, double)', () => {
    var result = subject.rotated(new TestModule.Ax1(new TestModule.Pnt(98.5, 99.5, 100.5), new TestModule.Dir(101.5, 102.5, 103.5)), 104.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('scale(Pnt, double)', () => {
    var result = subject.scale(new TestModule.Pnt(105.5, 106.5, 107.5), 108.5);

  });

  it('scaled(Pnt, double)', () => {
    var result = subject.scaled(new TestModule.Pnt(109.5, 110.5, 111.5), 112.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('translate(Vec)', () => {
    var result = subject.translate(new TestModule.Vec(113.5, 114.5, 115.5));

  });

  it('translate(Pnt, Pnt)', () => {
    var result = subject.translate(new TestModule.Pnt(116.5, 117.5, 118.5), new TestModule.Pnt(119.5, 120.5, 121.5));

  });

  it('translated(Vec)', () => {
    var result = subject.translated(new TestModule.Vec(122.5, 123.5, 124.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('translated(Pnt, Pnt)', () => {
    var result = subject.translated(new TestModule.Pnt(125.5, 126.5, 127.5), new TestModule.Pnt(128.5, 129.5, 130.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });
});