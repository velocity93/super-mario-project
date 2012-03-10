////////////////////////////////////////////////////////////////////////
// Block.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_BLOCKS
#define HPP_BLOCKS



#include "BlockOccurrence.hpp"

namespace Collisions
{
	class Tileset;
	class Block
    {
    public:
		Block(Tileset* tileset, int physicIndex, int type) : _tileset(tileset), _physicIndex(physicIndex), _type(type) { }

		Tileset* getTileset();
		const int getPhysicIndex();
		const int getType();

		BlockOccurrence* addNewBlockOccurrence(Block* alternativeBlock, Vector2f& position = Vector2f(0,0), Vector2f& speed = Vector2f(0,0), 
			BlockOccurrence::State state = BlockOccurrence::State::UNMOVABLE,
			BlockOccurrence::Side side = BlockOccurrence::Side::RIGHT_SIDE);

		void removeBlockOccurrence(const BlockOccurrence* block);

		void update(RenderWindow& app);
		void render(RenderWindow& app);

		void serialize(ofstream& file, string& tabs);

        virtual ~Block();
		
    private:
		vector<BlockOccurrence*> _blockOccurrences;
		Tileset* _tileset;
		Vector2i _coordSprite;
		int _physicIndex;
		int _type;
		
	};

	class BlocksConstants
	{
	public :
		/* Base Physics Blocks */
		static const int  EMPTY							= 0x000000;
		static const int  FILLED						= 0x000001;
		static const int  GROUND						= 0x000002;
		static const int  ROOF							= 0x000004;
		static const int  LEFT_WALL						= 0x000008; // Wall is on the sprite left, so collision with a LEFT_WALL happens when perso comes from RIGHT !
		static const int  RIGHT_WALL					= 0x000010;

		static const int  LEFT_EDGE						= GROUND;
		static const int  RIGHT_EDGE					= GROUND;

		/*	
			SLOPES :
			--------
			Numérotation par rapport à la hauteur du pixel en haut à gauche :
			on enlève une certaine hauteur de l'ordonnée du point le plus à gauche de la pente par rapport au coin en haut à gauche 
		*/
		static const int  SLOPE_30_LEFT_16				= 0x000100; // Here 16
		static const int  SLOPE_30_LEFT_32				= 0x000200; // Here 32
		static const int  SLOPE_30_RIGHT_0				= 0x000300;
		static const int  SLOPE_30_RIGHT_16				= 0x000400;
		static const int  SLOPE_45_LEFT					= 0x000800; // 32 pxls
		static const int  SLOPE_45_RIGHT				= 0x001000; // 0 pxls

		static const int  SLOPE_15_RIGHT_32				= 0x002000;
		static const int  SLOPE_15_LEFT_32				= 0x004000;
		static const int  SLOPE_15_RIGHT_24				= 0x008000;
		static const int  SLOPE_15_LEFT_24				= 0x010000;
		static const int  SLOPE_15_RIGHT_16				= 0x020000;
		static const int  SLOPE_15_LEFT_16				= 0x040000;
		static const int  SLOPE_15_RIGHT_8				= 0x080000;
		static const int  SLOPE_15_LEFT_8				= 0x100000;

		/* More complex physics */
		static const int  TOP_CORNER_LEFT				= (GROUND | LEFT_WALL);
		static const int  TOP_CORNER_RIGHT				= (GROUND | RIGHT_WALL);
		static const int  BOTTOM_CORNER_LEFT			= (ROOF | LEFT_WALL);
		static const int  BOTTOM_CORNER_RIGHT			= (ROOF | RIGHT_WALL);
		static const int  WATER							= EMPTY;
		static const int  PLANT							= FILLED;

		/* BLOCK TYPES */
		static const int BLOCK_TYPE_EMPTY				= 0x200000;
		static const int BLOCK_TYPE_COIN_DISTRIBUTOR	= 0x400000;
		static const int BLOCK_TYPE_BREAKABLE			= 0x800000;
		static const int BLOCK_TYPE_CLIMBING			= 0x1000000; /* Beans, ... */
		static const int BLOCK_TYPE_DEAD_BLOCK			= 0x2000000; /* Lava, acid, poison, ....*/
	};
} // namespace

#endif // HPP_BLOCKS
