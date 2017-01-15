const chai = require('chai');
const adhoc = require('chai-adhoc');

chai.use(adhoc);

adhoc.addAssertion('typeOrConstructorOf', function (ctx, shouldBeType) {
  function assert(isTrue, type, actualType) {
    ctx.assert(isTrue,
      `expected #{this} to be a ${type}, but it was a ${actualType}`,
      `expected #{this} to not be a ${type}`);
  }

  var type = typeof (ctx.obj);
  if (type === shouldBeType) return assert(true, shouldBeType);
  if (ctx.obj === undefined) return assert(false, shouldBeType, type);
  var type = ctx.obj.constructor.name;
  assert(type === shouldBeType, shouldBeType, type);
});