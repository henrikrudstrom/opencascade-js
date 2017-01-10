var chai = require('chai'),
  adhoc = require('chai-adhoc');

chai.use(adhoc);

adhoc.addAssertion('typeOrConstructorOf', function (ctx, shouldBeType) {
  function assert(isTrue, t, type) {
    ctx.assert(isTrue, 'expected #{t} to be a #{type}', 'expected #{t} to not be a #{type}');
  }

  var type = typeof (ctx.obj);
  if (type === shouldBeType) return assert(true, type, shouldBeType);
  var type = ctx.obj.constructor.name;
  assert(type === shouldBeType, type, shouldBeType);

});