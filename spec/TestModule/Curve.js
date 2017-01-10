var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Curve', () => {
  var subject;
  beforeEach(() => {
    subject = 'abstract'
  });

  it('d0(Number, Pnt', () => {
    var result = subject.d0(144, new TestModule.Pnt(145, 146, 147));

  });

  it('d1(Number, Pnt, Vec', () => {
    var result = subject.d1(148, new TestModule.Pnt(149, 150, 151), new TestModule.Vec(152, 153, 154));

  });
});