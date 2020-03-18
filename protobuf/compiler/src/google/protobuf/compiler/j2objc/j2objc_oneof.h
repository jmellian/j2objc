
// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Author: kstanger@google.com (Keith Stanger)
//  Based on original Protocol Buffers design by
//  Sanjay Ghemawat, Jeff Dean, Kenton Varda, and others.

#ifndef GOOGLE_PROTOBUF_COMPILER_J2OBJC_ONEOF_CASE_H__
#define GOOGLE_PROTOBUF_COMPILER_J2OBJC_ONEOF_CASE_H__

#include <string>
#include <vector>

#include "google/protobuf/compiler/j2objc/common.h"

namespace google {
namespace protobuf {
namespace compiler {
namespace j2objc {

class OneofGenerator {
 public:
  explicit OneofGenerator(const OneofDescriptor* descriptor);
  ~OneofGenerator();

  void CollectMessageOrBuilderForwardDeclarations(
      std::set<std::string>* declarations) const;
  void CollectHeaderImports(std::set<std::string>* imports) const;
  void CollectSourceImports(std::set<std::string>* imports) const;
  void GenerateStorageDeclaration(io::Printer* printer) const;
  void GenerateOneofData(io::Printer* printer) const;
  void GenerateHeader(io::Printer* printer);
  void GenerateSource(io::Printer* printer);
  void GenerateMessageOrBuilder(io::Printer* printer);

 private:
  const OneofDescriptor* descriptor_;

  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(OneofGenerator);
};

}  // namespace j2objc
}  // namespace compiler
}  // namespace protobuf
}  // namespace google

#endif  // GOOGLE_PROTOBUF_COMPILER_J2OBJC_ONEOF_CASE_H__
