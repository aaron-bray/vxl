#ifndef vtol_one_chain_h_
#define vtol_one_chain_h_
//-----------------------------------------------------------------------------
//
// .NAME        vtol_one_chain - Represents a set of edges
// .LIBRARY     vtol
// .HEADER      gel package
// .INCLUDE     vtol/vtol_one_chain.h
// .FILE        vtol_one_chain.cxx
//
// .SECTION Description
//  The vtol_one_chain class is used to represent a set of edges on a topological
//  structure.  A vtol_one_chain consists of its inferior edges and the superiors
//  on which it lies.  A vtol_one_chain may or may not be an ordered cycle.  If
//  the chain of edges encloses an area, then the vtol_one_chain may be used as
//  the boundary of a topological Face in a 3D structure.
//
// .SECTION Author
//     Patricia A. Vrobel
//
// .SECTION Modifications:
//     JLM Dec 1995, Added timeStamp (Touch) to operations which affect bounds.
//     JLM Dec 1995, no local method for ComputeBoundingBox
//                   Should use edge geometry recursively to be proper.
//                   Currently reverts to bounds on vertices from
//                   TopologyObject::ComputeBoundingBox()
//     JLM Jan 1998  Added method to get direction of an edge
//     JLM Feb 1999  Added correct method for ComputeBoundingBox()
//     PTU May 2000  ported to vxl
//-----------------------------------------------------------------------------
#include <vtol/vtol_one_chain_ref.h>

//#include <vtol/vtol_topology_object.h>
//#include <vtol/vtol_hierarchy_node.h>
#include <vtol/vtol_chain.h>

#include <vcl_vector.h>

class vtol_edge;
class vtol_vertex;
class vtol_face;
class vtol_block;
class vtol_zero_chain;
class vtol_two_chain;

//: The class represents a collection of edges and orientations

class vtol_one_chain
//: public vtol_topology_object,
  : public vtol_chain
{
public:
  //***************************************************************************
  // Initialization
  //***************************************************************************

  //---------------------------------------------------------------------------
  //: Default constructor
  //---------------------------------------------------------------------------
  explicit vtol_one_chain(void);

  //---------------------------------------------------------------------------
  //: Constructor from an array of edges
  //---------------------------------------------------------------------------
  explicit vtol_one_chain(edge_list &,
                             bool new_is_cycle=false);

  //---------------------------------------------------------------------------
  //: Constructor from an array of edges and an array of directions
  //---------------------------------------------------------------------------
  explicit vtol_one_chain(edge_list &,
                             vcl_vector<signed char> &,
                             bool new_is_cycle=false);

  //---------------------------------------------------------------------------
  //: Copy constructor
  //---------------------------------------------------------------------------
  vtol_one_chain(const vtol_one_chain &other);

  //---------------------------------------------------------------------------
  //: Destructor
  //---------------------------------------------------------------------------
  virtual ~vtol_one_chain();

  //---------------------------------------------------------------------------
  //: Clone `this': creation of a new object and initialization
  //: See Prototype pattern
  //---------------------------------------------------------------------------
  virtual vsol_spatial_object_3d_ref clone(void) const;

  // Easy access methods


  //: \brief Access methods

  //---------------------------------------------------------------------------
  //: Return the topology type
  //---------------------------------------------------------------------------
  virtual vtol_topology_object_type topology_type(void) const;

  virtual signed char direction(const vtol_edge &e) const;

  //***************************************************************************
  // Replaces dynamic_cast<T>
  //***************************************************************************

  //---------------------------------------------------------------------------
  //: Return `this' if `this' is an one_chain, 0 otherwise
  //---------------------------------------------------------------------------
  virtual const vtol_one_chain *cast_to_one_chain(void) const;

  //---------------------------------------------------------------------------
  //: Return `this' if `this' is an one_chain, 0 otherwise
  //---------------------------------------------------------------------------
  virtual vtol_one_chain *cast_to_one_chain(void);

  //***************************************************************************
  // Status report
  //***************************************************************************

  //---------------------------------------------------------------------------
  //: Is `inferior' type valid for `this' ?
  //---------------------------------------------------------------------------
  virtual bool
  valid_inferior_type(const vtol_topology_object &inferior) const;

  //---------------------------------------------------------------------------
  //: Is `superior' type valid for `this' ?
  //---------------------------------------------------------------------------
  virtual bool
  valid_superior_type(const vtol_topology_object &superior) const;

  //---------------------------------------------------------------------------
  //: Is `chain_inf_sup' type valid for `this' ?
  //---------------------------------------------------------------------------
  virtual bool
  valid_chain_type(const vtol_chain &chain_inf_sup) const;

  //: accessors for outside boundary elements

  virtual vertex_list *outside_boundary_vertices(void);
  virtual zero_chain_list *outside_boundary_zero_chains(void);
  virtual edge_list *outside_boundary_edges(void);
  virtual one_chain_list *outside_boundary_one_chains(void);

  //: accessors to inferiors and superiors
  virtual one_chain_list *inferior_one_chains(void);
  virtual one_chain_list *superior_one_chains(void);


  // Utilities
  //: \brief Utilitites

  virtual void reverse_directions(void);

  virtual vtol_one_chain *
  copy_with_arrays(vcl_vector<vtol_topology_object_ref> &verts,
                   vcl_vector<vtol_topology_object_ref> &edges) const;

  virtual void compute_bounding_box(void); //A local implementation

  virtual vtol_edge *edge(int i) const;
  virtual int num_edges(void) const
  {
    return numinf();
  }

  //  virtual vtol_one_chain *copy() { return new vtol_one_chain(*this); }

  virtual void determine_edge_directions(void);
  virtual void add_edge(vtol_edge &, bool);
  virtual void remove_edge(vtol_edge &, bool);
  
  

  //  virtual void deep_remove( vcl_vector< vtol_topology_object * > & removed );

  // Operators
  //: \brief Operators

  virtual bool operator==(const vtol_one_chain &other) const;
  bool operator==(const vsol_spatial_object_3d& obj) const; // virtual of vsol_spatial_object_3d

  virtual void print(vcl_ostream &strm=vcl_cout) const;
  virtual void describe_directions(vcl_ostream &strm=vcl_cout,
                                   int blanking=0) const;
  virtual void describe(vcl_ostream &strm=vcl_cout,
                        int blanking=0) const;

public:

  //: Warning clients should not use these methods;

  virtual vcl_vector<vtol_vertex*> *compute_vertices(void);
  virtual vcl_vector<vtol_edge*> *compute_edges(void);
  virtual vcl_vector<vtol_zero_chain*> *compute_zero_chains(void);
  virtual vcl_vector<vtol_one_chain*> *compute_one_chains(void);
  virtual vcl_vector<vtol_face*> *compute_faces(void);
  virtual vcl_vector<vtol_two_chain*> *compute_two_chains(void);
  virtual vcl_vector<vtol_block*> *compute_blocks(void);

  virtual vcl_vector<vtol_vertex*> *outside_boundary_compute_vertices(void);
  virtual vcl_vector<vtol_zero_chain*> *outside_boundary_compute_zero_chains(void);
  virtual vcl_vector<vtol_edge*> *outside_boundary_compute_edges(void);
  virtual vcl_vector<vtol_one_chain*> *outside_boundary_compute_one_chains(void);
};

#endif // vtol_one_chain_h_
