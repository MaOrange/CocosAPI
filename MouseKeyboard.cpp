auto myKeyListener = EventListenerKeyboard::create();
myKeyListener->onKeyPressed = [](EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{
	CCLOG("key is pressed,keycode is %d", keycode);
};
myKeyListener->onKeyReleased = [](EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{
	CCLOG("key is released,keycode is %d", keycode);
};

auto myMouseListener = EventListenerMouse::create();
myMouseListener->onMouseMove = [=](Event *event)
{
	EventMouse* e = (EventMouse*)event;
	this->mouse->setPosition(e->getCursorX(), e->getCursorY() + visibleSize.height);
};
myMouseListener->onMouseDown = [=](Event *event)
{
	this->mouse->setScale(0.2f);
};
myMouseListener->onMouseUp = [=](Event *event)
{
	this->mouse->setScale(0.3f);
};
_eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
_eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);
return true;
}