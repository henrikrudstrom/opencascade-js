var tm = require('./lib/TestModule.js');
var p = tm.Pnt(23,24,25);
var ax = new tm.Ax1(new tm.Pnt(42, 43, 44), new tm.Dir(45, 46, 47));
p.mirror(ax)
