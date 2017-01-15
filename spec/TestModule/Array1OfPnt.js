const chai = require('chai');
const expect = chai.expect;

var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Array1OfPnt', () => {
  it('works', () => {
    let items = [new TestModule.Pnt(0.5, 1.5, 2.5), new TestModule.Pnt(3.5, 4.5, 5.5)];
    let coll = new TestModule.Array1OfPnt(items);
    expect(coll).to.be.typeOrConstructorOf('Array1OfPnt');
    expect(coll.__cptr__()).to.be.above(0);
    expect(coll.length).to.equal(2);
    expect(coll[0]).to.eql(items[0]);
    expect(coll[1]).to.eql(items[1]);
  })
});