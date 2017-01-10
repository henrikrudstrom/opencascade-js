var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Dir', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.Dir(18, 19, 20)
  });

  it('Dir(Number, Number, Number', () => {
    var result = new TestModule.Dir(21, 22, 23);
    expect(result).to.be.typeOrConstructorOf('Dir');
  });

  it('Dir(Vec', () => {
    var result = new TestModule.Dir(new TestModule.Vec(24, 25, 26));
    expect(result).to.be.typeOrConstructorOf('Dir');
  });

  it('Dir(', () => {
    var result = new TestModule.Dir();
    expect(result).to.be.typeOrConstructorOf('Dir');
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

  it('setX(Number', () => {
    var result = subject.setX(27);

  });

  it('setY(Number', () => {
    var result = subject.setY(28);

  });

  it('setZ(Number', () => {
    var result = subject.setZ(29);

  });
});