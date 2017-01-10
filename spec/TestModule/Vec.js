var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Vec', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.Vec(126, 127, 128)
  });

  it('Vec(Number, Number, Number', () => {
    var result = new TestModule.Vec(129, 130, 131);
    expect(result).to.be.typeOrConstructorOf('Vec');
  });

  it('Vec(Pnt, Pnt', () => {
    var result = new TestModule.Vec(new TestModule.Pnt(132, 133, 134), new TestModule.Pnt(135, 136, 137));
    expect(result).to.be.typeOrConstructorOf('Vec');
  });

  it('Vec(Dir', () => {
    var result = new TestModule.Vec(new TestModule.Dir(138, 139, 140));
    expect(result).to.be.typeOrConstructorOf('Vec');
  });

  it('Vec(', () => {
    var result = new TestModule.Vec();
    expect(result).to.be.typeOrConstructorOf('Vec');
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
    var result = subject.setX(141);

  });

  it('setY(Number', () => {
    var result = subject.setY(142);

  });

  it('setZ(Number', () => {
    var result = subject.setZ(143);

  });
});