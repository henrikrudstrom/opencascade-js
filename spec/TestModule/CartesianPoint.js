var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('CartesianPoint', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.CartesianPoint(155, 156, 157)
  });

  it('CartesianPoint(Number, Number, Number', () => {
    var result = new TestModule.CartesianPoint(158, 159, 160);
    expect(result).to.be.typeOrConstructorOf('CartesianPoint');
  });

  it('CartesianPoint(Pnt', () => {
    var result = new TestModule.CartesianPoint(new TestModule.Pnt(161, 162, 163));
    expect(result).to.be.typeOrConstructorOf('CartesianPoint');
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
    var result = subject.setX(164);

  });

  it('setY(Number', () => {
    var result = subject.setY(165);

  });

  it('setZ(Number', () => {
    var result = subject.setZ(166);

  });
});