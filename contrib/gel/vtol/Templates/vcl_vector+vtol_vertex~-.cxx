#include <vcl/vcl_vector.h>
#include <vcl/vcl_vector.txx>
#include <vcl/vcl_algorithm.txx>
#include <vcl/vcl_algorithm.h>
#include <vtol/vtol_vertex.h>
//#include <vtol/some_stubs.h>

typedef class vtol_vertex *elt_t;

VCL_VECTOR_INSTANTIATE(elt_t);
VCL_FIND_INSTANTIATE(vcl_vector<elt_t>::iterator, elt_t);
