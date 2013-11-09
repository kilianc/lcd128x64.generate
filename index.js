var fs = require('fs'),
    path = require('path'),
    async = require('async'),
    moment = require('moment'),
    pixmap2ByteArray = require('./lib/pixmap2ba')

var MENU_ID = 'lcd128x64',
    MENU_LABEL = '$$$/JavaScripts/Generator/LCD 128x64 header file/Menu=LCD 128x64 header file'

exports.init = function init() {
  generator.addMenuItem(MENU_ID, MENU_LABEL, true, false).then(function () {
    console.log('Menu created', MENU_ID)
  }, function (err) {
    console.error('Menu creation failed %s: %s', MENU_ID, err.message)
  })

  generator.onPhotoshopEvent('generatorMenuChanged', function (e) {
    var menu = e.generatorMenuChanged
    if (!menu || menu.name !== MENU_ID) return

    compile(generator)
  })
}

function compile(generator) {
  generator.getDocumentInfo().then(function (document) {
    async.map(document.layers, function (layer, callback) {
      generator.getPixmap(document.id, layer.id, {}).then(function (pixmap) {
        callback(null, pixmap2ByteArray(pixmap))
      }).done()
    }, function (err, layersBA) {
      saveHeaderFileSync(layersBA, document.file.replace('.psd', '.h'))
    })
  }).done()
}

function saveHeaderFileSync(layersBA, filePath) {
  var digitLength = layersBA[0].length
  var matrix = layersBA.map(function (layer) {
    return layer.join(', ')
  })

  var tpl = fs.readFileSync('./etc/header.tpl.h', 'utf8')
  matrix.forEach(function (digit, i) {
    tpl = tpl.replace('{DIGIT_' + i + '}', digit)
  })

  tpl = tpl.replace('{DIGIT_W}', layersBA[0][0])
  tpl = tpl.replace('{DIGIT_W}', layersBA[0][1])
  tpl = tpl.replace('{LEN}', layersBA[0].length)
  tpl = tpl.replace('{FILENAME}', path(filePath).filename)
  tpl = tpl.replace('{DATE}', moment().format('MM/DD/YYYY'))

  fs.writeFileSync(filePath, tpl)
  console.log('File %s successfully saved', filePath)
}