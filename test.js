var testmod = require('./lib/TestModule.js');
var pp = new testmod.Pnt(1.0, 2.0, 3.0);
console.log(pp);
var p1 = new testmod.CartesianPoint(pp);
console.log(p1);
var pp2 = new testmod.Pnt(3, 2, 1);
var p2 = new testmod.CartesianPoint(pp2);
var dist = p1.distance(p2);
console.log(dist);
// var gpp = new testmod.Pnt(1, 2, 3);
//
// try {
//     var dist2 = p1.distance(gpp);
// } catch (ex) {
//     console.log(ex);
// }
var p3 = p1.mirrored(pp2);
console.log(p3);

var line = new testmod.Line(new testmod.Pnt(1, 2, 3), new testmod.Dir(1, 0, 0));
console.log(line)
var d0 = line.d0(0.5);
console.log(d0)
var d1 = line.d1(0.333);
console.log(d1)
