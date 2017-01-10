var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Point', () => {
  var subject;
  beforeEach(() => {
    subject = 'abstract'
  });

  it('distance(Point', () => {
    var result = subject.distance('abstract');
    expect(result).to.be.typeOrConstructorOf('Number');
  });
});