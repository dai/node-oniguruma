{OnigScanner} = require('bindings')('onig_scanner.node')

module.exports =
class OnigRegExp
  constructor: (@source) ->
    @scanner = new OnigScanner([@source])

  search: (string, startPosition=0) ->
    if result = @scanner.findNextMatch(string, startPosition)
      {captureIndices} = result
      for capture in captureIndices
        capture.match = string[capture.start...capture.end]
      captureIndices
    else
      null

  test: (string) -> @search(string)?
