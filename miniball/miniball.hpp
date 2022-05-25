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

#ifndef miniball_miniball_hpp_included_
#define miniball_miniball_hpp_included_

#include "math/geometry_core.hpp"

#include "miniball/Seb.h"

#include "adapter.hpp"

namespace miniball {

template <typename T>
struct MinimumBoundingSphere3_ {
    math::Point3_<T> center;
    T radius;

    MinimumBoundingSphere3_() : radius() {}
};

template <typename T> MinimumBoundingSphere3_<T>
minimumBoundingSphere(const std::vector<math::Point3_<T>> &points);

template <typename T, typename Points> MinimumBoundingSphere3_<T>
minimumBoundingSphere(const Points &points);

// implementation

namespace detail {

template <typename T, typename SebType>
MinimumBoundingSphere3_<T> msbFromSeb(SebType &seb)
{
    MinimumBoundingSphere3_<T> mbs;
    mbs.radius = seb.radius();
    auto iseb(seb.center_begin());
    mbs.center(0) = *iseb++;
    mbs.center(1) = *iseb++;
    mbs.center(2) = *iseb++;
    return mbs;
}

} // namespace detail

template <typename T> MinimumBoundingSphere3_<T>
minimumBoundingSphere(const std::vector<math::Point3_<T>> &points)
{
    Seb::Smallest_enclosing_ball<T, Point3_<T>, Point3Accessor_<T>>
        seb(3, Point3Accessor_<T>(points));

    return detail::msbFromSeb<T>(seb);
}

template <typename Points> MinimumBoundingSphere3_<typename Points::value_type>
minimumBoundingSphere(const Points &points)
{
    typedef typename Points::value_type value_type;
    Seb::Smallest_enclosing_ball<value_type, Point3_<value_type>, Points>
        seb(3, points);

    return detail::msbFromSeb<value_type>(seb);
}

} // namespace miniball

#endif // miniball_miniball_hpp_included_
