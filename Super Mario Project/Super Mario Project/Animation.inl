////////////////////////////////////////////////////////////////////////
// Animation.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template<typename T>
void Animation<T>::addNbSpritesForGivenState(T state, int nbSprites)
{
	pair<map<T,int>::iterator,bool> res;

	res = _nbSpritesByState.insert(pair<T, int>(state, nbSprites));
	
	if(res.second == false)
	{
		cout << "State : " << state << " already exists." << endl;
	}
}

template<typename T>
void Animation<T>::addFrameDelayForGivenState(T state, int frameDelay)
{
	pair<map<T,int>::iterator,bool> res;

	res = _frameDelayByState.insert(pair<T, int>(state, frameDelay));
	
	if(res.second == false)
	{
		cout << "State : " << state << " already exists." << endl;
	}
}

template<typename T>
void Animation<T>::setMapNbSprites(map<T, int>& nbSpritesByState)
{
	_nbSpritesByState = nbSpritesByState;
}

template<typename T>
void Animation<T>::setMapFrameDelay(map<T, int>& frameDelayByState)
{
	_frameDelayByState = frameDelayByState;
}

template<typename T>
void Animation<T>::setCurrentState(T state)
{
	_currentState = state;
}

template<typename T>
int Animation<T>::getNbSpritesMax()
{
	map<T, int>::iterator itNbSprites;
	int nbSpritesMax = 0;

	for(itNbSprites = _nbSpritesByState.begin(); itNbSprites !=  _nbSpritesByState.end(); ++itNbSprites)
	{
		if(itNbSprites->second > nbSpritesMax)
			nbSpritesMax = itNbSprites->second;
	}

	return nbSpritesMax;
}

template<typename T>
void Animation<T>::update(RenderWindow& app)
{
	if(_frameDelayByState[_currentState])
	{
		unsigned int frameCount = (unsigned int)((_clock.GetElapsedTime() * 1000) / _frameDelayByState[_currentState]);
		if(frameCount > _nbSpritesByState[_currentState])
		{
			//_clock.Reset();
			//_frameNumber = 0;
			_frameNumber = frameCount % _nbSpritesByState[_currentState];
		}
		else
		{
			_frameNumber = frameCount % _nbSpritesByState[_currentState];
		}
	}
}

template<typename T>
void Animation<T>::render(Texture* texture, RenderWindow& app, Vector2f& position)
{
	int numState = static_cast<int>(_currentState);
	Vector2f spriteSize = Vector2f(
		texture->getImage()->GetWidth() / getNbSpritesMax(),
		texture->getImage()->GetHeight() / _nbSpritesByState.size());
	Sprite sprite = texture->getSprite();
	
	sprite.SetSubRect(
		IntRect(
		_frameNumber * spriteSize.x,
		numState * spriteSize.y,
		(_frameNumber + 1) * spriteSize.x,
		(numState + 1) * spriteSize.y));

	sprite.SetPosition(position);

	app.Draw(sprite);
}