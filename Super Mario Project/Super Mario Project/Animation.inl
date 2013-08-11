////////////////////////////////////////////////////////////////////////
// Animation.inl
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template<typename T>
void Animation<T>::addNbSpritesForGivenState(T state, int nbSprites)
{
	std::pair<typename std::map<T, int>::iterator, bool> res;

	res = _nbSpritesByState.insert(std::pair<T, int>(state, nbSprites));
	
	if(res.second == false)
	{
		std::cout << "State : " << state << " already exists." << std::endl;
	}
	else
	{
		if(_nbSpritesMax < nbSprites)
			_nbSpritesMax = nbSprites;
	}
}

template<typename T>
void Animation<T>::addFrameDelayForGivenState(T state, int frameDelay)
{
	std::pair<typename std::map<T, int>::iterator, bool> res;

	res = _frameDelayByState.insert(std::pair<T, int>(state, frameDelay));
	
	if(res.second == false)
	{
		std::cout << "State : " << state << " already exists." << std::endl;
	}
}

template<typename T>
void Animation<T>::reset()
{
	_frameDelayByState.clear();
	_nbSpritesByState.clear();
}

template<typename T>
int Animation<T>::getNbSpritesMax()
{
	return _nbSpritesMax;
}

template<typename T>
int Animation<T>::getNbStates()
{
	return _nbSpritesByState.size();
}

template<typename T>
void Animation<T>::setMapNbSprites(std::map<T, int>& nbSpritesByState)
{
	_nbSpritesByState = nbSpritesByState;
	_nbSpritesMax = computeNbSpritesMax();
}

template<typename T>
void Animation<T>::setMapFrameDelay(std::map<T, int>& frameDelayByState)
{
	_frameDelayByState = frameDelayByState;
}

template<typename T>
int Animation<T>::getFrameDelayForCurrentState()
{
	typename std::map<T, int>::iterator itFrameDelay = _frameDelayByState.find(_currentState);
	if(itFrameDelay != _frameDelayByState.end())
		return itFrameDelay->second;
	else 
		return 0;
}

template<typename T>
int Animation<T>::getNbSpritesForCurrentState()
{
	typename std::map<T, int>::iterator itNbSprites = _nbSpritesByState.find(_currentState);

	if(itNbSprites != _nbSpritesByState.end())
		return itNbSprites->second;
	else 
		return 0;
}

template<typename T>
void Animation<T>::setCurrentState(T state)
{
	_currentState = (T)(((int)state) % _nbStatesMax);
	_frameDelayForCurrentState = getFrameDelayForCurrentState();
	_nbSpritesForCurrentState = getNbSpritesForCurrentState();
}

template<typename T>
int Animation<T>::computeNbSpritesMax()
{
	typename std::map<T, int>::iterator itNbSprites;
	int nbSpritesMax = INT_MIN;

	for(itNbSprites = _nbSpritesByState.begin(); itNbSprites !=  _nbSpritesByState.end(); ++itNbSprites)
	{
		if(itNbSprites->second > nbSpritesMax)
			nbSpritesMax = itNbSprites->second;
	}

	return nbSpritesMax;
}

template<typename T>
void Animation<T>::update()
{
	if(_frameDelayForCurrentState)
	{
		int frameCount = (unsigned int)((_clock.GetElapsedTime() * 1000) / abs(_frameDelayForCurrentState));
		if(frameCount > _nbSpritesForCurrentState && _frameDelayForCurrentState < 0)
		{
			_clock.Reset(true);
			_frameNumber = 0;
		}
		else
		{
			_frameNumber = frameCount % _nbSpritesForCurrentState;
		}
	}
	else
	{
		_frameNumber = 0;
	}
}

template<typename T>
void Animation<T>::render(Texture* texture, sf::RenderWindow& app, sf::Vector2f& position, bool isFlipX, int delta)
{
	int numState = (int)_currentState - delta;
	sf::Vector2i spriteSize = sf::Vector2i(
		texture->getSize().x / _nbSpritesMax,
		texture->getSize().y / _nbSpritesByState.size());
    //sf::Sprite& sprite = texture->getSprite();
	smp::Sprite sprite(*texture);

	if(_nbSpritesForCurrentState > 0)
	{
		int left = _frameNumber * spriteSize.x;
		int top = numState * spriteSize.y;

		sprite.setTextureRect(
			sf::IntRect(
			left,
			top,
			spriteSize.x,
			spriteSize.y));
	}

	if(isFlipX)
	{
		sprite.setScale(-1, 1);
	}
	else
	{
		sprite.setScale(1, 1);
	}

	sprite.setPosition(position);

	sprite.draw();

	//app.draw(sprite);
}

/* Special method for blocks with no animation */
template<typename T>
void Animation<T>::render(Texture* texture, sf::RenderWindow& app, sf::Vector2f& position, sf::Vector2i& coords, sf::Vector2i& size)
{
	smp::Sprite sprite(*texture);
	sprite.setTextureRect(sf::IntRect(coords.x, coords.y, size.x, size.y));

	/* We must correspond graphic to physic */
	sprite.setPosition(position.x, position.y);
	sprite.draw();
	/*app.draw(sprite);*/
}
