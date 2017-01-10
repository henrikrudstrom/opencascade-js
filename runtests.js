const glob = require('glob');
var Mocha = require('mocha'),
  fs = require('fs'),
  path = require('path');

var mocha = new Mocha({
  //ui: 'tdd'
  reporter: 'spec'
});

glob.sync('spec/**/*.js').forEach(file => {
  mocha.addFile(
    path.join(__dirname, file)
  );  
})


mocha.run(function (failures) {
  process.on('exit', function () {
    process.exit(failures);
  });
});
