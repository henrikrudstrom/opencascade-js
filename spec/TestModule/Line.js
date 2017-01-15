const chai = require('chai');
const expect = chai.expect;

var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Line', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.Line(new TestModule.Pnt(707.5, 708.5, 709.5), new TestModule.Dir(710.5, 711.5, 712.5))
  });

  it('makeLine(Ax1)', () => {
    var result = TestModule.Line.makeLine(new TestModule.Ax1(new TestModule.Pnt(713.5, 714.5, 715.5), new TestModule.Dir(716.5, 717.5, 718.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Line');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('makeLine(Pnt, Dir)', () => {
    var result = TestModule.Line.makeLine(new TestModule.Pnt(719.5, 720.5, 721.5), new TestModule.Dir(722.5, 723.5, 724.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Line');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('makeLine(Pnt, Pnt)', () => {
    var result = TestModule.Line.makeLine(new TestModule.Pnt(725.5, 726.5, 727.5), new TestModule.Pnt(728.5, 729.5, 730.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Line');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New(Pnt, Dir)', () => {
    var result = new TestModule.Line(new TestModule.Pnt(731.5, 732.5, 733.5), new TestModule.Dir(734.5, 735.5, 736.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Line');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('New(Ax1)', () => {
    var result = new TestModule.Line(new TestModule.Ax1(new TestModule.Pnt(737.5, 738.5, 739.5), new TestModule.Dir(740.5, 741.5, 742.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Line');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('position', () => {
    var result = subject.position;
    expect(result).to.be.typeOrConstructorOf('TestModule::Ax1');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('d0(double)', () => {
    var result = subject.d0(743.5);
    expect(result).to.be.typeOrConstructorOf('TestModule::Pnt');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('d1(double)', () => {
    var result = subject.d1(744.5);
    expect(result['P']).to.be.typeOrConstructorOf('TestModule::Pnt');
    expect(result['P'].__cptr__()).to.be.above(0);
    expect(result['V1']).to.be.typeOrConstructorOf('TestModule::Vec');
    expect(result['V1'].__cptr__()).to.be.above(0);
  });

  it('mirrored(Pnt)', () => {
    var result = subject.mirrored(new TestModule.Pnt(745.5, 746.5, 747.5));
    expect(result).to.be.typeOrConstructorOf('TestModule::Line');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax1)', () => {
    var result = subject.mirrored(new TestModule.Ax1(new TestModule.Pnt(748.5, 749.5, 750.5), new TestModule.Dir(751.5, 752.5, 753.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Line');
    expect(result.__cptr__()).to.be.above(0);
  });

  it('mirrored(Ax2)', () => {
    var result = subject.mirrored(new TestModule.Ax2(new TestModule.Pnt(754.5, 755.5, 756.5), new TestModule.Dir(757.5, 758.5, 759.5), new TestModule.Dir(760.5, 761.5, 762.5)));
    expect(result).to.be.typeOrConstructorOf('TestModule::Line');
    expect(result.__cptr__()).to.be.above(0);
  });
});