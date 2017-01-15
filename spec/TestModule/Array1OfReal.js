const chai = require('chai');
const expect = chai.expect;

var lib = require('../lib');
const TestModule = require('../../lib/TestModule.js');

describe('Array1OfReal', () => {
  it('works', () => {
    let items = [6.5, 7.5];
    let coll = new TestModule.Array1OfReal(items);
    expect(coll).to.be.typeOrConstructorOf('Array1OfReal');
    expect(coll.__cptr__()).to.be.above(0);
    expect(coll.length).to.equal(2);
    expect(coll[0]).to.eql(items[0]);
    expect(coll[1]).to.eql(items[1]);
  })
});