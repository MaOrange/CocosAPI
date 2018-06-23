/*
	4 the obj being touched is accessed by static_cast<Sprite *>(event->getCurrentTraget())
		  but when it comes to multi-touch, obj can also be accessed by touch: use ->getID() and then find the obj by id in this->getChildren() array.
*/

auto myListener = EventListenerTouchAllAtOnce::create();
myListener->onTouchesBegan = [=](const std::vector<Touch*>& touches, Event *unused_event)
{
	for (auto &item : touches)
	{
		auto* sprite = Sprite::create("sprite.png");
		sprite->setPosition(item->getLocation());
		sprite->setOpacity(120);
		sprite->setScale(0.2f);
		this->addChild(sprite);
	}
};
myListener->onTouchesMoved = [=](const std::vector<Touch*>& touches, Event *unused_event)
{
	for (auto &item : touches)
	{
		int id = item->getID();
		auto array = this->getChildren();
		auto sprite = array.at(id);
		auto point = item->getLocation();
		sprite->setPosition(point);
		CCLOG("id=%d\tx=%f\ty=%f", id, point.x, point.y);
	}
};
myListener->onTouchesEnded = [=](const std::vector<Touch*>& touches, Event *unused_event)
{
	for (auto &item : touches)
	{
		int id = item->getID();
		auto array = this->getChildren();
		auto sprite = array.at(id);
		sprite->setOpacity(255);
		auto point = item->getLocation();
		sprite->setPosition(point);
		CCLOG("id=%d\tx=%f\ty=%f", id, point.x, point.y);
	}
};
_eventDispatcher->addEventListenerWithSceneGraphPriority(myListener, this);
return true;
}
