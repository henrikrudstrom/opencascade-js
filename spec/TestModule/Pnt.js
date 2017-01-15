const chai = require('chai');
const expect = chai.expect;

var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Pnt', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.Pnt(382.5, 383.5, 384.5)
  });

  it('New(double, double, double)', () => {
    var result = new TestModule.Pnt(385.5, 386.5, 387.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Pnt');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New()', () => {
    var result = new TestModule.Pnt();
    expect(result).to.be.typeOrConstructorOf('TestModule::Pnt');
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

  it('baryCenter(double, Pnt, double)', () => {
    var result = subject.baryCenter(388.5, new TestModule.Pnt(389.5, 390.5, 391.5), 392.5);

  });

  it('distance(Pnt)', () => {
    var result = subject.distance(new TestModule.Pnt(393.5, 394.5, 395.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('isEqual(Pnt, double)', () => {
    var result = subject.isEqual(new TestModule.Pnt(396.5, 397.5, 398.5), 399.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('mirror(Pnt)', () => {
    var result = subject.mirror(new TestModule.Pnt(400.5, 401.5, 402.5));

  });

  it('mirror(Ax1)', () => {
    var result = subject.mirror(new TestModule.Ax1(new TestModule.Pnt(403.5, 404.5, 405.5), new TestModule.Dir(406.5, 407.5, 408.5)));

  });

  it('mirror(Ax2)', () => {
    var result = subject.mirror(new TestModule.Ax2(new TestModule.Pnt(409.5, 410.5, 411.5), new TestModule.Dir(412.5, 413.5, 414.5), new TestModule.Dir(415.5, 416.5, 417.5)));

  });

  it('mirrored(Pnt)', () => {
    var result = subject.mirrored(new TestModule.Pnt(418.5, 419.5, 420.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Pnt');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax1)', () => {
    var result = subject.mirrored(new TestModule.Ax1(new TestModule.Pnt(421.5, 422.5, 423.5), new TestModule.Dir(424.5, 425.5, 426.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Pnt');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax2)', () => {
    var result = subject.mirrored(new TestModule.Ax2(new TestModule.Pnt(427.5, 428.5, 429.5), new TestModule.Dir(430.5, 431.5, 432.5), new TestModule.Dir(433.5, 434.5, 435.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Pnt');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('rotate(Ax1, double)', () => {
    var result = subject.rotate(new TestModule.Ax1(new TestModule.Pnt(436.5, 437.5, 438.5), new TestModule.Dir(439.5, 440.5, 441.5)), 442.5);

  });

  it('rotated(Ax1, double)', () => {
    var result = subject.rotated(new TestModule.Ax1(new TestModule.Pnt(443.5, 444.5, 445.5), new TestModule.Dir(446.5, 447.5, 448.5)), 449.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Pnt');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('scale(Pnt, double)', () => {
    var result = subject.scale(new TestModule.Pnt(450.5, 451.5, 452.5), 453.5);

  });

  it('scaled(Pnt, double)', () => {
    var result = subject.scaled(new TestModule.Pnt(454.5, 455.5, 456.5), 457.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Pnt');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('squareDistance(Pnt)', () => {
    var result = subject.squareDistance(new TestModule.Pnt(458.5, 459.5, 460.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('translate(Vec)', () => {
    var result = subject.translate(new TestModule.Vec(461.5, 462.5, 463.5));

  });

  it('translate(Pnt, Pnt)', () => {
    var result = subject.translate(new TestModule.Pnt(464.5, 465.5, 466.5), new TestModule.Pnt(467.5, 468.5, 469.5));

  });

  it('translated(Vec)', () => {
    var result = subject.translated(new TestModule.Vec(470.5, 471.5, 472.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Pnt');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('translated(Pnt, Pnt)', () => {
    var result = subject.translated(new TestModule.Pnt(473.5, 474.5, 475.5), new TestModule.Pnt(476.5, 477.5, 478.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Pnt');
    expect(result.__cptr__()).to.be.above(0);
  });
});