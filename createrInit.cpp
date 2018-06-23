//creater & initializer


//coocs2d std version
#define CREATE_FUNC(__TYPE__) \  
static __TYPE__* create() \
{ \
__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->init()) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}


bool init()
{
	if (!BaseClass::init())
	{
		return false;
	}

	//user code here:

}


//user creater take  Rocker Class as example
static Rocker* Rocker::createRocker(...)
{
	Rocker * ptr = Rocker::create();//assign memory
	if (ptr)
	{
		ptr->initRocker();
		return ptr;
	}
	CC_SAFE_DELETE(ptr);
	return nullptr;
}

bool initRocker()
{
	//user code:
}