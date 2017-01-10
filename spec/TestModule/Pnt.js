var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Pnt', () => {
  var subject;
  beforeEach(() => {
    subject = new TestModule.Pnt(39, 40, 41)
  });

  it('Pnt(Number, Number, Number', () => {
    var result = new TestModule.Pnt(42, 43, 44);
    expect(result).to.be.typeOrConstructorOf('Pnt');
  });

  it('Pnt(', () => {
    var result = new TestModule.Pnt();
    expect(result).to.be.typeOrConstructorOf('Pnt');
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

  it('baryCenter(Number, Pnt, Number', () => {
    var result = subject.baryCenter(45, new TestModule.Pnt(46, 47, 48), 49);

  });

  it('distance(Pnt', () => {
    var result = subject.distance(new TestModule.Pnt(50, 51, 52));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('isEqual(Pnt, Number', () => {
    var result = subject.isEqual(new TestModule.Pnt(53, 54, 55), 56);
    expect(result).to.be.typeOrConstructorOf('Boolean');
  });

  it('mirror(Pnt', () => {
    var result = subject.mirror(new TestModule.Pnt(57, 58, 59));

  });

  it('mirror(Ax1', () => {
    var result = subject.mirror(new TestModule.Ax1(new TestModule.Pnt(60, 61, 62), new TestModule.Dir(63, 64, 65)));

  });

  it('mirrored(Pnt', () => {
    var result = subject.mirrored(new TestModule.Pnt(66, 67, 68));
    expect(result).to.be.typeOrConstructorOf('Pnt');
  });

  it('mirrored(Ax1', () => {
    var result = subject.mirrored(new TestModule.Ax1(new TestModule.Pnt(69, 70, 71), new TestModule.Dir(72, 73, 74)));
    expect(result).to.be.typeOrConstructorOf('Pnt');
  });

  it('rotate(Ax1, Number', () => {
    var result = subject.rotate(new TestModule.Ax1(new TestModule.Pnt(75, 76, 77), new TestModule.Dir(78, 79, 80)), 81);

  });

  it('rotated(Ax1, Number', () => {
    var result = subject.rotated(new TestModule.Ax1(new TestModule.Pnt(82, 83, 84), new TestModule.Dir(85, 86, 87)), 88);
    expect(result).to.be.typeOrConstructorOf('Pnt');
  });

  it('scale(Pnt, Number', () => {
    var result = subject.scale(new TestModule.Pnt(89, 90, 91), 92);

  });

  it('scaled(Pnt, Number', () => {
    var result = subject.scaled(new TestModule.Pnt(93, 94, 95), 96);
    expect(result).to.be.typeOrConstructorOf('Pnt');
  });

  // it('setCoord(Number, Number', () => {
  //   var result = subject.setCoord(97, 98);

  // });

  // it('setCoord(Number, Number, Number', () => {
  //   var result = subject.setCoord(99, 100, 101);

  // });

  it('squareDistance(Pnt', () => {
    var result = subject.squareDistance(new TestModule.Pnt(102, 103, 104));
    expect(result).to.be.typeOrConstructorOf('Number');
  });

  it('translate(Vec', () => {
    var result = subject.translate(new TestModule.Vec(105, 106, 107));

  });

  it('translate(Pnt, Pnt', () => {
    var result = subject.translate(new TestModule.Pnt(108, 109, 110), new TestModule.Pnt(111, 112, 113));

  });

  it('translated(Vec', () => {
    var result = subject.translated(new TestModule.Vec(114, 115, 116));
    expect(result).to.be.typeOrConstructorOf('Pnt');
  });

  it('translated(Pnt, Pnt', () => {
    var result = subject.translated(new TestModule.Pnt(117, 118, 119), new TestModule.Pnt(120, 121, 122));
    expect(result).to.be.typeOrConstructorOf('Pnt');
  });

  it('setX(Number', () => {
    var result = subject.setX(123);

  });

  it('setY(Number', () => {
    var result = subject.setY(124);

  });

  it('setZ(Number', () => {
    var result = subject.setZ(125);

  });
});