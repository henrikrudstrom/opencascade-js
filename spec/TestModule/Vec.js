const chai = require('chai');
const expect = chai.expect;

var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Vec', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.Vec(479.5, 480.5, 481.5)
  });

  it('New(double, double, double)', () => {
    var result = new TestModule.Vec(482.5, 483.5, 484.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New(Pnt, Pnt)', () => {
    var result = new TestModule.Vec(new TestModule.Pnt(485.5, 486.5, 487.5), new TestModule.Pnt(488.5, 489.5, 490.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New(Dir)', () => {
    var result = new TestModule.Vec(new TestModule.Dir(491.5, 492.5, 493.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New()', () => {
    var result = new TestModule.Vec();
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
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

  it('add(Vec)', () => {
    var result = subject.add(new TestModule.Vec(494.5, 495.5, 496.5));

  });

  it('added(Vec)', () => {
    var result = subject.added(new TestModule.Vec(497.5, 498.5, 499.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('angle(Vec)', () => {
    var result = subject.angle(new TestModule.Vec(500.5, 501.5, 502.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('angleWithRef(Vec, Vec)', () => {
    var result = subject.angleWithRef(new TestModule.Vec(503.5, 504.5, 505.5), new TestModule.Vec(506.5, 507.5, 508.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('cross(Vec)', () => {
    var result = subject.cross(new TestModule.Vec(509.5, 510.5, 511.5));

  });

  it('crossCross(Vec, Vec)', () => {
    var result = subject.crossCross(new TestModule.Vec(512.5, 513.5, 514.5), new TestModule.Vec(515.5, 516.5, 517.5));

  });

  it('crossCrossed(Vec, Vec)', () => {
    var result = subject.crossCrossed(new TestModule.Vec(518.5, 519.5, 520.5), new TestModule.Vec(521.5, 522.5, 523.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('crossMagnitude(Vec)', () => {
    var result = subject.crossMagnitude(new TestModule.Vec(524.5, 525.5, 526.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('crossSquareMagnitude(Vec)', () => {
    var result = subject.crossSquareMagnitude(new TestModule.Vec(527.5, 528.5, 529.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('crossed(Vec)', () => {
    var result = subject.crossed(new TestModule.Vec(530.5, 531.5, 532.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('divide(double)', () => {
    var result = subject.divide(533.5);

  });

  it('divided(double)', () => {
    var result = subject.divided(534.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('dot(Vec)', () => {
    var result = subject.dot(new TestModule.Vec(535.5, 536.5, 537.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('dotCross(Vec, Vec)', () => {
    var result = subject.dotCross(new TestModule.Vec(538.5, 539.5, 540.5), new TestModule.Vec(541.5, 542.5, 543.5));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('isEqual(Vec, double, double)', () => {
    var result = subject.isEqual(new TestModule.Vec(544.5, 545.5, 546.5), 547.5, 548.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('isNormal(Vec, double)', () => {
    var result = subject.isNormal(new TestModule.Vec(549.5, 550.5, 551.5), 552.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('isOpposite(Vec, double)', () => {
    var result = subject.isOpposite(new TestModule.Vec(553.5, 554.5, 555.5), 556.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('isParallel(Vec, double)', () => {
    var result = subject.isParallel(new TestModule.Vec(557.5, 558.5, 559.5), 560.5);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('magnitude()', () => {
    var result = subject.magnitude();
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('mirror(Vec)', () => {
    var result = subject.mirror(new TestModule.Vec(561.5, 562.5, 563.5));

  });

  it('mirror(Ax1)', () => {
    var result = subject.mirror(new TestModule.Ax1(new TestModule.Pnt(564.5, 565.5, 566.5), new TestModule.Dir(567.5, 568.5, 569.5)));

  });

  it('mirror(Ax2)', () => {
    var result = subject.mirror(new TestModule.Ax2(new TestModule.Pnt(570.5, 571.5, 572.5), new TestModule.Dir(573.5, 574.5, 575.5), new TestModule.Dir(576.5, 577.5, 578.5)));

  });

  it('mirrored(Vec)', () => {
    var result = subject.mirrored(new TestModule.Vec(579.5, 580.5, 581.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax1)', () => {
    var result = subject.mirrored(new TestModule.Ax1(new TestModule.Pnt(582.5, 583.5, 584.5), new TestModule.Dir(585.5, 586.5, 587.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax2)', () => {
    var result = subject.mirrored(new TestModule.Ax2(new TestModule.Pnt(588.5, 589.5, 590.5), new TestModule.Dir(591.5, 592.5, 593.5), new TestModule.Dir(594.5, 595.5, 596.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('multiplied(double)', () => {
    var result = subject.multiplied(597.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('multiply(double)', () => {
    var result = subject.multiply(598.5);

  });

  it('normalize()', () => {
    var result = subject.normalize();

  });

  it('normalized()', () => {
    var result = subject.normalized();
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('reverse()', () => {
    var result = subject.reverse();

  });

  it('reversed()', () => {
    var result = subject.reversed();
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('rotate(Ax1, double)', () => {
    var result = subject.rotate(new TestModule.Ax1(new TestModule.Pnt(599.5, 600.5, 601.5), new TestModule.Dir(602.5, 603.5, 604.5)), 605.5);

  });

  it('rotated(Ax1, double)', () => {
    var result = subject.rotated(new TestModule.Ax1(new TestModule.Pnt(606.5, 607.5, 608.5), new TestModule.Dir(609.5, 610.5, 611.5)), 612.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('scale(double)', () => {
    var result = subject.scale(613.5);

  });

  it('scaled(double)', () => {
    var result = subject.scaled(614.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('setLinearForm(double, Vec, double, Vec, double, Vec, Vec)', () => {
    var result = subject.setLinearForm(615.5, new TestModule.Vec(616.5, 617.5, 618.5), 619.5, new TestModule.Vec(620.5, 621.5, 622.5), 623.5, new TestModule.Vec(624.5, 625.5, 626.5), new TestModule.Vec(627.5, 628.5, 629.5));

  });

  it('setLinearForm(double, Vec, double, Vec, double, Vec)', () => {
    var result = subject.setLinearForm(630.5, new TestModule.Vec(631.5, 632.5, 633.5), 634.5, new TestModule.Vec(635.5, 636.5, 637.5), 638.5, new TestModule.Vec(639.5, 640.5, 641.5));

  });

  it('setLinearForm(double, Vec, double, Vec, Vec)', () => {
    var result = subject.setLinearForm(642.5, new TestModule.Vec(643.5, 644.5, 645.5), 646.5, new TestModule.Vec(647.5, 648.5, 649.5), new TestModule.Vec(650.5, 651.5, 652.5));

  });

  it('setLinearForm(double, Vec, double, Vec)', () => {
    var result = subject.setLinearForm(653.5, new TestModule.Vec(654.5, 655.5, 656.5), 657.5, new TestModule.Vec(658.5, 659.5, 660.5));

  });

  it('setLinearForm(double, Vec, Vec)', () => {
    var result = subject.setLinearForm(661.5, new TestModule.Vec(662.5, 663.5, 664.5), new TestModule.Vec(665.5, 666.5, 667.5));

  });

  it('setLinearForm(Vec, Vec)', () => {
    var result = subject.setLinearForm(new TestModule.Vec(668.5, 669.5, 670.5), new TestModule.Vec(671.5, 672.5, 673.5));

  });

  it('squareMagnitude()', () => {
    var result = subject.squareMagnitude();
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('subtract(Vec)', () => {
    var result = subject.subtract(new TestModule.Vec(674.5, 675.5, 676.5));

  });

  it('subtracted(Vec)', () => {
    var result = subject.subtracted(new TestModule.Vec(677.5, 678.5, 679.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result.__cptr__()).to.be.above(0);
  });
});