/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiBezierMesh.h"
#include "../../include/obj/NiBezierTriangle4.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBezierMesh::TYPE("NiBezierMesh", &NiAVObject::TYPE );

NiBezierMesh::NiBezierMesh() : numBezierTriangles((unsigned int)0), unknown1((unsigned int)0), count1((unsigned short)0), unknown2((unsigned short)0), unknown3((unsigned int)0), unknown4((unsigned int)0), count2((unsigned short)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiBezierMesh::~NiBezierMesh() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiBezierMesh::GetType() const {
	return TYPE;
}

NiObject * NiBezierMesh::Create() {
	return new NiBezierMesh;
}

void NiBezierMesh::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiAVObject::Read( in, link_stack, info );
	NifStream( numBezierTriangles, in, info );
	bezierTriangle.resize(numBezierTriangles);
	for (unsigned int i1 = 0; i1 < bezierTriangle.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( unknown1, in, info );
	NifStream( count1, in, info );
	NifStream( unknown2, in, info );
	points1.resize(count1);
	for (unsigned int i1 = 0; i1 < points1.size(); i1++) {
		NifStream( points1[i1], in, info );
	};
	NifStream( unknown3, in, info );
	points2.resize(count1);
	for (unsigned int i1 = 0; i1 < points2.size(); i1++) {
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( points2[i1][i2], in, info );
		};
	};
	NifStream( unknown4, in, info );
	NifStream( count2, in, info );
	data2.resize(count2);
	for (unsigned int i1 = 0; i1 < data2.size(); i1++) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( data2[i1][i2], in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiBezierMesh::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiAVObject::Write( out, link_map, info );
	count2 = (unsigned short)(data2.size());
	count1 = (unsigned short)(points1.size());
	numBezierTriangles = (unsigned int)(bezierTriangle.size());
	NifStream( numBezierTriangles, out, info );
	for (unsigned int i1 = 0; i1 < bezierTriangle.size(); i1++) {
		if ( info.version < VER_3_3_0_13 ) {
			WritePtr32( &(*bezierTriangle[i1]), out );
		} else {
			if ( bezierTriangle[i1] != NULL ) {
				NifStream( link_map.find( StaticCast<NiObject>(bezierTriangle[i1]) )->second, out, info );
			} else {
				NifStream( 0xFFFFFFFF, out, info );
			}
		}
	};
	NifStream( unknown1, out, info );
	NifStream( count1, out, info );
	NifStream( unknown2, out, info );
	for (unsigned int i1 = 0; i1 < points1.size(); i1++) {
		NifStream( points1[i1], out, info );
	};
	NifStream( unknown3, out, info );
	for (unsigned int i1 = 0; i1 < points2.size(); i1++) {
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( points2[i1][i2], out, info );
		};
	};
	NifStream( unknown4, out, info );
	NifStream( count2, out, info );
	for (unsigned int i1 = 0; i1 < data2.size(); i1++) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( data2[i1][i2], out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiBezierMesh::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiAVObject::asString();
	count2 = (unsigned short)(data2.size());
	count1 = (unsigned short)(points1.size());
	numBezierTriangles = (unsigned int)(bezierTriangle.size());
	out << "  Num Bezier Triangles:  " << numBezierTriangles << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < bezierTriangle.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Bezier Triangle[" << i1 << "]:  " << bezierTriangle[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown 1:  " << unknown1 << endl;
	out << "  Count 1:  " << count1 << endl;
	out << "  Unknown 2:  " << unknown2 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < points1.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Points 1[" << i1 << "]:  " << points1[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown 3:  " << unknown3 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < points2.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Points 2[" << i2 << "]:  " << points2[i1][i2] << endl;
			array_output_count++;
		};
	};
	out << "  Unknown 4:  " << unknown4 << endl;
	out << "  Count 2:  " << count2 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < data2.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Data 2[" << i2 << "]:  " << data2[i1][i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiBezierMesh::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiAVObject::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < bezierTriangle.size(); i1++) {
		bezierTriangle[i1] = FixLink<NiBezierTriangle4>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiBezierMesh::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	for (unsigned int i1 = 0; i1 < bezierTriangle.size(); i1++) {
		if ( bezierTriangle[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(bezierTriangle[i1]));
	};
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
