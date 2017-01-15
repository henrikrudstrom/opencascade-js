const chai = require('chai');
const expect = chai.expect;

var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Dir', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.Dir(271.5, 272.5, 273.5)
  });

  it('New(double, double, double)', () => {
    var result = new TestModule.Dir(274.5, 275.5, 276.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New(Vec)', () => {
    var result = new TestModule.Dir(new TestModule.Vec(277.5, 278.5, 279.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New()', () => {
    var result = new TestModule.Dir();
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
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

  it('angle(Dir)', () => {
    var result = subject.angle(new TestModule.Dir(280.5, 281.5, 282.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('angleWithRef(Dir, Dir)', () => {
    var result = subject.angleWithRef(new TestModule.Dir(283.5, 284.5, 285.5), new TestModule.Dir(286.5, 287.5, 288.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('cross(Dir)', () => {
    var result = subject.cross(new TestModule.Dir(289.5, 290.5, 291.5));

  });

  it('crossCross(Dir, Dir)', () => {
    var result = subject.crossCross(new TestModule.Dir(292.5, 293.5, 294.5), new TestModule.Dir(295.5, 296.5, 297.5));

  });

  it('crossCrossed(Dir, Dir)', () => {
    var result = subject.crossCrossed(new TestModule.Dir(298.5, 299.5, 300.5), new TestModule.Dir(301.5, 302.5, 303.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('crossed(Dir)', () => {
    var result = subject.crossed(new TestModule.Dir(304.5, 305.5, 306.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('dot(Dir)', () => {
    var result = subject.dot(new TestModule.Dir(307.5, 308.5, 309.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('dotCross(Dir, Dir)', () => {
    var result = subject.dotCross(new TestModule.Dir(310.5, 311.5, 312.5), new TestModule.Dir(313.5, 314.5, 315.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('isEqual(Dir, double)', () => {
    var result = subject.isEqual(new TestModule.Dir(316.5, 317.5, 318.5), 319.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('isNormal(Dir, double)', () => {
    var result = subject.isNormal(new TestModule.Dir(320.5, 321.5, 322.5), 323.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('isOpposite(Dir, double)', () => {
    var result = subject.isOpposite(new TestModule.Dir(324.5, 325.5, 326.5), 327.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('isParallel(Dir, double)', () => {
    var result = subject.isParallel(new TestModule.Dir(328.5, 329.5, 330.5), 331.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('mirror(Dir)', () => {
    var result = subject.mirror(new TestModule.Dir(332.5, 333.5, 334.5));

  });

  it('mirror(Ax1)', () => {
    var result = subject.mirror(new TestModule.Ax1(new TestModule.Pnt(335.5, 336.5, 337.5), new TestModule.Dir(338.5, 339.5, 340.5)));

  });

  it('mirror(Ax2)', () => {
    var result = subject.mirror(new TestModule.Ax2(new TestModule.Pnt(341.5, 342.5, 343.5), new TestModule.Dir(344.5, 345.5, 346.5), new TestModule.Dir(347.5, 348.5, 349.5)));

  });

  it('mirrored(Dir)', () => {
    var result = subject.mirrored(new TestModule.Dir(350.5, 351.5, 352.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax1)', () => {
    var result = subject.mirrored(new TestModule.Ax1(new TestModule.Pnt(353.5, 354.5, 355.5), new TestModule.Dir(356.5, 357.5, 358.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax2)', () => {
    var result = subject.mirrored(new TestModule.Ax2(new TestModule.Pnt(359.5, 360.5, 361.5), new TestModule.Dir(362.5, 363.5, 364.5), new TestModule.Dir(365.5, 366.5, 367.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('reverse()', () => {
    var result = subject.reverse();

  });

  it('reversed()', () => {
    var result = subject.reversed();
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('rotate(Ax1, double)', () => {
    var result = subject.rotate(new TestModule.Ax1(new TestModule.Pnt(368.5, 369.5, 370.5), new TestModule.Dir(371.5, 372.5, 373.5)), 374.5);

  });

  it('rotated(Ax1, double)', () => {
    var result = subject.rotated(new TestModule.Ax1(new TestModule.Pnt(375.5, 376.5, 377.5), new TestModule.Dir(378.5, 379.5, 380.5)), 381.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Dir');
    expect(result.__cptr__()).to.be.above(0);
  });
});