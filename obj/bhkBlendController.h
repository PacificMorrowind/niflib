/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKBLENDCONTROLLER_H_
#define _BHKBLENDCONTROLLER_H_

#include "xml_extract.h"
#include BHK_BLEND_CONTROLLER_INCLUDE

/*
 * bhkBlendController
 */

class bhkBlendController;
typedef Ref<bhkBlendController> bhkBlendControllerRef;

class bhkBlendController : public BHK_BLEND_CONTROLLER_PARENT {
public:
	bhkBlendController();
	~bhkBlendController();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	BHK_BLEND_CONTROLLER_MEMBERS
};
#endif