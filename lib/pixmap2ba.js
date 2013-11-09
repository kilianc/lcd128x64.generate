module.exports = function pixmap2ByteArray(pixmap) {
  var byteArray = [pixmap.width, pixmap.height]
  var byte = ''
  var pixels = pixmap.pixels
  var len = pixels.length
  var height = pixmap.height
  var width = pixmap.width
  var channels = pixmap.channelCount

  for (var yPage = 1; yPage <= height; yPage += 8) {
    for (var x = 1; x <= width; x++) {
      for (var y = yPage; y < yPage + 8; y++) {
        var pi = (y * width - (width - x) -1) * channels +1
        byte = (pixels[pi] ? '0' : '1') + byte
      }
      byteArray.push(parseInt(byte, 2))
      byte = ''
    }
  }