/**
 * Copyright (c) 2017 Melown Technologies SE
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * *  Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef miniball_adapter_hpp_included_
#define miniball_adapter_hpp_included_

#include "math/geometry_core.hpp"

#include "../externals/miniball/cpp/main/Seb.h"

namespace miniball {

template <typename T>
class Point3_
{
private:
    const math::Point3_<T> *p;

public:
    Point3_(const math::Point3_<T> &p) : p(&p) {}

    const T& operator[](std::size_t i) const { return (*p)(i); }

    auto begin() -> decltype(p->begin()) const { return p->begin(); }
    auto end() -> decltype(p->end()) const { return p->end(); }

};

template <typename T>
class Point3Accessor_
{
public:
    typedef std::vector<math::Point3_<T>> vector;
    Point3Accessor_(const vector &v) : v_(v) {}

    Point3_<T> operator[](std::size_t i) const { return Point3_<T>(v_[i]); }

    std::size_t size() const { return v_.size(); }

private:
    const vector &v_;
};

} // namespace miniball::detail

#endif // miniball_adapter_hpp_included_
