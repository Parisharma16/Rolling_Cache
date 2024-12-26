#include "memory_class.h"

class CACHE_SET
{
public:
    uint32_t set_id; // Identifier for this set
    uint32_t NUM_WAY;
    BLOCK *PsPtr;
    BLOCK *PrPtr;

    CACHE_SET(uint32_t set_id, uint32_t NUM_WAY, BLOCK *PrPtr)
    {
        this->set_id = set_id;
        this->NUM_WAY = NUM_WAY;
        this->PsPtr = NULL;
        this->PrPtr = PrPtr;
    }

    void updatePtrs(BLOCK *freeList_block)
    {
        this->PsPtr = this->PrPtr;
        this->PrPtr = freeList_block;
    }
};