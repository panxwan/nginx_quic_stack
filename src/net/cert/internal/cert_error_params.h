// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BVC_NET_CERT_INTERNAL_CERT_ERROR_PARAMS_H_
#define BVC_NET_CERT_INTERNAL_CERT_ERROR_PARAMS_H_

#include <memory>
#include <string>

#include "googleurl/base/macros.h"

namespace bvc {

namespace der {
class Input;
}

// CertErrorParams is a base class for describing extra parameters attached to
// a CertErrorNode.
//
// An example use for parameters is to identify the OID for an unconsumed
// critical extension. This parameter could then be pretty printed when
// diagnosing the error.
class CertErrorParams {
 public:
  CertErrorParams();
  virtual ~CertErrorParams();

  // Creates a representation of this parameter as a string, which may be
  // used for pretty printing the error.
  virtual std::string ToDebugString() const = 0;

 private:
  DISALLOW_COPY_AND_ASSIGN(CertErrorParams);
};

// Creates a parameter object that holds a copy of |der|, and names it |name|
// in debug string outputs.
std::unique_ptr<CertErrorParams> CreateCertErrorParams1Der(
    const char* name,
    const der::Input& der);

// Same as CreateCertErrorParams1Der() but has a second DER blob.
std::unique_ptr<CertErrorParams> CreateCertErrorParams2Der(
    const char* name1,
    const der::Input& der1,
    const char* name2,
    const der::Input& der2);

// Creates a parameter object that holds a single size_t value. |name| is used
// when pretty-printing the parameters.
std::unique_ptr<CertErrorParams> CreateCertErrorParams1SizeT(
    const char* name,
    size_t value);

// Same as CreateCertErrorParams1SizeT() but has a second size_t.
std::unique_ptr<CertErrorParams> CreateCertErrorParams2SizeT(
    const char* name1,
    size_t value1,
    const char* name2,
    size_t value2);

}  // namespace bvc

#endif  // BVC_NET_CERT_INTERNAL_CERT_ERROR_PARAMS_H_
