/*
MCZ Note: 1 create a listener of type EventListenerTouchOneByOne*, 
		  2 assigin onTouchBegin move end method by lambda expression. 
			* bool onTouchBegin return true indicates that this very touch event is really on the expected object.
			* onTouchBegin [](Touch * touch, Event * event){} where touch indicates the obj being touched while event indicates ??????
		  3 bind the listener to specific object by _eventDispatcher->addEventListenerWithSceneGraphPriority(listener,obj);
		    *binding one listener to many obj at the same time uses listener->clone()
		  4 ?????? the obj binded with the listener touched is accessed by static_cast<Sprite *>(event->getCurrentTraget())
		  but when it comes to multi-touch, obj can also be accessed by touch: use ->getID() and then find the obj by id in this->getChildren() array.
		  5 ***get touch location: touch->getLocation or touch->getLocationInView (zero point in left-top)
*/


Size visibleSize = Director::getInstance()->getVisibleSize();
Vec2 origin = Director::getInstance()->getVisibleOrigin();
// ���뱳��
auto* background = Sprite::create("background.png");
background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
this->addChild(background);
// ���뿨�ƾ���
for (int i = 0; i < 5; i++)
{
	char imageName[15] = { 0 };
	sprintf(imageName, "mycard0%d.png", i);
	myCard[i] = Sprite::create(imageName);
	myCard[i]->setScale(0.26f);
	myCard[i]->setPosition(visibleSize.width*(i + 1) / 6, visibleSize.height / 2);
	this->addChild(myCard[i]);
}
// �����¼�������
auto myListener = EventListenerTouchOneByOne::create();
myListener->setSwallowTouches(true);
myListener->onTouchBegan = [](Touch* touch, Event* event)
{
	// ��ȡ�¼����󶨵� target???????????????????????/
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	// ��ȡ��ǰ�����������԰�ť��λ������
	Point locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	// �����Χ�жϼ��
	if (rect.containsPoint(locationInNode))
	{
		// ��ʾ��ǰ���ƾ��������λ��
		log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
		target->setOpacity(180);
		return true;
	}
	return false;
};
myListener->onTouchMoved = [](Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	// ��ʾ��ǰ���ƾ��������λ��
	log("sprite move... x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
	// �ƶ���ǰ���ƾ��������λ��
	target->setPosition(target->getPosition() + touch->getDelta());
};
myListener->onTouchEnded = [](Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	target->setOpacity(255);
};
// Ϊ�¼����������¼�
_eventDispatcher->addEventListenerWithSceneGraphPriority(myListener, myCard[0]);
_eventDispatcher->addEventListenerWithSceneGraphPriority(myListener->clone(), myCard[1]);
_eventDispatcher->addEventListenerWithSceneGraphPriority(myListener->clone(), myCard[2]);
_eventDispatcher->addEventListenerWithSceneGraphPriority(myListener->clone(), myCard[3]);
_eventDispatcher->addEventListenerWithSceneGraphPriority(myListener->clone(), myCard[4]);

return true;
}