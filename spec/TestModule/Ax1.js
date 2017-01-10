var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Ax1', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.Ax1(new TestModule.Pnt(0, 1, 2), new TestModule.Dir(3, 4, 5))
  });

  it('Ax1(Pnt, Dir', () => {
    var result = new TestModule.Ax1(new TestModule.Pnt(6, 7, 8), new TestModule.Dir(9, 10, 11));
    expect(result).to.be.typeOrConstructorOf('Ax1');
  });

  it('Ax1(', () => {
    var result = new TestModule.Ax1();
    expect(result).to.be.typeOrConstructorOf('Ax1');
  });

  it('setDirection(Dir', () => {
    var result = subject.setDirection(new TestModule.Dir(12, 13, 14));

  });

  it('setLocation(Pnt', () => {
    var result = subject.setLocation(new TestModule.Pnt(15, 16, 17));

  });
});