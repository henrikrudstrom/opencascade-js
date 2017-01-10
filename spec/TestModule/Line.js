var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Line', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.Line(new TestModule.Pnt(167, 168, 169), new TestModule.Dir(170, 171, 172))
  });

  it('Line(Pnt, Dir', () => {
    var result = new TestModule.Line(new TestModule.Pnt(173, 174, 175), new TestModule.Dir(176, 177, 178));
    expect(result).to.be.typeOrConstructorOf('Line');
  });

  it('Line(Ax1', () => {
    var result = new TestModule.Line(new TestModule.Ax1(new TestModule.Pnt(179, 180, 181), new TestModule.Dir(182, 183, 184)));
    expect(result).to.be.typeOrConstructorOf('Line');
  });

  it('setPosition(Ax1', () => {
    var result = subject.setPosition(new TestModule.Ax1(new TestModule.Pnt(185, 186, 187), new TestModule.Dir(188, 189, 190)));

  });
});