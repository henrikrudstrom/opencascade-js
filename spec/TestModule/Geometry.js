var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Geometry', () => {
  var subject;
  beforeEach(() => {
    subject = 'abstract'
  });

  it('mirrored(Pnt', () => {
    var result = subject.mirrored(new TestModule.Pnt(30, 31, 32));
    expect(result).to.be.typeOrConstructorOf('Geometry');
  });

  it('mirrored(Ax1', () => {
    var result = subject.mirrored(new TestModule.Ax1(new TestModule.Pnt(33, 34, 35), new TestModule.Dir(36, 37, 38)));
    expect(result).to.be.typeOrConstructorOf('Geometry');
  });
});