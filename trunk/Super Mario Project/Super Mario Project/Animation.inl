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
int Animation<T>::getFrameDelayForCurrentState()
{
	map<T, int>::iterator itFrameDelay = _frameDelayByState.find(_currentState);
	if(itFrameDelay != _frameDelayByState.end())
		return itFrameDelay->second;
	else 
		return 0;
}

template<typename T>
int Animation<T>::getNbSpritesForCurrentState()
{
	map<T, int>::iterator itNbSprites = _nbSpritesByState.find(_currentState);

	if(itNbSprites != _nbSpritesByState.end())
		return itNbSprites->second;
	else 
		return 0;
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
void Animation<T>::update()
{
	int frameDelayForCurrentState = getFrameDelayForCurrentState();
	int nbSpritesForCurrentState = getNbSpritesForCurrentState();

	if(frameDelayForCurrentState)
	{
		unsigned int frameCount = (unsigned int)((_clock.GetElapsedTime() * 1000) / abs(frameDelayForCurrentState));
		if(frameCount > nbSpritesForCurrentState && frameDelayForCurrentState < 0)
		{
			_clock.Reset(true);
			_frameNumber = 0;
		}
		else
		{
			_frameNumber = frameCount % nbSpritesForCurrentState;
		}
	}
	else
	{
		_frameNumber = 0;
	}
}

template<typename T>
void Animation<T>::render(Texture* texture, RenderWindow& app, Vector2f& position, bool isFlipX)
{
	int numState = (int)_currentState;
	Vector2f spriteSize = Vector2f(
		texture->getImage()->GetWidth() / getNbSpritesMax(),
		texture->getImage()->GetHeight() / _nbSpritesByState.size());
    ReversedSprite sprite = texture->getSprite();

	if(getNbSpritesForCurrentState() > 0)
	{
		sprite.SetSubRect(
			IntRect(
			_frameNumber * spriteSize.x,
			numState * spriteSize.y,
			(_frameNumber + 1) * spriteSize.x,
			(numState + 1) * spriteSize.y));
	}

	sprite.FlipY(true);
	sprite.FlipX(isFlipX);
	sprite.SetPosition(position);

	app.Draw(sprite);
}