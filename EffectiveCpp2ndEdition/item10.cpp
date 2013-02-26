#include "effectivecpp.h"
/**item10 : manage mem allocation - mem pool!
    The system new have to deal with all kinds of mem
allocation, with this flexibility, it loses efficiency.
    We can use mem pool to manager the alloc of mem.
*/
//The description of an airplane
class AirPlaneRep{};
class AirPlane
{
private:
    static const int BLOC_SIZE;
    static AirPlane* pAP_headOfPool;
public:
    union{
        AirPlaneRep* pAPR_desc;//The real attribut
        AirPlane* pAP_next; //Next bloc in mem pool
    }uni;

    void* operator new(size_t size)
    {
        if(size != sizeof(AirPlane))
        {
            //call defaut new
            return ::operator new(size);
        }
        if(pAP_headOfPool == 0)
        {
            ///Allocate the pool
            pAP_headOfPool = static_cast<AirPlane*>(::operator new(BLOC_SIZE * sizeof(AirPlane)));
            //init the pointer 'next' of each sub-bloc
            int i_i;
            for(i_i = 0; i_i<BLOC_SIZE-1; i_i++)
            {
                (pAP_headOfPool[i_i].uni).pAP_next = &(pAP_headOfPool[i_i+1]);
            }
            (pAP_headOfPool[i_i].uni).pAP_next = 0;


        }
        AirPlane* pAP_res = pAP_headOfPool;//return the first bloc in the pool
        pAP_headOfPool = (pAP_headOfPool->uni).pAP_next;//pAP_next;
        return pAP_res;
    }

    /**The relative delete
    We don't really release the mem, so this is faster. But it's not leak,
    because we always have pointers in our control.
    */
    void operator delete(void* deadObject, size_t size)
    {
        if(deadObject == 0)return;
        if(size != sizeof(AirPlane))
        {
            ::operator delete(deadObject);
            return;
        }
        AirPlane* pAP_dead = static_cast<AirPlane*>(deadObject);
        //Put this bloc back to the pool
        pAP_dead = AirPlane::pAP_headOfPool;
        AirPlane::pAP_headOfPool = pAP_dead;
    }
};
AirPlane* AirPlane::pAP_headOfPool;//=0
//The size of mem pool = 100 airplane
const int AirPlane::BLOC_SIZE = 100;


/**We can abstract this mem management to a Pool class
*/
class Pool
{
private:
    size_t BLOC_SIZE;
public:
    Pool(size_t size):BLOC_SIZE(size){}
    void* alloc(size_t);
    void free(void*, size_t);
//    void* operator new(size_t);
//    void operator delete(void*);
};
/**Usage: in airplane,
override new and delete using memPool.alloc and memPool.free
declaration:static Pool memPool;
definition: static Pool AirPlane::memPool(sizeof(AirPlane));
*/
