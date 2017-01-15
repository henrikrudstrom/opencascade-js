const chai = require('chai');
const expect = chai.expect;

var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Ax2', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.Ax2(new TestModule.Pnt(131.5, 132.5, 133.5), new TestModule.Dir(134.5, 135.5, 136.5), new TestModule.Dir(137.5, 138.5, 139.5))
  });

  it('New(Pnt, Dir, Dir)', () => {
    var result = new TestModule.Ax2(new TestModule.Pnt(140.5, 141.5, 142.5), new TestModule.Dir(143.5, 144.5, 145.5), new TestModule.Dir(146.5, 147.5, 148.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax2');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New(Pnt, Dir)', () => {
    var result = new TestModule.Ax2(new TestModule.Pnt(149.5, 150.5, 151.5), new TestModule.Dir(152.5, 153.5, 154.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax2');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New()', () => {
    var result = new TestModule.Ax2();
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax2');
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

  it('angle(Ax2)', () => {
    var result = subject.angle(new TestModule.Ax2(new TestModule.Pnt(155.5, 156.5, 157.5), new TestModule.Dir(158.5, 159.5, 160.5), new TestModule.Dir(161.5, 162.5, 163.5)));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('axis()', () => {
    var result = subject.axis();
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('isCoplanar(Ax2, double, double)', () => {
    var result = subject.isCoplanar(new TestModule.Ax2(new TestModule.Pnt(164.5, 165.5, 166.5), new TestModule.Dir(167.5, 168.5, 169.5), new TestModule.Dir(170.5, 171.5, 172.5)), 173.5, 174.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('isCoplanar(Ax1, double, double)', () => {
    var result = subject.isCoplanar(new TestModule.Ax1(new TestModule.Pnt(175.5, 176.5, 177.5), new TestModule.Dir(178.5, 179.5, 180.5)), 181.5, 182.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('mirror(Pnt)', () => {
    var result = subject.mirror(new TestModule.Pnt(183.5, 184.5, 185.5));

  });

  it('mirror(Ax1)', () => {
    var result = subject.mirror(new TestModule.Ax1(new TestModule.Pnt(186.5, 187.5, 188.5), new TestModule.Dir(189.5, 190.5, 191.5)));

  });

  it('mirror(Ax2)', () => {
    var result = subject.mirror(new TestModule.Ax2(new TestModule.Pnt(192.5, 193.5, 194.5), new TestModule.Dir(195.5, 196.5, 197.5), new TestModule.Dir(198.5, 199.5, 200.5)));

  });

  it('mirrored(Pnt)', () => {
    var result = subject.mirrored(new TestModule.Pnt(201.5, 202.5, 203.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax2');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax1)', () => {
    var result = subject.mirrored(new TestModule.Ax1(new TestModule.Pnt(204.5, 205.5, 206.5), new TestModule.Dir(207.5, 208.5, 209.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax2');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax2)', () => {
    var result = subject.mirrored(new TestModule.Ax2(new TestModule.Pnt(210.5, 211.5, 212.5), new TestModule.Dir(213.5, 214.5, 215.5), new TestModule.Dir(216.5, 217.5, 218.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax2');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('rotate(Ax1, double)', () => {
    var result = subject.rotate(new TestModule.Ax1(new TestModule.Pnt(219.5, 220.5, 221.5), new TestModule.Dir(222.5, 223.5, 224.5)), 225.5);

  });

  it('rotated(Ax1, double)', () => {
    var result = subject.rotated(new TestModule.Ax1(new TestModule.Pnt(226.5, 227.5, 228.5), new TestModule.Dir(229.5, 230.5, 231.5)), 232.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax2');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('scale(Pnt, double)', () => {
    var result = subject.scale(new TestModule.Pnt(233.5, 234.5, 235.5), 236.5);

  });

  it('scaled(Pnt, double)', () => {
    var result = subject.scaled(new TestModule.Pnt(237.5, 238.5, 239.5), 240.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax2');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('setAxis(Ax1)', () => {
    var result = subject.setAxis(new TestModule.Ax1(new TestModule.Pnt(241.5, 242.5, 243.5), new TestModule.Dir(244.5, 245.5, 246.5)));

  });

  it('setXDirection(Dir)', () => {
    var result = subject.setXDirection(new TestModule.Dir(247.5, 248.5, 249.5));

  });

  it('setYDirection(Dir)', () => {
    var result = subject.setYDirection(new TestModule.Dir(250.5, 251.5, 252.5));

  });

  it('translate(Vec)', () => {
    var result = subject.translate(new TestModule.Vec(253.5, 254.5, 255.5));

  });

  it('translate(Pnt, Pnt)', () => {
    var result = subject.translate(new TestModule.Pnt(256.5, 257.5, 258.5), new TestModule.Pnt(259.5, 260.5, 261.5));

  });

  it('translated(Vec)', () => {
    var result = subject.translated(new TestModule.Vec(262.5, 263.5, 264.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax2');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('translated(Pnt, Pnt)', () => {
    var result = subject.translated(new TestModule.Pnt(265.5, 266.5, 267.5), new TestModule.Pnt(268.5, 269.5, 270.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax2');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('xDirection()', () => {
    var result = subject.xDirection();
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('yDirection()', () => {
    var result = subject.yDirection();
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });
});