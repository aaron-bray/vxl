// This is core/vgl/vgl_triangle_test.h
#ifndef vgl_triangle_test_h_
#define vgl_triangle_test_h_
#ifdef VCL_NEEDS_PRAGMA_INTERFACE
#pragma interface
#endif
//:
// \file
// \author fsm

//: Compute discriminant function
// Returns determinant of
// \verbatim
// [ x1 x2 x3 ]
// [ y1 y2 y3 ]
// [ 1  1  1  ]
// \endverbatim

template <class T>
T vgl_triangle_test_discriminant(T x1, T y1,
                                 T x2, T y2,
                                 T x3, T y3);

//:Function returns true if (x, y) is inside, or on the boundary of triangle
// The triangle whose vertices are (xi, yi), i=1,2,3.
template <class T>
bool vgl_triangle_test_inside(T x1, T y1,
                              T x2, T y2,
                              T x3, T y3,
                              T x , T y );

#endif // vgl_triangle_test_h_
