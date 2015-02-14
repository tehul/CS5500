#ifndef DUNGEON_HEADER
#define DUNGEON_HEADER
#include <vector>
#include <tuple>
#include "vector3.h"
#include "chunkmanager.h"
#include "chunk.h"

#endif

/*
  1. Create a 3D array of Chunk objects.
  2. Randomly select rooms, store locations in a list.
  3. Iterate through locations, expanding to different sizes,
     but only if a location is sufficiently far enough away
     from another location. Delete locations that are too close
     to a previously successful room.
  4. Create a minimum spanning tree to connect leftover rooms.
  5. Connect rooms to each other based on tree.
  TODO: figure out how to add chests and enemies.
  
 */

typedef std::tuple<int, int, int> Point3D;

class Dungeon {
 public:
  static void makeDungeon(ChunkList &list);
  // Indexes 256 x 256 x 256 dungeon for active blocks.
  static bool isBlockActive(const ChunkList &list, int x, int y, int z);
  static bool isChunkAllActive(const ChunkList &list, int x, int y, int z);
  static int dungeonBlockLength();
  static void printDungeon(ChunkList &list);
  static const int DUNGEON_SIZE = 16;
 private: 
  static int index(int x, int y, int z);
  static void makeChunksActive(ChunkList &chunkList);
  static void createRooms(ChunkList &chunkList);
  static void connectRoom(ChunkList& list, Point3D pos1, Point3D pos2);
  static Point3D createRoom(Chunk* chunkList);
};
