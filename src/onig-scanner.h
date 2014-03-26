#ifndef SRC_ONIG_SCANNER_H_
#define SRC_ONIG_SCANNER_H_

#include "onig-searcher.h"
#include <string>
#include <vector>
#include <memory>
#include "nan.h"

using ::v8::Array;
using ::v8::Function;
using ::v8::Handle;
using ::v8::Number;
using ::v8::Object;
using ::v8::String;
using ::v8::Value;

using ::std::string;
using ::std::shared_ptr;
using ::std::vector;

class OnigRegExp;
class OnigResult;

class OnigScanner : public node::ObjectWrap {
  public:
    static void Init(Handle<Object> target);

  private:
    static NAN_METHOD(New);
    static NAN_METHOD(FindNextMatch);
    static NAN_METHOD(FindNextMatchSync);
    explicit OnigScanner(Handle<Array> sources);
    ~OnigScanner();

    void FindNextMatch(Handle<String> v8String, Handle<Number> v8StartLocation, Handle<Function> v8Callback, Handle<Value> v8Scanner);
    Handle<Value> FindNextMatchSync(Handle<String> v8String, Handle<Number> v8StartLocation, Handle<Value> v8Scanner);
    Handle<Value> CaptureIndicesForMatch(OnigResult* result, Handle<String> v8String, const char* string, bool hasMultibyteCharacters);

    vector<shared_ptr<OnigRegExp>> regExps;
    shared_ptr<OnigSearcher> searcher;
};

#endif  // SRC_ONIG_SCANNER_H_
