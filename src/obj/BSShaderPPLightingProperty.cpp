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
#include "../../include/obj/BSShaderPPLightingProperty.h"
#include "../../include/obj/BSShaderTextureSet.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSShaderPPLightingProperty::TYPE("BSShaderPPLightingProperty", &BSShaderLightingProperty::TYPE );

BSShaderPPLightingProperty::BSShaderPPLightingProperty() : textureSet(NULL), unknownFloat2(0.0f), refractionPeriod((int)0), unknownFloat4(4.0f), unknownFloat5(1.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSShaderPPLightingProperty::~BSShaderPPLightingProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSShaderPPLightingProperty::GetType() const {
	return TYPE;
}

NiObject * BSShaderPPLightingProperty::Create() {
	return new BSShaderPPLightingProperty;
}

void BSShaderPPLightingProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	BSShaderLightingProperty::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( ((info.userVersion == 11) && (info.userVersion2 > 14)) ) {
		NifStream( unknownFloat2, in, info );
		NifStream( refractionPeriod, in, info );
	};
	if ( ((info.userVersion == 11) && (info.userVersion2 > 24)) ) {
		NifStream( unknownFloat4, in, info );
		NifStream( unknownFloat5, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSShaderPPLightingProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderLightingProperty::Write( out, link_map, info );
	if ( info.version < VER_3_3_0_13 ) {
		WritePtr32( &(*textureSet), out );
	} else {
		if ( textureSet != NULL ) {
			NifStream( link_map.find( StaticCast<NiObject>(textureSet) )->second, out, info );
		} else {
			NifStream( 0xFFFFFFFF, out, info );
		}
	}
	if ( ((info.userVersion == 11) && (info.userVersion2 > 14)) ) {
		NifStream( unknownFloat2, out, info );
		NifStream( refractionPeriod, out, info );
	};
	if ( ((info.userVersion == 11) && (info.userVersion2 > 24)) ) {
		NifStream( unknownFloat4, out, info );
		NifStream( unknownFloat5, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSShaderPPLightingProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << BSShaderLightingProperty::asString();
	out << "  Texture Set:  " << textureSet << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Refraction Period:  " << refractionPeriod << endl;
	out << "  Unknown Float 4:  " << unknownFloat4 << endl;
	out << "  Unknown Float 5:  " << unknownFloat5 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSShaderPPLightingProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderLightingProperty::FixLinks( objects, link_stack, info );
	textureSet = FixLink<BSShaderTextureSet>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSShaderPPLightingProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = BSShaderLightingProperty::GetRefs();
	if ( textureSet != NULL )
		refs.push_back(StaticCast<NiObject>(textureSet));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

Ref<BSShaderTextureSet > BSShaderPPLightingProperty::GetTextureSet() const {
	return textureSet;
}

void BSShaderPPLightingProperty::SetTextureSet( Ref<BSShaderTextureSet > value ) {
	textureSet = value;
}

//--END CUSTOM CODE--//
